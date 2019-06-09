#include "output_node_item.h"
#include "output_node.h"
#include "input_node.h"

Output_Node_Item::Output_Node_Item(int x, int y): Node_Item(x,y,50,50, new Output_Node){}

Node_Item* Output_Node_Item::make(int x, int y, void*){
	return new Output_Node_Item(x,y);
}
void Output_Node_Item::draw_body()const{
	fl_color(FL_GREEN);
	fl_rect(_x, _y, _w, _h);
	if(!core_node->valid) return;
	std::vector<Node*> program;
	core_node->prepare_program(program);
	for(int x=1; x<_w-1; x++){
		input_x= (float)x/_w;
		for(int y=1; y<_h-1; y++){
			input_y= (float)y/_h;
			for(unsigned i=0; i<program.size(); i++)
				program[i]->kernel();
			fl_color(core_node->cache->to_color());
			fl_point(x+_x,y+_y);
		}
	}
}
