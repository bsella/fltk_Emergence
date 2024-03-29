#include "logic_nodes.h"
#include <bool/bool_t.h>
#include <core/type_manager.h>

AND_Node::AND_Node():Node(2){
	cache= new Bool_t;
}
OR_Node::OR_Node():Node(2){
	cache= new Bool_t;
}
XOR_Node::XOR_Node():Node(2){
	cache= new Bool_t;
}
NOT_Node::NOT_Node():Node(1){
	cache= new Bool_t;
}

AND_Node::~AND_Node(){
	delete cache;
}
OR_Node::~OR_Node(){
	delete cache;
}
XOR_Node::~XOR_Node(){
	delete cache;
}
NOT_Node::~NOT_Node(){
	delete cache;
}

Node* AND_Node::make(std::istream*){return new AND_Node;}
Node* OR_Node::make(std::istream*){return new OR_Node;}
Node* XOR_Node::make(std::istream*){return new XOR_Node;}
Node* NOT_Node::make(std::istream*){return new NOT_Node;}

const char* AND_Node::id()const{return "and";}
const char* OR_Node::id()const{return "or";}
const char* XOR_Node::id()const{return "xor";}
const char* NOT_Node::id()const{return "not";}

void AND_Node::update_types(){
	main_func= get_func(id(), {inodes[0]->cache->id, inodes[1]->cache->id});
	if(!main_func) main_func= &Bool_t::rand;
}
void OR_Node::update_types(){
	main_func= get_func(id(), {inodes[0]->cache->id, inodes[1]->cache->id});
	if(!main_func) main_func= &Bool_t::rand;
}
void XOR_Node::update_types(){
	main_func= get_func(id(), {inodes[0]->cache->id, inodes[1]->cache->id});
	if(!main_func) main_func= &Bool_t::rand;
}
void NOT_Node::update_types(){
	main_func= get_func(id(), {inodes[0]->cache->id});
	if(!main_func) main_func= &Bool_t::rand;
}

void AND_Node::func(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Bool_t*>(nodes[0]->cache)->value && static_cast<Bool_t*>(nodes[1]->cache)->value;
}
void OR_Node::func(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Bool_t*>(nodes[0]->cache)->value || static_cast<Bool_t*>(nodes[1]->cache)->value;
}
void XOR_Node::func(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= static_cast<Bool_t*>(nodes[0]->cache)->value ^  static_cast<Bool_t*>(nodes[1]->cache)->value;
}
void NOT_Node::func(Node** nodes, void* ptr){
	static_cast<Bool_t*>(ptr)->value= !static_cast<Bool_t*>(nodes[0]->cache)->value;
}
