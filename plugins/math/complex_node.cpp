#include "complex_node.h"
#include <complex/complex_t.h>
#include <core/type_manager.h>
#include <real/real_t.h>

Complex_Node::Complex_Node():Node(2){
	cache= new Complex_t;
}
Complex_Node::~Complex_Node(){
	delete cache;
}

Node* Complex_Node::make(std::istream*){return new Complex_Node;}

void Complex_Node::cplx(Node** nodes, void* ptr){
	static_cast<Complex_t*>(ptr)->value= std::complex<double>(static_cast<Real_t*>(nodes[0]->cache)->value, static_cast<Real_t*>(nodes[1]->cache)->value);
}

void Complex_Node::update_types(){
	main_func= get_func("complex", {inodes[0]->cache->id, inodes[1]->cache->id});
	if(!main_func) main_func= &Complex_t::rand;
}

const char* Complex_Node::id()const{return "complex";}
