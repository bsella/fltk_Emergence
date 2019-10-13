#include "rgb_node_items.h"
#include "rgb_nodes.h"
#include <color/color_t.h>
#include <FL/fl_draw.H>

RGB_Node_Item::RGB_Node_Item(): Node_Item(50, 100, new RGB_Node){}
Red_Node_Item::Red_Node_Item(): Node_Item(50, 50, new Red_Node){}
Green_Node_Item::Green_Node_Item(): Node_Item(50, 50, new Green_Node){}
Blue_Node_Item::Blue_Node_Item(): Node_Item(50, 50, new Blue_Node){}
Alpha_Node_Item::Alpha_Node_Item(): Node_Item(50, 50, new Alpha_Node){}

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
void Red_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_color(FL_RED);
	fl_rectf(_x+_w/3, _y+_h/3, _w/3, _h/3);
}
void Green_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_color(FL_GREEN);
	fl_rectf(_x+_w/3, _y+_h/3, _w/3, _h/3);
}
void Blue_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_color(FL_BLUE);
	fl_rectf(_x+_w/3, _y+_h/3, _w/3, _h/3);
}
void Alpha_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("A", _x+_w/2-4,  _y+_h/2+4);
}

Node_Item* RGB_Node_Item::make(std::istream*){return new RGB_Node_Item;}
Node_Item* Red_Node_Item::make(std::istream*){return new Red_Node_Item;}
Node_Item* Green_Node_Item::make(std::istream*){return new Green_Node_Item;}
Node_Item* Blue_Node_Item::make(std::istream*){return new Blue_Node_Item;}
Node_Item* Alpha_Node_Item::make(std::istream*){return new Alpha_Node_Item;}
