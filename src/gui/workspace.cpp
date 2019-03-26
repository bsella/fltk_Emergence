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
	switch(e){
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
