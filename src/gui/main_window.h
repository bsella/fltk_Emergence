#pragma once
class Fl_Double_Window;
class Toolbox;
class Workspace;
class Fl_Menu_Bar;
class Fl_Widget;

extern Fl_Double_Window* main_window;
extern Toolbox* toolbox;
extern Workspace* workspace;
extern Fl_Menu_Bar* menu_bar;

void init_gui();
int run_gui();
void quit(Fl_Widget*,void*);
