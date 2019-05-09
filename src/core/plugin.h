#pragma once
#include <../plugins/plugin.h>
class Main_Window;

class Plugin {
public:
	Plugin(const std::string&);
	~Plugin();
	void init_gui(Main_Window*);

private:
	void (*destroy_function)(_Plugin*);
	void* lib;

	_Plugin* plugin= nullptr;
};

#include <iostream>
#include <dlfcn.h>
#include <gui/toolbox/toolbox.h>
#include <core/resources.h>

typedef _Plugin* create_t();
typedef void destroy_t(_Plugin*);

Plugin::Plugin(const std::string& path){
	lib = dlopen(path.c_str(), RTLD_LAZY);
	if(!lib){
		std::cerr << "Error openning library: " << dlerror() << std::endl;
		return;
	}
	dlerror();

	create_t* create_plugin = (create_t*) dlsym(lib, "create");
	const char* dlsym_error = dlerror();
	if(dlsym_error){
		std::cerr << "Error loading symbol create: " << dlsym_error << std::endl;
		return;
	}
	destroy_function = (destroy_t*) dlsym(lib,"destroy");
	dlsym_error= dlerror();
	if(dlsym_error){
		std::cerr << "Error loading symbol destroy: " << dlsym_error << std::endl;
		return;
	}
	plugin = create_plugin();
	plugin->toolbox_add_cb= &Toolbox::add;
	plugin->relative_path= &relative_path;
}
Plugin::~Plugin(){
	destroy_function(plugin);
	dlclose(lib);
}
void Plugin::init_gui(Main_Window* mw){
	plugin->init_gui(mw);
}
