#include "hsv_nodes.h"
#include <real/real_t.h>
#include <color/color_t.h>
#include <core/type_manager.h>

HSV_Node::HSV_Node(): Node(3){
	cache= new Color_t(0,0,0,1);
}
Hue_Node::Hue_Node(): Node(1){
	cache= new Real_t;
}
Saturation_Node::Saturation_Node(): Node(1){
	cache= new Real_t;
}
Value_Node::Value_Node(): Node(1){
	cache= new Real_t;
}

HSV_Node::~HSV_Node(){
	delete cache;
}
Hue_Node::~Hue_Node(){
	delete cache;
}
Saturation_Node::~Saturation_Node(){
	delete cache;
}
Value_Node::~Value_Node(){
	delete cache;
}

Node* HSV_Node::make(void*){return new HSV_Node;}
Node* Hue_Node::make(void*){return new Hue_Node;}
Node* Saturation_Node::make(void*){return new Saturation_Node;}
Node* Value_Node::make(void*){return new Value_Node;}

void HSV_Node::update_types(){
	main_func= get_func("hsv", {inodes[0]->cache->id, inodes[1]->cache->id, inodes[2]->cache->id});
	if(!main_func) main_func= &Color_t::rand;
}
void Hue_Node::update_types(){
	main_func= get_func("hue", {inodes[0]->cache->id});
	if(!main_func) main_func= &Real_t::rand;
}
void Saturation_Node::update_types(){
	main_func= get_func("saturation", {inodes[0]->cache->id});
	if(!main_func) main_func= &Real_t::rand;
}
void Value_Node::update_types(){
	main_func= get_func("value", {inodes[0]->cache->id});
	if(!main_func) main_func= &Real_t::rand;
}

#define _R ((Color_t*)ptr)->r
#define _G ((Color_t*)ptr)->g
#define _B ((Color_t*)ptr)->b
#define _H (((Real_t*)nodes[0]->cache)->value*6)
#define _S ((Real_t*)nodes[1]->cache)->value
#define _V ((Real_t*)nodes[2]->cache)->value
void HSV_Node::hsv(Node** nodes, void* ptr){
	static double f, p1, p2, p3;
	static int i;
	if (_S < 5.0e-6)
		_R = _G = _B = _V;
	else{
		i = (int)_H;  
		f = _H - (float)i;
		p1 = _V*(1.0-_S);
		p2 = _V*(1.0-_S*f);
		p3 = _V*(1.0-_S*(1.0-f));
		switch (i) {
		case 0: _R = _V;  _G = p3;  _B = p1;  break;
		case 1: _R = p2;  _G = _V;  _B = p1;  break;
		case 2: _R = p1;  _G = _V;  _B = p3;  break;
		case 3: _R = p1;  _G = p2;  _B = _V;  break;
		case 4: _R = p3;  _G = p1;  _B = _V;  break;
		case 5: _R = _V;  _G = p1;  _B = p2;  break;
		}
	}
}

#define R ((Color_t*)nodes[0]->cache)->r
#define G ((Color_t*)nodes[0]->cache)->g
#define B ((Color_t*)nodes[0]->cache)->b
static double maxx, minn;
void Hue_Node::hue(Node** nodes, void* ptr){
	maxx= std::max(std::max(R, G), B);
	minn= std::min(std::min(R, G), B);
	if(maxx == R){
		((Real_t*)ptr)->value= (G-B)/(maxx-minn);
		if(((Real_t*)ptr)->value<0)
			((Real_t*)ptr)->value += 6;
	}else if(maxx == G)
		((Real_t*)ptr)->value= 2+(B-R)/(maxx-minn);
	else
		((Real_t*)ptr)->value= 4+(R-G)/(maxx-minn);
	((Real_t*)ptr)->value/= 6;
}
void Saturation_Node::saturation(Node** nodes, void* ptr){
	maxx= std::max(std::max(R, G), B);
	((Real_t*)ptr)->value= 1 - std::min(std::min(R, G), B)/maxx;
}
void Value_Node::value(Node** nodes, void* ptr){
	((Real_t*)ptr)->value= std::max(std::max(R, G), B);
}
