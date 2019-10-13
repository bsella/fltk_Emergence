#pragma once
#include "toolbox_item.h"
#include <istream>

class Node_Item;
typedef Node_Item* (*make_node_item_t)(std::istream*);

class Toolbox_Node_Item : public Toolbox_Item{
public:
	Toolbox_Node_Item(const char* text, make_node_item_t);
	Toolbox_Node_Item(const char* text, Fl_PNG_Image* icon, make_node_item_t);
	Toolbox_Node_Item(const char* text, const char* icon_path, make_node_item_t);
	~Toolbox_Node_Item();
	static make_node_item_t dnd_node_factory;
private:
	make_node_item_t factory;
	const char* text;
	void mouse_drag_event(int,int)override;
};
