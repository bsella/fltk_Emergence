#pragma once
#include <gui/node_item.h>
#include <FL/fl_draw.H>
class Lerp_Base_Node;

class Lerp_Base_Node_Item : public Node_Item{
public:
	Lerp_Base_Node_Item(int, int, Lerp_Base_Node*);
protected:
	virtual void draw_body()const override;
private:
	Fl_Color color()const override;
};

class Lerp_Node_Item : public Lerp_Base_Node_Item{
public:
	Lerp_Node_Item(int, int);
	static Node_Item* make(int, int, void*);
private:
	void draw_body()const override;
};

class Clamp_Node_Item : public Lerp_Base_Node_Item{
public:
	Clamp_Node_Item(int, int);
	static Node_Item* make(int, int, void*);
private:
	void draw_body()const override;
};
