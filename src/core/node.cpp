#include "node.h"
Node::Node(int n){
    for(int i=0; i<n; i++)
        inodes.push_back(nullptr);
}
Node::~Node(){}
void Node::connect(int input, Node* to){
	if(!inodes[input])
		inodes[input]=to;
}
void Node::disconnect(int input){
	if(inodes[input])
		inodes[input]= nullptr;
}
