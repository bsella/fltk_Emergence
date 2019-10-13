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

const char* HSV_Node::id()const{return "hsv";}
const char* Hue_Node::id()const{return "hue";}
const char* Saturation_Node::id()const{return "saturation";}
const char* Value_Node::id()const{return "value";}

Node* HSV_Node::make(std::istream*){return new HSV_Node;}
Node* Hue_Node::make(std::istream*){return new Hue_Node;}
Node* Saturation_Node::make(std::istream*){return new Saturation_Node;}
Node* Value_Node::make(std::istream*){return new Value_Node;}

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

#define R static_cast<Color_t*>(ptr)->r
#define G static_cast<Color_t*>(ptr)->g
#define B static_cast<Color_t*>(ptr)->b
#define H (static_cast<Real_t*>(nodes[0]->cache)->value*6)
#define S static_cast<Real_t*>(nodes[1]->cache)->value
#define V static_cast<Real_t*>(nodes[2]->cache)->value
void HSV_Node::hsv(Node** nodes, void* ptr){
	static double f, p1, p2, p3;
	static int i;
    if (S < 5.0e-6)
        R = G = B = V;
	else{
        i = int(H);
        f = H - double(i);
        p1 = V*(1.0-S);
        p2 = V*(1.0-S*f);
        p3 = V*(1.0-S*(1.0-f));
		switch (i) {
        case 0: R =  V;  G = p3;  B = p1;  break;
        case 1: R = p2;  G =  V;  B = p1;  break;
        case 2: R = p1;  G =  V;  B = p3;  break;
        case 3: R = p1;  G = p2;  B =  V;  break;
        case 4: R = p3;  G = p1;  B =  V;  break;
        case 5: R =  V;  G = p1;  B = p2;  break;
		}
	}
}

#define RR static_cast<Color_t*>(nodes[0]->cache)->r
#define GG static_cast<Color_t*>(nodes[0]->cache)->g
#define BB static_cast<Color_t*>(nodes[0]->cache)->b
static double maxx, minn;
void Hue_Node::hue(Node** nodes, void* ptr){
    maxx= std::max(std::max(RR, GG), BB);
    minn= std::min(std::min(RR, GG), BB);
    if(maxx == RR){
        static_cast<Real_t*>(ptr)->value= (GG-BB)/(maxx-minn);
		if(static_cast<Real_t*>(ptr)->value<0)
			static_cast<Real_t*>(ptr)->value += 6;
    }else if(maxx == GG)
        static_cast<Real_t*>(ptr)->value= 2+(BB-RR)/(maxx-minn);
	else
        static_cast<Real_t*>(ptr)->value= 4+(RR-GG)/(maxx-minn);
	static_cast<Real_t*>(ptr)->value/= 6;
}
void Saturation_Node::saturation(Node** nodes, void* ptr){
    maxx= std::max(std::max(RR, GG), BB);
    static_cast<Real_t*>(ptr)->value= 1 - std::min(std::min(RR, GG), BB)/maxx;
}
void Value_Node::value(Node** nodes, void* ptr){
    static_cast<Real_t*>(ptr)->value= std::max(std::max(RR, GG), BB);
}
