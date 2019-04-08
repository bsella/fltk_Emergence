#include "graphics_view.h"
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <algorithm>
#include "item.h"

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
void Graphics_View::update_rubberband(int dx, int dy){
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
	rb_to_x+=dx;
	rb_to_y+=dy;
}
void Graphics_View::reset_rubberband(){
	rb_from_x=-1;
}
int Graphics_View::handle(int e){
	static bool skip_scroll=false; // The MOUSEWHEEL event is handled two times for some reason..
	static int tmp_x, tmp_y;
	static bool click= false;
	switch(e){
	case FL_MOVE:
		mouse_move_event(Fl::event_x(), Fl::event_y());
		return 1;
	case FL_PUSH:
		tmp_x= Fl::event_x();
		tmp_y= Fl::event_y();
		click= true;
		mouse_press_event(Fl::event_x(), Fl::event_y(), Fl::event_button());
		return 1;
	case FL_RELEASE:
		if(click){
			mouse_click_event(Fl::event_x(), Fl::event_y(), Fl::event_button());
			click= false;
		}
		mouse_release_event(Fl::event_button());
		return 1;
	case FL_DRAG:
		click=false;
		mouse_drag_event(Fl::event_x()-tmp_x, Fl::event_y()-tmp_y, Fl::event_button());
		tmp_x= Fl::event_x();
		tmp_y= Fl::event_y();
		return 1;
	case FL_MOUSEWHEEL:
		skip_scroll=!skip_scroll;
		if(skip_scroll) return 0;
		mouse_wheel_event(Fl::event_dx(),Fl::event_dy());
		return 1;
	case FL_DND_ENTER:
		dnd_enter_event(Fl::event_x(), Fl::event_y());
		return 1;
	case FL_DND_DRAG:
		dnd_drag_event(Fl::event_x(), Fl::event_y());
		return 1;
	case FL_DND_LEAVE:
		dnd_leave_event();
		return 1;
	}
	return Fl_Double_Window::handle(e);
}
void Graphics_View::mouse_move_event(int x,int y){
	for(const auto i: items)
		if(i->inside(x,y)){
			if(i==hover){
				i->mouse_move_event(x,y);
				return;
			}
			else{
				if(hover) hover->mouse_leave_event();
				i->mouse_enter_event(x,y);
				hover=i;
				redraw();
				return;
			}
		}
	if(hover){
		hover->mouse_leave_event();
		hover=nullptr;
		redraw();
	}
}
void Graphics_View::mouse_click_event(int x, int y, int button){
	for(const auto i: items)
		if(i->inside(x,y)){
			i->mouse_click_event(x,y,button);
			return;
		}
}
void Graphics_View::mouse_drag_event(int dx, int dy, int button){
	if(button!=FL_LEFT_MOUSE)
		for(auto i: items)
			i->move(dx, dy);
	else
		if(hover)
			for(auto i: selected)
				i->move(dx, dy);
		else
			update_rubberband(dx,dy);
	redraw();
}
void Graphics_View::mouse_press_event(int x, int y, int button){
	if(hover){
		//fl_cursor(FL_CURSOR_MOVE);
		items.remove(hover);
		items.push_front(hover);
		hover->mouse_press_event(x,y);
		if(!hover->is_selected()){
			while(selected.size()){
				(*selected.begin())->reset_selected();
				selected.erase(selected.begin());
			}
			selected.push_front(hover);
		}
	}
	else{
		if(button==FL_LEFT_MOUSE){
			while(selected.size()){
				(*selected.begin())->reset_selected();
				selected.erase(selected.begin());
			}
			rb_from_x= rb_to_x= x;
			rb_from_y= rb_to_y= y;
		}
	}
}
void Graphics_View::mouse_release_event(int){
	if(hover){
		fl_cursor(FL_CURSOR_DEFAULT);
		hover->mouse_release_event();
	}else reset_rubberband();
	redraw();
}
void Graphics_View::dnd_enter_event(int,int){}
void Graphics_View::dnd_drag_event(int,int){}
void Graphics_View::dnd_leave_event(){}
void Graphics_View::mouse_wheel_event(int, int dy){
	static const float scale_factor=1.1;
	static const float ratio= (scale_factor-1)/scale_factor;
	if(dy<0)
		zoom*=scale_factor;
	else
		zoom/=scale_factor;
	for(auto i: items){
		const float X = float(Fl::event_x()-i->x())/i->w();
		const float Y = float(Fl::event_y()-i->y())/i->h();
		if(dy<0)
			i->move(-X*(scale_factor-1)*i->w(), -Y*(scale_factor-1)*i->h());
		else
			i->move(X*(i->w()*ratio), Y*(i->h()*ratio));
		i->scale(zoom);
	}
	redraw();
}
