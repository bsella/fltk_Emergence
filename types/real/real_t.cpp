#include "real_t.h"
#include <core/type_manager.h>
#include <core/node.h>

Real_t::Real_t(double d): Data_t(get_type_id("real")){
	value= d;
}

void Real_t::rand(Node**, void* ptr){
	((Real_t*)ptr)->value= (float)::rand() / RAND_MAX;
}
void Real_t::to_color(Node** nodes, void* ptr){
	double value=((Real_t*)nodes[0]->cache)->value;
	if(value>=1){
		*((unsigned*)ptr)= 0xffffffff;
		return;
	}
	if(value<=0){
		*((unsigned*)ptr)= 0xff000000;
		return;
	}
	const unsigned char c= value*0xff;
	*((unsigned*)ptr)= (((((0xff<<8) | c) << 8) | c) << 8) | c;
}
void Real_t::to_bool(Node** nodes, void* ptr){
	*((bool*)ptr)=((Real_t*)nodes[0]->cache)->value != 0;
}
