#pragma once
#include <core/node.h>
#include <real/real_t.h>

extern Real_t* input_x;
extern Real_t* input_y;
extern Real_t* input_ratio;

class X_Node : public Node{
public:
   	X_Node();
	static Node* make(std::istream*);
private:
	void execute()override;
	void compile_specific(std::vector<Node*>&, bool) override;
	inline const char* id()const override;
};

class Y_Node : public Node{
public:
   	Y_Node();
	static Node* make(std::istream*);
private:
	void execute()override;
	void compile_specific(std::vector<Node*>&, bool) override;
	inline const char* id()const override;
};

class Ratio_Node : public Node{
public:
   	Ratio_Node();
	static Node* make(std::istream*);
private:
	void execute()override;
	void compile_specific(std::vector<Node*>&, bool) override;
	inline const char* id()const override;
};
