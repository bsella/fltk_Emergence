#include <../plugins/plugin.h>
#include <gui/main_window.h>
#include <gui/toolbox/toolbox.h>
#include <gui/toolbox/toolbox_node_item.h>
#include <gui/toolbox/toolbox_category.h>
#include <FL/Fl_Menu_Bar.H>
#include "logic_node_items.h"
#include <resources.h>
#include <core/type_manager.h>
#include <gui/workspace.h>

class Logic_Plugin : public _Plugin{
public:
	void init()const override;
	void init_gui()const override;
};

CREATE_DESTROY_C(Logic_Plugin)

void Logic_Plugin::init()const{
	int bool_id= get_type_id("bool");
	set_func("and", &AND_Node::func, {(unsigned)bool_id, (unsigned)bool_id});
	set_func("or",  &OR_Node::func , {(unsigned)bool_id, (unsigned)bool_id});
	set_func("xor", &XOR_Node::func, {(unsigned)bool_id, (unsigned)bool_id});
	set_func("not", &NOT_Node::func, {(unsigned)bool_id});
}
void Logic_Plugin::init_gui()const{
	menu_bar->add("Insert/Logic/AND", 0, &Workspace::insert, (void*)&AND_Node_Item::make);
	menu_bar->add("Insert/Logic/OR",  0, &Workspace::insert, (void*)&OR_Node_Item::make);
	menu_bar->add("Insert/Logic/XOR", 0, &Workspace::insert, (void*)&XOR_Node_Item::make);
	menu_bar->add("Insert/Logic/NOT", 0, &Workspace::insert, (void*)&NOT_Node_Item::make);

	auto cat = new Toolbox_Category("Logic", nullptr);
	cat->add(new Toolbox_Node_Item("And", &AND_Node_Item::icon, &AND_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Or",  &OR_Node_Item::icon,  &OR_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Xor", &XOR_Node_Item::icon, &XOR_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Not", &NOT_Node_Item::icon, &NOT_Node_Item::make));
	Toolbox::add(cat);
}
