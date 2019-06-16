#pragma once
#include "toolbox_item.h"
#include <gui/node_item.h>

class Toolbox_Node_Item : public Toolbox_Item{
public:
	Toolbox_Node_Item(const char* text, const char* icon_path, make_node_item_t);
	~Toolbox_Node_Item();
private:
	make_node_item_t factory;
	const char* text;
	void mouse_drag_event(int,int)override;
};
