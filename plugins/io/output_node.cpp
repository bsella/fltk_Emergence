#include "output_node.h"

Output_Node::Output_Node(): Node(1, false){}

void Output_Node::kernel(){
}
void Output_Node::connect(int index, Node* to){
	Node::connect(index, to);
	cache= inodes[0]->cache;
}
