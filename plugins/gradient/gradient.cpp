#include "gradient.h"
#include <color/color_t.h>

static bool compare(const std::pair<double, unsigned int>& c1, const std::pair<double, unsigned int>& c2){
	return c1.first<c2.first;
}

Gradient::Gradient():colors(&compare){
}
void Gradient::add_color(unsigned int color, double index){
	colors.insert({index, color});
}

void Gradient::get_color(double index, Color_t* color){
	if(colors.empty()){
		color->r= color->g= color->b= color->a= 0;
		return;
	}
	if(index<=colors.begin()->first){
        color->r= ((colors.begin()->second >> 0) & 0xff)/255.0;
        color->g= ((colors.begin()->second >> 8) & 0xff)/255.0;
        color->b= ((colors.begin()->second >>16) & 0xff)/255.0;
        color->a= ((colors.begin()->second >>24) & 0xff)/255.0;
		return;
	}
	//static double i;
	//i= (1-index) * 255.f;
	//index*= 255;
	for(auto pair= std::next(colors.begin()); pair!=colors.end(); pair++)
		if(index<pair->first){
			auto prev= std::prev(pair);
			index= (index-prev->first)/(pair->first-prev->first);
            color->r= index*((pair->second >> 0) & 0xff)/255.0 + (1-index)*((prev->second >> 0) & 0xff)/255.0;
            color->g= index*((pair->second >> 8) & 0xff)/255.0 + (1-index)*((prev->second >> 8) & 0xff)/255.0;
            color->b= index*((pair->second >>16) & 0xff)/255.0 + (1-index)*((prev->second >>16) & 0xff)/255.0;
            color->a= index*((pair->second >>24) & 0xff)/255.0 + (1-index)*((prev->second >>24) & 0xff)/255.0;
			return;
		}
    color->r= ((colors.rbegin()->second >> 0) & 0xff)/255.0;
    color->g= ((colors.rbegin()->second >> 8) & 0xff)/255.0;
    color->b= ((colors.rbegin()->second >>16) & 0xff)/255.0;
    color->a= ((colors.rbegin()->second >>24) & 0xff)/255.0;
}
