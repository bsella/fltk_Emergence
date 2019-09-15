#pragma once
#include <core/node.h>

class RGB_Node : public Node{
public:
   	RGB_Node();
   	~RGB_Node();
	static Node* make(void*);
private:
	void update_types()override;
};

void rgb_to_color_t(Node**, void*);
