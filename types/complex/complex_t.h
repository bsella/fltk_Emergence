#pragma once
#include <core/data_t.h>
#include <complex>
class Node;

class Complex_t : public Data_t{
public:
	explicit Complex_t(double r=0, double i=0);
	std::complex<double> value;

	static void rand(Node**, void*);
	static void to_color(Node**, void*);

	inline double abs(){return std::abs(value);}
	inline double arg(){return std::arg(value);}
};
