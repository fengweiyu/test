/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	VisitorPattern.c
* Description		: 	������ģʽ
						���ļ��Ǳ������ߵ�ʵ��
						�Ը���Ա��ͨ�����Եķ����߻�ø��Ե�
						��Ϣ����
						
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
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void ManagerVisitor(T_Manager *ptManagerEmployee)
{
	printf("����:%s,	нˮ:%d\r\n��Ч:%s\r\n",ptManagerEmployee->tEmployee.GetName(&ptManagerEmployee->tEmployee),
		ptManagerEmployee->tEmployee.GetSalary(&ptManagerEmployee->tEmployee),ptManagerEmployee->GetPerformance(&ptManagerEmployee->tEmployee));

}

/*****************************************************************************
-Fuction		: CommonEmployeeVisitor
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void CommonEmployeeVisitor(T_CommonEmployee *ptEmployee)
{
	printf("����:%s,	нˮ:%d\r\n����:%s\r\n",ptEmployee->tEmployee.GetName(&ptEmployee->tEmployee),
		ptEmployee->tEmployee.GetSalary(&ptEmployee->tEmployee),ptEmployee->GetJobContent(&ptEmployee->tEmployee));

}


