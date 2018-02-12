/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	VisitorPatternUsage.c
* Description		: 	访问者模式的使用

book@book-desktop:/work/projects/test/DesignPatterns/VisitorPattern$ gcc -o VisitorPatternUsage CommonEmployee.c Employee.c Manager.c VisitorPattern.c VisitorPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/VisitorPattern$ ./VisitorPatternUsage 
姓名:张三,      薪水:50000
绩效:基本上为负，但是会拍领导马屁啊
姓名:李四,      薪水:15000
工作:编写程序，苦逼的搬运工

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


	tManager.tEmployee.SetName(&tManager.tEmployee,"张三");
	tManager.tEmployee.SetSalary(&tManager.tEmployee,50000);
	tManager.SetPerformance("基本上为负，但是会拍领导马屁啊");

	tCommonEmployee.tEmployee.SetName(&tCommonEmployee.tEmployee,"李四");
	tCommonEmployee.tEmployee.SetSalary(&tCommonEmployee.tEmployee,15000);
	tCommonEmployee.SetJobContent("编写程序，苦逼的搬运工");


	tManager.tEmployee.Accept((T_Employee *)&tManager,tVisitor);//强制转换，内部再转回来

	tCommonEmployee.tEmployee.Accept((T_Employee *)&tCommonEmployee,tVisitor);//为了统一可以抽象出来
	return 0;
}


