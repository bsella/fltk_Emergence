#pragma once
#include "data_t.h"

static constexpr unsigned real_t_id= 0;

class Real_t : public Data_t{
public:
	explicit Real_t(double d=0);
	unsigned to_color()const override;
	inline void operator =(double d){value=d;}
	double value;
};
