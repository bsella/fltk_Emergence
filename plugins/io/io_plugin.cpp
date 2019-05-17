#include <../plugins/plugin.h>
#include <gui/main_window.h>
#include <gui/toolbox/toolbox.h>
#include <FL/Fl_Menu_Bar.H>
#include "input_node_item.h"
#include <core/resources.h>

class Io_Plugin : public _Plugin{
public:
	void init_core(void*)const;
	void init_gui (Main_Window*)const;
};

CREATE_DESTROY_C(Io_Plugin)

void Io_Plugin::init_core(void*)const{
}
void Io_Plugin::init_gui(Main_Window* mw)const{
	mw->menu_bar->add("Insert/X");
	mw->menu_bar->add("Insert/Y");
	mw->menu_bar->add("Insert/Ratio");

	Toolbox::add(&X_Node_Item::make, "X", RELATIVE("../plugins/io/x.png"));
	Toolbox::add(&Y_Node_Item::make, "Y", RELATIVE("../plugins/io/y.png"));
	Toolbox::add(&Ratio_Node_Item::make, "Ratio", nullptr);
}
