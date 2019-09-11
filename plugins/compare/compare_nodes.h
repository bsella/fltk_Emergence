#include <core/node.h>

class Compare_Node : public Node{
public:
	Compare_Node();
	virtual ~Compare_Node();
protected:
	void (*update_func)(Node**, void*);
	virtual void update_types()=0;
	void update_cache()override;
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
