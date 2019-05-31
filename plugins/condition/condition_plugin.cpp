#include <../plugins/plugin.h>
#include <gui/main_window.h>
#include <gui/toolbox/toolbox.h>
#include <FL/Fl_Menu_Bar.H>
#include "if_node_item.h"
#include <resources.h>

class Condition_Plugin : public _Plugin{
public:
	void init_core(void*)const;
	void init_gui (Main_Window*)const;
};

CREATE_DESTROY_C(Condition_Plugin)

void Condition_Plugin::init_core(void*)const{
}
void Condition_Plugin::init_gui (Main_Window* mw)const{
	mw->menu_bar->add("Insert/Condition");

	Toolbox::add(&If_Node_Item::make, "Condition", RELATIVE("../plugins/condition/if.png"));
}
