/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	DecoratorPattern.c
* Description		: 	װ��ģʽ
						���ļ��ǳɼ����ľ���ʵ��(δ������)
						�����γɼ�������	
						
* Created			: 	2017.07.25.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"DecoratorPattern.h"


/*****************************************************************************
-Fuction		: SchoolReportReport
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void SchoolReportReport(void *i_ptThis)
{
	printf("�𾴵�XXX�ҳ�:\r\n");
	printf(".......................................\r\n");
	printf("����62����ѧ65������98����Ȼ63\r\n");
	printf(".......................................\r\n");
	printf("                                 �ҳ�ǩ��                       \r\n");
}

/*****************************************************************************
-Fuction		: SchoolReportSign
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void SchoolReportSign(void *i_ptThis,char *i_strName)
{	
	printf("�ҳ�ǩ��Ϊ:%s\r\n",i_strName);
}


