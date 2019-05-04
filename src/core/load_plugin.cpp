#include "plugin.h"
#include "load_plugin.h"
#include <iostream>
#include <dlfcn.h>
#include <dirent.h>

Plugin* load_plugin(const std::string& path){
	void* lib = dlopen(path.c_str(), RTLD_LAZY);
	if(!lib){
		std::cerr << "Error openning library: " << dlerror() << std::endl;
		return nullptr;
	}
	dlerror();

	create_t* create_plugin = (create_t*) dlsym(lib, "create");
	const char* dlsym_error = dlerror();
	if(dlsym_error){
		std::cerr << "Error loading symbol create: " << dlsym_error << std::endl;
		return nullptr;
	}
	destroy_t* destroy_plugin = (destroy_t*) dlsym(lib,"destroy");
	dlsym_error= dlerror();
	if(dlsym_error){
		std::cerr << "Error loading symbol destroy: " << dlsym_error << std::endl;
		return nullptr;
	}
	Plugin* ret = create_plugin();
	ret->destroy_function = destroy_plugin;
	ret->lib= lib;
	return ret;
}
void unload_plugin(Plugin* plugin){
	void* lib= plugin->lib;
	if(plugin->destroy_function)
		plugin->destroy_function(plugin);
	dlclose(lib);
}
std::vector<Plugin*> load_all_plugins(const std::string& dir_path){
	std::vector<Plugin*> ret;
	DIR* dir;
	struct dirent *ent;
	if((dir= opendir(dir_path.c_str())) != NULL){
		while((ent= readdir(dir)) != NULL)
			if(ent->d_name[0]!='.'){
				Plugin* plugin= load_plugin(dir_path + '/' + std::string(ent->d_name));
				if(plugin)
					ret.push_back(plugin);
			}
	}
	return ret;
}
void unload_all_plugins(std::vector<Plugin*> plugins){
	for(auto p : plugins)
		unload_plugin(p);
}
