#include <../plugins/plugin.h>
#include <gui/main_window.h>
#include <gui/toolbox/toolbox.h>
#include <gui/toolbox/toolbox_node_item.h>
#include <gui/toolbox/toolbox_category.h>
#include <FL/Fl_Menu_Bar.H>
#include <resources.h>
#include "math_node_items.h"
#include "real_node_item.h"
#include "lerp_nodes.h"
#include "lerp_node_items.h"
#include <core/type_manager.h>

class Math_Plugin : public _Plugin{
public:
	void init()const override;
	void init_gui(Main_Window*)const override;
};

CREATE_DESTROY_C(Math_Plugin)

void Math_Plugin::init()const{
	int real_id= get_type_id("real");
	set_func("add", &Add_Node::real_real, {(unsigned)real_id, (unsigned)real_id});
	set_func("sub", &Sub_Node::real_real, {(unsigned)real_id, (unsigned)real_id});
	set_func("mul", &Mul_Node::real_real, {(unsigned)real_id, (unsigned)real_id});
	set_func("div", &Div_Node::real_real, {(unsigned)real_id, (unsigned)real_id});
	set_func("neg", &Neg_Node::real,      {(unsigned)real_id});
	set_func("sqrt",&Sqrt_Node::real,     {(unsigned)real_id});
	set_func("abs", &Abs_Node::real,      {(unsigned)real_id});
	set_func("sin", &Sin_Node::real,      {(unsigned)real_id});
	set_func("cos", &Cos_Node::real,      {(unsigned)real_id});
	set_func("pow", &Pow_Node::real_real, {(unsigned)real_id, (unsigned)real_id});
	set_func("log", &Log_Node::real,      {(unsigned)real_id});
	set_func("lerp",&Lerp_Node::real,     {(unsigned)real_id, (unsigned)real_id, (unsigned)real_id});
	set_func("clamp",&Clamp_Node::real,   {(unsigned)real_id, (unsigned)real_id, (unsigned)real_id});

	int color_id= get_type_id("color");
	set_func("lerp",&Lerp_Node::color,     {(unsigned)color_id, (unsigned)real_id, (unsigned)color_id});
	set_func("clamp",&Clamp_Node::color,   {(unsigned)color_id, (unsigned)color_id, (unsigned)color_id});

	set_func("add", &Add_Node::color_color, {(unsigned)color_id, (unsigned)color_id});
	set_func("sub", &Sub_Node::color_color, {(unsigned)color_id, (unsigned)color_id});
	set_func("mul", &Mul_Node::real_color , {(unsigned)real_id,  (unsigned)color_id});
	set_func("mul", &Mul_Node::color_real , {(unsigned)color_id, (unsigned)real_id});
	set_func("div", &Div_Node::color_real,  {(unsigned)color_id, (unsigned)real_id});
}
void Math_Plugin::init_gui(Main_Window*)const{
	auto cat = new Toolbox_Category("Math", nullptr);
	cat->add(new Toolbox_Node_Item("Real",        RELATIVE("plugins/math/real.png"), &Real_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Add",         &Add_Node_Item::icon,      &Add_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Subtract",    &Sub_Node_Item::icon,      &Sub_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Multiply",    &Mul_Node_Item::icon,      &Mul_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Divide",      &Div_Node_Item::icon,      &Div_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Negative",    &Neg_Node_Item::icon,      &Neg_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Square Root", &Sqrt_Node_Item::icon,     &Sqrt_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Absolute",    &Abs_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Sin",         RELATIVE("plugins/math/sin.png"), &Sin_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Cos",         RELATIVE("plugins/math/cos.png"), &Cos_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Min",         &Min_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Max",         &Max_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Power",       &Pow_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Log",         &Log_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Linear Interpolation", &Lerp_Node_Item::make));
	cat->add(new Toolbox_Node_Item("Clamp",       &Clamp_Node_Item::make));

	Toolbox::add(cat);
}
