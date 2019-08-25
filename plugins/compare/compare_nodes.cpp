#include "compare_nodes.h"
#include <core/bool_t.h>
#include <core/real_t.h>

Compare_Node::Compare_Node():Node(2){
	cache= new Bool_t;
}
Compare_Node::~Compare_Node(){
	delete cache;
}
void Compare_Node::update_cache(){
	update_func(inodes.data(), &((Bool_t*)cache)->value);
}

Node* GT_Node::make(void*){return new GT_Node;}
Node* LT_Node::make(void*){return new LT_Node;}
Node* EQ_Node::make(void*){return new EQ_Node;}
Node* NE_Node::make(void*){return new NE_Node;}

void GT_Node::compile(std::vector<Node*>& program){
	Node::compile(program);
	update_func= Data_t::get_func("gt", {typeid(*inodes[0]->cache), typeid(*inodes[1]->cache)});
}
void LT_Node::compile(std::vector<Node*>& program){
	Node::compile(program);
	update_func= Data_t::get_func("lt", {typeid(*inodes[0]->cache), typeid(*inodes[1]->cache)});
}
void EQ_Node::compile(std::vector<Node*>& program){
	Node::compile(program);
	update_func= Data_t::get_func("eq", {typeid(*inodes[0]->cache), typeid(*inodes[1]->cache)});
}
void NE_Node::compile(std::vector<Node*>& program){
	Node::compile(program);
	update_func= Data_t::get_func("ne", {typeid(*inodes[0]->cache), typeid(*inodes[1]->cache)});
}
