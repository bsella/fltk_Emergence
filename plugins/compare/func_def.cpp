#include "func_def.h"
#include <core/real_t.h>

///REAL
void gt_compare_real(Node** nodes, void* ret){
	*((bool*)ret)= ((Real_t*)nodes[0]->cache)->value > ((Real_t*)nodes[1]->cache)->value;
}
void lt_compare_real(Node** nodes, void* ret){
	*((bool*)ret)= ((Real_t*)nodes[0]->cache)->value < ((Real_t*)nodes[1]->cache)->value;
}
void eq_compare_real(Node** nodes, void* ret){
	*((bool*)ret)= ((Real_t*)nodes[0]->cache)->value == ((Real_t*)nodes[1]->cache)->value;
}
void ne_compare_real(Node** nodes, void* ret){
	*((bool*)ret)= ((Real_t*)nodes[0]->cache)->value != ((Real_t*)nodes[1]->cache)->value;
}
