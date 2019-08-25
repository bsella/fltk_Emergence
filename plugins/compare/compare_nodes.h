#include <core/node.h>

class Compare_Node : public Node{
public:
	Compare_Node();
	virtual ~Compare_Node();
protected:
	void (*update_func)(Node**, void*);
	virtual void compile(std::vector<Node*>&)=0;
	void update_cache()override;
};

class GT_Node : public Compare_Node{
public:
	static Node* make(void*);
private:
	void compile(std::vector<Node*>&)override;
};

class LT_Node : public Compare_Node{
public:
	static Node* make(void*);
private:
	void compile(std::vector<Node*>&)override;
};

class EQ_Node : public Compare_Node{
public:
	static Node* make(void*);
private:
	void compile(std::vector<Node*>&)override;
};

class NE_Node : public Compare_Node{
public:
	static Node* make(void*);
private:
	void compile(std::vector<Node*>&)override;
};
