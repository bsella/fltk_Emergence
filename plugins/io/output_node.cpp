#include "output_node.h"

Output_Node::Output_Node(): Node(1, false){}

void Output_Node::update_cache(){}
void Output_Node::prepare_program(std::vector<Node*>& prog){
	//cache= inodes[0]->cache;
	first= inodes[0];
	for(auto n : inodes)
		n->prepare_program(prog);
}
void Output_Node::update_valid(){
	Node::update_valid();
	if(valid){
		program.clear();
		prepare_program(program);
	}
}
