#pragma once
#include <gui/node_item.h>

class Gradient_Node_Item : public Node_Item{
public:
	Gradient_Node_Item(int, int);
    ~Gradient_Node_Item()override;
	static Node_Item* make(int,int,void*);
private:
	std::vector<unsigned int> draw_buffer;
	void draw_body()const override;
	void scale(double)override;
	void update_draw_buffer();
};
