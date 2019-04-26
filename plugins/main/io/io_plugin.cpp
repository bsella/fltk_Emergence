#include <core/plugin.h>
#include <FL/Fl_Menu_Bar.H>

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
}
