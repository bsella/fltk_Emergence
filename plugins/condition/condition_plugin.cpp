#include <../plugins/plugin.h>
#include <gui/main_window.h>
#include <FL/Fl_Menu_Bar.H>
#include "if_node.h"
#include <core/resources.h>

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

	toolbox_add_cb(&If_Node_Item::make, "Condition", RELATIVE("../plugins/condition/if.png"));
}
