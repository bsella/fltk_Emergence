#pragma once
#include <set>
class Color_t;

class Gradient{
public:
	Gradient();
	void add_color(unsigned int, double);
	void get_color(double, Color_t*);
	std::set<std::pair<double, unsigned>,
		bool (*)(const std::pair<double, unsigned>&, const std::pair<double, unsigned>&)> colors;
};
