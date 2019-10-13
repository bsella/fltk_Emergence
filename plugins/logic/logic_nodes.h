#pragma once
#include <core/node.h>

class AND_Node : public Node{
public:
	AND_Node();
	~AND_Node()override;
	static Node* make(std::istream*);
	static void func(Node**,void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class OR_Node : public Node{
public:
	OR_Node();
	~OR_Node()override;
	static Node* make(std::istream*);
	static void func(Node**,void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class XOR_Node : public Node{
public:
	XOR_Node();
	~XOR_Node()override;
	static Node* make(std::istream*);
	static void func(Node**,void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class NOT_Node : public Node{
public:
	NOT_Node();
	~NOT_Node()override;
	static Node* make(std::istream*);
	static void func(Node**,void*);
private:
	void update_types()override;
	inline const char* id()const override;
};
