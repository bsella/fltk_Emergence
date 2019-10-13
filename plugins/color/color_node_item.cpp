#include "color_node_item.h"
#include "color_node.h"
#include <color/color_t.h>
#include <FL/fl_draw.H>
#include <FL/Fl_Color_Chooser.H>

Color_Node_Item::Color_Node_Item(std::istream* ptr): Node_Item(16, 16, new Color_Node(ptr)){}

unsigned int Color_Node_Item::color()const{
	if(core_node->cache){
        const unsigned char temp_r = static_cast<Color_t*>(core_node->cache)->r*255;
        const unsigned char temp_g = static_cast<Color_t*>(core_node->cache)->g*255;
        const unsigned char temp_b = static_cast<Color_t*>(core_node->cache)->b*255;
		return ((((temp_r<<8) | temp_g) << 8) | temp_b) << 8;
	}
	return 0;
}
void Color_Node_Item::draw_body()const{
	fl_color(color());
	fl_pie(_x,_y, _w,_h, 0,360);
	fl_color(FL_BLACK);
	fl_circle(_x+_w/2,_y+_h/2, _w/2);
}

Node_Item* Color_Node_Item::make(std::istream* ptr){
	return new Color_Node_Item(ptr);
}

bool Color_Node_Item::settle(){
	double r,g,b;
	int ret= fl_color_chooser("Choose a color", r,g,b);
	if(ret){
		static_cast<Color_t*>(core_node->cache)->r= r;
		static_cast<Color_t*>(core_node->cache)->g= g;
		static_cast<Color_t*>(core_node->cache)->b= b;
		static_cast<Color_t*>(core_node->cache)->a= 1;
	}
	return ret;
}

static void color_edit_value(Fl_Widget*, void* ptr){
    Color_Node_Item* node= static_cast<Color_Node_Item*>(ptr);
	double r,g,b;
	if(fl_color_chooser("Choose a color", r,g,b)){
		static_cast<Color_t*>(node->cache())->r= r;
		static_cast<Color_t*>(node->cache())->g= g;
		static_cast<Color_t*>(node->cache())->b= b;
	}
}
void Color_Node_Item::context_menu(std::vector<Fl_Menu_Item>& menu){
	menu.back().flags|= FL_MENU_DIVIDER;

	menu.push_back({"Edit Color", 0, color_edit_value, this, 0,0,0,0,0});

	Node_Item::context_menu(menu);
}
