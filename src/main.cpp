#include "gui/main_window.h"
#include "resources.h"
#include "core/plugin.h"
#include <dirent.h>
#include <vector>
#include <dirent.h>
#include <core/type_manager.h>

std::string relative_path;
int main(int argc, char **argv){
	relative_path= argv[0];
	relative_path= relative_path.substr(0,relative_path.find_last_of("/\\")) +'/';
	Main_Window win(500, 550);
	win.show(argc,argv);

	DIR* plugin_dir;
	struct dirent *ent;
	std::vector<Plugin*> plugins;
	if((plugin_dir= opendir(RELATIVE("lib_t"))) != NULL){
		while((ent= readdir(plugin_dir)) != NULL)
			if(ent->d_name[0]!='.'){
				plugins.push_back(new Plugin(std::string(RELATIVE("lib_t")) + '/' + std::string(ent->d_name)));
				std::string type(ent->d_name);
				type= type.substr(3, type.find("_t")-3);
				add_type(type);
			}
		closedir(plugin_dir);
		for(Plugin* p: plugins)
			p->init();
	}
	if((plugin_dir= opendir(RELATIVE("lib"))) != NULL){
		while((ent= readdir(plugin_dir)) != NULL)
			if(ent->d_name[0]!='.'){
				Plugin* p= new Plugin(std::string(RELATIVE("lib")) + '/' + std::string(ent->d_name));
				p->init();
				p->init_gui(&win);
				plugins.push_back(p);
			}
		closedir(plugin_dir);
	}
	int ret = Main_Window::run();
	for(auto p : plugins)
		delete p;
	return ret;
}
