#include "output_node_item.h"
#include "output_node.h"
#include "input_node.h"

Output_Node_Item::Output_Node_Item(int x, int y): Node_Item(x,y,50,50, new Output_Node){
	image.reserve(_w*_h);
}

Node_Item* Output_Node_Item::make(int x, int y, void*){
	return new Output_Node_Item(x,y);
}
void Output_Node_Item::draw_body()const{
	if(core_node->valid)	
		fl_draw_image((unsigned char*)image.data()+1, _x, _y, _w, _h, 4);
	else{
		fl_color(FL_GREEN);
		fl_rect(_x, _y, _w, _h);
	}
}
void Output_Node_Item::connect(int i, Node_Item* n){
	Node_Item::connect(i, n);
	if(core_node->valid)
		update_image();
}
void Output_Node_Item::update_image(){
	image.resize(_w*_h);
	for(int x=0; x<_w; x++){
		input_x= (double)x/_w;
		for(int y=0; y<_h; y++){
			input_y= (double)y/_h;
			for(unsigned i=0; i<((Output_Node*)core_node)->program.size(); i++)
				((Output_Node*)core_node)->program[i]->kernel();
			image[x+_w*y]=core_node->cache->to_color();
		}
	}
}
void Output_Node_Item::scale(float s){
	Item::scale(s);
	if(core_node->valid){
		image.resize(_w*_h);
		update_image();
	}
}
