#include "gui/main_window.h"
#include "core/resources.h"
std::string relative_path;
int main(int argc, char **argv){
	relative_path= argv[0];
	relative_path= relative_path.substr(0,relative_path.find_last_of("/\\")) +'/';
	Main_Window win(500, 550);
	win.show(argc,argv);
	return Main_Window::run();
}
