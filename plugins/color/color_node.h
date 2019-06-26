#pragma once
#include <core/node.h>

class Color_Node : public Node{
public:
   	Color_Node();
   	~Color_Node();
	static Node* make(void*);
private:
	void update_cache()override;
};
