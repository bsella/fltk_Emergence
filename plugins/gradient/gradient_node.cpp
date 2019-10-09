#include "gradient_node.h"
#include "gradient.h"
#include <real/real_t.h>
#include <color/color_t.h>
#include <core/type_manager.h>

Gradient_Node::Gradient_Node(Gradient* grad): Node(1){
	if(!grad) gradient= new Gradient;
	else gradient= grad;
	cache= new Color_t;
	hack= this;
	gradient->add_color(0xff0000ff, .25);
	gradient->add_color(0xff00ff00, .5);
	gradient->add_color(0xffff0000, .75);
}
Gradient_Node::~Gradient_Node(){
	delete cache;
	delete gradient;
}

Node* Gradient_Node::make(void* ptr){return new Gradient_Node(static_cast<Gradient*>(ptr));}

void Gradient_Node::get_color(Node** nodes, void* ptr){
    Gradient_Node* _this= static_cast<Gradient_Node*>(nodes[0]);
    _this->gradient->get_color(static_cast<Real_t*>(_this->inodes[0]->cache)->value, (static_cast<Color_t*>(ptr)));
}

void Gradient_Node::update_types(){
	main_func= get_func("grad", {inodes[0]->cache->id});
	if(!main_func) main_func= &Color_t::rand;
}

void Gradient_Node::update_cache(){
	main_func(&hack, cache);
}
