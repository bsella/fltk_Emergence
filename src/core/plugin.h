#pragma once
#include <gui/main_window.h>

class Plugin {
public:
	virtual ~Plugin(){}
	virtual void init_core(void*)const=0;
	virtual void init_gui (Main_Window*)const=0;

	void (*destroy_function)(Plugin*);
	void* lib;
};

typedef Plugin* create_t();
typedef void destroy_t(Plugin*);

#define CREATE_DESTROY_C(subclass) extern "C"{\
	Plugin* create(){\
		return new subclass;\
	}\
	void destroy(Plugin* p){\
		delete p;\
	}\
}

#ifdef PLUGIN_CPP
#include <string>
#include <vector>

Plugin* load_plugin(const std::string& path);
void unload_plugin(Plugin* plugin);

std::vector<Plugin*> load_all_plugins(const std::string& dir_path);
void unload_all_plugins(std::vector<Plugin*> plugins);
#endif
