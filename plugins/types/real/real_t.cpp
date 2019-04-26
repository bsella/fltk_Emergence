#include "real_t.h"

Real_t::Real_t(double d):cache(d){}

int Real_t::to_color()const{
	if(cache>=1) return 0xffffffff;
	if(cache<=0) return 0xff000000;
	const unsigned char gray = 0xff*cache;
	return (((((0xff << 8) | gray) << 8) | gray) << 8) | gray;
}

template<>
Real_t::operator bool()const{
	return cache==0;
}
