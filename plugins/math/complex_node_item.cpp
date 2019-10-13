#include "complex_node_item.h"
#include "complex_node.h"
#include <resources.h>

Complex_Node_Item::Complex_Node_Item(): Node_Item(50, 50, new Complex_Node){}

Fl_PNG_Image Complex_Node_Item::icon(RELATIVE("plugins/math/complex.png"));

Node_Item* Complex_Node_Item::make(std::istream*){return new Complex_Node_Item;}

Fl_Color Complex_Node_Item::color()const{
	return FL_WHITE;
}

void Complex_Node_Item::draw_body()const{
	Node_Item::draw_body();
	if(_w>icon.w() && _h>icon.h()) icon.draw(_w/2 - icon.w()/2 + _x, _h/2 - icon.h()/2 + _y);
}
