#include "output_node.h"

Output_Node::Output_Node(): Node(1, false){}

void Output_Node::update_cache(){}
void Output_Node::compile(std::vector<Node*>& prog){
	//cache= inodes[0]->cache;
	first= inodes[0];
	for(auto n : inodes)
		n->compile(prog);
}
void Output_Node::update_valid(){
	Node::update_valid();
	if(valid){
		program.clear();
		compile(program);
	}
}
