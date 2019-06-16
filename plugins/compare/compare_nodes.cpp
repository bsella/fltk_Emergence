#include "compare_nodes.h"
#include <core/bool_t.h>
#include <core/real_t.h>

GT_Node::GT_Node():Node(2){
	cache= new Bool_t;
}
LT_Node::LT_Node():Node(2){
	cache= new Bool_t;
}
EQ_Node::EQ_Node():Node(2){
	cache= new Bool_t;
}
NE_Node::NE_Node():Node(2){
	cache= new Bool_t;
}

GT_Node::~GT_Node(){
	delete cache;
}
LT_Node::~LT_Node(){
	delete cache;
}
EQ_Node::~EQ_Node(){
	delete cache;
}
NE_Node::~NE_Node(){
	delete cache;
}

Node* GT_Node::make(void*){return new GT_Node;}
Node* LT_Node::make(void*){return new LT_Node;}
Node* EQ_Node::make(void*){return new EQ_Node;}
Node* NE_Node::make(void*){return new NE_Node;}

void GT_Node::update_cache(){
	switch(inodes[0]->cache->type_id){
		case real_t_id:
			if(inodes[1]->cache->type_id == real_t_id){
				*(Bool_t*)cache= ((Real_t*)inodes[0]->cache)->value>((Real_t*)inodes[1]->cache)->value;
				return;
			}
			break;
		default:break;
	}
	*(Bool_t*)cache=false;
}
void LT_Node::update_cache(){
	switch(inodes[0]->cache->type_id){
		case real_t_id:
			if(inodes[1]->cache->type_id == real_t_id){
				*(Bool_t*)cache= ((Real_t*)inodes[0]->cache)->value<((Real_t*)inodes[1]->cache)->value;
				return;
			}
			break;
		default:break;
	}
	*(Bool_t*)cache=false;
}
void EQ_Node::update_cache(){
	switch(inodes[0]->cache->type_id){
		case real_t_id:
			if(inodes[1]->cache->type_id == real_t_id){
				*(Bool_t*)cache= ((Real_t*)inodes[0]->cache)->value==((Real_t*)inodes[1]->cache)->value;
				return;
			}
			break;
		case bool_t_id:
			if(inodes[1]->cache->type_id == bool_t_id){
				*(Bool_t*)cache= ((Bool_t*)inodes[0]->cache)->value==((Bool_t*)inodes[1]->cache)->value;
				return;
			}
			break;
		default:break;
	}
	*(Bool_t*)cache=false;
}
void NE_Node::update_cache(){
	switch(inodes[0]->cache->type_id){
		case real_t_id:
			if(inodes[1]->cache->type_id == real_t_id){
				*(Bool_t*)cache= ((Real_t*)inodes[0]->cache)->value!=((Real_t*)inodes[1]->cache)->value;
				return;
			}
			break;
		case bool_t_id:
			if(inodes[1]->cache->type_id == bool_t_id){
				*(Bool_t*)cache= ((Bool_t*)inodes[0]->cache)->value!=((Bool_t*)inodes[1]->cache)->value;
				return;
			}
			break;
		default:break;
	}
	*(Bool_t*)cache=false;
}
