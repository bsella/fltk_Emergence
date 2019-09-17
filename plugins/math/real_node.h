#pragma once
#include <core/node.h>

class Real_Node : public Node{
public:
   	Real_Node(void*);
   	~Real_Node();
	static Node* make(void*);
private:
	void update_cache()override;
};
