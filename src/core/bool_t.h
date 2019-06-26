#pragma once
#include "data_t.h"

class Bool_t : public Data_t{
public:
	explicit Bool_t(bool b= false);
	inline explicit operator bool()const override{return value;}
	explicit operator double()const override;
	explicit operator unsigned()const override;
	unsigned to_color()const override;
	inline void operator =(bool b){value=b;}
	bool value;
};
