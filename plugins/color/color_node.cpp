#include "color_node.h"
#include <color/color_t.h>

Color_Node::Color_Node(void* ptr): Node(0){
	if(!ptr)
		cache= new Color_t;
	else{
        double* d= static_cast<double*>(ptr);
        cache= new Color_t(d[0],d[1],d[2],d[3]);
	}
	uniform= true;
}

Color_Node::~Color_Node(){
	delete cache;
}

Node* Color_Node::make(void* ptr){
	return new Color_Node(ptr);
}

void Color_Node::update_cache(){}
