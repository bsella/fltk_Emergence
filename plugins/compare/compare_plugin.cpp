#include <../plugins/plugin.h>
#include <gui/main_window.h>
#include <gui/toolbox/toolbox.h>
#include <gui/toolbox/toolbox_node_item.h>
#include <gui/toolbox/toolbox_category.h>
#include <FL/Fl_Menu_Bar.H>
#include "if_node_item.h"
#include "compare_node_items.h"
#include <resources.h>

class Compare_Plugin : public _Plugin{
public:
	void init_core(void*)const;
	void init_gui (Main_Window*)const;
};

CREATE_DESTROY_C(Compare_Plugin)

void Compare_Plugin::init_core(void*)const{
}
void Compare_Plugin::init_gui (Main_Window* mw)const{
	mw->menu_bar->add("Insert/Compare");

	auto cat = new Toolbox_Category("Compare", nullptr);
	cat->add(new Toolbox_Node_Item("Greater Than", RELATIVE("../plugins/compare/gt.png"), &GT_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Less Than",    RELATIVE("../plugins/compare/lt.png"), &LT_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Equal",        RELATIVE("../plugins/compare/eq.png"), &EQ_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Not Equal",    RELATIVE("../plugins/compare/ne.png"), &NE_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Condition", RELATIVE("../plugins/compare/if.png"), &If_Node_Item::make));
	Toolbox::add(cat);
}
