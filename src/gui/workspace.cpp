#include "workspace.h"
#include <FL/Fl.H>
#include "gui/node_item.h"
#include <algorithm>
#include <FL/fl_draw.H>
#include <FL/Fl_Menu_Item.H>
#include <gui/main_window.h>
#include <gui/toolbox/toolbox_node_item.h>
#include <gui/binary_save.h>

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
void Workspace::add_node(Node_Item* n){
	add_item(n);
	n->scale(zoom);
	n->_x= (n->pos_x - zero_x)*zoom;
	n->_y= (n->pos_y - zero_y)*zoom;
	//n->pos_x= zero_x + n->_x/zoom;
	//n->pos_y= zero_y + n->_y/zoom;
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
	if(auto make = Toolbox_Node_Item::dnd_node_factory){
		hover= make(nullptr);
		add_node(static_cast<Node_Item*>(hover));
		x= x-hover->_w/2;
		y= y-hover->_h/2;
		hover->set_pos(x, y);
		static_cast<Node_Item*>(hover)->pos_x= zero_x + x/zoom;
		static_cast<Node_Item*>(hover)->pos_y= zero_y + y/zoom;
		redraw();
	}
}
void Workspace::dnd_drag_event(int x, int y){
	if(hover){
		x= x-hover->_w/2;
		y= y-hover->_h/2;
		hover->set_pos(x, y);
		static_cast<Node_Item*>(hover)->pos_x= zero_x + x/zoom;
		static_cast<Node_Item*>(hover)->pos_y= zero_y + y/zoom;
		redraw();
	}
}
void Workspace::dnd_drop_event(int, int){
	if(!static_cast<Node_Item*>(hover)->settle()){
		items->remove(hover);
		delete hover;
		hover= nullptr;
	}
	Toolbox_Node_Item::dnd_node_factory= nullptr;
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
		menu.push_back(Fl_Menu_Item{"Copy",0,&copy_selected,&selected,flags,0,0,0,0});
		menu.push_back(Fl_Menu_Item{"Cut",0,0,0,flags,0,0,0,0});
		menu.push_back(Fl_Menu_Item{"Paste",0,&paste,this,FL_MENU_DIVIDER | clipboard.str().empty(),0,0,0,0});
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
	auto make= (Node_Item* (*)(std::istream*))ptr;
	Node_Item* ni= make(nullptr);
	ni->pos_x= (workspace->x() + workspace->w()/2 - ni->_w/2)/ workspace->zoom + workspace->zero_x;
	ni->pos_y= (workspace->y() + workspace->h()/2 - ni->_h/2)/ workspace->zoom + workspace->zero_y;
	workspace->add_node(ni);
	if(!ni->settle()){
		workspace->items->remove(ni);
		delete ni;
	}
	workspace->redraw();
}

std::stringstream Workspace::clipboard(std::ios::binary | std::ios::in | std::ios::out);
static const int minus_one= -1;
#include <map>
void Workspace::copy_selected(Fl_Widget*, void* ptr){
	clipboard.str("");
	clipboard.seekg(0, std::ios::beg);
	std::list<Node_Item*>* nodes = static_cast<std::list<Node_Item*>*>(ptr);
	int index=0;
	std::map<Node_Item*, int> node_indices;
	for(const auto n: *nodes){
		n->save(clipboard);
		node_indices[n]= index++;
	}
	size_t end=0;
	clipboard.write(reinterpret_cast<char*>(&end), sizeof(size_t));
	std::map<Node_Item*,int>::iterator it;
	for(const auto n: *nodes)
		for(auto in: n->inodes)
			if(in!=nullptr && ((it= node_indices.find(in)) != node_indices.end()))
				clipboard.write(reinterpret_cast<char*>(&it->second), sizeof(int));
			else
				clipboard.write(reinterpret_cast<const char*>(&minus_one), sizeof(minus_one));
}
void Workspace::paste(Fl_Widget*, void*ptr){
	size_t len;
	char* id;
	double x,y;
	clipboard.seekg(0, std::ios::beg);
	clipboard.read(reinterpret_cast<char*>(&len), sizeof(size_t));
	std::vector<Node_Item*> new_nodes;
	while(len){
		id= new char[len];
		clipboard.read(id, len);
		auto makefunc= get_node_item(id);
		delete[] id;
		Node_Item* new_node= makefunc(&clipboard);
		clipboard.read(reinterpret_cast<char*>(&x), sizeof(double));
		clipboard.read(reinterpret_cast<char*>(&y), sizeof(double));
		new_node->pos_x= x;
		new_node->pos_y= y;
		static_cast<Workspace*>(ptr)->add_node(new_node);
		clipboard.read(reinterpret_cast<char*>(&len), sizeof(size_t));
		new_nodes.push_back(new_node);
	}
	int temp;
	for(auto n: new_nodes)
		for(size_t i=0; i<n->inodes.size(); i++){
			clipboard.read(reinterpret_cast<char*>(&temp), sizeof(temp));
			if(temp!=minus_one) n->connect(i, new_nodes[temp]);
		}
	static_cast<Workspace*>(ptr)->deselect_all();
	for(auto n: new_nodes)
		static_cast<Workspace*>(ptr)->select(n);
	static_cast<Workspace*>(ptr)->redraw();
}
