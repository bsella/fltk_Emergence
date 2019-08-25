#include "real_t.h"

Real_t::Real_t(double d){
	value= d;
}
unsigned Real_t::to_color()const{
	if(value>=1) return 0xffffffff;
	if(value<=0) return 0xff000000;
	const unsigned char c= value*0xff;
	return (((((0xff<<8) | c) << 8) | c) << 8) | c;
}
