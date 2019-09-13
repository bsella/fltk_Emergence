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
Color_t::Color_t(): Color_t(1,1,1,1){}

void Color_t::rand(Node**, void* ptr){
	Color_t* cptr= (Color_t*)ptr;
	cptr->r= (float)::rand() / RAND_MAX;
	cptr->g= (float)::rand() / RAND_MAX;
	cptr->b= (float)::rand() / RAND_MAX;
	cptr->a= (float)::rand() / RAND_MAX;
}

void Color_t::to_color(Node** nodes, void* ptr){
	const unsigned char temp_r = ((Color_t*)nodes[0]->cache)->r*255;
	const unsigned char temp_g = ((Color_t*)nodes[0]->cache)->g*255;
	const unsigned char temp_b = ((Color_t*)nodes[0]->cache)->b*255;
	const unsigned char temp_a = ((Color_t*)nodes[0]->cache)->a*255;
	*((unsigned*)ptr)= (((((temp_a << 8) | temp_b) << 8) | temp_g) << 8) | temp_r;
}
