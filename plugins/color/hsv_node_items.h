#pragma once
#include <gui/node_item.h>
#include <FL/Fl.H>

class HSV_Node_Item : public Node_Item{
public:
	HSV_Node_Item();
	static Node_Item* make(std::istream*);
protected:
	Fl_Color color()const override;
	void draw_body()const override;
};

class Node;
class HSV_Base_Node_Item : public Node_Item{
public:
	HSV_Base_Node_Item(const char*, Node*);
private:
	const char* text;
	Fl_Color color()const override;
	void draw_body()const override;
};

class Hue_Node_Item : public HSV_Base_Node_Item{
public:
	Hue_Node_Item();
	static Node_Item* make(std::istream*);
};

class Saturation_Node_Item : public HSV_Base_Node_Item{
public:
	Saturation_Node_Item();
	static Node_Item* make(std::istream*);
};

class Value_Node_Item : public HSV_Base_Node_Item{
public:
	Value_Node_Item();
	static Node_Item* make(std::istream*);
};
