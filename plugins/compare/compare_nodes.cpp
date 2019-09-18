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

#include <real/real_t.h>
#include <color/color_t.h>

void GT_Node::real_real(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= ((Real_t*)nodes[0]->cache)->value > ((Real_t*)nodes[1]->cache)->value;
}
void LT_Node::real_real(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= ((Real_t*)nodes[0]->cache)->value < ((Real_t*)nodes[1]->cache)->value;
}
void EQ_Node::real_real(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= ((Real_t*)nodes[0]->cache)->value == ((Real_t*)nodes[1]->cache)->value;
}
void NE_Node::real_real(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= ((Real_t*)nodes[0]->cache)->value != ((Real_t*)nodes[1]->cache)->value;
}

double color_to_real(Color_t* c){
	return (c->r + c->g + c->b)/3 * c->a;
}

void GT_Node::real_color(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= ((Real_t*)nodes[0]->cache)->value > color_to_real(((Color_t*)nodes[1]->cache));
}
void LT_Node::real_color(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= ((Real_t*)nodes[0]->cache)->value < color_to_real(((Color_t*)nodes[1]->cache));
}
void EQ_Node::real_color(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= ((Real_t*)nodes[0]->cache)->value == color_to_real(((Color_t*)nodes[1]->cache));
}
void NE_Node::real_color(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= ((Real_t*)nodes[0]->cache)->value != color_to_real(((Color_t*)nodes[1]->cache));
}

void GT_Node::color_real(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= color_to_real((Color_t*)nodes[0]->cache) > ((Real_t*)nodes[1]->cache)->value;
}
void LT_Node::color_real(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= color_to_real((Color_t*)nodes[0]->cache) < ((Real_t*)nodes[1]->cache)->value;
}
void EQ_Node::color_real(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= color_to_real((Color_t*)nodes[0]->cache) == ((Real_t*)nodes[1]->cache)->value;
}
void NE_Node::color_real(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= color_to_real((Color_t*)nodes[0]->cache) != ((Real_t*)nodes[1]->cache)->value;
}

void GT_Node::color_color(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= color_to_real((Color_t*)nodes[0]->cache) > color_to_real((Color_t*)nodes[1]->cache);
}
void LT_Node::color_color(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= color_to_real((Color_t*)nodes[0]->cache) < color_to_real((Color_t*)nodes[1]->cache);
}
void EQ_Node::color_color(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= color_to_real((Color_t*)nodes[0]->cache) == color_to_real((Color_t*)nodes[1]->cache);
}
void NE_Node::color_color(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= color_to_real((Color_t*)nodes[0]->cache) != color_to_real((Color_t*)nodes[1]->cache);
}
