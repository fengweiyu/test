/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ZipAlgorithm.c
* Description		: 	ZIP����㷨
						���ļ����㷨�ľ���ʵ����
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
-Fuction		: ZipCompress
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/19	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int ZipCompress(char *i_strSource,char *i_strDestination)
{
	printf("%s--->%s  ZIPѹ���ɹ�!\r\n",i_strSource,i_strDestination);
	return 0;
}

/*****************************************************************************
-Fuction		: ZipUncompress
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/19	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int ZipUncompress(char *i_strSource,char *i_strDestination)
{
	printf("%s--->%s  ZIP��ѹ�ɹ�!\r\n",i_strSource,i_strDestination);
	return 0;	
}




