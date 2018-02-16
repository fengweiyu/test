/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ManyVirtual.cpp
* Description		: 	ManyVirtual operation center
* Created			: 	2017.09.11.
* Author			: 	Yu Weifeng
* Function List 	: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
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