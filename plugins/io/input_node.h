#include <core/node.h>

class X_Node : public Node{
public:
   	X_Node();
	static Node* make(void*);
private:
	void kernel()override;
};

class Y_Node : public Node{
public:
   	Y_Node();
	static Node* make(void*);
private:
	void kernel()override;
};

class Ratio_Node : public Node{
public:
   	Ratio_Node();
	static Node* make(void*);
private:
	void kernel()override;
};
