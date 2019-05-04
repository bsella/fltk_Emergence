#include <core/plugin.h>
#include <gui/main_window.h>
#include <FL/Fl_Menu_Bar.H>
#include "input_node.h"
#include "gui/main_window.h"

class Io_Plugin : public Plugin{
public:
	void init_core(void*)const;
	void init_gui (Main_Window*)const;
};

CREATE_DESTROY_C(Io_Plugin)

void Io_Plugin::init_core(void*)const{
}
void Io_Plugin::init_gui (Main_Window* mw)const{
	mw->menu_bar->add("Insert/X");
	mw->menu_bar->add("Insert/Y");
	mw->menu_bar->add("Insert/Output");

	toolbox_add_cb("x", "X", "../color.png");
	toolbox_add_cb("y", "Y", "../color.png");
	toolbox_add_cb("output", "Output", "../color.png");
}
