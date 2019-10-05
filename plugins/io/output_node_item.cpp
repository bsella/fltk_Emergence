#include "output_node_item.h"
#include "output_node.h"
#include <FL/fl_draw.H>
#include <FL/Fl_Menu_Item.H>

Output_Node_Item::Output_Node_Item(int x, int y): Node_Item(x,y,50,50, new Output_Node){
	draw_buffer= new unsigned int[_w*_h];
}
Output_Node_Item::~Output_Node_Item(){
	delete[] draw_buffer;
}

Node_Item* Output_Node_Item::make(int x, int y, void*){
	return new Output_Node_Item(x,y);
}
void Output_Node_Item::draw_body()const{
	if(core_node->valid){
		if(!image_valid) ((Output_Node*)core_node)->render(_w,_h, draw_buffer);
		fl_draw_image((const unsigned char*)draw_buffer, _x, _y, _w, _h, 4);
	}
	fl_color(FL_GREEN);
	fl_rect(_x-1, _y-1, _w+2, _h+2);
	((Output_Node_Item*)this)->image_valid= core_node->valid;
}
void Output_Node_Item::scale(double){}

void Output_Node_Item::context_menu(std::vector<Fl_Menu_Item>& menu){
	menu.back().flags|= FL_MENU_DIVIDER;

	menu.push_back({"Export", 0, export_output, this, !core_node->valid, 0,0,0,0});

	Node_Item::context_menu(menu);
}
