#include "toolbox.h"
#include <FL/fl_draw.H>

std::list<Item*> Toolbox::toolbox_items;

Toolbox::Toolbox(int x, int y, int w, int h):Graphics_View(x,y,w,h){
	items= &toolbox_items;
}
Toolbox::~Toolbox(){}
void Toolbox::mouse_wheel_event(int, int){
}
void Toolbox::add(Toolbox_Item* item){
	toolbox_items.push_back(item);
}
void Toolbox::remove(Toolbox_Item* item){
	toolbox_items.remove(item);
}
void Toolbox::draw(){
	fl_draw_box(box(), x(), y(), w(), h(), color());
	int y_offset = y();
	for(const auto i : *items){
		i->_w= w()-4;
		i->_x= x()+2;
		i->_y= y_offset+2;
		y_offset+= i->h();
		((Toolbox_Item*)i)->draw();
	}
}
void Toolbox::mouse_click_event(int x, int y, int button){
	Graphics_View::mouse_click_event(x,y,button);
	redraw();
}
