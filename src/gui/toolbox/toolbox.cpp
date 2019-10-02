#include "toolbox.h"
#include <FL/fl_draw.H>
#include "toolbox_category.h"
#include <cstring>

std::list<Item*> Toolbox::toolbox_items;

Toolbox::Toolbox(int x, int y, int w, int h):Graphics_View(x,y,w,h){
	items= &toolbox_items;
}
Toolbox::~Toolbox(){}

int Toolbox::content_height;
void Toolbox::mouse_wheel_event(int, int dy){
	static unsigned int step= 10;
	if(dy>0){
		scroll_y+= step;
		if(scroll_y + h() > content_height)
			scroll_y= content_height - h();
	}else
		if(dy<0){
			scroll_y-= step;
			if(scroll_y < 0)
				scroll_y= 0;
		}
	redraw();
}
void Toolbox::update_content_height(){
	content_height= 0;
	for(auto* item : toolbox_items)
		content_height+= item->_h;
}
void Toolbox::add(Toolbox_Item* item){
	toolbox_items.push_back(item);
	update_content_height();
}
Toolbox_Category* Toolbox::add_category(const char* cat, const char* icon){
	Toolbox_Category* category;
	for(Item* tb_item : toolbox_items){
		category= dynamic_cast<Toolbox_Category*>(tb_item);
		if(category && strcmp(category->text,cat)==0)
			return category;
	}
	category= new Toolbox_Category(cat, icon);
	Toolbox::add(category);
	return category;
}
void Toolbox::remove(Toolbox_Item* item){
	toolbox_items.remove(item);
	update_content_height();
}
void Toolbox::draw(){
	fl_draw_box(box(), x(), y(), w(), h(), color());
	int y_offset = y();
	for(const auto i : *items){
		i->_w= w()-4;
		i->_x= x()+2;
		i->_y= y_offset+2 - scroll_y;
		y_offset+= i->_h;
		((Toolbox_Item*)i)->draw();
	}
}
void Toolbox::mouse_click_event(int x, int y, int button){
	Graphics_View::mouse_click_event(x,y,button);
	update_content_height();
	redraw();
}
