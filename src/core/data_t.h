#pragma once

class Data_t{
public:
	virtual explicit operator bool()const;
	virtual explicit operator double()const;
	virtual explicit operator unsigned()const;
	virtual bool operator ==(const Data_t&)const;
	virtual unsigned to_color()const=0;
	virtual ~Data_t();
};
