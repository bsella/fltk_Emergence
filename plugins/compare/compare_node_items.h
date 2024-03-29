#include "compare_nodes.h"
#include <gui/node_item.h>
#include <FL/Fl_PNG_Image.H>

class Compare_Node_Item : public Node_Item{
public:
	Compare_Node_Item(Fl_PNG_Image*, Node*);
protected:
	Fl_PNG_Image* icon;
	Fl_Color color()const override;
	void draw_body()const override;
};

class GT_Node_Item : public Compare_Node_Item{
public:
	GT_Node_Item();
	static Node_Item* make(std::istream*);
	static Fl_PNG_Image icon;
};

class LT_Node_Item : public Compare_Node_Item{
public:
	LT_Node_Item();
	static Node_Item* make(std::istream*);
	static Fl_PNG_Image icon;
};

class EQ_Node_Item : public Compare_Node_Item{
public:
	EQ_Node_Item();
	static Node_Item* make(std::istream*);
	static Fl_PNG_Image icon;
};

class NE_Node_Item : public Compare_Node_Item{
public:
	NE_Node_Item();
	static Node_Item* make(std::istream*);
	static Fl_PNG_Image icon;
};
