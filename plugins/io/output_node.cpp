#include "output_node.h"
#include <core/data_t.h>
#include <core/type_manager.h>

Output_Node::Output_Node(): Node(1, false){}

void Output_Node::update_types(){
	main_func= get_func("to_color", {inodes[0]->cache->id});
}
void Output_Node::update_cache(){
	main_func(inodes.data(), &pixel_cache);
}
void Output_Node::update_valid(){
	Node::update_valid();
	if(valid){
		program.clear();
		compile(program);
	}
}
