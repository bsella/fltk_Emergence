#include "if_node_item.h"
#include <FL/fl_draw.H>

If_Node_Item::If_Node_Item(int x, int y): Node_Item(x,y,50,100, new If_Node){}

Node_Item* If_Node_Item::make(int x, int y, void*){
	return new If_Node_Item(x,y);
}

void If_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("then", _x+_w/2-14, _y+_h/4+2);
	fl_draw("if",   _x+_w/2-4,  _y+_h/2+4);
	fl_draw("else", _x+_w/2-14, _y+3*_h/4+6);
}

unsigned int If_Node_Item::color()const{
	return 0xb4b4ffff;
}

