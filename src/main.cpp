#include "gui/main_window.h"
#include "resources.h"
#include "core/plugin.h"
#include <dirent.h>
#include <vector>
#include <dirent.h>
#include <core/type_manager.h>

std::string relative_path;
int main(int, char **argv){
	relative_path= argv[0];
	relative_path= relative_path.substr(0,relative_path.find_last_of("/\\")) +'/';

	init_gui();

	DIR* plugin_dir;
	struct dirent *ent;
	std::vector<Plugin*> plugins;
    if((plugin_dir= opendir(RELATIVE("lib_t"))) != nullptr){
        while((ent= readdir(plugin_dir)) != nullptr)
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
    if((plugin_dir= opendir(RELATIVE("lib"))) != nullptr){
        while((ent= readdir(plugin_dir)) != nullptr)
			if(ent->d_name[0]!='.'){
				Plugin* p= new Plugin(std::string(RELATIVE("lib")) + '/' + std::string(ent->d_name));
				p->init();
				p->init_gui();
				plugins.push_back(p);
			}
		closedir(plugin_dir);
	}
	int ret= run_gui();
	for(auto p : plugins)
		delete p;
	return ret;
}
