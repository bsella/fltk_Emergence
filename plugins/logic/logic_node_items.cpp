#include "logic_node_items.h"
#include <resources.h>

Logic_Node_Item::Logic_Node_Item(int x, int y, Fl_PNG_Image* icon, Node* node):Node_Item(x,y,50, 50, node), icon(icon){}
Fl_Color Logic_Node_Item::color()const{
	return 0xffffb4b4;
}
void Logic_Node_Item::draw_body()const{
	Node_Item::draw_body();
	if(_w>icon->w() && _h>icon->h()) icon->draw(_w/2 - icon->w()/2 + _x, _h/2 - icon->h()/2 + _y);
}

AND_Node_Item::AND_Node_Item(int x, int y): Logic_Node_Item(x, y, &icon, new AND_Node){}
OR_Node_Item::OR_Node_Item(int x, int y): Logic_Node_Item(x, y, &icon, new OR_Node){}
XOR_Node_Item::XOR_Node_Item(int x, int y): Logic_Node_Item(x, y, &icon, new XOR_Node){}
NOT_Node_Item::NOT_Node_Item(int x, int y): Logic_Node_Item(x, y, &icon, new NOT_Node){}

Fl_PNG_Image AND_Node_Item::icon(RELATIVE("plugins/logic/and.png"));
Fl_PNG_Image OR_Node_Item::icon(RELATIVE("plugins/logic/or.png"));
Fl_PNG_Image XOR_Node_Item::icon(RELATIVE("plugins/logic/xor.png"));
Fl_PNG_Image NOT_Node_Item::icon(RELATIVE("plugins/logic/not.png"));

Node_Item* AND_Node_Item::make(int x, int y, void*){return new AND_Node_Item(x,y);}
Node_Item* OR_Node_Item::make(int x, int y, void*){return new OR_Node_Item(x,y);}
Node_Item* XOR_Node_Item::make(int x, int y, void*){return new XOR_Node_Item(x,y);}
Node_Item* NOT_Node_Item::make(int x, int y, void*){return new NOT_Node_Item(x,y);}
