/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	FactoryMethodPatternUsage.c
* Description		: 	工厂方法模式的使用

book@book-desktop:/work/projects/test/DesignPatterns/FactoryMethodPattern$ gcc -o FactoryMethodPatternUsage AdultSuperMan.c ChildSuperMan.c FactoryMethodPattern.c FactoryMethodPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/FactoryMethodPattern$ ./FactoryMethodPatternUsage 
------------生产成年超人:------------
超人力大无穷
-----------生产未成年超人:-----------
小超人的能力是刀枪不入,快速运动

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




/*****************************************************************************
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/31    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_SuperManFactory tSuperManFactory=newSuperManFactory;
	T_SuperMan tSuperMan;
	printf("------------生产成年超人:------------\r\n");
	tSuperMan=tSuperManFactory.CreatSuperMan("adult");
	tSuperMan.SuperManTalent();
	printf("-----------生产未成年超人:-----------\r\n");
	tSuperMan=tSuperManFactory.CreatSuperMan("child");
	tSuperMan.SuperManTalent();	
	return 0;
}


