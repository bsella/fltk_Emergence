#pragma once
#include <core/node.h>
#include <real/real_t.h>
#include <color/color_t.h>
#include <complex/complex_t.h>

class Math_Node : public Node{
public:
    Math_Node(int);
protected:
	Real_t real_cache;
	Color_t color_cache;
	Complex_t complex_cache;
	void init_cache1(Node**);
	void init_cache2(Node**);
	void set_random_func();
private:
	virtual void update_types()override=0;
	void compile_specific(std::vector<Node*>&, bool)override;
};

class Add_Node : public Math_Node{
public:
	Add_Node();
	static Node* make(std::istream*);
	static void real_real(Node**, void*);
	static void real_color(Node**, void*);
	static void color_real(Node**, void*);
	static void color_color(Node**, void*);
	static void complex_complex(Node**, void*);
	static void complex_real(Node**, void*);
	static void real_complex(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class Sub_Node : public Math_Node{
public:
	Sub_Node();
	static Node* make(std::istream*);
	static void real_real(Node**, void*);
	static void real_color(Node**, void*);
	static void color_real(Node**, void*);
	static void color_color(Node**, void*);
	static void complex_complex(Node**, void*);
	static void complex_real(Node**, void*);
	static void real_complex(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class Mul_Node : public Math_Node{
public:
	Mul_Node();
	static Node* make(std::istream*);
	static void real_real(Node**, void*);
	static void real_color(Node**, void*);
	static void color_real(Node**, void*);
	static void color_color(Node**, void*);
	static void complex_complex(Node**, void*);
	static void complex_real(Node**, void*);
	static void real_complex(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class Div_Node : public Math_Node{
public:
	Div_Node();
	static Node* make(std::istream*);
	static void real_real(Node**, void*);
	static void real_color(Node**, void*);
	static void color_real(Node**, void*);
	static void color_color(Node**, void*);
	static void complex_complex(Node**, void*);
	static void complex_real(Node**, void*);
	static void real_complex(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class Neg_Node : public Math_Node{
public:
	Neg_Node();
	static Node* make(std::istream*);
	static void real(Node**, void*);
	static void color(Node**, void*);
	static void cplx(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class Sqrt_Node : public Math_Node{
public:
	Sqrt_Node();
	static Node* make(std::istream*);
	static void real(Node**, void*);
	static void color(Node**, void*);
	static void cplx(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class Abs_Node : public Math_Node{
public:
	Abs_Node();
	static Node* make(std::istream*);
	static void real(Node**, void*);
	static void color(Node**, void*);
	static void cplx(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class Sin_Node : public Math_Node{
public:
	Sin_Node();
	static Node* make(std::istream*);
	static void real(Node**, void*);
	static void color(Node**, void*);
	static void cplx(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class Cos_Node : public Math_Node{
public:
	Cos_Node();
	static Node* make(std::istream*);
	static void real(Node**, void*);
	static void color(Node**, void*);
	static void cplx(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class Pow_Node : public Math_Node{
public:
	Pow_Node();
	static Node* make(std::istream*);
	static void real_real(Node**, void*);
	static void real_color(Node**, void*);
	static void color_real(Node**, void*);
	static void color_color(Node**, void*);
	static void complex_complex(Node**, void*);
	static void complex_real(Node**, void*);
	static void real_complex(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class Log_Node : public Math_Node{
public:
	Log_Node();
	static Node* make(std::istream*);
	static void real(Node**, void*);
	static void color(Node**, void*);
	static void cplx(Node**, void*);
private:
	void update_types()override;
	inline const char* id()const override;
};

class Min_Max_Node : public Node{
public:
	Min_Max_Node();
protected:
	static bool rand(Data_t*, Data_t*);
	static bool gt_real(Data_t*, Data_t*);
	static bool gt_color(Data_t*, Data_t*);
	static bool gt_complex(Data_t*, Data_t*);
	bool (*gt_func)(Data_t*, Data_t*)= nullptr;
private:
	void update_types()override;
	virtual void update_cache()override=0;
	void execute()override;
	bool last_random;
};

class Min_Node : public Min_Max_Node{
public:
	static Node* make(std::istream*);
private:
	void update_cache()override;
	inline const char* id()const override;
};

class Max_Node : public Min_Max_Node{
public:
	static Node* make(std::istream*);
private:
	void update_cache()override;
	inline const char* id()const override;
};
