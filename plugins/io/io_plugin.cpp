#include <../plugins/plugin.h>
#include <gui/main_window.h>
#include <gui/toolbox/toolbox.h>
#include <gui/toolbox/toolbox_node_item.h>
#include <gui/toolbox/toolbox_category.h>
#include <FL/Fl_Menu_Bar.H>
#include "input_node_item.h"
#include "output_node_item.h"
#include <resources.h>
#include <gui/workspace.h>
#include <gui/binary_save.h>

class Io_Plugin : public _Plugin{
public:
	void init()const override;
	void init_gui()const override;
};

CREATE_DESTROY_C(Io_Plugin)

void Io_Plugin::init()const{
	input_x= new Real_t;
	input_y= new Real_t;
	input_ratio= new Real_t;
}
void Io_Plugin::init_gui()const{
	map_id_to_node_item("x",      &X_Node_Item::make);
	map_id_to_node_item("y",      &Y_Node_Item::make);
	map_id_to_node_item("ratio",  &Ratio_Node_Item::make);
	map_id_to_node_item("output", &Output_Node_Item::make);

	menu_bar->add("Insert/IO/X", 0, &Workspace::insert, (void*)&X_Node_Item::make);
	menu_bar->add("Insert/IO/Y", 0, &Workspace::insert, (void*)&Y_Node_Item::make);
	menu_bar->add("Insert/IO/Ratio", 0, &Workspace::insert, (void*)&Ratio_Node_Item::make);
	menu_bar->add("Insert/IO/Output", 0, &Workspace::insert, (void*)&Output_Node_Item::make);

	auto cat = new Toolbox_Category("I/O", nullptr);
	cat->add(new Toolbox_Node_Item("X",      &X_Node_Item::icon,      &X_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Y",      &Y_Node_Item::icon,      &Y_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Ratio",                                     &Ratio_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Output", RELATIVE("plugins/io/output.png"), &Output_Node_Item::make));

	Toolbox::add(cat);
}
