#include "rgb_node_item.h"
#include "rgb_node.h"
#include <color/color_t.h>
#include <FL/fl_draw.H>

RGB_Node_Item::RGB_Node_Item(int x, int y): Node_Item(x, y, 50, 100, new RGB_Node){}

unsigned int RGB_Node_Item::color()const{
	return 0xffffffff;
}
void RGB_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_color(FL_RED);
	fl_rectf(_x+1,_y+_h*.25-3,_w-1,6);
	fl_color(FL_GREEN);
	fl_rectf(_x+1,_y+_h*.5-3,_w-1,6);
	fl_color(FL_BLUE);
	fl_rectf(_x+1,_y+_h*.75-3,_w-1,6);
}

Node_Item* RGB_Node_Item::make(int x, int y, void*){
	return new RGB_Node_Item(x,y);
}
