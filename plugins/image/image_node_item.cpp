#include "image_node_item.h"
#include "image_node.h"
#include <FL/fl_draw.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_File_Chooser.H>
#include <resources.h>

Image_Node_Item::Image_Node_Item(int x, int y, const char* ptr): Node_Item(x,y,70,70, new Image_Node(ptr)){
	if(((Image_Node*)core_node)->image)
		image= ((Image_Node*)core_node)->image->copy(_w-2, _h-2);
}
Image_Node_Item::~Image_Node_Item(){
	delete image;
}

Node_Item* Image_Node_Item::make(int x, int y, void* ptr){
	return new Image_Node_Item(x,y, (const char*)ptr);
}
void Image_Node_Item::draw_body()const{
	fl_color(FL_BLACK);
	fl_rect(_x, _y, _w, _h);
	if(image)
		image->draw(_x+1, _y+1, _w-2, _h-2);
}
void Image_Node_Item::scale(float s){
	Item::scale(s);
	if(((Image_Node*)core_node)->image){
		delete image;
		image= ((Image_Node*)core_node)->image->copy(_w-2, _h-2);
	}
}
static void change_image(Fl_Widget*, void* ptr){
	char* file= fl_file_chooser("Choose an image","*.bmp", RELATIVE("."), 0);
	((Image_Node_Item*)ptr)->set_image(file);
}
bool Image_Node_Item::settle(){
	char* file= fl_file_chooser("Choose an image","*.bmp", RELATIVE("."), 0);
	set_image(file);
	return file;
}
void Image_Node_Item::set_image(const char* file){
	if(file){
		delete image;
		((Image_Node*)core_node)->set_image(file);
		image= ((Image_Node*)core_node)->image->copy(_w-2, _h-2);
	}
}
void Image_Node_Item::context_menu(std::vector<Fl_Menu_Item>& menu){
	menu.back().flags|= FL_MENU_DIVIDER;
	menu.push_back({"Change Image", 0, change_image, this, 0,0,0,0,0});
	Node_Item::context_menu(menu);
}
