#include "math_node_items.h"
#include <resources.h>
#include <FL/fl_draw.H>

Math_Node_Item::Math_Node_Item(int x, int y, Fl_PNG_Image* icon, Node* node): Node_Item(x, y, 50,50, node), icon(icon){}
Fl_Color Math_Node_Item::color()const{
	return 0xb4ffb4ff;
}
void Math_Node_Item::draw_body()const{
	Node_Item::draw_body();
	if(_w>icon->w() && _h>icon->h()) icon->draw(_w/2 - icon->w()/2 + _x, _h/2 - icon->h()/2 + _y);
}

Add_Node_Item::Add_Node_Item(int x, int y): Math_Node_Item(x, y, &icon, new Add_Node){}
Sub_Node_Item::Sub_Node_Item(int x, int y): Math_Node_Item(x, y, &icon, new Sub_Node){}
Mul_Node_Item::Mul_Node_Item(int x, int y): Math_Node_Item(x, y, &icon, new Mul_Node){}
Div_Node_Item::Div_Node_Item(int x, int y): Math_Node_Item(x, y, &icon, new Div_Node){}
Neg_Node_Item::Neg_Node_Item(int x, int y): Math_Node_Item(x, y, &icon, new Neg_Node){}
Sqrt_Node_Item::Sqrt_Node_Item(int x, int y): Math_Node_Item(x, y, &icon, new Sqrt_Node){}
Abs_Node_Item::Abs_Node_Item(int x, int y): Math_Node_Item(x, y, nullptr, new Abs_Node){}
Sin_Node_Item::Sin_Node_Item(int x, int y): Math_Node_Item(x, y, nullptr, new Sin_Node){}
Cos_Node_Item::Cos_Node_Item(int x, int y): Math_Node_Item(x, y, nullptr, new Cos_Node){}
Min_Node_Item::Min_Node_Item(int x, int y): Math_Node_Item(x, y, nullptr, new Min_Node){}
Max_Node_Item::Max_Node_Item(int x, int y): Math_Node_Item(x, y, nullptr, new Max_Node){}
Pow_Node_Item::Pow_Node_Item(int x, int y): Math_Node_Item(x, y, nullptr, new Pow_Node){}
Log_Node_Item::Log_Node_Item(int x, int y): Math_Node_Item(x, y, nullptr, new Log_Node){}

Fl_PNG_Image Add_Node_Item::icon(RELATIVE("../plugins/math/add.png"));
Fl_PNG_Image Sub_Node_Item::icon(RELATIVE("../plugins/math/subtract.png"));
Fl_PNG_Image Mul_Node_Item::icon(RELATIVE("../plugins/math/multiply.png"));
Fl_PNG_Image Div_Node_Item::icon(RELATIVE("../plugins/math/divide.png"));
Fl_PNG_Image Neg_Node_Item::icon(RELATIVE("../plugins/math/neg.png"));
Fl_PNG_Image Sqrt_Node_Item::icon(RELATIVE("../plugins/math/sqrt.png"));

Node_Item* Add_Node_Item::make(int x, int y, void*){return new Add_Node_Item(x,y);}
Node_Item* Sub_Node_Item::make(int x, int y, void*){return new Sub_Node_Item(x,y);}
Node_Item* Mul_Node_Item::make(int x, int y, void*){return new Mul_Node_Item(x,y);}
Node_Item* Div_Node_Item::make(int x, int y, void*){return new Div_Node_Item(x,y);}
Node_Item* Neg_Node_Item::make(int x, int y, void*){return new Neg_Node_Item(x,y);}
Node_Item* Sqrt_Node_Item::make(int x, int y, void*){return new Sqrt_Node_Item(x,y);}
Node_Item* Abs_Node_Item::make(int x, int y, void*){return new Abs_Node_Item(x,y);}
Node_Item* Sin_Node_Item::make(int x, int y, void*){return new Sin_Node_Item(x,y);}
Node_Item* Cos_Node_Item::make(int x, int y, void*){return new Cos_Node_Item(x,y);}
Node_Item* Min_Node_Item::make(int x, int y, void*){return new Min_Node_Item(x,y);}
Node_Item* Max_Node_Item::make(int x, int y, void*){return new Max_Node_Item(x,y);}
Node_Item* Pow_Node_Item::make(int x, int y, void*){return new Pow_Node_Item(x,y);}
Node_Item* Log_Node_Item::make(int x, int y, void*){return new Log_Node_Item(x,y);}

void Abs_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("abs", _x+_w/2-12, _y+_h/2+4);
}
void Sin_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("sin", _x+_w/2-12, _y+_h/2+4);
}
void Cos_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("cos", _x+_w/2-12, _y+_h/2+4);
}
void Min_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("min", _x+_w/2-12, _y+_h/2+4);
}
void Max_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("max", _x+_w/2-12, _y+_h/2+4);
}
void Pow_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("pow", _x+_w/2-12, _y+_h/2+4);
}
void Log_Node_Item::draw_body()const{
	Node_Item::draw_body();
	fl_draw("log", _x+_w/2-12, _y+_h/2+4);
}
