#include "item.h"

Item::Item():Item(0, 0){}
Item::Item(int w, int h):Item(0,0, w, h){}
Item::Item(int x, int y, int w, int h):_x(x),_y(y),_w(w),_h(h){}
Item::~Item(){}
bool Item::inside(int x, int y)const{
	return y>_y && y<_y+_h && x<_x+_w && x>_x;
}
bool Item::inside(int x1, int y1, int x2, int y2)const{
	if(x1>x2)std::swap(x1,x2);
	if(y1>y2)std::swap(y1,y2);
	return _x>x1 && _x<x2 && _x+_w>x1 && _x+_w<x2 && _y>y1 && _y<y2 && _y+_h>y1 && _y+_h<y2;
}
void Item::set_pos(int x, int y){
	_x=x;
	_y=y;
}
void Item::move(int x,int y){
	_x+=x;
	_y+=y;
}
void Item::mouse_enter_event(int,int){}
void Item::mouse_leave_event(){}
void Item::mouse_move_event(int,int){}
void Item::mouse_press_event(int,int){}
void Item::mouse_release_event(){}
void Item::mouse_drag_event(int, int){}
void Item::mouse_click_event(int,int,int){}
