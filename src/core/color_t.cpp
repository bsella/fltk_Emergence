#include "color_t.h"

Color_t::Color_t(unsigned color){
	r= (color>>24) /255.0f;
	g= (color>>16 & 0x000ff00) /255.0f;
	b= (color>>8  & 0x00000ff) /255.0f;
}
Color_t::Color_t(float r, float g, float b){
	this->r= r;
	this->g= g;
	this->b= b;
}
unsigned Color_t::to_color()const{
	const unsigned char temp_r = r*255;
	const unsigned char temp_g = g*255;
	const unsigned char temp_b = b*255;
	return (((((0xff<<8) | temp_b) << 8) | temp_g) << 8) | temp_r;
}
