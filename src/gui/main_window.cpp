#include "main_window.h"
#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Double_Window.H>
#include "gui/workspace.h"
#include "gui/toolbox/toolbox.h"
#include "core/resources.h"

const unsigned int Main_Window::menu_bar_height = 30;
Main_Window::Main_Window(int _w, int _h):Fl_Double_Window(_w, _h, "Emergence"){
	init_gui();
	end();
    resizable(*this);
}
Main_Window::~Main_Window(){
	delete toolbox;
	delete menu_bar;
    delete workspace;
}
int Main_Window::run(){
	return Fl::run();
}
void Main_Window::resize(int X, int Y, int W, int H){
	Fl_Double_Window::resize(X,Y,W,H);
	menu_bar->size(W,menu_bar_height);
	static const int toolbox_min_width = 100;
	static const int toolbox_max_width = 140;
	toolbox->resize(0,menu_bar_height, std::min(std::max(toolbox->w(),toolbox_min_width),toolbox_max_width), H-menu_bar_height);
	workspace->resize(toolbox->w(), menu_bar_height, W-toolbox->w(), H-menu_bar_height);
}
void Main_Window::init_gui(){
	toolbox = new Toolbox(0,menu_bar_height, w()/5, h()-menu_bar_height);
	Toolbox::add("clr1", "Color1", RELATIVE("../color.png"));
    Toolbox::add("clr2", "Color2", RELATIVE("../color.png"));
    Toolbox::add("clr3", "Color3", RELATIVE("../color.png"));

	menu_bar = new Fl_Menu_Bar(0,0,w(), menu_bar_height);
	menu_bar->add("File/New", "^n", nullptr);
	menu_bar->add("File/Open", "^o", nullptr);
	menu_bar->add("File/Save", "^s", nullptr);
	menu_bar->add("File/_Save as...", "^S", nullptr);
	menu_bar->add("File/Quit", "^q", quit, this);

	menu_bar->add("Edit/Undo", "^z", nullptr);
	menu_bar->add("Edit/_Redo", "^Z", nullptr);
	menu_bar->add("Edit/Cut", "^x", nullptr);
	menu_bar->add("Edit/Copy", "^c", nullptr);
	menu_bar->add("Edit/Paste", "^v", nullptr);
	menu_bar->add("Edit/_Delete", FL_Delete, nullptr);
	menu_bar->add("Edit/Select all", "^a", nullptr);

	workspace = new Workspace(w()/5, menu_bar_height, 4*w()/5, h()-menu_bar_height);
	
	add(menu_bar);
	add_resizable(*toolbox);
	add_resizable(*workspace);
}
void Main_Window::quit(Fl_Widget*, void* w){
	((Main_Window*)w)->hide();
}
