#include "lerp_node_items.h"
#include "lerp_nodes.h"

Lerp_Node_Item::Lerp_Node_Item(int x, int y): Node_Item(x,y, 50, 100, new Lerp_Node){}

Node_Item* Lerp_Node_Item::make(int x, int y, void*){return new Lerp_Node_Item(x,y);}

void Lerp_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("1",_x+4,_y+_h*.25+4);
	fl_draw("0",_x+4,_y+_h*.75+4);
	fl_draw("lerp",_x+4,_y+_h*.5+4);
}

Fl_Color Lerp_Node_Item::color()const{
	return 0xb4ffb4ff;
}
