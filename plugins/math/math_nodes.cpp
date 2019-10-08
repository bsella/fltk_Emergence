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

void Math_Node::compile_specific(std::vector<Node*>& program, bool check_uniform){
	Node::compile_specific(program, check_uniform);
	if(inodes.size()==1) init_cache1(inodes.data());
	else init_cache2(inodes.data());
}

void Math_Node::init_cache1(Node** nodes){
	if(nodes[0]->cache->id == (unsigned)get_type_id("real"))
		cache= &real_cache;
	else
		if(nodes[0]->cache->id == (unsigned)get_type_id("color"))
			cache= &color_cache;
	else
		if(nodes[0]->cache->id == (unsigned)get_type_id("complex"))
			cache= &complex_cache;

}
void Math_Node::init_cache2(Node** nodes){
	if(nodes[0]->cache->id == (unsigned)get_type_id("real"))
		init_cache1(nodes+1);
	else
		if(nodes[0]->cache->id == (unsigned)get_type_id("color"))
			cache= &color_cache;
		else
			if(nodes[0]->cache->id == (unsigned)get_type_id("complex")){
				if(nodes[1]->cache->id == (unsigned)get_type_id("real") || nodes[1]->cache->id == (unsigned)get_type_id("complex"))
					cache= &complex_cache;
				else
					if(nodes[1]->cache->id == (unsigned)get_type_id("color"))
						cache= &color_cache;
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
	if(cache==&complex_cache) cache= &real_cache;
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
void Pow_Node::real_real(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= std::pow(((Real_t*)(nodes[0]->cache))->value,((Real_t*)(nodes[1]->cache))->value);
}
void Log_Node::real(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= std::log(((Real_t*)(nodes[0]->cache))->value);
}

#define R0 ((Color_t*)(nodes[0]->cache))->r
#define G0 ((Color_t*)(nodes[0]->cache))->g
#define B0 ((Color_t*)(nodes[0]->cache))->b
#define A0 ((Color_t*)(nodes[0]->cache))->a

#define R1 ((Color_t*)(nodes[1]->cache))->r
#define G1 ((Color_t*)(nodes[1]->cache))->g
#define B1 ((Color_t*)(nodes[1]->cache))->b
#define A1 ((Color_t*)(nodes[1]->cache))->a

void Add_Node::real_color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= ((Real_t*)nodes[0]->cache)->value + R1;
	((Color_t*)ptr)->g= ((Real_t*)nodes[0]->cache)->value + G1;
	((Color_t*)ptr)->b= ((Real_t*)nodes[0]->cache)->value + B1;
	((Color_t*)ptr)->a= ((Real_t*)nodes[0]->cache)->value + A1;
}
void Add_Node::color_real(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= R0 + ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->g= G0 + ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->b= B0 + ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->a= A0 + ((Real_t*)nodes[1]->cache)->value;
}
void Add_Node::color_color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= R0 + R1;
	((Color_t*)ptr)->g= G0 + G1;
	((Color_t*)ptr)->b= B0 + B1;
	((Color_t*)ptr)->a= A0 + A1;
}

void Sub_Node::real_color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= ((Real_t*)nodes[0]->cache)->value - R1;
	((Color_t*)ptr)->g= ((Real_t*)nodes[0]->cache)->value - G1;
	((Color_t*)ptr)->b= ((Real_t*)nodes[0]->cache)->value - B1;
	((Color_t*)ptr)->a= ((Real_t*)nodes[0]->cache)->value - A1;
}
void Sub_Node::color_real(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= R0 - ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->g= G0 - ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->b= B0 - ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->a= A0 - ((Real_t*)nodes[1]->cache)->value;
}
void Sub_Node::color_color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= R0 - R1;
	((Color_t*)ptr)->g= G0 - G1;
	((Color_t*)ptr)->b= B0 - B1;
	((Color_t*)ptr)->a= A0 - A1;
}

