#include "output_node.h"
#include <core/data_t.h>
#include <core/type_manager.h>
#include "input_node.h"

Output_Node::Output_Node(): Node(1, false){}

void Output_Node::update_types(){
	main_func= get_func("to_color", {inodes[0]->cache->id});
}
void Output_Node::update_cache(){
	main_func(inodes.data(), current_pixel);
}
void Output_Node::update_valid(){
	Node::update_valid();
	if(valid){
		program.clear();
		compile(program);
	}
}
void Output_Node::render(int w, int h, unsigned int* draw_buffer){
	*input_ratio= (double)w/h;
	for(int x=0; x<w; x++){
		*input_x= (double)x/w;
		for(int y=0; y<h; y++){
			*input_y= (double)y/h;
			current_pixel= &draw_buffer[x+w*y];
			for(unsigned i=0; i<program.size(); i++)
				program[i]->execute();
		}
	}
}
