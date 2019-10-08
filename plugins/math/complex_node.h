#pragma once
#include <core/node.h>

class Complex_Node : public Node{
public:
	Complex_Node();
	~Complex_Node()override;
	Node* make(void*);
	static void cplx(Node**, void*);
private:
	void update_types()override;
};
