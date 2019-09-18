#include "math_nodes.h"
#include <core/data_t.h>
#include <core/type_manager.h>

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
	if(nodes[0]->cache->id == (unsigned)get_type_id("real"))
		cache= &real_cache;
	else
		if(nodes[0]->cache->id == (unsigned)get_type_id("color"))
			cache= &color_cache;

}
void Math_Node::init_cache2(Node** nodes){
	if(nodes[0]->cache->id == nodes[1]->cache->id){
		if(nodes[0]->cache->id == (unsigned)get_type_id("real"))
			cache= &real_cache;
		else if(nodes[0]->cache->id == (unsigned)get_type_id("color"))
			cache= &color_cache;
	}else{
		if(nodes[0]->cache->id == (unsigned)get_type_id("color") || nodes[0]->cache->id == (unsigned)get_type_id("real"))
			cache= &color_cache;
		else cache= &real_cache;
	}
}
void Math_Node::set_random_func(){
	if(!main_func){
		if(cache== &real_cache)
			main_func= &Real_t::rand;
		else if(cache== &color_cache)
			main_func= &Color_t::rand;
	}
}

void Add_Node::update_types(){
	init_cache2(inodes.data());
	main_func= get_func("add", {inodes[0]->cache->id, inodes[1]->cache->id});
	set_random_func();
}
void Sub_Node::update_types(){
	init_cache2(inodes.data());
	main_func= get_func("sub", {inodes[0]->cache->id, inodes[1]->cache->id});
	set_random_func();
}
void Mul_Node::update_types(){
	init_cache2(inodes.data());
	main_func= get_func("mul", {inodes[0]->cache->id, inodes[1]->cache->id});
	set_random_func();
}
void Div_Node::update_types(){
	init_cache2(inodes.data());
	main_func= get_func("div", {inodes[0]->cache->id, inodes[1]->cache->id});
	set_random_func();
}
void Neg_Node::update_types(){
	init_cache1(inodes.data());
	main_func= get_func("neg", {inodes[0]->cache->id});
	set_random_func();
}
void Sqrt_Node::update_types(){
	init_cache1(inodes.data());
	main_func= get_func("sqrt", {inodes[0]->cache->id});
	set_random_func();
}
void Abs_Node::update_types(){
	init_cache1(inodes.data());
	main_func= get_func("abs", {inodes[0]->cache->id});
	set_random_func();
}
void Sin_Node::update_types(){
	init_cache1(inodes.data());
	main_func= get_func("sin", {inodes[0]->cache->id});
	set_random_func();
}
void Cos_Node::update_types(){
	init_cache1(inodes.data());
	main_func= get_func("cos", {inodes[0]->cache->id});
	set_random_func();
}
void Min_Node::update_types(){
	init_cache2(inodes.data());
	main_func= get_func("min", {inodes[0]->cache->id, inodes[1]->cache->id});
	set_random_func();
}
void Max_Node::update_types(){
	init_cache2(inodes.data());
	main_func= get_func("max", {inodes[0]->cache->id, inodes[1]->cache->id});
	set_random_func();
}
void Pow_Node::update_types(){
	init_cache2(inodes.data());
	main_func= get_func("pow", {inodes[0]->cache->id, inodes[1]->cache->id});
	set_random_func();
}
void Log_Node::update_types(){
	init_cache1(inodes.data());
	main_func= get_func("log", {inodes[0]->cache->id});
	set_random_func();
}

#include <cmath>
void Add_Node::real_real(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= ((Real_t*)(nodes[0]->cache))->value + ((Real_t*)(nodes[1]->cache))->value;
}
void Sub_Node::real_real(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= ((Real_t*)(nodes[0]->cache))->value - ((Real_t*)(nodes[1]->cache))->value;
}
void Mul_Node::real_real(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= ((Real_t*)(nodes[0]->cache))->value * ((Real_t*)(nodes[1]->cache))->value;
}
void Div_Node::real_real(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= ((Real_t*)(nodes[0]->cache))->value / ((Real_t*)(nodes[1]->cache))->value;
}
void Neg_Node::real(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= -((Real_t*)(nodes[0]->cache))->value;
}
void Sqrt_Node::real(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= std::sqrt(((Real_t*)(nodes[0]->cache))->value);
}
void Abs_Node::real(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= std::abs(((Real_t*)(nodes[0]->cache))->value);
}
void Sin_Node::real(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= std::sin(((Real_t*)(nodes[0]->cache))->value);
}
void Cos_Node::real(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= std::cos(((Real_t*)(nodes[0]->cache))->value);
}
void Min_Node::real_real(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= std::min(((Real_t*)(nodes[0]->cache))->value,((Real_t*)(nodes[1]->cache))->value);
}
void Max_Node::real_real(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= std::max(((Real_t*)(nodes[0]->cache))->value,((Real_t*)(nodes[1]->cache))->value);
}
void Pow_Node::real_real(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= std::pow(((Real_t*)(nodes[0]->cache))->value,((Real_t*)(nodes[1]->cache))->value);
}
void Log_Node::real(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= std::log(((Real_t*)(nodes[0]->cache))->value);
}

#define r0 ((Color_t*)(nodes[0]->cache))->r
#define g0 ((Color_t*)(nodes[0]->cache))->g
#define b0 ((Color_t*)(nodes[0]->cache))->b
#define a0 ((Color_t*)(nodes[0]->cache))->a

#define r1 ((Color_t*)(nodes[1]->cache))->r
#define g1 ((Color_t*)(nodes[1]->cache))->g
#define b1 ((Color_t*)(nodes[1]->cache))->b
#define a1 ((Color_t*)(nodes[1]->cache))->a

void Add_Node::color_color(Node** nodes, void* ptr){
	static double diff;
	diff= 1 - a1;
	((Color_t*)ptr)->r= r1 + r0 * diff;
	((Color_t*)ptr)->g= g1 + g0 * diff;
	((Color_t*)ptr)->b= b1 + b0 * diff;
	((Color_t*)ptr)->a= a1 + a0 * diff;
}
void Sub_Node::color_color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= r0 - r1;
	((Color_t*)ptr)->g= g0 - g1;
	((Color_t*)ptr)->b= b0 - b1;
	((Color_t*)ptr)->a= a0 - a1;

	((Color_t*)ptr)->r= std::max(((Color_t*)ptr)->r, 0.0);
	((Color_t*)ptr)->g= std::max(((Color_t*)ptr)->g, 0.0);
	((Color_t*)ptr)->b= std::max(((Color_t*)ptr)->b, 0.0);
	((Color_t*)ptr)->a= std::max(((Color_t*)ptr)->a, 0.0);
}
void Mul_Node::color_real(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= r0 * ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->g= g0 * ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->b= b0 * ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->a= a0 * ((Real_t*)nodes[1]->cache)->value;
}
void Mul_Node::real_color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= ((Real_t*)nodes[0]->cache)->value * r1;
	((Color_t*)ptr)->g= ((Real_t*)nodes[0]->cache)->value * g1;
	((Color_t*)ptr)->b= ((Real_t*)nodes[0]->cache)->value * b1;
	((Color_t*)ptr)->a= ((Real_t*)nodes[1]->cache)->value * a1;
}
void Div_Node::color_real(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= r0 / ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->g= g0 / ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->b= b0 / ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->a= a0 / ((Real_t*)nodes[1]->cache)->value;
}
