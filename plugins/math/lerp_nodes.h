#pragma once
#include <core/node.h>
#include <real/real_t.h>
#include <color/color_t.h>

class Lerp_Base_Node : public Node{
public:
	Lerp_Base_Node();
	Real_t real_cache;
	Color_t color_cache;
protected:
	void init_cache();
};

class Lerp_Node : public Lerp_Base_Node{
public:
	static Node* make(void*);
	static void real(Node**, void*);
	static void color(Node**, void*);
private:
	void update_types()override;
};

class Clamp_Node : public Lerp_Base_Node{
public:
	static Node* make(void*);
	static void real(Node**, void*);
	static void color(Node**, void*);
private:
	void update_types()override;
};
