/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ObserverLisi.c
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
-Fuction		: LisiReportToQinshihuang
-Description	: ˽�к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/13	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void LisiReportToQinshihuang(char *i_strContext)
{
	printf("��˹:����,���ϰ�,�������л��-->%s\r\n",i_strContext);
}

/*****************************************************************************
-Fuction		: LisiUpdate
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/13	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void LisiUpdate(char *i_strContext)
{
	printf("��˹:�۲쵽�����ӻ,��ʼ�����ϰ�㱨\r\n");
	LisiReportToQinshihuang(i_strContext);
	printf("��˹:�㱨���...\r\n");
}



