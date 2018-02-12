/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SingletonPattern.h
* Description		: 	µ¥ÀýÄ£Ê½
* Created			: 	2017.07.02.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef SINGLETON_PATTERN_H
#define SINGLETON_PATTERN_H


typedef struct Singleton
{
	void (*PrintInfo)();
	void (*SetId)(int i_iId);
	int (*GetId)();
}T_Singleton;


extern const T_Singleton g_tSingleton;



#endif

