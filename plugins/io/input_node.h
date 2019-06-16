#pragma once
#include <core/node.h>
#include <core/real_t.h>

extern Real_t input_x;
extern Real_t input_y;
extern Real_t input_ratio;

class X_Node : public Node{
public:
   	X_Node();
	static Node* make(void*);
private:
	void update_cache()override;
	void prepare_program(std::vector<Node*>&) override;
};

class Y_Node : public Node{
public:
   	Y_Node();
	static Node* make(void*);
private:
	void update_cache()override;
	void prepare_program(std::vector<Node*>&) override;
};

class Ratio_Node : public Node{
public:
   	Ratio_Node();
	static Node* make(void*);
private:
	void update_cache()override;
	void prepare_program(std::vector<Node*>&) override;
};
