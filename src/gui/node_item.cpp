#include "node_item.h"
const int NodeItem::socket_size=5;
const int NodeItem::head_size=5;
Fl_Color NodeItem::color()const{
	return FL_GRAY;
}
NodeItem::NodeItem(int x, int y, int w, int h, int n):Node(n),Item(x,y,w,h){
}
NodeItem::~NodeItem(){}
void NodeItem::draw_body()const{
	fl_color(color());
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
	if(is_selected() || (is_hover() && socket_hover==-1))
		fl_line_style(0,2);
	else
		fl_line_style(0);
	draw_body();
	fl_line_style(0);
	for(float i=1; i<inodes.size()+1; i++){
		const int Y= _y+i/(1+inodes.size())*_h;
		fl_line(_x-socket_size, Y, _x, Y);
		if(!inodes[i-1]){
			if(is_hover() && socket_hover==i){
				fl_line_style(0,2);
				if(socket_drag){
					fl_circle(socket_x,socket_y, head_size);
					fl_line_style(0);
					fl_line(socket_x+head_size,socket_y, _x-socket_size,Y);
				}else
					fl_circle(_x-socket_size-head_size,Y, head_size);
				fl_line_style(0);
			}else
				fl_circle(_x-socket_size-head_size,Y, head_size);
		}else{
			const NodeItem* n= (NodeItem*)inodes[i-1];
			fl_line(_x-socket_size,Y, n->x()+n->w()+socket_size, n->y()+n->h()/2);
		}
	}
	fl_line(_x+_w, _y+_h/2, _x+_w+socket_size, _y+_h/2);
	fl_line_style(0);
}
bool NodeItem::inside(int x, int y)const{
	if(Item::inside(x,y))
		return true;
	if(x<_x && x<=_x-socket_size && x>=_x-socket_size-head_size*2){
		const int Y= y-_y+head_size, H=_h/(inodes.size()+1);
		if(Y%H < head_size*2){
			const int tmp= Y/H;
			if(tmp>0 && tmp<=(int)inodes.size())
				return true;
			return false;
		}
	}
	return false;
}
int NodeItem::socket_hover = 0;
int NodeItem::socket_x;
int NodeItem::socket_y;
bool NodeItem::socket_drag = false;
void NodeItem::mouse_enter_event(int x, int y){
	Item::mouse_enter_event(x,y);
	if(x>=_x)
		socket_hover=-1;
	else
		socket_hover=(y-_y+head_size)/(_h/(inodes.size()+1));
}
void NodeItem::mouse_leave_event(){
	Item::mouse_leave_event();
	socket_hover=0;
}
static int press_x, press_y;
void NodeItem::mouse_press_event(int x, int y){
	press_x=x;
	press_y=y;
}
void NodeItem::mouse_move_event(int,int){
}
void NodeItem::mouse_release_event(){
}
