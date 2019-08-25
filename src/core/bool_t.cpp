#include "bool_t.h"

Bool_t::Bool_t(bool b){
	value= b;
}
unsigned Bool_t::to_color()const{
	return value? 0xffffffff : 0x00000000;
}
