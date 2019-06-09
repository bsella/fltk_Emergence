#include "input_node.h"
#include <core/real_t.h>

double input_x;
double input_y;
double input_ratio;

X_Node::X_Node(): Node(0){
	cache = new Real_t;
}
Y_Node::Y_Node(): Node(0){
	cache = new Real_t;
}
Ratio_Node::Ratio_Node(): Node(0){
	cache = new Real_t;
	uniform= true;
}

X_Node::~X_Node(){
	delete cache;
}
Y_Node::~Y_Node(){
	delete cache;
}
Ratio_Node::~Ratio_Node(){
	delete cache;
}

void X_Node::kernel(){
	*(Real_t*)cache = input_x;
}
void Y_Node::kernel(){
	*(Real_t*)cache = input_y;
}
void Ratio_Node::kernel(){
	*(Real_t*)cache = input_ratio;
}
