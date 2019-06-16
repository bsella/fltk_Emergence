#include "toolbox_node_item.h"
#include <FL/Fl.H>

Toolbox_Node_Item::Toolbox_Node_Item(const char* text, const char* icon_path, make_node_item_t make)
	: Toolbox_Item(36, text, icon_path), factory(make){
}

Toolbox_Node_Item::~Toolbox_Node_Item(){}

void Toolbox_Node_Item::mouse_drag_event(int, int){
	Node_Item::dnd_node_factory = factory;
 	Fl::dnd();
}
