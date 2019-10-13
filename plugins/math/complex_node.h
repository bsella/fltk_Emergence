#pragma once
#include <core/node.h>

class Complex_Node : public Node{
public:
	Complex_Node();
	~Complex_Node()override;
	Node* make(std::istream*);
	static void cplx(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};
