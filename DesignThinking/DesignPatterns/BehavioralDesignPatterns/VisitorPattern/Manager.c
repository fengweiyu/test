/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	Manager.c
* Description		: 	经理(管理类员工)
						本文件是经理实现类具体的动作
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
#include"VisitorPattern.h"




static char *g_strPerformance="零";

/*****************************************************************************
-Fuction		: ManagerGetPerformance
-Description	: 获取绩效
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
char * ManagerGetPerformance()
{
	return g_strPerformance;
}

/*****************************************************************************
-Fuction		: ManagerSetPerformance
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void ManagerSetPerformance(char *i_strPerformance)
{
	g_strPerformance=i_strPerformance;
}

/*****************************************************************************
-Fuction		: ManagerAccept
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void ManagerAccept(T_Employee *ptThis,T_Visitor i_tAcceptVisitor)
{
	i_tAcceptVisitor.ManagerVisit((T_Manager *)ptThis);
}



