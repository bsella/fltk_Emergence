#include <core/node.h>

class GT_Node : public Node{
public:
	GT_Node();
	~GT_Node()override;
	static Node* make(void*);

	static void real_real(Node**, void*);
	static void real_color(Node**, void*);
	static void color_real(Node**, void*);
	static void color_color(Node**, void*);

private:
	void update_types()override;
	inline const char* id()const override;
};

class LT_Node : public Node{
public:
	LT_Node();
	~LT_Node()override;
	static Node* make(void*);

	static void real_real(Node**, void*);
	static void real_color(Node**, void*);
	static void color_real(Node**, void*);
	static void color_color(Node**, void*);

private:
	void update_types()override;
	inline const char* id()const override;
};

class EQ_Node : public Node{
public:
	EQ_Node();
	~EQ_Node()override;
	static Node* make(void*);

	static void real_real(Node**, void*);
	static void real_color(Node**, void*);
	static void color_real(Node**, void*);
	static void color_color(Node**, void*);

private:
	void update_types()override;
	inline const char* id()const override;
};

class NE_Node : public Node{
public:
	NE_Node();
	~NE_Node()override;
	static Node* make(void*);

	static void real_real(Node**, void*);
	static void real_color(Node**, void*);
	static void color_real(Node**, void*);
	static void color_color(Node**, void*);

private:
	void update_types()override;
	inline const char* id()const override;
};
