/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	VisitorPattern.h
* Description		: 	访问者模式
									
* Created			: 	2017.07.17.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef VISITOR_PATTERN_H
#define VISITOR_PATTERN_H

struct Employee;
struct Manager;
struct CommonEmployee;

typedef struct Visitor//访问者类
{//C不好实现重载，暂时用定义多个的形式
	void (*ManagerVisit)(struct Manager *ptEmployee);//访问函数
	void (*CommonEmployeeVisit)(struct CommonEmployee *ptEmployee);//访问函数

	//void (*Visit)(struct Employee *ptEmployee);//访问函数
}T_Visitor;//接口

typedef struct Employee
{
	char *strName;//因为各个对象需要各自的空间,所以,不得已,私有数据成员放这里
	int iSalary;//但是为保证不直接访问私有的数据成员,人为约定,访问只能通过公有函数
	char  *(*GetName)(struct Employee *ptThis);//具体函数(本层实现)
	void (*SetName)(struct Employee *ptThis,char *i_strName);//具体函数(本层实现)
	int (*GetSalary)(struct Employee *ptThis);//具体函数(本层实现)
	void (*SetSalary)(struct Employee *ptThis,int i_iSalary);//具体函数(本层实现)
	//允许的访问者,可选择具体哪个访问者//函数内部对传入参数指针强制转换
	void (*Accept)(struct Employee *ptThis,T_Visitor i_tAcceptVisitor);//抽象函数(下一层实现)
}T_Employee;//员工抽象类

typedef struct CommonEmployee
{
	T_Employee tEmployee;
	char  *(*GetJobContent)();//具体函数(本层实现)
	void (*SetJobContent)(char *i_strJobContent);//具体函数(本层实现)
}T_CommonEmployee;

typedef struct Manager
{
	T_Employee tEmployee;
	char  *(*GetPerformance)();//具体函数(本层实现)
	void (*SetPerformance)(char *i_strPerformance);//具体函数(本层实现)
}T_Manager;



void ManagerVisitor(T_Manager *ptEmployee);
void CommonEmployeeVisitor(T_CommonEmployee *ptEmployee);
#define newVisitor {ManagerVisitor,CommonEmployeeVisitor}


char * EmployeeGetName(T_Employee *ptThis);
void EmployeeSetName(T_Employee *ptThis,char *i_strName);
int EmployeeGetSalary(T_Employee *ptThis);
void EmployeeSetSalary(T_Employee *ptThis,int i_iSalary);

void ManagerAccept(T_Employee *ptThis,T_Visitor i_tAcceptVisitor);
char * ManagerGetPerformance();
void ManagerSetPerformance(char *i_strPerformance);
//宏定义里面内容不可修改
#define newManager {NULL,0,EmployeeGetName,EmployeeSetName,EmployeeGetSalary,EmployeeSetSalary,\
				     ManagerAccept,ManagerGetPerformance,ManagerSetPerformance}

void CommonEmployeeAccept(T_Employee *ptThis,T_Visitor i_tAcceptVisitor);
char * CommonEmployeeGetJobContent();
void CommonEmployeeSetJobContent(char *i_strJobContent);
//宏定义里面内容不可修改
#define newCommonEmployee {NULL,0,EmployeeGetName,EmployeeSetName,EmployeeGetSalary,EmployeeSetSalary,\
				     		    CommonEmployeeAccept,CommonEmployeeGetJobContent,CommonEmployeeSetJobContent}

#endif

