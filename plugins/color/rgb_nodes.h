#pragma once
#include <core/node.h>

class RGB_Node : public Node{
public:
   	RGB_Node();
    ~RGB_Node()override;
	static Node* make(std::istream*);
	static void rgb(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class Red_Node : public Node{
public:
	Red_Node();
    ~Red_Node()override;
	static Node* make(std::istream*);
	static void red(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class Green_Node : public Node{
public:
	Green_Node();
    ~Green_Node()override;
	static Node* make(std::istream*);
	static void green(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class Blue_Node : public Node{
public:
	Blue_Node();
    ~Blue_Node()override;
	static Node* make(std::istream*);
	static void blue(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class Alpha_Node : public Node{
public:
	Alpha_Node();
    ~Alpha_Node()override;
	static Node* make(std::istream*);
	static void alpha(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};
