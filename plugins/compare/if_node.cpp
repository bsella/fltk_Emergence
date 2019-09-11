#include "if_node.h"
#include <bool/bool_t.h>

If_Node::If_Node():Node(3){}

Node* If_Node::make(void*){return new If_Node;}

void If_Node::update_cache(){
	//if(bool(*inodes[1]->cache)){
	//	for(unsigned i=0; i<then_program.size(); i++)
	//		then_program[i]->update_cache();
	//	cache = inodes[0]->cache;
	//}else{
	//	for(unsigned i=0; i<else_program.size(); i++)
	//		else_program[i]->update_cache();
	//	cache = inodes[2]->cache;
	//}
}
void If_Node::compile(std::vector<Node*>& program){
	inodes[1]->compile(program);
	program.push_back(this);

	then_program.clear();
	inodes[0]->compile(then_program);

	else_program.clear();
}
