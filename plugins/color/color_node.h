#pragma once
#include <core/node.h>

class Color_Node : public Node{
public:
   	Color_Node(void*);
    ~Color_Node()override;
	static Node* make(void*);
private:
	void update_cache()override;
};
