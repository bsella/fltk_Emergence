#include "gui/main_window.h"
#include "core/resources.h"
#define PLUGIN_CPP
#include "core/plugin.h"

std::string relative_path;
int main(int argc, char **argv){
	relative_path= argv[0];
	relative_path= relative_path.substr(0,relative_path.find_last_of("/\\")) +'/';
	Main_Window win(500, 550);
	win.show(argc,argv);
	std::vector<Plugin*> plugins = load_all_plugins(RELATIVE("lib/main"));
	for(auto p : plugins){
		p->init_gui(&win);
	}
	unload_all_plugins(plugins);
	return Main_Window::run();
}
