/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	HouseCorp.c
* Description		: 	����ģʽ
						���ļ��Ƿ��ز���˾��ʵ����
						
* Created			: 	2017.07.20.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"BridgePattern.h"

/*****************************************************************************
-Fuction		: HouseMakeMoney
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/20	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void HouseCorpMakeMoney(T_HouseCorp *i_ptThis)
{
	i_ptThis->tFatherCorp.MakeMoney(&i_ptThis->tFatherCorp);
	printf("���ز���˾׬��Ǯ��...\r\n");
}




