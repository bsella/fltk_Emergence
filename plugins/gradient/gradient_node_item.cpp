#include "gradient_node_item.h"
#include "gradient_node.h"
#include <FL/fl_draw.H>
#include "gradient.h"
#include <color/color_t.h>

Gradient_Node_Item::Gradient_Node_Item(): Node_Item(100, 20, new Gradient_Node){
	update_draw_buffer();
}
Gradient_Node_Item::~Gradient_Node_Item(){}

Node_Item* Gradient_Node_Item::make(std::istream*){return new Gradient_Node_Item;}

void Gradient_Node_Item::draw_body()const{
    if(static_cast<Gradient_Node*>(core_node)->gradient) fl_draw_image(reinterpret_cast<const unsigned char*>(draw_buffer.data()), _x+1, _y+1, _w-2, _h-2, 4);
	fl_color(FL_BLACK);
	fl_rect(_x, _y, _w, _h);
}

void Gradient_Node_Item::scale(double s){
	Node_Item::scale(s);
	update_draw_buffer();
}

void Gradient_Node_Item::update_draw_buffer(){
	static Color_t temp_color;
	static unsigned char temp_r, temp_g, temp_b, temp_a;
	if((_w-2)*(_h-2)<=0) return;
	draw_buffer.reserve((_w-2)*(_h-2));
	for(int x=0; x<_w-2; x++){
        (static_cast<Gradient_Node*>(core_node))->gradient->get_color(double(x)/(_w-2), &temp_color);
		temp_r = temp_color.r*255;
		temp_g = temp_color.g*255;
		temp_b = temp_color.b*255;
		temp_a = temp_color.a*255;
		for(int y=0; y<_h-2; y++)
			draw_buffer[x+y*(_w-2)]=(((((temp_a << 8) | temp_b) << 8) | temp_g) << 8) | temp_r;
	}
}
