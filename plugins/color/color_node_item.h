#pragma once
#include <gui/node_item.h>

class Color_Node_Item : public Node_Item{
public:
	Color_Node_Item(int, int);
	static Node_Item* make(int,int,void*);
protected:
	unsigned int color()const override;
	void draw_body()const override;
	bool settle()override;
};
