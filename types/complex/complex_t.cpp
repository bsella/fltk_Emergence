#include "complex_t.h"
#include <core/type_manager.h>
#include <core/node.h>

Complex_t::Complex_t(double r, double i): Data_t(get_type_id("complex")){
	value= std::complex(r,i);
}

void Complex_t::rand(Node**, void* ptr){
	((Complex_t*)ptr)->value= std::complex((double)::rand() / RAND_MAX, (double)::rand() / RAND_MAX);
}

void Complex_t::to_color(Node** nodes, void* ptr){
	static double _R, _G, _B;
	static double _V, p2, p3, H, f;
	static unsigned char temp_r, temp_g, temp_b;

	_V= std::abs(((Complex_t*)(nodes[0]->cache))->value);
	H= 6*(std::arg(((Complex_t*)(nodes[0]->cache))->value)+M_PI)/(M_PI*2);
	f= H-int(H);
	p2 = _V*(1.0-f);
	p3 = _V*(1.0-(1.0-f));
	switch (int(H)){
		case 0: _R = _V;  _G = p3;  _B =  0;  break;
		case 1: _R = p2;  _G = _V;  _B =  0;  break;
		case 2: _R =  0;  _G = _V;  _B = p3;  break;
		case 3: _R =  0;  _G = p2;  _B = _V;  break;
		case 4: _R = p3;  _G =  0;  _B = _V;  break;
		case 5: _R = _V;  _G =  0;  _B = p2;  break;
	}

	temp_r = _R>1? 255: _R*255;
	temp_g = _G>1? 255: _G*255;
	temp_b = _B>1? 255: _B*255;
	*((unsigned*)ptr)= (((((0xff << 8) | temp_b) << 8) | temp_g) << 8) | temp_r;
}
