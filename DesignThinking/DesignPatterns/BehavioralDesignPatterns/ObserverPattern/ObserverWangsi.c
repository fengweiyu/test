/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ObserverWangsi.c
* Description		: 	�۲�����˹
						���ļ��ǹ۲���ʵ������˹�Ķ���
* Created			: 	2017.07.13.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"ObserverPattern.h"

/*****************************************************************************
-Fuction		: WangsiCry
-Description	: ˽�к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/13	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void WangsiCry(char *i_strContext)
{
	printf("��˹:��Ϊ%s,�����ұ��˰�\r\n",i_strContext);
}

/*****************************************************************************
-Fuction		: WangsiUpdate
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/13	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void WangsiUpdate(char *i_strContext)
{
	printf("��˹:�۲쵽�����ӻ,�Լ�Ҳ��ʼ���...\r\n");
	WangsiCry(i_strContext);
	printf("��˹:������...\r\n");
}




