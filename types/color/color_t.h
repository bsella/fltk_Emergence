#pragma once
#include <core/data_t.h>
#include <core/node.h>

class Color_t : public Data_t{
public:
	explicit Color_t(unsigned color);
	explicit Color_t(float r, float g, float b);
	float r, g, b;
};

void to_color(Node** nodes, void* ptr);
