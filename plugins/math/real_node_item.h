#pragma once
#include <gui/node_item.h>

class Real_Node_Item : public Node_Item{
public:
	Real_Node_Item(int, int, void*);
	static Node_Item* make(int,int,void*);
protected:
	void draw_body()const override;
	bool settle()override;
};

