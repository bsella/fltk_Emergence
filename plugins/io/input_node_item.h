#include <gui/node_item.h>
#include "input_node.h"
#include <FL/Fl_PNG_Image.H>

class X_Node_Item : public Node_Item{
public:
   	X_Node_Item();
	static Node_Item* make(std::istream*);
	static Fl_PNG_Image icon;
private:
	void draw_body()const override;
};

class Y_Node_Item : public Node_Item{
public:
   	Y_Node_Item();
	static Node_Item* make(std::istream*);
	static Fl_PNG_Image icon;
private:
	void draw_body()const override;
};

class Ratio_Node_Item : public Node_Item{
public:
   	Ratio_Node_Item();
	static Node_Item* make(std::istream*);
private:
	void draw_body()const override;
};
