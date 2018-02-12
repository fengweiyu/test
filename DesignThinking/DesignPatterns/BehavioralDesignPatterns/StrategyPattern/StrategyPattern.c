/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	StrategyPattern.c
* Description		: 	����ģʽ
						���ļ��ǻ���(������)��ɫ(��װ�㷨)
						��ѹ������ѹ�㷨����	
						
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
-Description	: ���к���
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
-Description	: ���к���
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
-Description	: ���к���
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


