/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	AbstractFactoryPatternUsage.c
* Description		: 	���󹤳�ģʽ��ʹ��

book@book-desktop:/work/projects/test/DesignPatterns/AbstractFactoryPattern$ gcc -o AbstractFactoryPatternUsage MaleYellowHuman.c MaleBlackHuman.c  MaleWhiteHuman.c BlackHuman.c WhiteHuman.c YellowHuman.c FemaleBlackHuman.c FemaleYellowHuman.c FemaleWhiteHuman.c FemaleHumanFactory.c MaleHumanFactory.c AbstractFactoryPattern.c AbstractFactoryPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/AbstractFactoryPattern$ ./AbstractFactoryPatternUsage 
------------����һ����ɫŮ��:------------
��ɫ���ֵ�Ƥ���ǻ�ɫ��
��ɫ���ֻ�˵����һ��˵����˫�ֽ�
����Ů��
------------����һ����ɫ����:------------
��ɫ���ֵ�Ƥ���ǻ�ɫ��
��ɫ���ֻ�˵����һ��˵����˫�ֽ�
��������

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
	printf("------------����һ����ɫŮ��:------------\r\n");
	tFemaleYellowHuman.GetColor();
	tFemaleYellowHuman.Talk();
	tFemaleYellowHuman.GetSex();
	printf("------------����һ����ɫ����:------------\r\n");
	tMaleYellowHuman.GetColor();
	tMaleYellowHuman.Talk();
	tMaleYellowHuman.GetSex();
	
	return 0;
}


