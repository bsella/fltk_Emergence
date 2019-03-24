#include "node_item.h"
#include <FL/fl_draw.H>
static const int socket_size=5;
static const int head_size=5;
NodeItem::NodeItem(int x, int y, int w, int h, int n):Node(n),_x(x),_y(y),width(w),height(h){
}
NodeItem::~NodeItem(){}
void NodeItem::draw_body()const{
	fl_color(FL_RED);
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
void NodeItem::draw()const{
	if(_x+_w<0 || _y+_h<0) return;
	if(hover==this && socket_hover==-1)
		fl_line_style(0,2);
	else
		fl_line_style(0);
	draw_body();
	for(float i=1; i<inodes.size()+1; i++){
		const int Y= _y+i/(1+inodes.size())*_h;
		fl_line(_x-socket_size, Y, _x, Y);
		if(!inodes[i-1]){
			if(hover==this && socket_hover==i)
				fl_line_style(0,2);
			else
				fl_line_style(0);
			fl_circle(_x-socket_size-head_size,Y, head_size);
			fl_line_style(0);
		}
	}
	fl_line(_x+_w, _y+_h/2, _x+_w+socket_size, _y+_h/2);
	fl_line_style(0);
}
NodeItem* NodeItem::hover = nullptr;
int NodeItem::socket_hover = 0;
int NodeItem::socket_x;
int NodeItem::socket_y = -1;
int NodeItem::inside(int x, int y)const{
	if(y<_y || y>_y+_h || x>_x+_w || x<=_x-socket_size-head_size*2)
		return 0;
	if(x>=_x)
		return -1;
	if(x>_x-socket_size || y-_y< head_size)
		return 0;
	if((y-_y+head_size)%(_h/(inodes.size()+1)) < head_size*2)
		return (y-_y)/(_h/inodes.size()) + 1;
	return 0;
}
bool NodeItem::inside(int x1, int y1, int x2, int y2)const{
	if(x1>x2)std::swap(x1,x2);
	if(y1>y2)std::swap(y1,y2);
	return _x>x1 && _x<x2 && _x+_w>x1 && _x+_w<x2 && _y>y1 && _y<y2 && _y+_h>y1 && _y+_h<y2;
}
void NodeItem::set_pos(int x, int y){
	_x=x-_w/2;
	_y=y-_h/2;
}
void NodeItem::move(int x,int y){
	_x+=x;
	_y+=y;
}
void NodeItem::scale(float s){
	_w=width*s;
	_h=height*s;
}
