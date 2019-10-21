#include "node.h"
#include "data_t.h"

Node::Node(int n, bool hasOutput):hasOutput(hasOutput){
	valid= n==0;
    for(int i=0; i<n; i++)
        inodes.push_back(nullptr);
}
Node::~Node(){}
void Node::connect(unsigned int input, Node* to){
	inodes[input]=to;
	to->onodes.push_back(this);
	update_valid();
	update_uniform();
}
void Node::disconnect(unsigned int input){
	inodes[input]->onodes.remove(this);
	inodes[input]= nullptr;
	uniform= false;
	valid= false;
	valid_types= false;
	for(auto n : onodes){
		n->update_valid();
		n->update_uniform();
	}
}
void Node::update_valid(){
	valid= true;
	for(const auto n: inodes)
		if(!n || !n->valid){
			valid= false;
			break;
		}
	for(auto n: onodes)
		if(n) n->update_valid();
}
void Node::update_uniform(){
	uniform= true;
	for(const auto n: inodes)
		if(!n || !n->uniform){
			uniform= false;
			break;
		}
	for(auto n: onodes)
		if(n) n->update_uniform();
}
bool Node::is_looping(Node* source)const{
	if(this==source) return true;
	for(const auto n: inodes)
		if(n && n->is_looping(source))
			return true;
	return false;
}
unsigned int Node::last_compile_id= 0;
void Node::compile_specific(std::vector<Node*>& program, bool check_uniform){
	for(auto n : inodes)
		n->compile_recursive(program, check_uniform);
	program.push_back(this);
}
void Node::compile_recursive(std::vector<Node*>& program, bool check_uniform){
	if(compile_id!=last_compile_id){
		if(check_uniform && uniform){
			std::vector<Node*> uniform_program;
			compile_recursive(uniform_program, false);
			for(auto n : uniform_program)
				n->execute();
		}else
			compile_specific(program, check_uniform);
		compile_id= last_compile_id;
	}
}
void Node::compile(std::vector<Node*>& program){
	last_compile_id++;
	compile_recursive(program);
}
void Node::invalidate_output_types(){
	for(const auto n: onodes)
		n->valid_types= false;
}
void Node::update_types(){}
void Node::update_cache(){
	main_func(inodes.data(), cache);
}
void Node::execute(){
	if(!valid_types) update_types();
	valid_types= true;
	update_cache();
}

#include <cstring>
void Node::save(std::ostream& os)const{
	size_t len= strlen(id())+1;
	os.write(reinterpret_cast<const char*>(&len), sizeof(size_t));
	os.write(id(), len);
}
