#include "func_def.h"
#include <real/real_t.h>
#include <cmath>

///Add
void add_real(Node** nodes, void* ptr){
	*((double*)ptr)= ((Real_t*)(nodes[0]->cache))->value + ((Real_t*)(nodes[1]->cache))->value;
}

///Sub
void sub_real(Node** nodes, void* ptr){
	*((double*)ptr)= ((Real_t*)(nodes[0]->cache))->value - ((Real_t*)(nodes[1]->cache))->value;
}

///Mul
void mul_real(Node** nodes, void* ptr){
	*((double*)ptr)= ((Real_t*)(nodes[0]->cache))->value * ((Real_t*)(nodes[1]->cache))->value;
}

///Div
void div_real(Node** nodes, void* ptr){
	*((double*)ptr)= ((Real_t*)(nodes[0]->cache))->value / ((Real_t*)(nodes[1]->cache))->value;
}

///Neg
void neg_real(Node** nodes, void* ptr){
	*((double*)ptr)= -((Real_t*)(nodes[0]->cache))->value;
}

///Sqrt
void sqrt_real(Node** nodes, void* ptr){
	*((double*)ptr)= std::sqrt(((Real_t*)(nodes[0]->cache))->value);
}

///Abs
void abs_real(Node** nodes, void* ptr){
	*((double*)ptr)= std::abs(((Real_t*)(nodes[0]->cache))->value);
}

///Sin
void sin_real(Node** nodes, void* ptr){
	*((double*)ptr)= std::sin(((Real_t*)(nodes[0]->cache))->value);
}

///Cos
void cos_real(Node** nodes, void* ptr){
	*((double*)ptr)= std::cos(((Real_t*)(nodes[0]->cache))->value);
}

///Min
void min_real(Node** nodes, void* ptr){
	*((double*)ptr)= std::min(((Real_t*)(nodes[0]->cache))->value,((Real_t*)(nodes[1]->cache))->value);
}

///Max
void max_real(Node** nodes, void* ptr){
	*((double*)ptr)= std::max(((Real_t*)(nodes[0]->cache))->value,((Real_t*)(nodes[1]->cache))->value);
}

///Pow
void pow_real(Node** nodes, void* ptr){
	*((double*)ptr)= std::pow(((Real_t*)(nodes[0]->cache))->value,((Real_t*)(nodes[1]->cache))->value);
}

///Log
void log_real(Node** nodes, void* ptr){
	*((double*)ptr)= std::log(((Real_t*)(nodes[0]->cache))->value);
}
