#include "workspace.h"
#include <FL/Fl.H>
#include "gui/node_item.h"
#include <algorithm>
#include <FL/fl_draw.H>
#include <FL/Fl_Menu_Item.H>
#include <gui/main_window.h>

Workspace::Workspace(int x, int y, int w, int h): Graphics_View(x,y,w,h){
	items = new std::list<Item*>;
	zoom=1;
}
Workspace::~Workspace(){
	delete items;
}
static int rb_from_x=-1;
static int rb_from_y;
static int rb_to_x;
static int rb_to_y;
void Workspace::update_rubberband(int dx, int dy){
	for(auto it=selected.rbegin(); it!=selected.rend(); it++)
		if(!(((Item*)*it))->inside(rb_from_x, rb_from_y, rb_to_x, rb_to_y))
			deselect(*it);
	if(items)
	for(const auto i: *items){
		Node_Item* ni= (Node_Item*)i;
		if(i->inside(rb_from_x, rb_from_y, rb_to_x, rb_to_y))
			if(std::find(selected.begin(), selected.end(), ni) == selected.end())
				select(ni);
	}
	rb_to_x+=dx;
	rb_to_y+=dy;
}
void Workspace::reset_rubberband(){
	rb_from_x=-1;
}
void Workspace::draw(){
	Graphics_View::draw();
	if(rb_from_x!=-1){
		fl_line_style(FL_DASH);
		fl_color(FL_BLACK);
		fl_rect(std::min(rb_from_x, rb_to_x), std::min(rb_from_y, rb_to_y), std::abs(rb_to_x-rb_from_x), std::abs(rb_to_y-rb_from_y));
		fl_line_style(0);
	}
}
void Workspace::add_node(Node_Item*n){
	add_item(n);
	n->scale(zoom);
	n->pos_x= zero_x + n->_x/zoom;
	n->pos_y= zero_y + n->_y/zoom;
}
static Node_Item* hover_to= nullptr;
void Workspace::mouse_press_event(int x, int y, int button){
	if(Node_Item::socket_hover>0 && button==FL_LEFT_MOUSE){
		Node_Item::socket_x=Fl::event_x();
		Node_Item::socket_y=Fl::event_y();
		Node_Item::socket_drag=true;
	}else{
		if(hover){
			//fl_cursor(FL_CURSOR_MOVE);
			items->remove(hover);
			items->push_front(hover);
			if(!((Node_Item*)hover)->selected){
				deselect_all();
				selected.push_front((Node_Item*)hover);
			}
		}
		else{
			if(button==FL_LEFT_MOUSE){
				deselect_all();
				rb_from_x= rb_to_x= x;
				rb_from_y= rb_to_y= y;
			}
		}
	}
}
void Workspace::mouse_release_event(int button){
	if(Node_Item::socket_drag && button==FL_LEFT_MOUSE){
		if(hover_to){
			((Node_Item*)hover)->connect(Node_Item::socket_hover-1, hover_to);
			hover_to=nullptr;
		}
		Node_Item::socket_drag=false;
	}else{
		if(hover) fl_cursor(FL_CURSOR_DEFAULT);
		else reset_rubberband();
	}
	redraw();
}
void Workspace::mouse_drag_event(int dx, int dy, int button){
	if(Node_Item::socket_drag && button==FL_LEFT_MOUSE){
		for(const auto i: *items){
			Node_Item* n= ((Node_Item*)i);
			if(!n->hasOutput()) continue;
			if(!n->Item::inside(Fl::event_x(), Fl::event_y())) continue;
			if(!n->is_looping((Node_Item*)hover)){
				if(n==hover_to) return;
				Node_Item::socket_x= n->_x+n->_w+Node_Item::socket_size*2;
				Node_Item::socket_y= n->_y+n->_h/2;
				hover_to= n;
				redraw();
				return;
			}
		}
		Node_Item::socket_x=Fl::event_x();
		Node_Item::socket_y=Fl::event_y();
		hover_to= nullptr;
	}else{
		if(button!=FL_LEFT_MOUSE){
			zero_x-= dx/zoom;
			zero_y-= dy/zoom;
			for(auto i: *items)
				i->move(dx, dy);
		}
		else
			if(hover)
				for(auto i: selected){
					i->move(dx, dy);
					i->pos_x+= dx/zoom;
					i->pos_y+= dy/zoom;
				}
			else
				update_rubberband(dx,dy);
	}
	redraw();
}
void Workspace::dnd_enter_event(int x, int y){
	if(make_node_item_t make = Node_Item::dnd_node_factory){
		hover= make(x,y,nullptr);
		add_node((Node_Item*)hover);
	}
}
void Workspace::dnd_drag_event(int x, int y){
	if(hover){
		x= x-hover->_w/2;
		y= y-hover->_h/2;
		hover->set_pos(x, y);
		((Node_Item*)hover)->pos_x= zero_x + x/zoom;
		((Node_Item*)hover)->pos_y= zero_y + y/zoom;
	}
	redraw();
}
void Workspace::dnd_drop_event(int, int){
	if(!((Node_Item*)hover)->settle()){
		items->remove(hover);
		delete hover;
		hover= nullptr;
	}
	Node_Item::dnd_node_factory= nullptr;
	redraw();
}
void Workspace::dnd_leave_event(){
	items->remove(hover);
	redraw();
}
void Workspace::mouse_wheel_event(int, int dy){
	static const float scale_factor=1.1;
	if(dy<0){
		if(zoom>5) return;
		zoom*=scale_factor;
		zero_x+= (Fl::event_x()/zoom)*(scale_factor-1);
		zero_y+= (Fl::event_y()/zoom)*(scale_factor-1);
	}
	else{
		if(zoom<.1) return;
		zero_x-= (Fl::event_x()/zoom)*(scale_factor-1);
		zero_y-= (Fl::event_y()/zoom)*(scale_factor-1);
		zoom/=scale_factor;
	}
	for(auto i: *items){
		Node_Item* ni = ((Node_Item*)i);
		i->_x= (ni->pos_x-zero_x)*zoom;
		i->_y= (ni->pos_y-zero_y)*zoom;
		ni->scale(zoom);
	}
	redraw();
}
void Workspace::select(Node_Item* node){
	if(std::find(selected.begin(), selected.end(), node) == selected.end())
		selected.push_back(node);
	node->selected=true;
}
void Workspace::select_all(Fl_Widget*, void* ptr){
	Workspace* ws = (Workspace*)ptr;
	ws->selected.clear();
	for(auto& n: *ws->items)
		ws->select((Node_Item*)n);
	ws->redraw();
}
void Workspace::deselect(Node_Item* node){
	selected.remove(node);
	node->selected=false;
}
void Workspace::deselect_all(){
	for(auto n : selected)
		n->selected= false;
	selected.clear();
}
void Workspace::remove_selected(Fl_Widget*, void* ptr){
	Workspace* ws = (Workspace*)ptr;
	for(auto& n: ws->selected){
		n->disconnect_all();
		ws->items->remove(n);
		if(ws->hover==n) ws->hover= nullptr;
		delete n;
	}
	ws->selected.clear();
	ws->redraw();
}
void Workspace::mouse_click_event(int x, int y, int button){
	if(button== FL_RIGHT_MOUSE){
		std::vector<Fl_Menu_Item> menu;
		int flags = selected.size()? 0:FL_MENU_INACTIVE;
		menu.push_back(Fl_Menu_Item{"Copy",0,0,0,flags,0,0,0,0});
		menu.push_back(Fl_Menu_Item{"Cut",0,0,0,flags,0,0,0,0});
		menu.push_back(Fl_Menu_Item{"Paste",0,0,0,FL_MENU_DIVIDER,0,0,0,0});
		menu.push_back(Fl_Menu_Item{"Delete",0,&remove_selected,this, flags,0,0,0,0});
		menu.push_back(Fl_Menu_Item{"Select All",0,&select_all,this,0,0,0,0,0});
		if(hover)
			((Node_Item*)hover)->context_menu(menu);
		menu.push_back({});
		const Fl_Menu_Item* m= menu.data()->popup(x,y);
		if(m && m->callback() && m->user_data())
			m->do_callback(this,m->user_data());
	}
}
void Workspace::insert(Fl_Widget*, void* ptr){
	auto make= (Node_Item* (*)(int,int,void*))ptr;
	Node_Item* ni= make(workspace->x()+workspace->w()/2, workspace->y()+workspace->h()/2, nullptr);
	ni->_x-= ni->_w/2;
	ni->_y-= ni->_h/2;
	workspace->add_node(ni);
	if(!ni->settle()){
		workspace->items->remove(ni);
		delete ni;
	}
	workspace->redraw();
}
