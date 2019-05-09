#include "gui/main_window.h"
#include "core/resources.h"
#include "core/plugin.h"
#include <dirent.h>
#include <vector>
#include <dirent.h>

std::string relative_path;
int main(int argc, char **argv){
	relative_path= argv[0];
	relative_path= relative_path.substr(0,relative_path.find_last_of("/\\")) +'/';
	Main_Window win(500, 550);
	win.show(argc,argv);

	DIR* plugin_dir;
	struct dirent *ent;
	std::vector<Plugin*> plugins;
	if((plugin_dir= opendir(RELATIVE("lib"))) != NULL){
		while((ent= readdir(plugin_dir)) != NULL)
			if(ent->d_name[0]!='.'){
				Plugin* p= new Plugin(std::string(RELATIVE("lib")) + '/' + std::string(ent->d_name));
				p->init_gui(&win);
				plugins.push_back(p);
			}
	}
	int ret = Main_Window::run();
	for(auto p : plugins)
		delete p;
	return ret;
}
