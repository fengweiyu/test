/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BridgePattern.c
* Description		: 	����ģʽ
						���ļ��ǳ���˾���ʵ��
						�Թ�˾�Ͳ�Ʒ�Ĺ�ϵ����	
						
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
-Fuction		: MakeMoney
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/20	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void MakeMoney(T_Corp *i_ptThis)
{
	i_ptThis->tProduct.BeProducted();
	i_ptThis->tProduct.BeSelled();
}



