#include <../plugins/plugin.h>
#include <gui/main_window.h>
#include <gui/toolbox/toolbox.h>
#include <gui/toolbox/toolbox_node_item.h>
#include <gui/toolbox/toolbox_category.h>
#include <FL/Fl_Menu_Bar.H>
#include "color_node_item.h"
#include "rgb_node_items.h"
#include "rgb_nodes.h"
#include "hsv_node_items.h"
#include "hsv_nodes.h"
#include <resources.h>
#include <core/type_manager.h>
#include <gui/workspace.h>

class Color_Plugin : public _Plugin{
public:
	void init()const override;
	void init_gui()const override;
};

CREATE_DESTROY_C(Color_Plugin)

void Color_Plugin::init()const{
	const int real_id= get_type_id("real");
	const int color_id= get_type_id("color");

	set_func("rgb",   &RGB_Node::rgb, {(unsigned)real_id, (unsigned)real_id, (unsigned)real_id});
	set_func("red",   &Red_Node::red, {(unsigned)color_id});
	set_func("green", &Green_Node::green, {(unsigned)color_id});
	set_func("blue",  &Blue_Node::blue, {(unsigned)color_id});
	set_func("alpha", &Alpha_Node::alpha, {(unsigned)color_id});

	set_func("hsv", &HSV_Node::hsv, {(unsigned)real_id, (unsigned)real_id, (unsigned)real_id});
	set_func("hue", &Hue_Node::hue, {(unsigned)color_id});
	set_func("saturation", &Saturation_Node::saturation, {(unsigned)color_id});
	set_func("value", &Value_Node::value, {(unsigned)color_id});
}
void Color_Plugin::init_gui()const{
	menu_bar->add("Insert/Color/_Color", 0, &Workspace::insert, (void*)&Color_Node_Item::make);
	menu_bar->add("Insert/Color/RGB",    0, &Workspace::insert, (void*)&RGB_Node_Item::make);
	menu_bar->add("Insert/Color/Red",    0, &Workspace::insert, (void*)&Red_Node_Item::make);
	menu_bar->add("Insert/Color/Green",  0, &Workspace::insert, (void*)&Green_Node_Item::make);
	menu_bar->add("Insert/Color/Blue",   0, &Workspace::insert, (void*)&Blue_Node_Item::make);
	menu_bar->add("Insert/Color/_Alpha", 0, &Workspace::insert, (void*)&Alpha_Node_Item::make);
	menu_bar->add("Insert/Color/HSV",    0, &Workspace::insert, (void*)&HSV_Node_Item::make);
	menu_bar->add("Insert/Color/Hue",    0, &Workspace::insert, (void*)&Hue_Node_Item::make);
	menu_bar->add("Insert/Color/Saturation", 0, &Workspace::insert, (void*)&Saturation_Node_Item::make);
	menu_bar->add("Insert/Color/Value",  0, &Workspace::insert, (void*)&Value_Node_Item::make);

	auto cat = Toolbox::add_category("Color", nullptr);
	cat->add(new Toolbox_Node_Item("Color", RELATIVE("plugins/color/color.png"), &Color_Node_Item::make));
	cat->add(new Toolbox_Node_Item("RGB",  &RGB_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Red",  &Red_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Green",&Green_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Blue", &Blue_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Alpha",&Alpha_Node_Item::make));
	cat->add(new Toolbox_Node_Item("HSV",  &HSV_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Hue",  &Hue_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Saturation",  &Saturation_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Value",  &Value_Node_Item::make));
}
