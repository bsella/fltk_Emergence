#pragma once
#include "data_t.h"

class Color_t : public Data_t{
public:
	explicit Color_t(unsigned color);
	explicit Color_t(float r, float g, float b);
	unsigned to_color()const override;
	float r, g, b;
};
