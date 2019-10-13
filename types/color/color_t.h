#pragma once
#include <core/data_t.h>
#include <core/node.h>

class Color_t : public Data_t{
public:
	explicit Color_t(std::istream* str= nullptr);
	explicit Color_t(unsigned color);
	explicit Color_t(double r, double g, double b);
	explicit Color_t(double r, double g, double b, double a);
	double r, g, b, a;
	double to_real()const;

	static void rand(Node**, void*);
	static void to_color(Node**, void*);
	
	void save(std::ostream&)const;
};
