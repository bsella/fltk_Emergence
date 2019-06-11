#include "output_node.h"

Output_Node::Output_Node(): Node(1, false){}

void Output_Node::update_cache(){}
void Output_Node::connect(int index, Node* to){
	Node::connect(index, to);
	cache= inodes[0]->cache;
	if(valid){
		program.clear();
		prepare_program(program);
	}
}
void Output_Node::prepare_program(std::vector<Node*>& prog)const{
	for(auto n : inodes)
		n->prepare_program(prog);
}
