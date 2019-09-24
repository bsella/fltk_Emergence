#pragma once
#include <gui/node_item.h>
#include <FL/Fl.H>

class HSV_Node_Item : public Node_Item{
public:
	HSV_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
protected:
	Fl_Color color()const override;
	void draw_body()const override;
};

class Node;
class HSV_Base_Node_Item : public Node_Item{
public:
	HSV_Base_Node_Item(int,int, const char*, Node*);
private:
	const char* text;
	Fl_Color color()const override;
	void draw_body()const override;
};

class Hue_Node_Item : public HSV_Base_Node_Item{
public:
	Hue_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
};

class Saturation_Node_Item : public HSV_Base_Node_Item{
public:
	Saturation_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
};

class Value_Node_Item : public HSV_Base_Node_Item{
public:
	Value_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
};
