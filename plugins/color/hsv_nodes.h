#pragma once
#include <core/node.h>

class HSV_Node : public Node{
public:
	HSV_Node();
	~HSV_Node()override;
	static Node* make(std::istream*);
	static void hsv(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class Hue_Node : public Node{
public:
	Hue_Node();
	~Hue_Node()override;
	static Node* make(std::istream*);
	static void hue(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};
class Saturation_Node : public Node{
public:
	Saturation_Node();
	~Saturation_Node()override;
	static Node* make(std::istream*);
	static void saturation(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};
class Value_Node : public Node{
public:
	Value_Node();
	~Value_Node()override;
	static Node* make(std::istream*);
	static void value(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};
