#pragma once
class Node;

class Data_t{
public:
	Data_t(unsigned int);
	virtual ~Data_t();
	virtual unsigned to_color()const=0;
	const unsigned int id;
};
