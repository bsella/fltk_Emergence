#include "data_t.h"

Data_t::~Data_t(){}
Data_t::operator bool()const{
	return false;
}
Data_t::operator double()const{
	return 0.0;
}
bool Data_t::operator ==(const Data_t&)const{
	return false;
}
