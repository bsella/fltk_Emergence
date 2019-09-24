#pragma once
#include <core/node.h>

class HSV_Node : public Node{
public:
	HSV_Node();
	~HSV_Node()override;
	static Node* make(void*);
	static void hsv(Node**, void*);
private:
	void update_types()override;
};

class Hue_Node : public Node{
public:
	Hue_Node();
	~Hue_Node()override;
	static Node* make(void*);
	static void hue(Node**, void*);
private:
	void update_types()override;
};
class Saturation_Node : public Node{
public:
	Saturation_Node();
	~Saturation_Node()override;
	static Node* make(void*);
	static void saturation(Node**, void*);
private:
	void update_types()override;
};
class Value_Node : public Node{
public:
	Value_Node();
	~Value_Node()override;
	static Node* make(void*);
	static void value(Node**, void*);
private:
	void update_types()override;
};
