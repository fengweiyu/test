/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	CommonEmployee.c
* Description		: 	��ͨԱ��(��ͨ��Ա��)
						���ļ�����ͨԱ��ʵ�������Ķ���
* Created			: 	2017.07.17.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"VisitorPattern.h"


static char *g_strJobContent="��";

/*****************************************************************************
-Fuction		: CommonEmployeeGetJobContent
-Description	: ��ȡ��Ч
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
char * CommonEmployeeGetJobContent()
{
	return g_strJobContent;
}

/*****************************************************************************
-Fuction		: CommonEmployeeSetJobContent
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void CommonEmployeeSetJobContent(char *i_strJobContent)
{
	g_strJobContent=i_strJobContent;
}

/*****************************************************************************
-Fuction		: CommonEmployeeAccept
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void CommonEmployeeAccept(T_Employee *ptThis,T_Visitor i_tAcceptVisitor)
{
	i_tAcceptVisitor.CommonEmployeeVisit((T_CommonEmployee *)ptThis);
}