void Mul_Node::real_color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= ((Real_t*)nodes[0]->cache)->value * R1;
	((Color_t*)ptr)->g= ((Real_t*)nodes[0]->cache)->value * G1;
	((Color_t*)ptr)->b= ((Real_t*)nodes[0]->cache)->value * B1;
	((Color_t*)ptr)->a= ((Real_t*)nodes[0]->cache)->value * A1;
}
void Mul_Node::color_real(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= R0 * ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->g= G0 * ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->b= B0 * ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->a= A0 * ((Real_t*)nodes[1]->cache)->value;
}
void Mul_Node::color_color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= R0 * R1;
	((Color_t*)ptr)->g= G0 * G1;
	((Color_t*)ptr)->b= B0 * B1;
	((Color_t*)ptr)->a= A0 * A1;
}

void Div_Node::real_color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= ((Real_t*)nodes[0]->cache)->value / R1;
	((Color_t*)ptr)->g= ((Real_t*)nodes[0]->cache)->value / G1;
	((Color_t*)ptr)->b= ((Real_t*)nodes[0]->cache)->value / B1;
	((Color_t*)ptr)->a= ((Real_t*)nodes[0]->cache)->value / A1;
}
void Div_Node::color_real(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= R0 / ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->g= G0 / ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->b= B0 / ((Real_t*)nodes[1]->cache)->value;
	((Color_t*)ptr)->a= A0 / ((Real_t*)nodes[1]->cache)->value;
}
void Div_Node::color_color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= R0 / R1;
	((Color_t*)ptr)->g= G0 / G1;
	((Color_t*)ptr)->b= B0 / B1;
	((Color_t*)ptr)->a= A0 / A1;
}

void Neg_Node::color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= -R0;
	((Color_t*)ptr)->g= -G0;
	((Color_t*)ptr)->b= -B0;
	((Color_t*)ptr)->a= -A0;
}

void Abs_Node::color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= std::abs(R0);
	((Color_t*)ptr)->g= std::abs(G0);
	((Color_t*)ptr)->b= std::abs(B0);
	((Color_t*)ptr)->a= std::abs(A0);
}

void Sin_Node::color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= std::sin(R0);
	((Color_t*)ptr)->g= std::sin(G0);
	((Color_t*)ptr)->b= std::sin(B0);
	((Color_t*)ptr)->a= std::sin(A0);
}

void Cos_Node::color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= std::cos(R0);
	((Color_t*)ptr)->g= std::cos(G0);
	((Color_t*)ptr)->b= std::cos(B0);
	((Color_t*)ptr)->a= std::cos(A0);
}

void Pow_Node::real_color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= std::pow(((Real_t*)nodes[0]->cache)->value, R1);
	((Color_t*)ptr)->g= std::pow(((Real_t*)nodes[0]->cache)->value, G1);
	((Color_t*)ptr)->b= std::pow(((Real_t*)nodes[0]->cache)->value, B1);
	((Color_t*)ptr)->a= std::pow(((Real_t*)nodes[0]->cache)->value, A1);
}
void Pow_Node::color_real(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= std::pow(R0, ((Real_t*)nodes[1]->cache)->value);
	((Color_t*)ptr)->g= std::pow(G0, ((Real_t*)nodes[1]->cache)->value);
	((Color_t*)ptr)->b= std::pow(B0, ((Real_t*)nodes[1]->cache)->value);
	((Color_t*)ptr)->a= std::pow(A0, ((Real_t*)nodes[1]->cache)->value);
}
void Pow_Node::color_color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= std::pow(R0, R1);
	((Color_t*)ptr)->g= std::pow(G0, G1);
	((Color_t*)ptr)->b= std::pow(B0, B1);
	((Color_t*)ptr)->a= std::pow(A0, A1);
}

void Log_Node::color(Node** nodes, void* ptr){
	((Color_t*)ptr)->r= std::log(R0);
	((Color_t*)ptr)->g= std::log(G0);
	((Color_t*)ptr)->b= std::log(B0);
	((Color_t*)ptr)->a= std::log(A0);
}

void Add_Node::real_complex(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= ((Real_t*)nodes[0]->cache)->value + ((Complex_t*)nodes[1]->cache)->value;
}
void Add_Node::complex_real(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= ((Complex_t*)nodes[0]->cache)->value + ((Real_t*)nodes[1]->cache)->value;
}
void Add_Node::complex_complex(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= ((Complex_t*)nodes[0]->cache)->value + ((Complex_t*)nodes[1]->cache)->value;
}

