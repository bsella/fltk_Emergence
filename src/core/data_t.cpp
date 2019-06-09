#include "data_t.h"

template<> Data_t::operator bool()const{
	return false;
}

Data_t::~Data_t(){}
