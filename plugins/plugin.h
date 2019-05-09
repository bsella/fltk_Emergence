#pragma once
class Main_Window;
class Node_Item;
#include <string>

class _Plugin {
public:
	virtual ~_Plugin(){}
protected:
	virtual void init_core(void*)const=0;
	virtual void init_gui (Main_Window*)const=0;

	void (*toolbox_add_cb)(Node_Item*(*)(int,int,void*), const char*, const char*);
	std::string* relative_path;
	friend class Plugin;
};

#define CREATE_DESTROY_C(subclass) extern "C"{\
	_Plugin* create(){\
		return new subclass;\
	}\
	void destroy(_Plugin* p){\
		delete p;\
	}\
}
