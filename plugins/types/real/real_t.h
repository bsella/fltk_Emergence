#pragma once
#include <core/data_t.h>

class Real_t : public Data_t{
public:
	explicit Real_t(double d=0);
private:
	const double cache;
	int to_color()const override;
	template<typename T> explicit operator T()const;
};
