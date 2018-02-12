/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	GzipAlgorithm.c
* Description		: 	GZIP相关算法
						本文件是算法的具体实现类
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
-Fuction		: GzipCompress
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/19	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int GzipCompress(char *i_strSource,char *i_strDestination)
{
	printf("%s--->%s  GZIP压缩成功!\r\n",i_strSource,i_strDestination);
	return 0;
}

/*****************************************************************************
-Fuction		: GzipUncompress
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/19	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int GzipUncompress(char *i_strSource,char *i_strDestination)
{
	printf("%s--->%s  GZIP解压成功!\r\n",i_strSource,i_strDestination);
	return 0;	
}





