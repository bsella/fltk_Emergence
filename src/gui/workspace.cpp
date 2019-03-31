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
int Workspace::handle(int e){
	static Node_Item* hover_to= nullptr;
	switch(e){
	case FL_PUSH:
		if(Node_Item::socket_hover>0){
			Node_Item::socket_x=Fl::event_x();
			Node_Item::socket_y=Fl::event_y();
			Node_Item::socket_drag=true;
			return 1;
		}
		return Graphics_View::handle(e);
	case FL_DRAG:
		if(Node_Item::socket_drag){
			for(const auto i: items){
				Node_Item* n= ((Node_Item*)i);
				if(n->Item::inside(Fl::event_x(), Fl::event_y()) && !n->is_looping((Node_Item*)hover)){
					if(n==hover_to) return 0;
					Node_Item::socket_x= n->x()+n->w()+Node_Item::socket_size*2;
					Node_Item::socket_y= n->y()+n->h()/2;
					hover_to= n;
					redraw();
					return 1;
				}
			}
			Node_Item::socket_x=Fl::event_x();
			Node_Item::socket_y=Fl::event_y();
			hover_to= nullptr;
			redraw();
			return 1;
		}
		return Graphics_View::handle(e);
	case FL_RELEASE:
		if(Node_Item::socket_drag){
			if(hover_to){
				((Node_Item*)hover)->connect(Node_Item::socket_hover-1, hover_to);
				hover_to=nullptr;
			}
			Node_Item::socket_drag=false;
			redraw();
			return 1;
		}
		return Graphics_View::handle(e);
	case FL_DND_ENTER:
		hover= new Node_Item(0,0,30,30,2);
		add_node((Node_Item*)hover);
		hover->set_pos(Fl::event_x(), Fl::event_y());
		redraw();
		return 1;
	case FL_DND_DRAG:
		if(hover)
			hover->set_pos(Fl::event_x(), Fl::event_y());
		redraw();
		return 1;
	case FL_DND_LEAVE:
		remove_node((Node_Item*)hover);
		redraw();
		return 1;
	}
	return Graphics_View::handle(e);
}
