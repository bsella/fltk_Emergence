#include "output_node_item.h"
#include "output_node.h"
#include "input_node.h"
#include <FL/fl_draw.H>

Output_Node_Item::Output_Node_Item(int x, int y): Node_Item(x,y,50,50, new Output_Node){
	draw_buffer.reserve(_w*_h);
}

Node_Item* Output_Node_Item::make(int x, int y, void*){
	return new Output_Node_Item(x,y);
}
void Output_Node_Item::draw_body()const{
	if(core_node->valid){
		if(!image_valid) ((Output_Node_Item*)this)->update_image();
		fl_draw_image((const unsigned char*)draw_buffer.data(), _x, _y, _w, _h, 4);
	}
	else{
		((Output_Node_Item*)this)->image_valid=false;
		fl_color(FL_GREEN);
		fl_rect(_x, _y, _w, _h);
	}
}
void Output_Node_Item::update_image(){
	draw_buffer.resize(_w*_h);
	*input_ratio= (double)_w/_h;
	for(int x=0; x<_w; x++){
		*input_x= (double)x/_w;
		for(int y=0; y<_h; y++){
			*input_y= (double)y/_h;
			for(unsigned i=0; i<((Output_Node*)core_node)->program.size(); i++)
				((Output_Node*)core_node)->program[i]->execute();
			draw_buffer[x+_w*y]=((Output_Node*)core_node)->first->cache->to_color();
		}
	}
}
void Output_Node_Item::scale(float s){
	Item::scale(s);
	if(core_node->valid){
		draw_buffer.resize(_w*_h);
		update_image();
	}
}
