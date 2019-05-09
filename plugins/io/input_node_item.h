#pragma once
#include <gui/node_item.h>
#include "../plugins/nodes/io/input_node.h"

class X_Node_Item : public X_Node, public Node_Item{
public:
	X_Node_Item();
	void draw_body()const override;
}

class Y_Node_Item : public Y_Node, public Node_Item{
public:
	Y_Node_Item();
	void draw_body()const override;
}
