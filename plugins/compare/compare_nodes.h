#include <core/node.h>

class GT_Node : public Node{
public:
	GT_Node();
	~GT_Node()override;
	static Node* make(void*);
private:
	void update_cache()override;
};

class LT_Node : public Node{
public:
	LT_Node();
	~LT_Node()override;
	static Node* make(void*);
private:
	void update_cache()override;
};

class EQ_Node : public Node{
public:
	EQ_Node();
	~EQ_Node()override;
	static Node* make(void*);
private:
	void update_cache()override;
};

class NE_Node : public Node{
public:
	NE_Node();
	~NE_Node()override;
	static Node* make(void*);
private:
	void update_cache()override;
};
