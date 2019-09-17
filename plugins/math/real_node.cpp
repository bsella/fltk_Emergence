#include "real_node.h"
#include <real/real_t.h>

Real_Node::Real_Node(void* ptr): Node(0){
	if(!ptr) cache= new Real_t;
	else cache= new Real_t(*((double*)ptr));
	uniform= true;
}

Real_Node::~Real_Node(){
	delete cache;
}

Node* Real_Node::make(void* ptr){
	return new Real_Node(ptr);
}

void Real_Node::update_cache(){}
