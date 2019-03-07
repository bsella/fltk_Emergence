#include "node_item.h"
#include <FL/fl_draw.H>

BaseNodeItem::BaseNodeItem(int x, int y, int w, int h, int n):BaseNode(n),_x(x),_y(y),width(w),height(h){
}
BaseNodeItem::~BaseNodeItem(){}
void BaseNodeItem::draw_body()const{
	fl_color(FL_RED);
	fl_line_style(0,hover==this? 2:0);
	//fl_rect(_x,_y,_w,_h);
	const int W= _w/5,                   X1= _x+W, X3= _x+_w-2*W, X4= X3+W;
	const int H= _h/(inodes.size()+1)/2, Y1= _y+H, Y3= _y+_h-2*H, Y4= Y3+H; 
	fl_pie(_x, _y, 2*W, 2*H, 90,180);
	fl_pie(X3, _y, 2*W, 2*H,  0, 90);
	fl_pie(X3, Y3, 2*W, 2*H,270,360);
	fl_pie(_x, Y3, 2*W, 2*H,180,270);
	fl_rectf(X1, _y, _w-2*W, _h);
	fl_rectf(_x, _y+H, W, _h-2*H);
	fl_rectf(_x+_w-W, _y+H, W, _h-2*H);
    
	fl_color(FL_BLACK);
	fl_arc(_x, _y, 2*W, 2*H, 90,180);
	fl_arc(_x+_w-2*W, _y, 2*W, 2*H,  0, 90);
	fl_arc(_x+_w-2*W, Y3, 2*W, 2*H,270,360);
	fl_arc(_x, Y3, 2*W, 2*H,180,270);
	fl_line(X1,   _y,    X4,_y);
	fl_line(_x+_w,Y1, _x+_w,Y4);
	fl_line(X4,_y+_h, X1,_y+_h);
	fl_line(_x, Y1, _x, Y4);
}
void BaseNodeItem::draw()const{
	if(_x+_w<0 || _y+_h<0) return;
	draw_body();
    static const int socket_size = 5;
	for(float i=1; i<inodes.size()+1; i++)
		fl_line(_x-socket_size, _y+i/(1+inodes.size())*_h, _x, _y+i/(1+inodes.size())*_h);
	fl_line(_x+_w, _y+_h/2, _x+_w+socket_size, _y+_h/2);
}
BaseNodeItem* BaseNodeItem::hover = nullptr;
bool BaseNodeItem::inside(int x, int y)const{
	return x>=_x && x<=_x+_w && y>=_y && y<=_y+_h;
}
void BaseNodeItem::set_pos(int x, int y){
	_x=x-_w/2;
	_y=y-_h/2;
}
void BaseNodeItem::move(int x,int y){
	_x+=x;
	_y+=y;
}
void BaseNodeItem::scale(float s){
	_w=width*s;
	_h=height*s;
}
