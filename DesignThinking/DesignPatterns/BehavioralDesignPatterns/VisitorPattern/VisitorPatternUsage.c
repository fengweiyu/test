/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	VisitorPatternUsage.c
* Description		: 	������ģʽ��ʹ��

book@book-desktop:/work/projects/test/DesignPatterns/VisitorPattern$ gcc -o VisitorPatternUsage CommonEmployee.c Employee.c Manager.c VisitorPattern.c VisitorPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/VisitorPattern$ ./VisitorPatternUsage 
����:����,      нˮ:50000
��Ч:������Ϊ�������ǻ����쵼��ƨ��
����:����,      нˮ:15000
����:��д���򣬿�Ƶİ��˹�

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
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_Visitor tVisitor=newVisitor;

	T_Manager tManager=newManager;
	T_CommonEmployee tCommonEmployee=newCommonEmployee;


	tManager.tEmployee.SetName(&tManager.tEmployee,"����");
	tManager.tEmployee.SetSalary(&tManager.tEmployee,50000);
	tManager.SetPerformance("������Ϊ�������ǻ����쵼��ƨ��");

	tCommonEmployee.tEmployee.SetName(&tCommonEmployee.tEmployee,"����");
	tCommonEmployee.tEmployee.SetSalary(&tCommonEmployee.tEmployee,15000);
	tCommonEmployee.SetJobContent("��д���򣬿�Ƶİ��˹�");


	tManager.tEmployee.Accept((T_Employee *)&tManager,tVisitor);//ǿ��ת�����ڲ���ת����

	tCommonEmployee.tEmployee.Accept((T_Employee *)&tCommonEmployee,tVisitor);//Ϊ��ͳһ���Գ������
	return 0;
}


