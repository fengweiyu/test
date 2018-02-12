/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	StrategyPattern.c
* Description		: 	策略模式
						本文件是环境(上下文)角色(封装算法)
						以压缩，解压算法举例	
						
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

static void SetAlgorithm(T_Algorithm *i_ptAlgorithm);
static int Compress(char *i_strSource,char *i_strDestination);
static int Uncompress(char *i_strSource,char *i_strDestination);
static T_Algorithm g_tAlgorithm;

const T_Context g_tContext={
	.SetAlgorithm	=SetAlgorithm,
	.Compress	=Compress,
	.Uncompress	=Uncompress,
};
/*****************************************************************************
-Fuction		: SetAlgorithm
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/19	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void SetAlgorithm(T_Algorithm *i_ptAlgorithm)
{
	memcpy(&g_tAlgorithm,i_ptAlgorithm,sizeof(T_Algorithm));
}

/*****************************************************************************
-Fuction		: Compress
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/19	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int Compress(char *i_strSource,char *i_strDestination)
{
	return g_tAlgorithm.Compress(i_strSource,i_strDestination);
}

/*****************************************************************************
-Fuction		: Uncompress
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/19	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int Uncompress(char *i_strSource,char *i_strDestination)
{
	return g_tAlgorithm.Uncompress(i_strSource,i_strDestination);
}


