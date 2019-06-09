#pragma once
#include <core/node.h>
#include <core/real_t.h>

extern double input_x;
extern double input_y;
extern double input_ratio;

class X_Node : public Node{
public:
   	X_Node();
   	~X_Node();
	static Node* make(void*);
private:
	void kernel()override;
};

class Y_Node : public Node{
public:
   	Y_Node();
   	~Y_Node();
	static Node* make(void*);
private:
	void kernel()override;
};

class Ratio_Node : public Node{
public:
   	Ratio_Node();
   	~Ratio_Node();
	static Node* make(void*);
private:
	void kernel()override;
};
