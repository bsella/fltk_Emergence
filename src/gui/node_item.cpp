#include "node_item.h"
#include <FL/Fl_Menu_Item.H>
#include <string>
#include <FL/fl_draw.H>

const int Node_Item::socket_size=5;
const int Node_Item::head_size=5;
make_node_item_t Node_Item::dnd_node_factory;
Fl_Color Node_Item::color()const{
	return FL_GRAY;
}
Node_Item::Node_Item(int x, int y, int w, int h, Node* n)
	:Item(x,y,w,h), core_node(n){
	for(unsigned int i=0; i<n->inodes.size(); i++)
		inodes.push_back(nullptr);
}
Node_Item::~Node_Item(){}
void Node_Item::connect(int index, Node_Item* to){
	if(!inodes[index]){
		inodes[index]= to;
		core_node->connect(index, to->core_node);
	}
}
void Node_Item::disconnect(int index){
	if(inodes[index]){
		inodes[index]= nullptr;
		core_node->disconnect(index);
	}
}
bool Node_Item::is_looping(Node_Item* source)const{
	if(this==source) return true;
	for(const auto n: inodes)
		if(n && n->is_looping(source))
			return true;
	return false;
}
void Node_Item::draw_body()const{
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
void Node_Item::draw()const{
	//if(_x+_w<0 || _y+_h<0) return;
	if(selected || (hover && socket_hover==-1))
		fl_line_style(0,2);
	else
		fl_line_style(0);
	draw_body();
	fl_line_style(0);
	fl_color(FL_BLACK);
	for(float i=1; i<input_size()+1; i++){
		const int Y= _y+i/(1+input_size())*_h;
		fl_line(_x-socket_size, Y, _x, Y);
		if(!inodes[i-1]){
			if(hover && socket_hover==i){
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
			const Node_Item* n= inodes[i-1];
			fl_line(_x-socket_size,Y, n->x()+n->w()+socket_size, n->y()+n->h()/2);
		}
	}
	if(hasOutput()) fl_line(_x+_w, _y+_h/2, _x+_w+socket_size, _y+_h/2);
	fl_line_style(0);
}
bool Node_Item::inside(int x, int y)const{
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
int Node_Item::socket_hover = 0;
int Node_Item::socket_x;
int Node_Item::socket_y;
bool Node_Item::socket_drag = false;
void Node_Item::mouse_enter_event(int x, int y){
	hover= true;
	if(x>=_x)
		socket_hover=-1;
	else
		socket_hover=(y-_y+head_size)/(_h/(inodes.size()+1));
}
void Node_Item::mouse_leave_event(){
	hover= false;
	socket_hover=0;
}
void Node_Item::mouse_move_event(int x,	int y){
	if(x<_x)
		socket_hover=(y-_y+head_size)/(_h/(inodes.size()+1));
}
void Node_Item::mouse_click_event(int x, int y, int button){
	if(button== FL_RIGHT_MOUSE){
		std::vector<Fl_Menu_Item> menu;
		context_menu(menu);
		menu.push_back({});
		const Fl_Menu_Item* m= menu.data()->popup(x,y);
		if(m && m->callback() && m->user_data())
			m->do_callback(0,m->user_data());
	}
}

struct disconnect_ud{
	Node_Item* node;
	unsigned int i;
};
void disconnect_cb(Fl_Widget*, void* d){
	disconnect_ud* ud= (disconnect_ud*)d;
	if(ud->node)
		ud->node->disconnect(ud->i);
}

void Node_Item::context_menu(std::vector<Fl_Menu_Item>& menu){
	menu.push_back(Fl_Menu_Item{"Copy",0,0,0,0,0,0,0,0});
	menu.push_back(Fl_Menu_Item{"Cut",0,0,0,0,0,0,0,0});
	menu.push_back(Fl_Menu_Item{"Delete",0,0,0,FL_MENU_DIVIDER,0,0,0,0});
	if(inodes.size()==0) return;
	
	menu.push_back({"disconnect", 0, 0, 0, FL_SUBMENU,0,0,0,0});

	static std::vector<std::string> numbers;
	if(numbers.size()<inodes.size())
		for(unsigned int i=numbers.size(); i<inodes.size(); i++)
			numbers.push_back(std::to_string(i));
	static std::vector<disconnect_ud> ud;
	for(unsigned int i=0; i<inodes.size(); i++)
		if(ud.size()>i){
			ud[i].node=this;
			ud[i].i=i;
		}else
			ud.push_back(disconnect_ud{this,i});
	for(unsigned int i=0; i<inodes.size(); i++)
		menu.push_back({numbers[i].c_str(),0, disconnect_cb, &ud[i], inodes[i]? 0:FL_MENU_INACTIVE,0,0,0,0});
	
	menu.push_back({});
}
bool Node_Item::settle(){return true;}
