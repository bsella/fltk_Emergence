#pragma once
#include <core/node.h>
#include <core/type_manager.h>

class RGB_Node : public Node{
public:
   	RGB_Node();
   	~RGB_Node();
	static Node* make(void*);
private:
	void update_types()override;
	void update_cache()override;
	func_t update_func;
};

void rgb_to_color_t(Node**, void*);
