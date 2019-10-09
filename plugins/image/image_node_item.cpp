#include "image_node_item.h"
#include "image_node.h"
#include <FL/fl_draw.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <resources.h>

Image_Node_Item::Image_Node_Item(int x, int y, const char* ptr): Node_Item(x,y,70,70, new Image_Node(ptr)){
    if(static_cast<Image_Node*>(core_node)->image)
        image= static_cast<Image_Node*>(core_node)->image->copy(_w-2, _h-2);
}
Image_Node_Item::~Image_Node_Item(){
	delete image;
}

Node_Item* Image_Node_Item::make(int x, int y, void* ptr){
    return new Image_Node_Item(x,y, reinterpret_cast<const char*>(ptr));
}
void Image_Node_Item::draw_body()const{
	if(image)
		image->draw(_x+1, _y+1, _w-2, _h-2);
	fl_color(FL_BLACK);
	fl_rect(_x, _y, _w, _h);
}
void Image_Node_Item::scale(double s){
	Node_Item::scale(s);
    if(static_cast<Image_Node*>(core_node)->image){
		delete image;
        image= static_cast<Image_Node*>(core_node)->image->copy(_w-2, _h-2);
	}
}
static bool ok=false;
void Image_Node_Item::change_image(Fl_Widget*, void* ptr){
	Fl_Native_File_Chooser fnfc;
	fnfc.title("Pick an image");
	fnfc.type(Fl_Native_File_Chooser::BROWSE_FILE);
	fnfc.filter("Image\t*.bmp");
	fnfc.directory(".");
	int temp= fnfc.show();
	if(temp==1 || temp==-1){
		ok=false;
		return;
	}
    Image_Node_Item* ini= static_cast<Image_Node_Item*>(ptr);
	delete ini->image;
    static_cast<Image_Node*>(ini->core_node)->set_image(fnfc.filename());
    ini->image= static_cast<Image_Node*>(ini->core_node)->image->copy(ini->_w-2, ini->_h-2);
	ok= true;
}
bool Image_Node_Item::settle(){
	change_image(nullptr, this);
	return ok;
}
void Image_Node_Item::context_menu(std::vector<Fl_Menu_Item>& menu){
	menu.back().flags|= FL_MENU_DIVIDER;
	menu.push_back({"Change Image", 0, change_image, this, 0,0,0,0,0});
	Node_Item::context_menu(menu);
}
