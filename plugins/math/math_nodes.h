#pragma once
#include <core/node.h>
#include <real/real_t.h>
#include <color/color_t.h>

class Math_Node : public Node{
public:
	Math_Node(unsigned int);
protected:
	Real_t real_cache;
	Color_t color_cache;
	void init_cache1(Node**);
	void init_cache2(Node**);
	void set_random_func();
private:
	virtual void update_types()override=0;
};

class Add_Node : public Math_Node{
public:
	Add_Node();
	static Node* make(void*);
	static void real_real(Node**, void*);
	static void color_color(Node**, void*);
private:
	void update_types()override;
};

class Sub_Node : public Math_Node{
public:
	Sub_Node();
	static Node* make(void*);
	static void real_real(Node**, void*);
	static void color_color(Node**, void*);
private:
	void update_types()override;
};

class Mul_Node : public Math_Node{
public:
	Mul_Node();
	static Node* make(void*);
	static void real_real(Node**, void*);
	static void real_color(Node**, void*);
	static void color_real(Node**, void*);
private:
	void update_types()override;
};

class Div_Node : public Math_Node{
public:
	Div_Node();
	static Node* make(void*);
	static void real_real(Node**, void*);
	static void color_real(Node**, void*);
private:
	void update_types()override;
};

class Neg_Node : public Math_Node{
public:
	Neg_Node();
	static Node* make(void*);
	static void real(Node**, void*);
	static void color(Node**, void*);
private:
	void update_types()override;
};

class Sqrt_Node : public Math_Node{
public:
	Sqrt_Node();
	static Node* make(void*);
	static void real(Node**, void*);
private:
	void update_types()override;
};

class Abs_Node : public Math_Node{
public:
	Abs_Node();
	static Node* make(void*);
	static void real(Node**, void*);
private:
	void update_types()override;
};

class Sin_Node : public Math_Node{
public:
	Sin_Node();
	static Node* make(void*);
	static void real(Node**, void*);
private:
	void update_types()override;
};

class Cos_Node : public Math_Node{
public:
	Cos_Node();
	static Node* make(void*);
	static void real(Node**, void*);
private:
	void update_types()override;
};

class Min_Node : public Math_Node{
public:
	Min_Node();
	static Node* make(void*);
	static void real_real(Node**, void*);
	//static void color_color(Node**, void*);
private:
	void update_types()override;
};

class Max_Node : public Math_Node{
public:
	Max_Node();
	static Node* make(void*);
	static void real_real(Node**, void*);
	//static void color_color(Node**, void*);
private:
	void update_types()override;
};

class Pow_Node : public Math_Node{
public:
	Pow_Node();
	static Node* make(void*);
	static void real_real(Node**, void*);
private:
	void update_types()override;
};

class Log_Node : public Math_Node{
public:
	Log_Node();
	static Node* make(void*);
	static void real(Node**, void*);
private:
	void update_types()override;
};
