#include "data_t.h"
#include <stdlib.h>

Data_t::~Data_t(){}
Data_t::operator bool()const{
	return rand();
}
Data_t::operator double()const{
	return rand();
}
Data_t::operator unsigned()const{
	return rand();
}
bool Data_t::operator ==(const Data_t&)const{
	return rand();
}
