#include "color_node.h"
#include <color/color_t.h>

Color_Node::Color_Node(void* ptr): Node(0){
	if(!ptr)
		cache= new Color_t;
	else{
		float* f= (float*)ptr;
		cache= new Color_t(f[0],f[1],f[2],f[3]);
	}
}

Color_Node::~Color_Node(){
	delete cache;
}

Node* Color_Node::make(void* ptr){
	return new Color_Node(ptr);
}

void Color_Node::update_cache(){}
