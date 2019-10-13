#include "compare_nodes.h"
#include <bool/bool_t.h>
#include <core/type_manager.h>

GT_Node::GT_Node():Node(2){cache= new Bool_t;}
LT_Node::LT_Node():Node(2){cache= new Bool_t;}
EQ_Node::EQ_Node():Node(2){cache= new Bool_t;}
NE_Node::NE_Node():Node(2){cache= new Bool_t;}

GT_Node::~GT_Node(){delete cache;}
LT_Node::~LT_Node(){delete cache;}
EQ_Node::~EQ_Node(){delete cache;}
NE_Node::~NE_Node(){delete cache;}

Node* GT_Node::make(void*){return new GT_Node;}
Node* LT_Node::make(void*){return new LT_Node;}
Node* EQ_Node::make(void*){return new EQ_Node;}
Node* NE_Node::make(void*){return new NE_Node;}

const char* GT_Node::id()const{return "gt";}
const char* LT_Node::id()const{return "lt";}
const char* EQ_Node::id()const{return "eq";}
const char* NE_Node::id()const{return "ne";}

void GT_Node::update_types(){
	main_func= get_func(id(), {inodes[0]->cache->id, inodes[1]->cache->id});
	if(!main_func) main_func= &Bool_t::rand;
}
void LT_Node::update_types(){
	main_func= get_func(id(), {inodes[0]->cache->id, inodes[1]->cache->id});
	if(!main_func) main_func= &Bool_t::rand;
}
void EQ_Node::update_types(){
	main_func= get_func(id(), {inodes[0]->cache->id, inodes[1]->cache->id});
	if(!main_func) main_func= &Bool_t::rand;
}
void NE_Node::update_types(){
	main_func= get_func(id(), {inodes[0]->cache->id, inodes[1]->cache->id});
	if(!main_func) main_func= &Bool_t::rand;
}

#include <real/real_t.h>
#include <color/color_t.h>

void GT_Node::real_real(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Real_t*>(nodes[0]->cache)->value > static_cast<Real_t*>(nodes[1]->cache)->value;
}
void LT_Node::real_real(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Real_t*>(nodes[0]->cache)->value < static_cast<Real_t*>(nodes[1]->cache)->value;
}
void EQ_Node::real_real(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Real_t*>(nodes[0]->cache)->value == static_cast<Real_t*>(nodes[1]->cache)->value;
}
void NE_Node::real_real(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Real_t*>(nodes[0]->cache)->value != static_cast<Real_t*>(nodes[1]->cache)->value;
}

void GT_Node::real_color(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Real_t*>(nodes[0]->cache)->value > static_cast<Color_t*>(nodes[1]->cache)->to_real();
}
void LT_Node::real_color(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Real_t*>(nodes[0]->cache)->value < static_cast<Color_t*>(nodes[1]->cache)->to_real();
}
void EQ_Node::real_color(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Real_t*>(nodes[0]->cache)->value == static_cast<Color_t*>(nodes[1]->cache)->to_real();
}
void NE_Node::real_color(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Real_t*>(nodes[0]->cache)->value != static_cast<Color_t*>(nodes[1]->cache)->to_real();
}

void GT_Node::color_real(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Color_t*>(nodes[0]->cache)->to_real() > static_cast<Real_t*>(nodes[1]->cache)->value;
}
void LT_Node::color_real(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Color_t*>(nodes[0]->cache)->to_real() < static_cast<Real_t*>(nodes[1]->cache)->value;
}
void EQ_Node::color_real(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Color_t*>(nodes[0]->cache)->to_real() == static_cast<Real_t*>(nodes[1]->cache)->value;
}
void NE_Node::color_real(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Color_t*>(nodes[0]->cache)->to_real() != static_cast<Real_t*>(nodes[1]->cache)->value;
}

void GT_Node::color_color(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Color_t*>(nodes[0]->cache)->to_real()> static_cast<Color_t*>(nodes[1]->cache)->to_real();
}
void LT_Node::color_color(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Color_t*>(nodes[0]->cache)->to_real()< static_cast<Color_t*>(nodes[1]->cache)->to_real();
}
void EQ_Node::color_color(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Color_t*>(nodes[0]->cache)->to_real()== static_cast<Color_t*>(nodes[1]->cache)->to_real();
}
void NE_Node::color_color(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Color_t*>(nodes[0]->cache)->to_real()!= static_cast<Color_t*>(nodes[1]->cache)->to_real();
}
