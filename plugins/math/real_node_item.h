#pragma once
#include <gui/node_item.h>

class Real_Node_Item : public Node_Item{
public:
	Real_Node_Item(std::istream*);
	static Node_Item* make(std::istream*);
private:
	void draw_body()const override;
	bool settle()override;
	void context_menu(std::vector<Fl_Menu_Item>&)override;
};
