#include "lerp_node_items.h"
#include "lerp_nodes.h"

Lerp_Base_Node_Item::Lerp_Base_Node_Item(int x, int y, Lerp_Base_Node* n): Node_Item(x,y, 50, 100, n){}
Lerp_Node_Item::Lerp_Node_Item(int x, int y): Lerp_Base_Node_Item(x,y, new Lerp_Node){}
Clamp_Node_Item::Clamp_Node_Item(int x, int y): Lerp_Base_Node_Item(x,y, new Clamp_Node){}

Node_Item* Lerp_Node_Item::make(int x, int y, void*){return new Lerp_Node_Item(x,y);}
Node_Item* Clamp_Node_Item::make(int x, int y, void*){return new Clamp_Node_Item(x,y);}

Fl_Color Lerp_Base_Node_Item::color()const{
	return 0xb4ffb4ff;
}

void Lerp_Base_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("1",_x+4,_y+_h*.25+4);
	fl_draw("0",_x+4,_y+_h*.75+4);
}
void Lerp_Node_Item::draw_body()const{
	Lerp_Base_Node_Item::draw_body();
	fl_draw("lerp",_x+4,_y+_h*.5+4);
}
void Clamp_Node_Item::draw_body()const{
	Lerp_Base_Node_Item::draw_body();
	fl_draw("clamp",_x+4,_y+_h*.5+4);
}
