#include "workspace.h"
#include <FL/Fl.H>

Workspace::Workspace(int x, int y, int w, int h): Fl_Double_Window(x,y,w,h){
	box(FL_DOWN_BOX);
	color(FL_WHITE);
	zoom=1;
	add_node(new BaseNodeItem(20,30,50,70,10));
//	add_node(new BaseNodeItem(100,130,50,70,10));
}
Workspace::~Workspace(){
}
#include <FL/fl_draw.H>
void Workspace::draw(){
	fl_line_style(0);
	Fl_Double_Window::draw();
	for(const auto& n: nodes)
		if(n->x()<w() && n->y()<h())
			n->draw();
}
void Workspace::add_node(BaseNodeItem*n){
	nodes.push_back(n);
	n->scale(zoom);
}
void Workspace::remove_node(BaseNodeItem*n){
	delete n;
	nodes.remove(n);
	if(n==BaseNodeItem::hover)
		BaseNodeItem::hover=nullptr;
}
#include <iostream>
int Workspace::handle(int e){
	static int last_x, last_y;
	static const float scale_factor=1.1;
	static bool skip_scroll=false; // The MOUSEWHEEL event is handled two times for some reason..
	switch(e){
	case FL_MOVE:
		for(auto it=nodes.rbegin(); it!=nodes.rend(); it++)
			if((*it)->inside(Fl::event_x(),Fl::event_y())){
				BaseNodeItem::hover=*it;
				redraw();
				return 1;
			}
		if(!BaseNodeItem::hover) return 0;
		BaseNodeItem::hover=nullptr;
		redraw();
		return 1;
	case FL_PUSH:
		last_x = Fl::event_x();
		last_y = Fl::event_y();
		if(BaseNodeItem::hover){
			fl_cursor(FL_CURSOR_MOVE);
			nodes.remove(BaseNodeItem::hover);
			nodes.push_back(BaseNodeItem::hover);
		}
		return 1;
	case FL_RELEASE:
		fl_cursor(FL_CURSOR_DEFAULT);
		return 1;
	case FL_DRAG:
		if(Fl::event_button()!=FL_LEFT_MOUSE)
			for(auto n: nodes)
				n->move(Fl::event_x()-last_x, Fl::event_y()-last_y);
		else
			if(BaseNodeItem::hover)
				BaseNodeItem::hover->move(Fl::event_x()-last_x, Fl::event_y()-last_y);
			//else rubberband
		last_x = Fl::event_x();
		last_y = Fl::event_y();
		redraw();
		return 1;
	case FL_MOUSEWHEEL:
		skip_scroll=!skip_scroll;
		if(skip_scroll) return 0;
		if(Fl::event_dy()<0)
			zoom*=scale_factor;
		else
			zoom/=scale_factor;
		for(auto n:nodes){
			const float x = float(Fl::event_x()-n->x())/n->w();
			const float y = float(Fl::event_y()-n->y())/n->h();
			n->move(Fl::event_dy()*x*(scale_factor-1)*n->w(),Fl::event_dy()*y*(scale_factor-1)*n->h());
			n->scale(zoom);
		}
		redraw();
		return 1;
	case FL_DND_ENTER:
		add_node(BaseNodeItem::hover=new BaseNodeItem(0,0,30,30,2));
		BaseNodeItem::hover->set_pos(Fl::event_x(), Fl::event_y());
		redraw();
		return 1;
	case FL_DND_DRAG:
		if(BaseNodeItem::hover)
			BaseNodeItem::hover->set_pos(Fl::event_x(), Fl::event_y());
		redraw();
		return 1;
	case FL_DND_LEAVE:
		remove_node(BaseNodeItem::hover);
		redraw();
		return 1;
	}
	return Fl_Double_Window::handle(e);
}
