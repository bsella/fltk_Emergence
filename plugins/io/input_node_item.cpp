#include "input_node_item.h"
#include <FL/fl_draw.H>
#include <resources.h>

X_Node_Item::X_Node_Item(): Node_Item(70,50, new X_Node){}
Y_Node_Item::Y_Node_Item(): Node_Item(70,50, new Y_Node){}
Ratio_Node_Item::Ratio_Node_Item(): Node_Item(70,50, new Ratio_Node){}

Node_Item* X_Node_Item::make(std::istream*){
	return new X_Node_Item;
}
Node_Item* Y_Node_Item::make(std::istream*){
	return new Y_Node_Item;
}
Node_Item* Ratio_Node_Item::make(std::istream*){
	return new Ratio_Node_Item;
}

Fl_PNG_Image X_Node_Item::icon(RELATIVE("plugins/io/x.png"));
Fl_PNG_Image Y_Node_Item::icon(RELATIVE("plugins/io/y.png"));

void X_Node_Item::draw_body()const{
	Node_Item::draw_body();
	if(_w>icon.w() && _h>icon.h()) icon.draw(_w/2 - icon.w()/2 + _x, _h/2 - icon.h()/2 + _y);
}
void Y_Node_Item::draw_body()const{
	Node_Item::draw_body();
	if(_w>icon.w() && _h>icon.h()) icon.draw(_w/2 - icon.w()/2 + _x, _h/2 - icon.h()/2 + _y);
}
void Ratio_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("W/H", _x+_w/2-14, _y+_h/2+4);
}
