#include <core/node.h>
#include <gui/node_item.h>

class X_Node : public Node{
public:
   	X_Node();
	static Node* make(void*);
private:
	//void kernel()const override;
};

class Y_Node : public Node{
public:
   	Y_Node();
	static Node* make(void*);
private:
	//void kernel()const override;
};

class Ratio_Node : public Node{
public:
   	Ratio_Node();
	static Node* make(void*);
private:
	//void kernel()const override;
};

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
