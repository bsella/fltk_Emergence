#include "bool_t.h"

Bool_t::Bool_t(bool b): Data_t(bool_t_id){
	value= b;
}
unsigned Bool_t::to_color()const{
	return value? 0xffffffff : 0x000000ff;
}
