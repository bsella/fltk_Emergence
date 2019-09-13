#pragma once
#include <core/data_t.h>
class Node;

class Bool_t : public Data_t{
public:
	explicit Bool_t(bool b= false);
	inline void operator =(bool b){value=b;}
	bool value;

	static void rand(Node**, void*);
	static void to_color(Node**, void*);
	static void to_bool(Node**, void*);
};
