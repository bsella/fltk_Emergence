#pragma once
#include <gui/node_item.h>

class Color_Node_Item : public Node_Item{
public:
	Color_Node_Item(std::istream*);
	static Node_Item* make(std::istream*);
private:
	unsigned int color()const override;
	void draw_body()const override;
	bool settle()override;
	void context_menu(std::vector<Fl_Menu_Item>& menu)override;
};
