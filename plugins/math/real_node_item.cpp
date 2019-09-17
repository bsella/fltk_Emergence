#include "real_node_item.h"
#include "real_node.h"
#include <real/real_t.h>
#include <FL/fl_draw.H>
#include <string>
#include "real_chooser.h"

Real_Node_Item::Real_Node_Item(int x, int y, void* ptr): Node_Item(x, y, 70, 16, new Real_Node(ptr)){}

void Real_Node_Item::draw_body()const{
	fl_color(FL_WHITE);
	fl_rectf(_x, _y, _w, _h);
	fl_color(FL_BLACK);
	fl_rect(_x, _y, _w, _h);
	fl_draw(std::to_string(((Real_t*)core_node->cache)->value).c_str(), _x, _y+_h-2);
}

Node_Item* Real_Node_Item::make(int x, int y, void* ptr){
	return new Real_Node_Item(x,y, ptr);
}

bool Real_Node_Item::settle(){
	bool ret= real_chooser(this);
	return ret;
}
