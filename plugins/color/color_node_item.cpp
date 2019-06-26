#include "color_node_item.h"
#include "color_node.h"
#include <core/color_t.h>
#include <FL/fl_draw.H>
#include <FL/Fl_Color_Chooser.H>

Color_Node_Item::Color_Node_Item(int x, int y): Node_Item(x, y, 16, 16, new Color_Node){}

Fl_Color Color_Node_Item::color()const{
	if(core_node->cache)
		return core_node->cache->to_color();
	return 0;
}
void Color_Node_Item::draw_body()const{
	fl_color(color());
	fl_pie(_x,_y, _w,_h, 0,360);
	fl_color(FL_BLACK);
	fl_circle(_x+_w/2,_y+_h/2, _w/2);
}

Node_Item* Color_Node_Item::make(int x, int y, void*){
	return new Color_Node_Item(x,y);
}

bool Color_Node_Item::settle(){
	double r,g,b;
	int ret= fl_color_chooser("Choose a color", r,g,b);
	if(ret) core_node->cache= new Color_t(r,g,b);
	return ret;
}
