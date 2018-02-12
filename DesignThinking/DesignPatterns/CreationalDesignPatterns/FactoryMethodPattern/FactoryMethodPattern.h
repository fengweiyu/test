/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	FactoryMethodPattern.h
* Description		: 	工厂方法模式
									
* Created			: 	2017.07.31.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef FACTORY_METHOD_PATTERN_H
#define FACTORY_METHOD_PATTERN_H

typedef struct SuperMan
{
	void (*SuperManTalent)();
	
}T_SuperMan;

typedef struct SuperManFactory
{
	T_SuperMan (*CreatSuperMan)(char *i_strSuperManType);
	
}T_SuperManFactory;



T_SuperMan CreatSuperMan(char *i_strType);
#define newSuperManFactory {CreatSuperMan}


#endif

