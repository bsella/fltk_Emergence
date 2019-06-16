#pragma once

class Data_t{
public:
	const unsigned type_id;
	template<typename T> explicit operator T()const;
	virtual unsigned to_color()const=0;
	Data_t(unsigned);
	virtual ~Data_t();
};
