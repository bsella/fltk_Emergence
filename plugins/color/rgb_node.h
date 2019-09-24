#pragma once
#include <core/node.h>

class RGB_Node : public Node{
public:
   	RGB_Node();
   	~RGB_Node();
	static Node* make(void*);
	static void rgb(Node**, void*);
private:
	void update_types()override;
};

