#include "bool_t.h"
#include <core/type_manager.h>
#include <core/node.h>

Bool_t::Bool_t(bool b): Data_t(get_type_id("bool")){
	value= b;
}

void to_color(Node** nodes, void* ptr){
	*((unsigned*)ptr)= ((Bool_t*)nodes[0]->cache)->value? 0xffffffff:0xff000000;
}
void to_bool(Node** nodes, void* ptr){
	*((bool*)ptr)=((Bool_t*)nodes[0]->cache)->value;
}
