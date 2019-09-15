#include "func_def.h"
#include <bool/bool_t.h>

void and_bool(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= ((Bool_t*)nodes[0]->cache)->value && ((Bool_t*)nodes[1]->cache)->value;
}
void or_bool(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= ((Bool_t*)nodes[0]->cache)->value || ((Bool_t*)nodes[1]->cache)->value;
}
void xor_bool(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= ((Bool_t*)nodes[0]->cache)->value ^ ((Bool_t*)nodes[1]->cache)->value;
}
void not_bool(Node** nodes, void* ptr){
	((Bool_t*)ptr)->value= !((Bool_t*)nodes[0]->cache)->value;
}
