#pragma once
#include <core/data_t.h>
#include <core/node.h>

class Color_t : public Data_t{
public:
	explicit Color_t(unsigned color);
	explicit Color_t();
	explicit Color_t(float r, float g, float b);
	explicit Color_t(float r, float g, float b, float a);
	float r, g, b, a;

	static void rand(Node**, void*);
	static void to_color(Node**, void*);
};
