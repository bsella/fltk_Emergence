#include "hsv_node_items.h"
#include "hsv_nodes.h"
#include <FL/fl_draw.H>

HSV_Node_Item::HSV_Node_Item(): Node_Item(50, 100, new HSV_Node){}
Node_Item* HSV_Node_Item::make(std::istream*){return new HSV_Node_Item;}
Fl_Color HSV_Node_Item::color()const{
	return 0xffffffff;
}
void HSV_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("H", _x+10, _y+_h/4+4);
	fl_draw("S", _x+10,  _y+_h/2+4);
	fl_draw("V", _x+10, _y+3*_h/4+4);
}

HSV_Base_Node_Item::HSV_Base_Node_Item(const char* text, Node* node): Node_Item(50, 50, node), text(text){
}
Fl_Color HSV_Base_Node_Item::color()const{
	return 0xffffffff;
}
void HSV_Base_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw(text, _x+_w/2-4,  _y+_h/2+4);
}

Hue_Node_Item::Hue_Node_Item(): HSV_Base_Node_Item("H", new Hue_Node){}
Saturation_Node_Item::Saturation_Node_Item(): HSV_Base_Node_Item("S", new Saturation_Node){}
Value_Node_Item::Value_Node_Item(): HSV_Base_Node_Item("V", new Value_Node){}


Node_Item* Hue_Node_Item::make(std::istream*){return new Hue_Node_Item;}
Node_Item* Saturation_Node_Item::make(std::istream*){return new Saturation_Node_Item;}
Node_Item* Value_Node_Item::make(std::istream*){return new Value_Node_Item;}
