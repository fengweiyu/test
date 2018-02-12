/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	Employee.c
* Description		: 	Ա��
						���ļ���Ա��ʵ�������Ķ���
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

/*****************************************************************************
-Fuction		: EmployeeGetName
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
char * EmployeeGetName(T_Employee *ptThis)
{
	return ptThis->strName;
}
/*****************************************************************************
-Fuction		: EmployeeSetName
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void EmployeeSetName(T_Employee *ptThis,char *i_strName)
{
	ptThis->strName=i_strName;
}

/*****************************************************************************
-Fuction		: EmployeeGetSalary
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int EmployeeGetSalary(T_Employee *ptThis)
{
	return ptThis->iSalary;
}

/*****************************************************************************
-Fuction		: EmployeeSetSalary
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void EmployeeSetSalary(T_Employee *ptThis,int i_iSalary)
{
	ptThis->iSalary=i_iSalary;
}



