#pragma once
#include <FL/Fl_Double_Window.H>
class Node_Box;
class Workspace;
class Fl_Menu_Bar;

class Main_Window : public Fl_Double_Window{
public:
	Main_Window(int,int);
	~Main_Window();
	static int run();
	Node_Box* node_box=nullptr;
	Fl_Menu_Bar* menu_bar=nullptr;
private:
	Workspace* workspace=nullptr;
	static const unsigned int menu_bar_height;
	void resize(int, int, int, int)override;
	void init_gui();
	static void quit(Fl_Widget*,void*);
};
