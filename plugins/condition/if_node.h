#include <core/node.h>
#include <gui/node_item.h>

class If_Node : public Node{
public:
   	If_Node();
	static Node* make(void*);
private:
	//void kernel()const override;
};

class If_Node_Item : public Node_Item{
public:
   	If_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
private:
	void draw_body()const override;
	Fl_Color color()const override;
};
