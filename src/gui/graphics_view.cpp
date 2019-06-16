#include "graphics_view.h"
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "item.h"

Graphics_View::Graphics_View(int x, int y, int w, int h): Fl_Widget(x,y,w,h){
	box(FL_DOWN_BOX);
	color(FL_WHITE);
}
Graphics_View::~Graphics_View(){
}
Item* Graphics_View::hover=nullptr;
void Graphics_View::draw(){
	fl_draw_box(box(), x(), y(), w(), h(), color());
	if(!items) return;
	for(auto i= items->rbegin(); i!=items->rend(); i++)
		//if((*i)->x()<w() && (*i)->y()<h())
			(*i)->draw();
}
void Graphics_View::add_item(Item*i){
	items->push_front(i);
}
void Graphics_View::remove_item(Item*i){
	if(i==hover)
		hover=nullptr;
	items->remove(i);
	delete i;
}
int Graphics_View::handle(int e){
	static int tmp_x, tmp_y, dx, dy;
	static bool click= false;
	switch(e){
	case FL_ENTER:
		Fl::belowmouse(this);
		return 1;
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
		dx=Fl::event_x()-tmp_x;
		dy=Fl::event_y()-tmp_y;
		mouse_drag_event(dx, dy, Fl::event_button());
		tmp_x= Fl::event_x();
		tmp_y= Fl::event_y();
		return 1;
	case FL_MOUSEWHEEL:
		if(Fl::belowmouse()!=this) return 0;
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
	return Fl_Widget::handle(e);
}
void Graphics_View::mouse_move_event(int x, int y){
	if(!items) return;
	for(const auto i: *items)
		if(i->inside(x,y)){
			if(i==hover) i->mouse_move_event(x,y);
			else{
				if(hover) hover->mouse_leave_event();
				i->mouse_enter_event(x,y);
				hover=i;
				redraw();
			}
			return;
		}
	if(hover){
		hover->mouse_leave_event();
		hover=nullptr;
		redraw();
	}
}
void Graphics_View::mouse_click_event(int x, int y, int button){
	if(hover) hover->mouse_click_event(x,y, button);
}
void Graphics_View::mouse_drag_event(int dx, int dy, int){
	if(hover) hover->mouse_drag_event(dx,dy);
}
void Graphics_View::mouse_press_event(int x, int y, int){
	if(hover) hover->mouse_press_event(x,y);
}
void Graphics_View::mouse_release_event(int){
	if(hover) hover->mouse_release_event();
}
void Graphics_View::dnd_enter_event(int,int){}
void Graphics_View::dnd_drag_event(int,int){}
void Graphics_View::dnd_leave_event(){}
void Graphics_View::mouse_wheel_event(int, int){}
