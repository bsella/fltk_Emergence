#pragma once
#include <gui/node_item.h>
#include <FL/fl_draw.H>

class Lerp_Node_Item : public Node_Item{
public:
	Lerp_Node_Item(int, int);
	static Node_Item* make(int, int, void*);
private:
	void draw_body()const override;
	Fl_Color color()const override;
};
