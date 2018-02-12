/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BuilderPattern.h
* Description		: 	建造者模式
									
* Created			: 	2017.08.01.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef BUILDER_PATTERN_H
#define BUILDER_PATTERN_H

typedef struct SuperMan
{
	char *strBody;//私有变量，禁止直接访问
	char *strSpecialTalent;//私有变量，禁止直接访问
	char *strSpecialSymbol;//私有变量，禁止直接访问
	void (*SetBody)(struct SuperMan *ptThis,char *i_strBody);
	char * (*GetBody)(struct SuperMan *ptThis);
	void (*SetSpecialTalent)(struct SuperMan *ptThis,char *i_strSpecialTalent);
	char * (*GetSpecialTalent)(struct SuperMan *ptThis);
	void (*SetSpecialSymbol)(struct SuperMan *ptThis,char *i_strSpecialSymbol);	
	char * (*GetSpecialSymbol)(struct SuperMan *ptThis);
}T_SuperMan;

typedef struct Builder
{
	T_SuperMan tSuperMan;
	void (*SetBody)(struct Builder *ptThis,char *i_strBody);
	void (*SetSpecialTalent)(struct Builder *ptThis,char *i_strSpecialTalent);
	void (*SetSpecialSymbol)(struct Builder *ptThis,char *i_strSpecialSymbol);
	T_SuperMan (*GetSuperMan)(struct Builder *ptThis);
}T_Builder;

typedef struct Director
{
	T_SuperMan (*GetAdultSuperMan)();
	T_SuperMan (*GetChildSuperMan)();
}T_Director;

const T_Director g_tDirector;


#endif

