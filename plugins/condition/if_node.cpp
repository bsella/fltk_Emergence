#include "if_node.h"

If_Node::If_Node():Node(3){}

Node* If_Node::make(void*){return new If_Node;}

void If_Node::kernel(){}
