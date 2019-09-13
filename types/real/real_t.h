#pragma once
#include <core/data_t.h>
class Node;

class Real_t : public Data_t{
public:
	explicit Real_t(double d=0);
	inline void operator =(double d){value=d;}
	double value;

	static void rand(Node**, void*);
	static void to_color(Node**, void*);
	static void to_bool(Node**, void*);
};
