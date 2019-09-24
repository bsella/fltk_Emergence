#include "rgb_nodes.h"
#include <color/color_t.h>
#include <real/real_t.h>
#include <core/type_manager.h>

RGB_Node::RGB_Node(): Node(3){
	cache= new Color_t;
}
RGB_Node::~RGB_Node(){
	delete cache;
}

Red_Node::Red_Node(): Node(1){
	cache= new Real_t;
}
Green_Node::Green_Node(): Node(1){
	cache= new Real_t;
}
Blue_Node::Blue_Node(): Node(1){
	cache= new Real_t;
}
Alpha_Node::Alpha_Node(): Node(1){
	cache= new Real_t;
}

Red_Node::~Red_Node(){
	delete cache;
}
Green_Node::~Green_Node(){
	delete cache;
}
Blue_Node::~Blue_Node(){
	delete cache;
}
Alpha_Node::~Alpha_Node(){
	delete cache;
}

Node* RGB_Node::make(void*){return new RGB_Node;}
Node* Red_Node::make(void*){return new Red_Node;}
Node* Green_Node::make(void*){return new Green_Node;}
Node* Blue_Node::make(void*){return new Blue_Node;}
Node* Alpha_Node::make(void*){return new Alpha_Node;}

void RGB_Node::update_types(){
	main_func= get_func("rgb", {inodes[0]->cache->id,inodes[1]->cache->id,inodes[2]->cache->id});
	if(!main_func) main_func= &Color_t::rand;
}
void Red_Node::update_types(){
	main_func= get_func("red", {inodes[0]->cache->id});
	if(!main_func) main_func= &Real_t::rand;
}
void Green_Node::update_types(){
	main_func= get_func("green", {inodes[0]->cache->id});
	if(!main_func) main_func= &Real_t::rand;
}
void Blue_Node::update_types(){
	main_func= get_func("blue", {inodes[0]->cache->id});
	if(!main_func) main_func= &Real_t::rand;
}
void Alpha_Node::update_types(){
	main_func= get_func("alpha", {inodes[0]->cache->id});
	if(!main_func) main_func= &Real_t::rand;
}

void RGB_Node::rgb(Node** nodes, void* ptr){
	Color_t* color_ptr= (Color_t*)ptr;
	color_ptr->r= ((Real_t*)nodes[0]->cache)->value;
	color_ptr->g= ((Real_t*)nodes[1]->cache)->value;
	color_ptr->b= ((Real_t*)nodes[2]->cache)->value;
}
void Red_Node::red(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= ((Color_t*)nodes[0]->cache)->r;
}
void Green_Node::green(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= ((Color_t*)nodes[0]->cache)->g;
}
void Blue_Node::blue(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= ((Color_t*)nodes[0]->cache)->b;
}
void Alpha_Node::alpha(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= ((Color_t*)nodes[0]->cache)->a;
}
