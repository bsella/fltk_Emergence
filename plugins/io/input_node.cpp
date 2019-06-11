#include "input_node.h"

Real_t input_x;
Real_t input_y;
Real_t input_ratio;

X_Node::X_Node(): Node(0){
	cache = &input_x;
}
Y_Node::Y_Node(): Node(0){
	cache = &input_y;
}
Ratio_Node::Ratio_Node(): Node(0){
	cache = &input_ratio;
	uniform= true;
}

void X_Node::update_cache(){}
void Y_Node::update_cache(){}
void Ratio_Node::update_cache(){}

void X_Node::prepare_program(std::vector<Node*>&)const{}
void Y_Node::prepare_program(std::vector<Node*>&)const{}
void Ratio_Node::prepare_program(std::vector<Node*>&)const{}
