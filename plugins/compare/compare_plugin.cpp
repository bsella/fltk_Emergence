#include <../plugins/plugin.h>
#include <gui/main_window.h>
#include <gui/toolbox/toolbox.h>
#include <gui/toolbox/toolbox_node_item.h>
#include <gui/toolbox/toolbox_category.h>
#include <FL/Fl_Menu_Bar.H>
#include "if_node_item.h"
#include "compare_node_items.h"
#include <resources.h>
#include <core/type_manager.h>
#include <gui/workspace.h>
#include <gui/binary_save.h>

class Compare_Plugin : public _Plugin{
public:
	void init()const override;
	void init_gui()const override;
};

CREATE_DESTROY_C(Compare_Plugin)

void Compare_Plugin::init()const{
	int real_id= get_type_id("real");
	int color_id= get_type_id("color");

	set_func("gt", &GT_Node::real_real, {(unsigned)real_id, (unsigned)real_id});
	set_func("lt", &LT_Node::real_real, {(unsigned)real_id, (unsigned)real_id});
	set_func("eq", &EQ_Node::real_real, {(unsigned)real_id, (unsigned)real_id});
	set_func("ne", &NE_Node::real_real, {(unsigned)real_id, (unsigned)real_id});

	set_func("gt", &GT_Node::real_color, {(unsigned)real_id, (unsigned)color_id});
	set_func("lt", &LT_Node::real_color, {(unsigned)real_id, (unsigned)color_id});
	set_func("eq", &EQ_Node::real_color, {(unsigned)real_id, (unsigned)color_id});
	set_func("ne", &NE_Node::real_color, {(unsigned)real_id, (unsigned)color_id});

	set_func("gt", &GT_Node::color_real, {(unsigned)color_id, (unsigned)real_id});
	set_func("lt", &LT_Node::color_real, {(unsigned)color_id, (unsigned)real_id});
	set_func("eq", &EQ_Node::color_real, {(unsigned)color_id, (unsigned)real_id});
	set_func("ne", &NE_Node::color_real, {(unsigned)color_id, (unsigned)real_id});

	set_func("gt", &GT_Node::color_color, {(unsigned)color_id, (unsigned)color_id});
	set_func("lt", &LT_Node::color_color, {(unsigned)color_id, (unsigned)color_id});
	set_func("eq", &EQ_Node::color_color, {(unsigned)color_id, (unsigned)color_id});
	set_func("ne", &NE_Node::color_color, {(unsigned)color_id, (unsigned)color_id});
}
void Compare_Plugin::init_gui()const{
	map_id_to_node_item("gt", &GT_Node_Item::make);
	map_id_to_node_item("lt", &LT_Node_Item::make);
	map_id_to_node_item("eq", &EQ_Node_Item::make);
	map_id_to_node_item("ne", &NE_Node_Item::make);
	map_id_to_node_item("if", &If_Node_Item::make);

	menu_bar->add("Insert/Compare/Greater Than", 0, &Workspace::insert, (void*)&GT_Node_Item::make);
	menu_bar->add("Insert/Compare/Less Than",    0, &Workspace::insert, (void*)&LT_Node_Item::make);
	menu_bar->add("Insert/Compare/Equal",        0, &Workspace::insert, (void*)&EQ_Node_Item::make);
	menu_bar->add("Insert/Compare/_Not Equal",   0, &Workspace::insert, (void*)&NE_Node_Item::make);
	menu_bar->add("Insert/Compare/Condition",    0, &Workspace::insert, (void*)&If_Node_Item::make);

	auto cat = new Toolbox_Category("Compare", nullptr);
	cat->add(new Toolbox_Node_Item("Greater Than", &GT_Node_Item::icon, &GT_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Less Than",    &LT_Node_Item::icon, &LT_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Equal",        &EQ_Node_Item::icon, &EQ_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Not Equal",    &NE_Node_Item::icon, &NE_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Condition",    RELATIVE("plugins/compare/if.png"), &If_Node_Item::make));
	Toolbox::add(cat);
}
