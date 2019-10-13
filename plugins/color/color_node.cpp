#include "color_node.h"
#include <color/color_t.h>

Color_Node::Color_Node(std::istream* str): Node(0){
	cache= new Color_t(str);
	uniform= true;
}

Color_Node::~Color_Node(){
	delete cache;
}

Node* Color_Node::make(std::istream* ptr){
	return new Color_Node(ptr);
}

void Color_Node::update_cache(){}

void Color_Node::save(std::ostream& os)const{
	Node::save(os);
	static_cast<Color_t*>(cache)->save(os);
}

const char* Color_Node::id()const{return "color";}
