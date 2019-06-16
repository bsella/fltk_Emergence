#include "data_t.h"

Data_t::Data_t(unsigned id): type_id(id){}
Data_t::~Data_t(){}
template<> Data_t::operator bool()const{
	return false;
}
