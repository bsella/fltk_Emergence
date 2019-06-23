#include "bool_t.h"

Bool_t::Bool_t(bool b){
	value= b;
}
unsigned Bool_t::to_color()const{
	return value? 0xffffffff : 0x000000ff;
}
Bool_t::operator double()const{return value? 1.0:0.0;}
