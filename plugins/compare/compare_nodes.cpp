#include "compare_nodes.h"
#include <bool/bool_t.h>
#include <core/type_manager.h>

Compare_Node::Compare_Node():Node(2){
	cache= new Bool_t;
}
Compare_Node::~Compare_Node(){
	delete cache;
}

Node* GT_Node::make(void*){return new GT_Node;}
Node* LT_Node::make(void*){return new LT_Node;}
Node* EQ_Node::make(void*){return new EQ_Node;}
Node* NE_Node::make(void*){return new NE_Node;}

void GT_Node::update_types(){
	main_func= get_func("gt", {inodes[0]->cache->id, inodes[1]->cache->id});
	if(!main_func) main_func= &Bool_t::rand;
}
void LT_Node::update_types(){
	main_func= get_func("lt", {inodes[0]->cache->id, inodes[1]->cache->id});
	if(!main_func) main_func= &Bool_t::rand;
}
void EQ_Node::update_types(){
	main_func= get_func("eq", {inodes[0]->cache->id, inodes[1]->cache->id});
	if(!main_func) main_func= &Bool_t::rand;
}
void NE_Node::update_types(){
	main_func= get_func("ne", {inodes[0]->cache->id, inodes[1]->cache->id});
	if(!main_func) main_func= &Bool_t::rand;
}
