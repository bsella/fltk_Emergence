#include "real_chooser.h"
#include <FL/Fl_Window.H>
#include <FL/Fl_Return_Button.H>
#include <real/real_t.h>
#include "real_node_item.h"
#include <FL/Fl_Value_Input.H>
#include <FL/Fl.H>

static void input_cb(Fl_Widget* w, void* ptr){
    (static_cast<Real_t*>(static_cast<Real_Node_Item*>(ptr)->cache()))->value= static_cast<Fl_Value_Input*>(w)->value();
	//((Real_Node_Item*)ptr)->draw();
}

static void ok_cb(Fl_Widget* w, void* ptr){
    *static_cast<bool*>(ptr)= true;
	w->window()->hide();
}
static void cancel_cb(Fl_Widget* w, void* ptr){
    *static_cast<bool*>(ptr)= false;
	if(w->window())
		w->window()->hide();
	else
		w->hide();
}

bool real_chooser(Real_Node_Item* node){
	Fl_Window window(230,110);
	bool ret;
	window.callback(cancel_cb,&ret);
	Fl_Value_Input input(10, 10, 210, 40);
	input.callback(input_cb, node);
	Fl_Return_Button ok_button(10, 60, 100, 40, "OK");
	ok_button.callback(ok_cb,&ret);
	Fl_Button cancel_button(120, 60, 100, 40, "Cancel");
	cancel_button.callback(cancel_cb,&ret);
	window.resizable(input);
	window.end();
	window.set_modal();
	window.hotspot(window);
	window.show();
	while (window.shown()) Fl::wait();
	return ret;
}
