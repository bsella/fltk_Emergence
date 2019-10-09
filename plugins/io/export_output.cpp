#include "output_node.h"
#include "output_node_item.h"
#include <FL/Fl_Window.H>
#include <FL/Fl.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_RGB_Image.H>
#include <resources.h>
extern "C"{
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
}
#include <string>

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
void Output_Node_Item::export_output(Fl_Widget*, void* ptr){
	Fl_Native_File_Chooser fnfc;
	fnfc.title("Choose output image path");
	fnfc.type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
	fnfc.filter("Image\t*.{bmp,jpg,jpeg,png}");
	fnfc.directory(".");
	fnfc.options(Fl_Native_File_Chooser::Option::SAVEAS_CONFIRM);
	int temp= fnfc.show();
	if(temp==1 || temp==-1) return;
	bool ok;
	Fl_Window window(230,120, "Output Size");
	window.callback(cancel_cb, &ok);
    Output_Node_Item* oni= static_cast<Output_Node_Item*>(ptr);
	Fl_Box image_label(10,10, oni->_w, oni->_h);
	image_label.image(oni->output_image);
	Fl_Box width_label(70, 10, 40, 20, "Width:");
	Fl_Box height_label(70, 40, 40, 20, "Height:");
	Fl_Value_Input input_w(120, 10, 100, 20);
	input_w.type(FL_INT_INPUT);
	input_w.minimum(0);
	input_w.step(1);
	Fl_Value_Input input_h(120, 40, 100, 20);
	input_h.type(FL_INT_INPUT);
	input_h.minimum(0);
	input_w.step(1);
	Fl_Return_Button ok_button(10, 70, 100, 40, "OK");
	ok_button.callback(ok_cb,&ok);
	Fl_Button cancel_button(120, 70, 100, 40, "Cancel");
	cancel_button.callback(cancel_cb,&ok);
	window.end();
	window.set_modal();
	window.show();
	while (window.shown()) Fl::wait();
	if(ok && input_h.value()>0 && input_w.value()>0){
		std::vector<unsigned int> draw_buffer(input_h.value()*input_w.value());
        static_cast<Output_Node*>(oni->core_node)->render(input_w.value(), input_h.value(), draw_buffer.data());
		std::string filename(fnfc.filename());
		std::string extension= filename.substr(filename.find_last_of('.')+1, filename.size());
		if(extension=="bmp")
			stbi_write_bmp(fnfc.filename(), input_w.value(), input_h.value(), 4, draw_buffer.data());
		else if(extension=="jpg" || extension=="jpeg")
			stbi_write_jpg(fnfc.filename(), input_w.value(), input_h.value(), 4, draw_buffer.data(), 100);
		else if(extension=="png")
			stbi_write_png(fnfc.filename(), input_w.value(), input_h.value(), 4, draw_buffer.data(), input_w.value()*4);
	}
}
