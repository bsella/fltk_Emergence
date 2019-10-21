#include "main_window.h"
#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Double_Window.H>
#include "gui/workspace.h"
#include "gui/toolbox/toolbox.h"
#include "resources.h"

Fl_Double_Window* main_window;
Toolbox* toolbox;
Workspace* workspace;
Fl_Menu_Bar* menu_bar;

void init_gui(){
	main_window= new Fl_Double_Window(500,550, "Emergence");
	static const unsigned int menu_bar_height = 30;
	toolbox = new Toolbox(0,menu_bar_height, main_window->w()/4, main_window->h()-menu_bar_height);

	workspace = new Workspace(main_window->w()/4, menu_bar_height, 4*main_window->w()/5, main_window->h()-menu_bar_height);

	menu_bar = new Fl_Menu_Bar(0,0, main_window->w(), menu_bar_height);
	menu_bar->add("File/New", "^n", nullptr);
	menu_bar->add("File/Open", "^o", nullptr);
	menu_bar->add("File/Save", "^s", nullptr);
	menu_bar->add("File/_Save as...", "^S", nullptr);
	menu_bar->add("File/Quit", "^q", quit);

	menu_bar->add("Edit/Undo", "^z", nullptr);
	menu_bar->add("Edit/_Redo", "^Z", nullptr);
	menu_bar->add("Edit/Cut", "^x", nullptr);
	menu_bar->add("Edit/Copy", "^c", &Workspace::copy_selected, &workspace->selected);
	menu_bar->add("Edit/Paste", "^v", &Workspace::paste, workspace);
	menu_bar->add("Edit/_Delete", FL_Delete, &Workspace::remove_selected, workspace);
	menu_bar->add("Edit/Select all", "^a", &Workspace::select_all, workspace);

	main_window->end();
	main_window->resizable(workspace);
}

int run_gui(){
	main_window->show();
	return Fl::run();
}

void quit(Fl_Widget*, void*){
	main_window->hide();
}
