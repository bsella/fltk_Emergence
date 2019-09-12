#include "math_nodes.h"
#include <core/data_t.h>

Math_Node::Math_Node(unsigned int n): Node(n){}
Add_Node::Add_Node(): Math_Node(2){}
Sub_Node::Sub_Node(): Math_Node(2){}
Mul_Node::Mul_Node(): Math_Node(2){}
Div_Node::Div_Node(): Math_Node(2){}
Neg_Node::Neg_Node(): Math_Node(1){}
Sqrt_Node::Sqrt_Node(): Math_Node(1){}
Abs_Node::Abs_Node(): Math_Node(1){}
Sin_Node::Sin_Node(): Math_Node(1){}
Cos_Node::Cos_Node(): Math_Node(1){}
Min_Node::Min_Node(): Math_Node(2){}
Max_Node::Max_Node(): Math_Node(2){}
Pow_Node::Pow_Node(): Math_Node(2){}
Log_Node::Log_Node(): Math_Node(1){}

void Math_Node::update_cache(){
	if(cache== &real_cache)
		update_func(inodes.data(), &real_cache.value);
}

Node* Add_Node::make(void*){return new Add_Node;}
Node* Sub_Node::make(void*){return new Sub_Node;}
Node* Mul_Node::make(void*){return new Mul_Node;}
Node* Div_Node::make(void*){return new Div_Node;}
Node* Neg_Node::make(void*){return new Neg_Node;}
Node* Sqrt_Node::make(void*){return new Sqrt_Node;}
Node* Abs_Node::make(void*){return new Abs_Node;}
Node* Sin_Node::make(void*){return new Sin_Node;}
Node* Cos_Node::make(void*){return new Cos_Node;}
Node* Min_Node::make(void*){return new Min_Node;}
Node* Max_Node::make(void*){return new Max_Node;}
Node* Pow_Node::make(void*){return new Pow_Node;}
Node* Log_Node::make(void*){return new Log_Node;}

void Math_Node::init_cache1(Node** nodes){
	if(nodes[0]->cache->id == (unsigned)get_type_id("real")){
		cache= &real_cache;
	}
}
void Math_Node::init_cache2(Node** nodes){
	if(nodes[0]->cache->id == nodes[1]->cache->id && nodes[0]->cache->id == (unsigned)get_type_id("real")){
		cache= &real_cache;
	}
}

void Add_Node::update_types(){
	init_cache2(inodes.data());
	update_func= get_func("add", {inodes[0]->cache->id, inodes[1]->cache->id});
}
void Sub_Node::update_types(){
	init_cache2(inodes.data());
	update_func= get_func("sub", {inodes[0]->cache->id, inodes[1]->cache->id});
}
void Mul_Node::update_types(){
	init_cache2(inodes.data());
	update_func= get_func("mul", {inodes[0]->cache->id, inodes[1]->cache->id});
}
void Div_Node::update_types(){
	init_cache2(inodes.data());
	update_func= get_func("div", {inodes[0]->cache->id, inodes[1]->cache->id});
}
void Neg_Node::update_types(){
	init_cache1(inodes.data());
	update_func= get_func("neg", {inodes[0]->cache->id});
}
void Sqrt_Node::update_types(){
	init_cache1(inodes.data());
	update_func= get_func("sqrt", {inodes[0]->cache->id});
}
void Abs_Node::update_types(){
	init_cache1(inodes.data());
	update_func= get_func("abs", {inodes[0]->cache->id});
}
void Sin_Node::update_types(){
	init_cache1(inodes.data());
	update_func= get_func("sin", {inodes[0]->cache->id});
}
void Cos_Node::update_types(){
	init_cache1(inodes.data());
	update_func= get_func("cos", {inodes[0]->cache->id});
}
void Min_Node::update_types(){
	init_cache2(inodes.data());
	update_func= get_func("min", {inodes[0]->cache->id, inodes[1]->cache->id});
}
void Max_Node::update_types(){
	init_cache2(inodes.data());
	update_func= get_func("max", {inodes[0]->cache->id, inodes[1]->cache->id});
}
void Pow_Node::update_types(){
	init_cache2(inodes.data());
	update_func= get_func("pow", {inodes[0]->cache->id, inodes[1]->cache->id});
}
void Log_Node::update_types(){
	init_cache1(inodes.data());
	update_func= get_func("log", {inodes[0]->cache->id});
}
