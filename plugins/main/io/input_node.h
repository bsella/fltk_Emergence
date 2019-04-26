#include <core/node.h>

class Input_Node : public Node{
public:
	static double input_x, input_y;
protected:
	Input_Node();
};

class X_Node : public Input_Node{
public:
   	X_Node();
private:
	void kernel()const;
}

class Y_Node : public Input_Node{
public:
   	Y_Node();
private:
	void kernel()const;
}
