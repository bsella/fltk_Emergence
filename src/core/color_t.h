#pragma once
#include "data_t.h"

class Color_t : public Data_t{
public:
	explicit Color_t(unsigned color);
	explicit Color_t(float r, float g, float b);
	explicit operator bool()const override;
	explicit operator double()const override;
	explicit operator unsigned()const override;
	unsigned to_color()const override;
	float r, g, b;
};
