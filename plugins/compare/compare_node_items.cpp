#include "compare_node_items.h"
#include <resources.h>

Compare_Node_Item::Compare_Node_Item(Fl_PNG_Image* icon, Node* node):Node_Item(50, 50, node), icon(icon){}
Fl_Color Compare_Node_Item::color()const{
	return 0xffb4b4ff;
}
void Compare_Node_Item::draw_body()const{
	Node_Item::draw_body();
	if(_w>icon->w() && _h>icon->h()) icon->draw(_w/2 - icon->w()/2 + _x, _h/2 - icon->h()/2 + _y);
}

GT_Node_Item::GT_Node_Item(): Compare_Node_Item(&icon, new GT_Node){}
LT_Node_Item::LT_Node_Item(): Compare_Node_Item(&icon, new LT_Node){}
EQ_Node_Item::EQ_Node_Item(): Compare_Node_Item(&icon, new EQ_Node){}
NE_Node_Item::NE_Node_Item(): Compare_Node_Item(&icon, new NE_Node){}

Fl_PNG_Image GT_Node_Item::icon(RELATIVE("plugins/compare/gt.png"));
Fl_PNG_Image LT_Node_Item::icon(RELATIVE("plugins/compare/lt.png"));
Fl_PNG_Image EQ_Node_Item::icon(RELATIVE("plugins/compare/eq.png"));
Fl_PNG_Image NE_Node_Item::icon(RELATIVE("plugins/compare/ne.png"));

Node_Item* GT_Node_Item::make(std::istream*){return new GT_Node_Item;}
Node_Item* LT_Node_Item::make(std::istream*){return new LT_Node_Item;}
Node_Item* EQ_Node_Item::make(std::istream*){return new EQ_Node_Item;}
Node_Item* NE_Node_Item::make(std::istream*){return new NE_Node_Item;}
