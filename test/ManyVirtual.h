#ifndef MANY_VIRTUAL
#define MANY_VIRTUAL

#include "stdio.h"
#include "stdlib.h"

class virtual1
{
public:
	virtual1();
	~virtual1();
	virtual void print();


};

class virtual2 : virtual1
{
public:
	virtual2();
	~virtual2();
	void print();
};

class virtual3 : virtual2
{
public:
	 virtual3();
	~virtual3();
	void print();
};
#endif