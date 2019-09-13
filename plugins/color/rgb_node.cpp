#include "rgb_node.h"
#include <color/color_t.h>
#include <real/real_t.h>

RGB_Node::RGB_Node(): Node(3){
	cache= new Color_t;
}
RGB_Node::~RGB_Node(){
	delete cache;
}

Node* RGB_Node::make(void*){
	return new RGB_Node;
}

void RGB_Node::update_types(){
	update_func= get_func("rgb", {inodes[0]->cache->id,inodes[1]->cache->id,inodes[2]->cache->id});
	if(!update_func)
		update_func= &Color_t::rand;
}
void RGB_Node::update_cache(){
	update_func(inodes.data(), cache);
}

void rgb_to_color_t(Node** nodes, void* ptr){
	Color_t* color_ptr= (Color_t*)ptr;
	color_ptr->r= ((Real_t*)nodes[0]->cache)->value;
	color_ptr->g= ((Real_t*)nodes[1]->cache)->value;
	color_ptr->b= ((Real_t*)nodes[2]->cache)->value;
}
