#include "node.h"
Node::Node(int n, bool hasOutput):hasOutput(hasOutput){
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
bool Node::is_looping(Node* source)const{
	if(this==source) return true;
	for(const auto n: inodes)
		if(n && n->is_looping(source))
			return true;
	return false;
}
