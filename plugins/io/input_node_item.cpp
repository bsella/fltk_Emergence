#include "input_node_item.h"

X_Node_Item::X_Node_Item(int x, int y): Node_Item(x,y,70,50,0){}
Y_Node_Item::Y_Node_Item(int x, int y): Node_Item(x,y,70,50,0){}
Ratio_Node_Item::Ratio_Node_Item(int x, int y): Node_Item(x,y,70,50,0){}

Node_Item* X_Node_Item::make(int x, int y, void*){
	return new X_Node_Item(x,y);
}
Node_Item* Y_Node_Item::make(int x, int y, void*){
	return new Y_Node_Item(x,y);
}
Node_Item* Ratio_Node_Item::make(int x, int y, void*){
	return new Ratio_Node_Item(x,y);
}

void X_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("X", _x+_w/2-4, _y+_h/2+4);
}
void Y_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("Y", _x+_w/2-4, _y+_h/2+4);
}
void Ratio_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("W/H", _x+_w/2-14, _y+_h/2+4);
}
