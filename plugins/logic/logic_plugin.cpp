#include <../plugins/plugin.h>
#include <gui/main_window.h>
#include <gui/toolbox/toolbox.h>
#include <gui/toolbox/toolbox_node_item.h>
#include <gui/toolbox/toolbox_category.h>
#include <FL/Fl_Menu_Bar.H>
#include "logic_node_items.h"
#include <resources.h>
#include <core/type_manager.h>

class Compare_Plugin : public _Plugin{
public:
	void init()const override;
	void init_gui(Main_Window*)const override;
};

CREATE_DESTROY_C(Compare_Plugin)

void Compare_Plugin::init()const{
	int bool_id= get_type_id("bool");
	set_func("and", &AND_Node::func, {(unsigned)bool_id, (unsigned)bool_id});
	set_func("or",  &OR_Node::func , {(unsigned)bool_id, (unsigned)bool_id});
	set_func("xor", &XOR_Node::func, {(unsigned)bool_id, (unsigned)bool_id});
	set_func("not", &NOT_Node::func, {(unsigned)bool_id});
}
void Compare_Plugin::init_gui(Main_Window* mw)const{
	mw->menu_bar->add("Insert/Compare");

	auto cat = new Toolbox_Category("Logic", nullptr);
	cat->add(new Toolbox_Node_Item("And", RELATIVE("plugins/logic/and.png"), &AND_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Or",  RELATIVE("plugins/logic/or.png"),  &OR_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Xor", RELATIVE("plugins/logic/xor.png"), &XOR_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Not", RELATIVE("plugins/logic/not.png"), &NOT_Node_Item::make));
	Toolbox::add(cat);
}
