#include "color_t.h"
#include <core/type_manager.h>

Color_t::Color_t(unsigned color): Data_t(get_type_id("color")){
	r= (color>>24) /255.0f;
	g= (color>>16 & 0x000ff00) /255.0f;
	b= (color>>8  & 0x00000ff) /255.0f;
}
Color_t::Color_t(float r, float g, float b): Data_t(get_type_id("color")){
	this->r= r;
	this->g= g;
	this->b= b;
}

void to_color(Node** nodes, void* ptr){
	const unsigned char temp_r = ((Color_t*)nodes[0]->cache)->r*255;
	const unsigned char temp_g = ((Color_t*)nodes[0]->cache)->g*255;
	const unsigned char temp_b = ((Color_t*)nodes[0]->cache)->b*255;
	*((unsigned*)ptr)= (((((0xff<<8) | temp_b) << 8) | temp_g) << 8) | temp_r;
}
