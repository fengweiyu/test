/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	TemplateMethodPatternUsage.c
* Description		: 	模版方法模式的使用

book@book-desktop:/work/projects/test/DesignPatterns/TemplateMethodPattern$ gcc -o TemplateMethodPatternUsage TemplateMethodPattern.c HummerH1Model.c HummerH2Model.c TemplateMethodPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/TemplateMethodPattern$ ./TemplateMethodPatternUsage 
HummerH1 start...
HummerH1 engine boom...
HummerH1 alarm...
HummerH1 stop...
HummerH2 start...
HummerH2 engine boom...
HummerH2 alarm...
HummerH2 stop...


* Created			: 	2017.07.12.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"TemplateMethodPattern.h"




/*****************************************************************************
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
 	T_HummerModel tHummerModel=newHummerH1Model;
	
	tHummerModel.tFatherDemonstration.Run(&tHummerModel);
	
	tHummerModel=(T_HummerModel)newHummerH2Model;
	tHummerModel.tFatherDemonstration.Run(&tHummerModel);
	
	return 0;
}


