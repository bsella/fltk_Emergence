#include "if_node.h"
#include <bool/bool_t.h>
#include <stdlib.h>

If_Node::If_Node():Node(3){}

Node* If_Node::make(void*){return new If_Node;}

void If_Node::update_cache(){
	bool res;
	if(main_func) main_func(inodes.data()+1, &res);
	else res= (float)::rand() / RAND_MAX < .5;
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
void If_Node::compile_recursive(std::vector<Node*>& program, bool check_uniform){
	if(compile_id != last_compile_id){
		if(check_uniform && uniform){
			std::vector<Node*> uniform_program;
			compile_recursive(uniform_program, false);
			for(auto n : uniform_program)
				n->execute();
		}else{
			inodes[1]->compile_recursive(program, check_uniform);
			program.push_back(this);
	
			then_program.clear();
			inodes[0]->compile_recursive(then_program, check_uniform);
	
			else_program.clear();
			inodes[2]->compile_recursive(else_program, check_uniform);
		}
		compile_id= last_compile_id;
	}
}
void If_Node::update_types(){
	main_func= get_func("to_bool", {inodes[1]->cache->id});
}
