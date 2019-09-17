#include <../plugins/plugin.h>
#include <gui/main_window.h>
#include <gui/toolbox/toolbox.h>
#include <gui/toolbox/toolbox_node_item.h>
#include <gui/toolbox/toolbox_category.h>
#include <FL/Fl_Menu_Bar.H>
#include <resources.h>
#include "math_node_items.h"
#include "real_node_item.h"
#include "func_def.h"
#include <core/type_manager.h>

class Math_Plugin : public _Plugin{
public:
	void init()const override;
	void init_gui(Main_Window*)const override;
};

CREATE_DESTROY_C(Math_Plugin)

void Math_Plugin::init()const{
	int real_id= get_type_id("real");
	set_func("add", &add_real, {(unsigned)real_id, (unsigned)real_id});
	set_func("sub", &sub_real, {(unsigned)real_id, (unsigned)real_id});
	set_func("mul", &mul_real, {(unsigned)real_id, (unsigned)real_id});
	set_func("div", &div_real, {(unsigned)real_id, (unsigned)real_id});
	set_func("neg", &neg_real, {(unsigned)real_id});
	set_func("sqrt", &sqrt_real, {(unsigned)real_id});
	set_func("abs", &abs_real, {(unsigned)real_id});
	set_func("sin", &sin_real, {(unsigned)real_id});
	set_func("cos", &cos_real, {(unsigned)real_id});
	set_func("min", &min_real, {(unsigned)real_id, (unsigned)real_id});
	set_func("max", &max_real, {(unsigned)real_id, (unsigned)real_id});
	set_func("pow", &pow_real, {(unsigned)real_id, (unsigned)real_id});
	set_func("log", &log_real, {(unsigned)real_id});
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

	Toolbox::add(cat);
}
