#pragma once
#include <core/node.h>
#include <real/real_t.h>
#include <color/color_t.h>

class Lerp_Node : public Node{
public:
	Lerp_Node();
	static Node* make(void*);
	Real_t real_cache;
	Color_t color_cache;
	static void real(Node**, void*);
	static void color(Node**, void*);
private:
	void update_types()override;
};

class Clamp_Node : public Node{
public:
	Clamp_Node();
	~Clamp_Node()override;
	static Node* make(void*);
	static void real(Node**, void*);
private:
	void update_types()override;
};
