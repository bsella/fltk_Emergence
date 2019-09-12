#pragma once
#include <core/data_t.h>

class Bool_t : public Data_t{
public:
	explicit Bool_t(bool b= false);
	inline void operator =(bool b){value=b;}
	bool value;
};

class Node;

void to_color(Node**, void*);
void to_bool(Node**, void*);
