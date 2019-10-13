#include "real_node.h"
#include <real/real_t.h>

Real_Node::Real_Node(std::istream* str): Node(0, "real"){
	cache= new Real_t(str);
	uniform= true;
}

Real_Node::~Real_Node(){
	delete cache;
}

Node* Real_Node::make(std::istream* ptr){
	return new Real_Node(ptr);
}

void Real_Node::update_cache(){}

void Real_Node::save(std::ostream& os)const{
	Node::save(os);
	static_cast<Real_t*>(cache)->save(os);
}

const char* Real_Node::id()const{return "real";}
