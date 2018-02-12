/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	FactoryMethodPattern.c
* Description		: 	工厂方法模式
						本文件是超人生产工厂的具体实现
						以生产超人举例	
						
* Created			: 	2017.07.31.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FactoryMethodPattern.h"


void AdultTalent();
#define newAdultTalent {AdultTalent}
void ChildTalent();
#define newChildTalent {ChildTalent}

/*****************************************************************************
-Fuction		: CreatSuperMan
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/31    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
T_SuperMan CreatSuperMan(char *i_strType)
{
	T_SuperMan tSuperMan={NULL};
	if(0==strcmp("adult",i_strType))
	{
		tSuperMan=(T_SuperMan)newAdultTalent;
	}
	else if(0==strcmp("child",i_strType))
	{
		tSuperMan=(T_SuperMan)newChildTalent;
	}
	else
	{
		printf("CreatSuperMan err,UnkownType:%s",i_strType);
	}
	return tSuperMan;
}


