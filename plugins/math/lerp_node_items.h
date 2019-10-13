#pragma once
#include <gui/node_item.h>
#include <FL/fl_draw.H>
class Lerp_Base_Node;

class Lerp_Base_Node_Item : public Node_Item{
public:
	Lerp_Base_Node_Item(Lerp_Base_Node*);
protected:
	virtual void draw_body()const override;
private:
	Fl_Color color()const override;
};

class Lerp_Node_Item : public Lerp_Base_Node_Item{
public:
	Lerp_Node_Item();
	static Node_Item* make(std::istream*);
private:
	void draw_body()const override;
};

class Clamp_Node_Item : public Lerp_Base_Node_Item{
public:
	Clamp_Node_Item();
	static Node_Item* make(std::istream*);
private:
	void draw_body()const override;
};
