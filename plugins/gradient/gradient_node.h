#pragma once
#include <core/node.h>
class Gradient;

class Gradient_Node : public Node{
public:
	Gradient_Node(Gradient* grad= nullptr);
    ~Gradient_Node()override;
	static Node* make(void*);
	static void get_color(Node**, void*);
	Gradient* gradient;
private:
	Node* hack;
	void update_types()override;
	void update_cache()override;
};
