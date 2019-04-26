#include "main_window.h"
#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Double_Window.H>
#include "gui/workspace.h"
#include "gui/node_box.h"
#include "core/resources.h"

const unsigned int Main_Window::menu_bar_height = 30;
Main_Window::Main_Window(int _w, int _h):Fl_Double_Window(_w, _h, "Emergence"){
	init_gui();
	end();
    resizable(*this);
}
Main_Window::~Main_Window(){
	delete node_box;
	delete menu_bar;
    delete workspace;
}
int Main_Window::run(){
	return Fl::run();
}
void Main_Window::resize(int X, int Y, int W, int H){
	Fl_Window::resize(X,Y,W,H);
	menu_bar->size(W,menu_bar_height);
	static const int node_box_min_width = 100;
	static const int node_box_max_width = 140;
	node_box->resize(0,menu_bar_height, std::min(std::max(node_box->w(),node_box_min_width),node_box_max_width), H-menu_bar_height);
	workspace->resize(node_box->w(), menu_bar_height, W-node_box->w(), H-menu_bar_height);
}
void Main_Window::init_gui(){

	node_box = new Node_Box(0,menu_bar_height, w()/5, h()-menu_bar_height);
    node_box->addTool("clr1", "Color1", RELATIVE("../color.png"));
    node_box->addTool("clr2", "Color2", RELATIVE("../color.png"));
    node_box->addTool("clr3", "Color3", RELATIVE("../color.png"));

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
}
void Main_Window::quit(Fl_Widget*, void* w){
	((Main_Window*)w)->hide();
}
