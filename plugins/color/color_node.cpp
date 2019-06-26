#include "color_node.h"
#include <core/color_t.h>

Color_Node::Color_Node(): Node(0){}

Color_Node::~Color_Node(){
	delete cache;
}

Node* Color_Node::make(void*){return new Color_Node;}

void Color_Node::update_cache(){}
