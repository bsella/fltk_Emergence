#include "toolbox_item.h"
#include <FL/fl_draw.H>

Toolbox_Item::Toolbox_Item(int h, const char* text, const char* icon_path)
	:Item(0, 0, 0, h), text(text){
	icon= new Fl_PNG_Image(icon_path);
}
Toolbox_Item::~Toolbox_Item(){
	delete icon;
}
void Toolbox_Item::draw()const{
	fl_draw_box(FL_UP_BOX, _x, _y, _w, _h, FL_GRAY);
	fl_color(FL_BLACK);
	fl_draw(text, _x+36, _y+_h/2+4);
	icon->draw(_x+4, _y+_h/2- icon->h()/2);
}
