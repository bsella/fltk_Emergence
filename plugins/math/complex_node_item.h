#pragma once
#include <gui/node_item.h>
#include <FL/Fl_PNG_Image.H>

class Complex_Node_Item : public Node_Item{
public:
	Complex_Node_Item();
	static Fl_PNG_Image icon;
	static Node_Item* make(std::istream*);
private:
	Fl_Color color()const override;
	void draw_body()const override;
};
