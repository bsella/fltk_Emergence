#include <../plugins/plugin.h>
#include <gui/main_window.h>
#include <gui/toolbox/toolbox.h>
#include <gui/toolbox/toolbox_node_item.h>
#include <gui/toolbox/toolbox_category.h>
#include <FL/Fl_Menu_Bar.H>
#include "gradient_node.h"
#include "gradient_node_item.h"
#include <resources.h>
#include <core/type_manager.h>
#include <gui/workspace.h>
#include <gui/binary_save.h>

class Gradient_Plugin : public _Plugin{
public:
	void init()const override;
	void init_gui()const override;
};

CREATE_DESTROY_C(Gradient_Plugin)

void Gradient_Plugin::init()const{
	int real_id= get_type_id("real");
	set_func("grad", &Gradient_Node::get_color, {(unsigned)real_id});
}
void Gradient_Plugin::init_gui()const{
	map_id_to_node_item("gradient", &Gradient_Node_Item::make);

	menu_bar->add("Insert/Color/Gradient", 0, &Workspace::insert, (void*)&Gradient_Node_Item::make);

	auto cat = Toolbox::add_category("Color");
	cat->add(new Toolbox_Node_Item("Gradient", &Gradient_Node_Item::make));
}
