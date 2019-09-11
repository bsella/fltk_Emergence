#pragma once
#include <core/data_t.h>

class Bool_t : public Data_t{
public:
	explicit Bool_t(bool b= false);
	unsigned to_color()const override;
	inline void operator =(bool b){value=b;}
	bool value;
};
