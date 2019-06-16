#pragma once
#include "data_t.h"

static constexpr unsigned bool_t_id= 1;

class Bool_t : public Data_t{
public:
	explicit Bool_t(bool b= false);
	unsigned to_color()const override;
	inline void operator =(bool b){value=b;}
	bool value;
};
