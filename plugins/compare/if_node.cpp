#include "if_node.h"
#include <bool/bool_t.h>

If_Node::If_Node():Node(3){}

Node* If_Node::make(void*){return new If_Node;}

void If_Node::update_cache(){
	bool res;
	to_bool(inodes.data()+1, &res);
	if(res){
		for(unsigned i=0; i<then_program.size(); i++)
			then_program[i]->execute();
		cache = inodes[0]->cache;
	}else{
		for(unsigned i=0; i<else_program.size(); i++)
			else_program[i]->execute();
		cache = inodes[2]->cache;
	}
	if(last_res != res && inodes[0]->cache->id != inodes[2]->cache->id)
		invalidate_output_types();
	last_res= res;
}
void If_Node::compile(std::vector<Node*>& program){
	inodes[1]->compile(program);
	program.push_back(this);

	then_program.clear();
	inodes[0]->compile(then_program);

	else_program.clear();
	inodes[2]->compile(else_program);
}
void If_Node::update_types(){
	to_bool= get_func("to_bool", {inodes[1]->cache->id});
}
