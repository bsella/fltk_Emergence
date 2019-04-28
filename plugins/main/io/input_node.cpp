#include "input_node.h"

//X_Node::X_Node(): Node(0){
//}

X_Node_Item::X_Node_Item(int x, int y): Node_Item(x,y,70,50,0){}
Y_Node_Item::Y_Node_Item(int x, int y): Node_Item(x,y,70,50,0){}
Ratio_Node_Item::Ratio_Node_Item(int x, int y): Node_Item(x,y,70,50,0){}

Node_Item* X_Node_Item::make(int x, int y){
	return new X_Node_Item(x,y);
}
Node_Item* Y_Node_Item::make(int x, int y){
	return new Y_Node_Item(x,y);
}
Node_Item* Ratio_Node_Item::make(int x, int y){
	return new Ratio_Node_Item(x,y);
}

void X_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("X", _x, _y);
}
void Y_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("Y", _x, _y);
}
void Ratio_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("W/H", _x, _y);
}
