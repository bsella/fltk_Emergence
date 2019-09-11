#include "bool_t.h"
#include <core/type_manager.h>

Bool_t::Bool_t(bool b): Data_t(get_type_id("bool")){
	value= b;
}
unsigned Bool_t::to_color()const{
	return value? 0xffffffff : 0x00000000;
}
