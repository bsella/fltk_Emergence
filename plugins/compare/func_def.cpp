#include "func_def.h"
#include <real/real_t.h>
#include <bool/bool_t.h>

///REAL
void gt_compare_real(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= ((Real_t*)nodes[0]->cache)->value > ((Real_t*)nodes[1]->cache)->value;
}
void lt_compare_real(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= ((Real_t*)nodes[0]->cache)->value < ((Real_t*)nodes[1]->cache)->value;
}
void eq_compare_real(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= ((Real_t*)nodes[0]->cache)->value == ((Real_t*)nodes[1]->cache)->value;
}
void ne_compare_real(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= ((Real_t*)nodes[0]->cache)->value != ((Real_t*)nodes[1]->cache)->value;
}
