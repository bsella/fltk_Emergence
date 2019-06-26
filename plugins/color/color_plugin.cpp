#include <../plugins/plugin.h>
#include <gui/main_window.h>
#include <gui/toolbox/toolbox.h>
#include <gui/toolbox/toolbox_node_item.h>
#include <gui/toolbox/toolbox_category.h>
#include <FL/Fl_Menu_Bar.H>
#include "color_node_item.h"
#include <resources.h>

class Color_Plugin : public _Plugin{
public:
	void init_core(void*)const;
	void init_gui (Main_Window*)const;
};

CREATE_DESTROY_C(Color_Plugin)

void Color_Plugin::init_core(void*)const{
}
void Color_Plugin::init_gui(Main_Window* mw)const{
	mw->menu_bar->add("Insert/Color");

	auto cat = new Toolbox_Category("Color", nullptr);
	cat->add(new Toolbox_Node_Item("Color", RELATIVE("../plugins/color/color.png"), &Color_Node_Item::make));

	Toolbox::add(cat);
}

