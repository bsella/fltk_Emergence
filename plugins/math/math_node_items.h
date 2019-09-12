#include "math_nodes.h"
#include <gui/node_item.h>
#include <FL/Fl_PNG_Image.H>

class Math_Node_Item : public Node_Item{
public:
	Math_Node_Item(int, int, Fl_PNG_Image*, Node*);
protected:
	Fl_PNG_Image* icon;
	Fl_Color color()const override;
	virtual void draw_body()const override;
};

class Add_Node_Item : public Math_Node_Item{
public:
	Add_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
	static Fl_PNG_Image icon;
};

class Sub_Node_Item : public Math_Node_Item{
public:
	Sub_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
	static Fl_PNG_Image icon;
};

class Mul_Node_Item : public Math_Node_Item{
public:
	Mul_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
	static Fl_PNG_Image icon;
};

class Div_Node_Item : public Math_Node_Item{
public:
	Div_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
	static Fl_PNG_Image icon;
};

class Neg_Node_Item : public Math_Node_Item{
public:
	Neg_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
	static Fl_PNG_Image icon;
};

class Sqrt_Node_Item : public Math_Node_Item{
public:
	Sqrt_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
	static Fl_PNG_Image icon;
};

class Abs_Node_Item : public Math_Node_Item{
public:
	Abs_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
private:
	void draw_body()const override;
};

class Sin_Node_Item : public Math_Node_Item{
public:
	Sin_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
private:
	void draw_body()const override;
};

class Cos_Node_Item : public Math_Node_Item{
public:
	Cos_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
private:
	void draw_body()const override;
};

class Min_Node_Item : public Math_Node_Item{
public:
	Min_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
private:
	void draw_body()const override;
};

class Max_Node_Item : public Math_Node_Item{
public:
	Max_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
private:
	void draw_body()const override;
};

class Pow_Node_Item : public Math_Node_Item{
public:
	Pow_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
private:
	void draw_body()const override;
};

class Log_Node_Item : public Math_Node_Item{
public:
	Log_Node_Item(int,int);
	static Node_Item* make(int,int,void*);
private:
	void draw_body()const override;
};
