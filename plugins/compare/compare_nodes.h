#include <core/node.h>

class Compare_Node : public Node{
public:
	Compare_Node();
	virtual ~Compare_Node();
protected:
	virtual void update_types()=0;
};

class GT_Node : public Compare_Node{
public:
	static Node* make(void*);
private:
	void update_types()override;
};

class LT_Node : public Compare_Node{
public:
	static Node* make(void*);
private:
	void update_types()override;
};

class EQ_Node : public Compare_Node{
public:
	static Node* make(void*);
private:
	void update_types()override;
};

class NE_Node : public Compare_Node{
public:
	static Node* make(void*);
private:
	void update_types()override;
};
