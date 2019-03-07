#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include "node_box.h"
#include "workspace.h"
class MainWindow : public Fl_Double_Window{
public:
	MainWindow(int,int);
	~MainWindow();
	static int run();
private:
	NodeBox* node_box=nullptr;
	Fl_Menu_Bar* menu_bar=nullptr;
	Workspace* workspace=nullptr;
	static const unsigned int menu_bar_height;
	void resize(int, int, int, int)override;
	void init_gui();
	static void quit(Fl_Widget*,void*);
};
#endif//MAIN_WINDOW_H
