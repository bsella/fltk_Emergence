#include "if_node.h"
#include <core/data_t.h>

If_Node::If_Node():Node(3){}

Node* If_Node::make(void*){return new If_Node;}

void If_Node::kernel(){
	//if((bool)*cache)
	//	cache= then_program->execute();
	//else
	//	cache= else_program->execute();
}
void If_Node::prepare_program(std::vector<Node*>& program)const{
	inodes[1]->prepare_program(program);
	//prepare then program
	//prepare else program
}
