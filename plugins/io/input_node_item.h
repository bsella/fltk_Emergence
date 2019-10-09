#include <gui/node_item.h>
#include "input_node.h"
#include <FL/Fl_PNG_Image.H>

class X_Node_Item : public Node_Item{
public:
   	X_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
	static Fl_PNG_Image icon;
private:
	void draw_body()const override;
};

class Y_Node_Item : public Node_Item{
public:
   	Y_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
	static Fl_PNG_Image icon;
private:
	void draw_body()const override;
};

class Ratio_Node_Item : public Node_Item{
public:
   	Ratio_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
private:
	void draw_body()const override;
};
