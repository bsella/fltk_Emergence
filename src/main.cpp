#include "gui/main_window.h"
int main(int argc, char **argv){
	Main_Window win(500, 550);
	win.show(argc,argv);
	return Main_Window::run();
}
