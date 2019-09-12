#pragma once
#include <core/data_t.h>

class Real_t : public Data_t{
public:
	explicit Real_t(double d=0);
	inline void operator =(double d){value=d;}
	double value;
};

class Node;

void to_color(Node**, void*);
void to_bool(Node**, void*);
