#pragma once

class Data_t{
public:
	template<typename T> explicit operator T()const;
	virtual unsigned to_color()const=0;
	virtual ~Data_t();
};
