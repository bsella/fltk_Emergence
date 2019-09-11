#pragma once
class Main_Window;

class _Plugin {
public:
	virtual ~_Plugin(){}
protected:
	virtual void init()const{}
	virtual void init_gui(Main_Window*)const{}

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
