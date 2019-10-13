#include "toolbox_node_item.h"
#include <FL/Fl.H>

Toolbox_Node_Item::Toolbox_Node_Item(const char* text, make_node_item_t make)
	: Toolbox_Item(36, text), factory(make){
}
Toolbox_Node_Item::Toolbox_Node_Item(const char* text, Fl_PNG_Image* icon, make_node_item_t make)
	: Toolbox_Item(36, text, icon), factory(make){
}
Toolbox_Node_Item::Toolbox_Node_Item(const char* text, const char* icon_path, make_node_item_t make)
	: Toolbox_Item(36, text, icon_path), factory(make){
}

Toolbox_Node_Item::~Toolbox_Node_Item(){}

void Toolbox_Node_Item::mouse_drag_event(int, int){
	dnd_node_factory = factory;
 	Fl::dnd();
}

make_node_item_t Toolbox_Node_Item::dnd_node_factory= nullptr;
