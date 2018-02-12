/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	StrategyPatternUsage.c
* Description		: 	策略模式的使用

book@book-desktop:/work/projects/test/DesignPatterns/StrategyPattern$ gcc -o StrategyPatternUsage GzipAlgorithm.c ZipAlgorithm.c StrategyPattern.c StrategyPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/StrategyPattern$ ./StrategyPatternUsage 
-----------------执行算法----------------
c:\Hello--->d:\Hello.zip  ZIP压缩成功!
c:\Hello.zip--->d:\Hello  ZIP解压成功!
*****************替换算法****************
c:\Hello--->d:\Hello.gzip  GZIP压缩成功!
c:\Hello.gzip--->d:\Hello  GZIP解压成功!

* Created			: 	2017.07.19.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"StrategyPattern.h"




/*****************************************************************************
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/19    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_Algorithm tAlgorithm=newZipAlgorithm;
	printf("-----------------执行算法----------------\r\n");
	g_tContext.SetAlgorithm(&tAlgorithm);
	g_tContext.Compress("c:\\Hello","d:\\Hello.zip");
	g_tContext.Uncompress("c:\\Hello.zip","d:\\Hello");

	printf("*****************替换算法****************\r\n");
	tAlgorithm=(T_Algorithm)newGzipAlgorithm;
	g_tContext.SetAlgorithm(&tAlgorithm);
	g_tContext.Compress("c:\\Hello","d:\\Hello.gzip");
	g_tContext.Uncompress("c:\\Hello.gzip","d:\\Hello");

	
	return 0;
}


