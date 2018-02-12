/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SingletonPattenUsage.c
* Description		: 	单例模式的使用

book@book-desktop:/work/projects/test/DesignPatterns$ gcc -o SingletonPatternUsage SingletonPattern.c SingletonPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns$ ./SingletonPatternUsage 
This is:Singleton
SingletonGetId:12

* Created			: 	2017.07.02.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"SingletonPattern.h"




/*****************************************************************************
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	g_tSingleton.PrintInfo();
	g_tSingleton.SetId(12);
	printf("SingletonGetId:%d\r\n",g_tSingleton.GetId());

	return 0;
}


