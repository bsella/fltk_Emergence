#include "toolbox.h"
#include "toolbox_item.h"
#include <FL/fl_draw.H>

std::list<Item*> Toolbox::toolbox_items;

Toolbox::Toolbox(int x, int y, int w, int h):Graphics_View(x,y,w,h){
	items= &toolbox_items;
}
Toolbox::~Toolbox(){}
void Toolbox::mouse_wheel_event(int, int){
}
static unsigned int y_bottom= 0;
void Toolbox::add(make_node_item_t factory, const char* text, const char* icon_path){
	toolbox_items.push_back(new Toolbox_Item(y_bottom,factory,text,icon_path));
	y_bottom+= Toolbox_Item::h;
}
void Toolbox::remove(Toolbox_Item*){
}
void Toolbox::draw(){
	fl_draw_box(box(), x(), y(), w(), h(), color());
	int y_offset = y();
	for(const auto i : *items){
		i->_w= w()-4;
		i->_x= x()+2;
		i->_y= y_offset+2;
		y_offset+= Toolbox_Item::h;
		((Toolbox_Item*)i)->draw();
	}
}
