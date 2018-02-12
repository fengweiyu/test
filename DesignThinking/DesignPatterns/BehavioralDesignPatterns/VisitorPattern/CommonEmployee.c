/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	CommonEmployee.c
* Description		: 	普通员工(普通类员工)
						本文件是普通员工实现类具体的动作
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


static char *g_strJobContent="无";

/*****************************************************************************
-Fuction		: CommonEmployeeGetJobContent
-Description	: 获取绩效
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



