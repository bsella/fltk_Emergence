#pragma once
#include <gui/node_item.h>
#include <FL/Fl.H>

class RGB_Node_Item : public Node_Item{
public:
	RGB_Node_Item();
	static Node_Item* make(std::istream*);
private:
	Fl_Color color()const override;
	void draw_body()const override;
};

class Red_Node_Item : public Node_Item{
public:
	Red_Node_Item();
	static Node_Item* make(std::istream*);
private:
	void draw_body()const override;
};

class Green_Node_Item : public Node_Item{
public:
	Green_Node_Item();
	static Node_Item* make(std::istream*);
private:
	void draw_body()const override;
};

class Blue_Node_Item : public Node_Item{
public:
	Blue_Node_Item();
	static Node_Item* make(std::istream*);
private:
	void draw_body()const override;
};

class Alpha_Node_Item : public Node_Item{
public:
	Alpha_Node_Item();
	static Node_Item* make(std::istream*);
private:
	void draw_body()const override;
};
