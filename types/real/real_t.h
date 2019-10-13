#pragma once
#include <core/data_t.h>
#include <core/node.h>

class Real_t : public Data_t{
public:
	explicit Real_t(std::istream*);
	explicit Real_t(double d= 0.0);
	double value;

	static void rand(Node**, void*);
	static void to_color(Node**, void*);
	static void to_bool(Node**, void*);
	void save(std::ostream&)const;
};
