#include "node.h"
#include "data_t.h"

Node::Node(int n, bool hasOutput):hasOutput(hasOutput){
	valid= n==0;
    for(int i=0; i<n; i++)
        inodes.push_back(nullptr);
}
Node::~Node(){}
void Node::connect(int input, Node* to){
	if(!inodes[input])
		inodes[input]=to;
	to->onodes.push_back(this);
	uniform= true;
	valid= true;
	for(const auto n : inodes)
		if(!n){
			uniform= false;
			valid= false;
			break;
		}
		else{
			if(!n->uniform) uniform= false;
			if(!n->valid)   valid=   false;
		}
	for(auto n : onodes){
		n->update_valid();
		n->update_uniform();
	}
}
void Node::disconnect(int input){
	if(inodes[input]){
		inodes[input]->onodes.remove(this);
		inodes[input]= nullptr;
	}
	uniform= false;
	valid= false;
	for(auto n : onodes){
		n->update_valid();
		n->update_uniform();
	}
}
void Node::update_valid(){
	valid= true;
	for(const auto n: inodes)
		if(!n->valid){
			valid= false;
			break;
		}
	for(auto n: onodes)
		n->update_valid();
}
void Node::update_uniform(){
	uniform= true;
	for(const auto n: inodes)
		if(!n->uniform){
			uniform= false;
			break;
		}
	for(auto n: onodes)
		n->update_uniform();
}
bool Node::is_looping(Node* source)const{
	if(this==source) return true;
	for(const auto n: inodes)
		if(n && n->is_looping(source))
			return true;
	return false;
}
void Node::prepare_program(std::vector<Node*>& program)const{
	if(!uniform)
		for(auto n : inodes)
			n->prepare_program(program);
	program.push_back((Node*)this);
}
