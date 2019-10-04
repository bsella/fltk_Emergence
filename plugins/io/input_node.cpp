#include "input_node.h"

Real_t* input_x;
Real_t* input_y;
Real_t* input_ratio;

X_Node::X_Node(): Node(0){
	cache = input_x;
}
Y_Node::Y_Node(): Node(0){
	cache = input_y;
}
Ratio_Node::Ratio_Node(): Node(0){
	cache = input_ratio;
	uniform= true;
}

void X_Node::execute(){}
void Y_Node::execute(){}
void Ratio_Node::execute(){}

void X_Node::compile_specific(std::vector<Node*>&, bool){}
void Y_Node::compile_specific(std::vector<Node*>&, bool){}
void Ratio_Node::compile_specific(std::vector<Node*>&, bool){}
