#pragma once
#include "data_t.h"

class Real_t : public Data_t{
public:
	explicit Real_t(double d=0);
	explicit operator bool()const override;
	inline explicit operator double()const override{return value;}
	unsigned to_color()const override;
	inline void operator =(double d){value=d;}
	double value;
};
