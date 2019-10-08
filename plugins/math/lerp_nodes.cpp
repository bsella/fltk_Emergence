#include "lerp_nodes.h"
#include <core/type_manager.h>

Lerp_Base_Node::Lerp_Base_Node():Node(3){}

void Lerp_Base_Node::init_cache(){
	if(inodes[0]->cache->id == (unsigned)get_type_id("color")){
		if(!main_func) main_func= &Color_t::rand;
		cache= &color_cache;
	}else{
		if(inodes[0]->cache->id == (unsigned)get_type_id("complex")){
			if(!main_func) main_func= &Complex_t::rand;
			cache= &complex_cache;
		}else{
			if(!main_func) main_func= &Real_t::rand;
			cache= &real_cache;
		}
	}
}

Node* Lerp_Node::make(void*){return new Lerp_Node;}
Node* Clamp_Node::make(void*){return new Clamp_Node;}

void Lerp_Node::update_types(){
	main_func= get_func("lerp", {inodes[0]->cache->id,inodes[1]->cache->id,inodes[2]->cache->id});
	init_cache();
}
void Clamp_Node::update_types(){
	main_func= get_func("clamp", {inodes[0]->cache->id,inodes[1]->cache->id,inodes[2]->cache->id});
	init_cache();
}

static double alpha;
void Lerp_Node::real(Node** nodes, void* ptr){
	alpha= ((Real_t*)nodes[1]->cache)->value;
	((Real_t*)ptr)->value= (1-alpha)*((Real_t*)nodes[2]->cache)->value + alpha*((Real_t*)nodes[0]->cache)->value;
}
void Lerp_Node::color(Node** nodes, void* ptr){
	alpha= ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->r= (1-alpha)*((Color_t*)nodes[2]->cache)->r + alpha*((Color_t*)nodes[0]->cache)->r;
	((Color_t*)ptr)->g= (1-alpha)*((Color_t*)nodes[2]->cache)->g + alpha*((Color_t*)nodes[0]->cache)->g;
	((Color_t*)ptr)->b= (1-alpha)*((Color_t*)nodes[2]->cache)->b + alpha*((Color_t*)nodes[0]->cache)->b;
	((Color_t*)ptr)->a= (1-alpha)*((Color_t*)nodes[2]->cache)->a + alpha*((Color_t*)nodes[0]->cache)->a;
}
void Lerp_Node::cplx(Node** nodes, void* ptr){
	alpha= ((Real_t*)nodes[1]->cache)->value;
	((Complex_t*)ptr)->value= (1-alpha)*((Complex_t*)nodes[2]->cache)->value + alpha*((Complex_t*)nodes[0]->cache)->value;
}

void Clamp_Node::real(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= (((Real_t*)nodes[1]->cache)->value - ((Real_t*)nodes[2]->cache)->value) / (((Real_t*)nodes[0]->cache)->value - ((Real_t*)nodes[2]->cache)->value);
}
void Clamp_Node::color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= (((Color_t*)nodes[1]->cache)->r - ((Color_t*)nodes[2]->cache)->r) / (((Color_t*)nodes[0]->cache)->r - ((Color_t*)nodes[2]->cache)->r);
	((Color_t*)ptr)->g= (((Color_t*)nodes[1]->cache)->g - ((Color_t*)nodes[2]->cache)->g) / (((Color_t*)nodes[0]->cache)->g - ((Color_t*)nodes[2]->cache)->g);
	((Color_t*)ptr)->b= (((Color_t*)nodes[1]->cache)->b - ((Color_t*)nodes[2]->cache)->b) / (((Color_t*)nodes[0]->cache)->b - ((Color_t*)nodes[2]->cache)->b);
	((Color_t*)ptr)->a= (((Color_t*)nodes[1]->cache)->a - ((Color_t*)nodes[2]->cache)->a) / (((Color_t*)nodes[0]->cache)->a - ((Color_t*)nodes[2]->cache)->a);
}
void Clamp_Node::cplx(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= (((Complex_t*)nodes[1]->cache)->value - ((Complex_t*)nodes[2]->cache)->value) / (((Complex_t*)nodes[0]->cache)->value - ((Complex_t*)nodes[2]->cache)->value);
}
