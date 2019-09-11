#include <../plugins/plugin.h>
#include <gui/main_window.h>
#include <gui/toolbox/toolbox.h>
#include <gui/toolbox/toolbox_node_item.h>
#include <gui/toolbox/toolbox_category.h>
#include <FL/Fl_Menu_Bar.H>
#include "input_node_item.h"
#include "output_node_item.h"
#include <resources.h>

class Io_Plugin : public _Plugin{
public:
	void init()const override;
	void init_gui(Main_Window*)const override;
};

CREATE_DESTROY_C(Io_Plugin)

void Io_Plugin::init()const{
	input_x= new Real_t;
	input_y= new Real_t;
	input_ratio= new Real_t;
}
void Io_Plugin::init_gui(Main_Window* mw)const{
	mw->menu_bar->add("Insert/X");
	mw->menu_bar->add("Insert/Y");
	mw->menu_bar->add("Insert/Output");
	mw->menu_bar->add("Insert/Ratio");

	auto cat = new Toolbox_Category("I/O", nullptr);
	cat->add(new Toolbox_Node_Item("X",      RELATIVE("../plugins/io/x.png"),      &X_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Y",      RELATIVE("../plugins/io/y.png"),      &Y_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Ratio",                          nullptr,      &Ratio_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Output", RELATIVE("../plugins/io/output.png"), &Output_Node_Item::make));

	Toolbox::add(cat);
}
