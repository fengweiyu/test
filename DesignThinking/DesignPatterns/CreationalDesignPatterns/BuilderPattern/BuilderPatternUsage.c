/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BuilderPatternUsage.c
* Description		: 	建造者模式的使用

book@book-desktop:/work/projects/test/DesignPatterns/BuilderPattern$ gcc -o BuilderPatternUsage SuperMan.c AdultSuperManBuilder.c Builder.c ChildSuperManBuilder.c BuilderPattern.c BuilderPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/BuilderPattern$ ./BuilderPatternUsage 
------------创造成年超人:------------
成年超人的天赋是:刀枪不入
-----------创造未成年超人:-----------
未成年超人的天赋是:会飞行

* Created			: 	2017.08.01.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BuilderPattern.h"




/*****************************************************************************
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/01    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	printf("------------创造成年超人:------------\r\n");
	T_SuperMan tAdultSuperMan=g_tDirector.GetAdultSuperMan();
	printf("成年超人的天赋是:%s\r\n",tAdultSuperMan.GetSpecialTalent(&tAdultSuperMan));
	
	printf("-----------创造未成年超人:-----------\r\n");
	T_SuperMan tChildSuperMan=g_tDirector.GetChildSuperMan();
	printf("未成年超人的天赋是:%s\r\n",tChildSuperMan.GetSpecialTalent(&tChildSuperMan));
	
	return 0;
}


