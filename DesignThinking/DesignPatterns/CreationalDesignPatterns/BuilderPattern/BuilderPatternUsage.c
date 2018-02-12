/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BuilderPatternUsage.c
* Description		: 	������ģʽ��ʹ��

book@book-desktop:/work/projects/test/DesignPatterns/BuilderPattern$ gcc -o BuilderPatternUsage SuperMan.c AdultSuperManBuilder.c Builder.c ChildSuperManBuilder.c BuilderPattern.c BuilderPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/BuilderPattern$ ./BuilderPatternUsage 
------------������곬��:------------
���곬�˵��츳��:��ǹ����
-----------����δ���곬��:-----------
δ���곬�˵��츳��:�����

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
	printf("------------������곬��:------------\r\n");
	T_SuperMan tAdultSuperMan=g_tDirector.GetAdultSuperMan();
	printf("���곬�˵��츳��:%s\r\n",tAdultSuperMan.GetSpecialTalent(&tAdultSuperMan));
	
	printf("-----------����δ���곬��:-----------\r\n");
	T_SuperMan tChildSuperMan=g_tDirector.GetChildSuperMan();
	printf("δ���곬�˵��츳��:%s\r\n",tChildSuperMan.GetSpecialTalent(&tChildSuperMan));
	
	return 0;
}


