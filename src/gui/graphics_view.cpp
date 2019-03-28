#include "graphics_view.h"
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <algorithm>

Graphics_View::Graphics_View(int x, int y, int w, int h): Fl_Double_Window(x,y,w,h){
	box(FL_DOWN_BOX);
	color(FL_WHITE);
	zoom=1;
}
Graphics_View::~Graphics_View(){
	for(auto i= items.rbegin(); i!=items.rend(); i++)
		remove_item(*i);
}
Item* Graphics_View::hover=nullptr;
static int rb_from_x=-1;
static int rb_from_y;
static int rb_to_x;
static int rb_to_y;
void Graphics_View::draw(){
	Fl_Double_Window::draw();
	for(auto i= items.rbegin(); i!=items.rend(); i++)
		if((*i)->x()<w() && (*i)->y()<h())
			(*i)->draw();
	if(rb_from_x!=-1){
		fl_line_style(FL_DASH);
		fl_rect(std::min(rb_from_x, rb_to_x), std::min(rb_from_y, rb_to_y), std::abs(rb_to_x-rb_from_x), std::abs(rb_to_y-rb_from_y));
		fl_line_style(0);
	}
}
void Graphics_View::add_item(Item*i){
	items.push_front(i);
	i->scale(zoom);
}
void Graphics_View::remove_item(Item*i){
	if(i==hover)
		hover=nullptr;
	items.remove(i);
	delete i;
}
void Graphics_View::update_rubberband(int x, int y){
	if(rb_from_x==-1){
		selected.clear();
		rb_from_x= x;
		rb_from_y= y;
	}else{
		for(auto it=selected.rbegin(); it!=selected.rend(); it++)
			if(!(*it)->inside(rb_from_x, rb_from_y, rb_to_x, rb_to_y)){
				(*it)->reset_selected();
				selected.remove(*it);
			}
		for(const auto i: items)
			if(i->inside(rb_from_x, rb_from_y, rb_to_x, rb_to_y))
				if(std::find(selected.begin(), selected.end(), i) == selected.end()){
					selected.push_back(i);
					i->set_selected();
				}
	}
	rb_to_x=x;
	rb_to_y=y;
}
void Graphics_View::reset_rubberband(){
	rb_from_x=-1;
}
int Graphics_View::handle(int e){
	static const float scale_factor=1.1;
	static bool skip_scroll=false; // The MOUSEWHEEL event is handled two times for some reason..
	static const float ratio= (scale_factor-1)/scale_factor;
	static int tmp_x, tmp_y;
	switch(e){
	case FL_MOVE:
		for(const auto i: items)
			if(i->inside(Fl::event_x(),Fl::event_y())){
				if(i==hover){
					i->mouse_move_event(Fl::event_x(), Fl::event_y());
					return 0;
				}
				else{
					if(hover) hover->mouse_leave_event();
					i->mouse_enter_event(Fl::event_x(), Fl::event_y());
					hover=i;
					redraw();
					return 1;
				}
			}
		if(hover){
			hover->mouse_leave_event();
			hover=nullptr;
			redraw();
			return 1;
		}
		return 0;
	case FL_PUSH:
		tmp_x= Fl::event_x();
		tmp_y= Fl::event_y();
		if(hover){
			fl_cursor(FL_CURSOR_MOVE);
			items.remove(hover);
			items.push_front(hover);
			if(!hover->is_selected()){
				while(selected.size()){
					(*selected.begin())->reset_selected();
					selected.erase(selected.begin());
				}
				selected.push_front(hover);
			}
		}
		else{
			while(selected.size()){
				(*selected.begin())->reset_selected();
				selected.erase(selected.begin());
			}
			update_rubberband(tmp_x,tmp_y);
		}
		return 1;
	case FL_RELEASE:
		if(hover){
			fl_cursor(FL_CURSOR_DEFAULT);
			hover->mouse_release_event();
			redraw();
			return 1;
		}
		reset_rubberband();
		redraw();
		return 1;
	case FL_DRAG:
		if(Fl::event_button()!=FL_LEFT_MOUSE)
			for(auto i: items)
				i->move(Fl::event_x()-tmp_x, Fl::event_y()-tmp_y);
		else
			if(hover)
				for(auto i: selected)
					i->move(Fl::event_x()-tmp_x, Fl::event_y()-tmp_y);
			else
				update_rubberband(Fl::event_x(), Fl::event_y());
		tmp_x= Fl::event_x();
		tmp_y= Fl::event_y();
		redraw();
		return 1;
	case FL_MOUSEWHEEL:
		skip_scroll=!skip_scroll;
		if(skip_scroll) return 0;
		if(Fl::event_dy()<0)
			zoom*=scale_factor;
		else
			zoom/=scale_factor;
		for(auto i: items){
			const float X = float(Fl::event_x()-i->x())/i->w();
			const float Y = float(Fl::event_y()-i->y())/i->h();
			if(Fl::event_dy()<0)
				i->move(-X*(scale_factor-1)*i->w(), -Y*(scale_factor-1)*i->h());
			else
				i->move(X*(i->w()*ratio), Y*(i->h()*ratio));
			i->scale(zoom);
		}
		redraw();
		return 1;
	}
	return Fl_Double_Window::handle(e);
}
