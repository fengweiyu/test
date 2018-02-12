/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	AbstractFactoryPatternUsage.c
* Description		: 	抽象工厂模式的使用

book@book-desktop:/work/projects/test/DesignPatterns/AbstractFactoryPattern$ gcc -o AbstractFactoryPatternUsage MaleYellowHuman.c MaleBlackHuman.c  MaleWhiteHuman.c BlackHuman.c WhiteHuman.c YellowHuman.c FemaleBlackHuman.c FemaleYellowHuman.c FemaleWhiteHuman.c FemaleHumanFactory.c MaleHumanFactory.c AbstractFactoryPattern.c AbstractFactoryPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/AbstractFactoryPattern$ ./AbstractFactoryPatternUsage 
------------创造一个黄色女性:------------
黄色人种的皮肤是黄色的
黄色人种会说话，一般说的是双字节
黄人女性
------------创造一个黄色男性:------------
黄色人种的皮肤是黄色的
黄色人种会说话，一般说的是双字节
黄人男性

* Created			: 	2017.08.02.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AbstractFactoryPattern.h"




/*****************************************************************************
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/02    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_HumanFactory tFemaleHumanFactory=newFemaleHumanFactory;
	T_HumanFactory tMaleHumanFactory=newMaleHumanFactory;

	T_Human tMaleYellowHuman =tMaleHumanFactory.CreateYellowHuman();
	T_Human tFemaleYellowHuman =tFemaleHumanFactory.CreateYellowHuman();
	printf("------------创造一个黄色女性:------------\r\n");
	tFemaleYellowHuman.GetColor();
	tFemaleYellowHuman.Talk();
	tFemaleYellowHuman.GetSex();
	printf("------------创造一个黄色男性:------------\r\n");
	tMaleYellowHuman.GetColor();
	tMaleYellowHuman.Talk();
	tMaleYellowHuman.GetSex();
	
	return 0;
}


