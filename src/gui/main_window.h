#pragma once
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>
class Node_Box;
class Workspace;

class Main_Window : public Fl_Double_Window{
public:
	Main_Window(int,int);
	~Main_Window();
	static int run();
private:
	Node_Box* node_box=nullptr;
	Fl_Menu_Bar* menu_bar=nullptr;
	Workspace* workspace=nullptr;
	static const unsigned int menu_bar_height;
	void resize(int, int, int, int)override;
	void init_gui();
	static void quit(Fl_Widget*,void*);
};
