#include "gui/main_window.h"
int main(int argc, char **argv){
	MainWindow win(500, 550);
	win.show(argc,argv);
	return MainWindow::run();
}
