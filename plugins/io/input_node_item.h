#include <gui/node_item.h>

class X_Node_Item : public Node_Item{
public:
   	X_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
private:
	void draw_body()const override;
};

class Y_Node_Item : public Node_Item{
public:
   	Y_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
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
