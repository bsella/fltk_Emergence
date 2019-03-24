#include "workspace.h"
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <algorithm>

Workspace::Workspace(int x, int y, int w, int h): Fl_Double_Window(x,y,w,h){
	box(FL_DOWN_BOX);
	color(FL_WHITE);
	zoom=1;
	add_node(new NodeItem(20,30,50,70,3));
//	add_node(new NodeItem(100,130,50,70,10));
}
Workspace::~Workspace(){
}
void Workspace::draw(){
	fl_line_style(0);
	Fl_Double_Window::draw();
	for(const auto n: nodes)
		if(n->x()<w() && n->y()<h())
			n->draw();
	if(rb_from_x!=-1){
		fl_line_style(FL_DASH);
		fl_rect(std::min(rb_from_x, rb_to_x), std::min(rb_from_y, rb_to_y), std::abs(rb_to_x-rb_from_x), std::abs(rb_to_y-rb_from_y));
		fl_line_style(0);
	}
}
NodeItem* Workspace::top_node(int x, int y, int* s)const{
	for(const auto n : nodes)
		if((*s=n->inside(x,y))!=0)
			return n;
	return nullptr;
}
void Workspace::add_node(NodeItem*n){
	nodes.push_back(n);
	n->scale(zoom);
}
void Workspace::remove_node(NodeItem*n){
	delete n;
	nodes.remove(n);
	if(n==NodeItem::hover)
		NodeItem::hover=nullptr;
}
int Workspace::rb_from_x=-1;
int Workspace::rb_from_y;
int Workspace::rb_to_x;
int Workspace::rb_to_y;
void Workspace::update_rubberband(int x, int y){
	if(rb_from_x==-1){
		selected.clear();
		rb_from_x= x;
		rb_from_y= y;
	}else{
		for(auto it=selected.rbegin(); it!=selected.rend(); it++)
			if(!(*it)->inside(rb_from_x, rb_from_y, rb_to_x, rb_to_y))
				selected.remove(*it);
		for(const auto n: nodes)
			if(n->inside(rb_from_x, rb_from_y, rb_to_x, rb_to_y))
				if(std::find(selected.begin(), selected.end(), n) == selected.end())
					selected.push_back(n);
	}
	rb_to_x=x;
	rb_to_y=y;
}
void Workspace::reset_rubberband(){
	rb_from_x=-1;
}
int Workspace::handle(int e){
	static int last_x, last_y;
	static const float scale_factor=1.1;
	static bool skip_scroll=false; // The MOUSEWHEEL event is handled two times for some reason..
	static const float ratio= (scale_factor-1)/scale_factor;
	static NodeItem* tmp;
	switch(e){
	case FL_MOVE:
		tmp= top_node(Fl::event_x(), Fl::event_y(), &NodeItem::socket_hover);
		if(NodeItem::hover==tmp) return 0;
		NodeItem::hover=tmp;
		redraw();
		return 1;
	case FL_PUSH:
		last_x = Fl::event_x();
		last_y = Fl::event_y();
		if(NodeItem::hover){
			fl_cursor(FL_CURSOR_MOVE);
			nodes.remove(NodeItem::hover);
			nodes.push_back(NodeItem::hover);
			if(std::find(selected.begin(), selected.end(), NodeItem::hover) == selected.end()){
				selected.clear();
				selected.push_back(NodeItem::hover);
			}
		}
		else
			update_rubberband(Fl::event_x(), Fl::event_y());
		return 1;
	case FL_RELEASE:
		fl_cursor(FL_CURSOR_DEFAULT);
		reset_rubberband();
		redraw();
		return 1;
	case FL_DRAG:
		if(Fl::event_button()!=FL_LEFT_MOUSE)
			for(auto n: nodes)
				n->move(Fl::event_x()-last_x, Fl::event_y()-last_y);
		else
			if(NodeItem::hover)
				for(auto n: selected)
					n->move(Fl::event_x()-last_x, Fl::event_y()-last_y);
			else
				update_rubberband(Fl::event_x(), Fl::event_y());
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
			if(Fl::event_dy()<0)
				n->move(-x*(scale_factor-1)*n->w(), -y*(scale_factor-1)*n->h());
			else
				n->move(x*(n->w()*ratio), y*(n->h()*ratio));
			n->scale(zoom);
		}
		redraw();
		return 1;
	case FL_DND_ENTER:
		add_node(NodeItem::hover=new NodeItem(0,0,30,30,2));
		NodeItem::hover->set_pos(Fl::event_x(), Fl::event_y());
		redraw();
		return 1;
	case FL_DND_DRAG:
		if(NodeItem::hover)
			NodeItem::hover->set_pos(Fl::event_x(), Fl::event_y());
		redraw();
		return 1;
	case FL_DND_LEAVE:
		remove_node(NodeItem::hover);
		redraw();
		return 1;
	}
	return Fl_Double_Window::handle(e);
}
