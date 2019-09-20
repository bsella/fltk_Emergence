#include "color_t.h"
#include <core/type_manager.h>
#include <stdlib.h>

Color_t::Color_t(unsigned color): Data_t(get_type_id("color")){
	r= (color>>24 & 0xff) /255.0f;
	g= (color>>16 & 0xff) /255.0f;
	b= (color>>8  & 0xff) /255.0f;
	a= (color>>0  & 0xff) /255.0f;
}
Color_t::Color_t(float r, float g, float b, float a): Data_t(get_type_id("color")){
	this->r= r;
	this->g= g;
	this->b= b;
	this->a= a;
}
Color_t::Color_t(float r, float g, float b): Color_t(r,g,b,1){}
Color_t::Color_t(): Color_t(0,0,0,0){}

double Color_t::to_real()const{
	return (r + g + b)/3 * a;
}

void Color_t::rand(Node**, void* ptr){
	Color_t* cptr= (Color_t*)ptr;
	cptr->r= (double)::rand() / RAND_MAX;
	cptr->g= (double)::rand() / RAND_MAX;
	cptr->b= (double)::rand() / RAND_MAX;
	cptr->a= (double)::rand() / RAND_MAX;
}

#define r0 ((Color_t*)(nodes[0]->cache))->r
#define g0 ((Color_t*)(nodes[0]->cache))->g
#define b0 ((Color_t*)(nodes[0]->cache))->b
#define a0 ((Color_t*)(nodes[0]->cache))->a

void Color_t::to_color(Node** nodes, void* ptr){
	const unsigned char temp_r = r0>1? 255: r0*255;
	const unsigned char temp_g = g0>1? 255: g0*255;
	const unsigned char temp_b = b0>1? 255: b0*255;
	const unsigned char temp_a = a0>1? 255: a0*255;
	*((unsigned*)ptr)= (((((temp_a << 8) | temp_b) << 8) | temp_g) << 8) | temp_r;
}
