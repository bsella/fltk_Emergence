#include "workspace.h"
#include <FL/Fl.H>
#include "gui/node_item.h"

Workspace::Workspace(int x, int y, int w, int h): Graphics_View(x,y,w,h){
	add_node(new Node_Item(20,30,50,70,3));
}
Workspace::~Workspace(){
}
void Workspace::add_node(Node_Item*n){
	add_item(n);
}
void Workspace::remove_node(Node_Item*n){
	remove_item(n);
}
static Node_Item* hover_to= nullptr;
void Workspace::mouse_press_event(int x, int y, int button){
	if(Node_Item::socket_hover>0 && button==FL_LEFT_MOUSE){
		Node_Item::socket_x=Fl::event_x();
		Node_Item::socket_y=Fl::event_y();
		Node_Item::socket_drag=true;
	}else Graphics_View::mouse_press_event(x,y,button);
}
void Workspace::mouse_release_event(int button){
	if(Node_Item::socket_drag && button==FL_LEFT_MOUSE){
		if(hover_to){
			((Node_Item*)hover)->connect(Node_Item::socket_hover-1, hover_to);
			hover_to=nullptr;
		}
		Node_Item::socket_drag=false;
		redraw();
	}else Graphics_View::mouse_release_event(button);
}
void Workspace::mouse_drag_event(int dx, int dy, int button){
	if(Node_Item::socket_drag && button==FL_LEFT_MOUSE){
		for(const auto i: items){
			Node_Item* n= ((Node_Item*)i);
			if(n->Item::inside(Fl::event_x(), Fl::event_y()) && !n->is_looping((Node_Item*)hover)){
				if(n==hover_to) return;
				Node_Item::socket_x= n->x()+n->w()+Node_Item::socket_size*2;
				Node_Item::socket_y= n->y()+n->h()/2;
				hover_to= n;
				redraw();
				return;
			}
		}
		Node_Item::socket_x=Fl::event_x();
		Node_Item::socket_y=Fl::event_y();
		hover_to= nullptr;
		redraw();
	}else Graphics_View::mouse_drag_event(dx, dy, button);
}
void Workspace::dnd_enter_event(int x, int y){
	hover= new Node_Item(0,0,30,30,2);
	add_node((Node_Item*)hover);
	hover->set_pos(x, y);
	redraw();
}
void Workspace::dnd_drag_event(int x, int y){
	if(hover)
		hover->set_pos(x, y);
	redraw();
}
void Workspace::dnd_leave_event(){
	remove_node((Node_Item*)hover);
	redraw();
}
