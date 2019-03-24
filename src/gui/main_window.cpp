#include "main_window.h"
#include <FL/Fl.H>
#include <FL/Fl_Plugin.H>
const unsigned int MainWindow::menu_bar_height = 30;
MainWindow::MainWindow(int _w, int _h):Fl_Double_Window(_w, _h, "Emergence"){
    Fl_Plugin_Manager pm("nodes");
	init_gui();
	end();
    resizable(*this);
}
MainWindow::~MainWindow(){
	delete node_box;
	delete menu_bar;
    delete workspace;
}
int MainWindow::run(){
	return Fl::run();
}
void MainWindow::resize(int X, int Y, int W, int H){
	Fl_Window::resize(X,Y,W,H);
	menu_bar->size(W,menu_bar_height);
	static const int node_box_min_width = 100;
	static const int node_box_max_width = 140;
	node_box->resize(0,menu_bar_height, std::min(std::max(node_box->w(),node_box_min_width),node_box_max_width), H-menu_bar_height);
	workspace->resize(node_box->w(), menu_bar_height, W-node_box->w(), H-menu_bar_height);
}
void MainWindow::init_gui(){
	node_box = new NodeBox(0,menu_bar_height, w()/5, h()-menu_bar_height);
    node_box->addTool("clr1", "Color1", "./../color.png");
    node_box->addTool("clr2", "Color2", "../color.png");
    node_box->addTool("clr3", "Color3", "../color.png");

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
	menu_bar->add("Edit/_Delete", "127", nullptr);
	menu_bar->add("Edit/Select all", "^a", nullptr);

	workspace = new Workspace(w()/5, menu_bar_height, 4*w()/5, h()-menu_bar_height);
}
void MainWindow::quit(Fl_Widget*, void* w){
	((MainWindow*)w)->hide();
}
