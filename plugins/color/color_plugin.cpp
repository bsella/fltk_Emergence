#include <../plugins/plugin.h>
#include <gui/main_window.h>
#include <gui/toolbox/toolbox.h>
#include <gui/toolbox/toolbox_node_item.h>
#include <gui/toolbox/toolbox_category.h>
#include <FL/Fl_Menu_Bar.H>
#include "color_node_item.h"
#include "rgb_node_item.h"
#include "rgb_node.h"
#include <resources.h>
#include <core/type_manager.h>

class Color_Plugin : public _Plugin{
public:
	void init()const override;
	void init_gui(Main_Window*)const override;
};

CREATE_DESTROY_C(Color_Plugin)

void Color_Plugin::init()const{
	const int real_id= get_type_id("real");
	set_func("rgb", &rgb_to_color_t, {(unsigned)real_id, (unsigned)real_id, (unsigned)real_id});
}
#include <iostream>
void Color_Plugin::init_gui(Main_Window* mw)const{
	mw->menu_bar->add("Insert/Color");

	auto cat = new Toolbox_Category("Color", nullptr);
	cat->add(new Toolbox_Node_Item("Color", RELATIVE("../plugins/color/color.png"), &Color_Node_Item::make));
    std::cout << RELATIVE("../plugins/color/color.png") << std::endl;
	cat->add(new Toolbox_Node_Item("RGB",  &RGB_Node_Item::make));

	Toolbox::add(cat);
}

