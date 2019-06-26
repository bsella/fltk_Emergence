#include "real_t.h"

Real_t::Real_t(double d){
	value= d;
}
unsigned Real_t::to_color()const{
	if(value>=1) return 0xffffffff;
	if(value<=0) return 0x000000ff;
	const unsigned char c= value*0xff;
	return (((((c<<8) | c) << 8) | c) << 8) | 0xff;
}
Real_t::operator bool()const{return value!=0.0;}
Real_t::operator unsigned()const{
	return to_color();
}
