#include "logic_nodes.h"
#include <gui/node_item.h>
#include <FL/Fl_PNG_Image.H>

class Logic_Node_Item : public Node_Item{
public:
	Logic_Node_Item(int,int, Fl_PNG_Image*, Node*);
protected:
	Fl_PNG_Image* icon;
	Fl_Color color()const override;
	void draw_body()const override;
};

class AND_Node_Item : public Logic_Node_Item{
public:
	AND_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
	static Fl_PNG_Image icon;
};

class OR_Node_Item : public Logic_Node_Item{
public:
	OR_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
	static Fl_PNG_Image icon;
};

class XOR_Node_Item : public Logic_Node_Item{
public:
	XOR_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
	static Fl_PNG_Image icon;
};

class NOT_Node_Item : public Logic_Node_Item{
public:
	NOT_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
	static Fl_PNG_Image icon;
};