void Sub_Node::real_complex(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= ((Real_t*)nodes[0]->cache)->value - ((Complex_t*)nodes[1]->cache)->value;
}
void Sub_Node::complex_real(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= ((Complex_t*)nodes[0]->cache)->value - ((Real_t*)nodes[1]->cache)->value;
}
void Sub_Node::complex_complex(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= ((Complex_t*)nodes[0]->cache)->value - ((Complex_t*)nodes[1]->cache)->value;
}

void Mul_Node::real_complex(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= ((Real_t*)nodes[0]->cache)->value * ((Complex_t*)nodes[1]->cache)->value;
}
void Mul_Node::complex_real(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= ((Complex_t*)nodes[0]->cache)->value * ((Real_t*)nodes[1]->cache)->value;
}
void Mul_Node::complex_complex(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= ((Complex_t*)nodes[0]->cache)->value * ((Complex_t*)nodes[1]->cache)->value;
}

void Div_Node::real_complex(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= ((Real_t*)nodes[0]->cache)->value / ((Complex_t*)nodes[1]->cache)->value;
}
void Div_Node::complex_real(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= ((Complex_t*)nodes[0]->cache)->value / ((Real_t*)nodes[1]->cache)->value;
}
void Div_Node::complex_complex(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= ((Complex_t*)nodes[0]->cache)->value / ((Complex_t*)nodes[1]->cache)->value;
}

void Neg_Node::cplx(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= -((Complex_t*)nodes[0]->cache)->value;
}

void Abs_Node::cplx(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= ((Complex_t*)nodes[0]->cache)->abs();
}

void Sin_Node::cplx(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= std::sin(((Complex_t*)nodes[0]->cache)->value);
}

void Cos_Node::cplx(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= std::cos(((Complex_t*)nodes[0]->cache)->value);
}

void Pow_Node::real_complex(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= std::pow(((Real_t*)nodes[0]->cache)->value, ((Complex_t*)nodes[1]->cache)->value);
}
void Pow_Node::complex_real(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= std::pow(((Complex_t*)nodes[0]->cache)->value, ((Real_t*)nodes[1]->cache)->value);
}
void Pow_Node::complex_complex(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= std::pow(((Complex_t*)nodes[0]->cache)->value, ((Complex_t*)nodes[1]->cache)->value);
}

void Log_Node::cplx(Node** nodes, void* ptr){
	((Complex_t*)ptr)->value= std::log(((Complex_t*)nodes[0]->cache)->value);
}

Min_Max_Node::Min_Max_Node():Node(2){}

bool Min_Max_Node::rand(Data_t*, Data_t*){
	return ::rand() > RAND_MAX/2;
}
bool Min_Max_Node::gt_real(Data_t* r1, Data_t* r2){
	return ((Real_t*)r1)->value > ((Real_t*)r2)->value;
}
bool Min_Max_Node::gt_color(Data_t* c1, Data_t* c2){
	return ((Color_t*)c1)->to_real() > ((Color_t*)c2)->to_real();
}
bool Min_Max_Node::gt_complex(Data_t* c1, Data_t* c2){
	return ((Complex_t*)c1)->abs() > ((Complex_t*)c2)->abs();
}
void Min_Max_Node::update_types(){
	if(inodes[0]->cache->id == inodes[1]->cache->id){
		if(inodes[0]->cache->id == (unsigned)get_type_id("real"))
			gt_func= &Min_Max_Node::gt_real;
		else
			if(inodes[0]->cache->id == (unsigned)get_type_id("color"))
				gt_func= &Min_Max_Node::gt_color;
		invalidate_output_types();
		return;
	}
	gt_func= &Min_Max_Node::rand;
}
void Min_Max_Node::execute(){
	if(!valid_types) update_types();
	valid_types= true;
	if(gt_func == &Min_Max_Node::rand){
		const bool temp= Min_Max_Node::rand(inodes[0]->cache, inodes[1]->cache);
		cache= inodes[temp]->cache;
		if(temp != last_random) invalidate_output_types();
		last_random= temp;
	}else update_cache();
}
void Min_Node::update_cache(){
	cache= inodes[gt_func(inodes[0]->cache, inodes[1]->cache)]->cache;
}
void Max_Node::update_cache(){
	cache= inodes[!gt_func(inodes[0]->cache, inodes[1]->cache)]->cache;
}
