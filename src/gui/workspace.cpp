#include "workspace.h"
#include <FL/Fl.H>

Workspace::Workspace(int x, int y, int w, int h): Graphics_View(x,y,w,h){
	add_node(new NodeItem(20,30,50,70,3));
}
Workspace::~Workspace(){
}
void Workspace::add_node(NodeItem*n){
	add_item(n);
}
void Workspace::remove_node(NodeItem*n){
	remove_item(n);
}
int Workspace::handle(int e){
	static NodeItem* hover_to= nullptr;
	switch(e){
	case FL_PUSH:
		if(NodeItem::socket_hover>0){
			NodeItem::socket_x=Fl::event_x();
			NodeItem::socket_y=Fl::event_y();
			NodeItem::socket_drag=true;
			return 1;
		}
		return Graphics_View::handle(e);
	case FL_DRAG:
		if(NodeItem::socket_drag){
			for(const auto i: items){
				NodeItem* n= ((NodeItem*)i);
				if(n->Item::inside(Fl::event_x(), Fl::event_y()) && !n->is_looping((NodeItem*)hover)){
					if(n==hover_to) return 0;
					NodeItem::socket_x= n->x()+n->w()+NodeItem::socket_size*2;
					NodeItem::socket_y= n->y()+n->h()/2;
					hover_to= n;
					redraw();
					return 1;
				}
			}
			NodeItem::socket_x=Fl::event_x();
			NodeItem::socket_y=Fl::event_y();
			hover_to= nullptr;
			redraw();
			return 1;
		}
		return Graphics_View::handle(e);
	case FL_RELEASE:
		if(NodeItem::socket_drag){
			if(hover_to){
				((NodeItem*)hover)->connect(NodeItem::socket_hover-1, hover_to);
				hover_to=nullptr;
			}
			NodeItem::socket_drag=false;
			redraw();
			return 1;
		}
		return Graphics_View::handle(e);
	case FL_DND_ENTER:
		hover= new NodeItem(0,0,30,30,2);
		add_node((NodeItem*)hover);
		hover->set_pos(Fl::event_x(), Fl::event_y());
		redraw();
		return 1;
	case FL_DND_DRAG:
		if(hover)
			hover->set_pos(Fl::event_x(), Fl::event_y());
		redraw();
		return 1;
	case FL_DND_LEAVE:
		remove_node((NodeItem*)hover);
		redraw();
		return 1;
	}
	return Graphics_View::handle(e);
}
