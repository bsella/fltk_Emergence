#pragma once
#include <core/node.h>

class Lerp_Node : public Node{
public:
	Lerp_Node();
	static Node* make(void*);
private:
	void update_types()override;
};

class Clamp_Node : public Node{
public:
	Clamp_Node();
	static Node* make(void*);
private:
	void update_types()override;
};
