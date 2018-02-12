/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	VisitorPattern.c
* Description		: 	访问者模式
						本文件是被访问者的实现
						以各种员工通过各自的访问者获得各自的
						信息举例
						
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
-Fuction		: ManagerVisitor
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void ManagerVisitor(T_Manager *ptManagerEmployee)
{
	printf("姓名:%s,	薪水:%d\r\n绩效:%s\r\n",ptManagerEmployee->tEmployee.GetName(&ptManagerEmployee->tEmployee),
		ptManagerEmployee->tEmployee.GetSalary(&ptManagerEmployee->tEmployee),ptManagerEmployee->GetPerformance(&ptManagerEmployee->tEmployee));

}

/*****************************************************************************
-Fuction		: CommonEmployeeVisitor
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void CommonEmployeeVisitor(T_CommonEmployee *ptEmployee)
{
	printf("姓名:%s,	薪水:%d\r\n工作:%s\r\n",ptEmployee->tEmployee.GetName(&ptEmployee->tEmployee),
		ptEmployee->tEmployee.GetSalary(&ptEmployee->tEmployee),ptEmployee->GetJobContent(&ptEmployee->tEmployee));

}


