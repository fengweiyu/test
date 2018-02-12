/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	VisitorPattern.h
* Description		: 	������ģʽ
									
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

typedef struct Visitor//��������
{//C����ʵ�����أ���ʱ�ö���������ʽ
	void (*ManagerVisit)(struct Manager *ptEmployee);//���ʺ���
	void (*CommonEmployeeVisit)(struct CommonEmployee *ptEmployee);//���ʺ���

	//void (*Visit)(struct Employee *ptEmployee);//���ʺ���
}T_Visitor;//�ӿ�

typedef struct Employee
{
	char *strName;//��Ϊ����������Ҫ���ԵĿռ�,����,������,˽�����ݳ�Ա������
	int iSalary;//����Ϊ��֤��ֱ�ӷ���˽�е����ݳ�Ա,��ΪԼ��,����ֻ��ͨ�����к���
	char  *(*GetName)(struct Employee *ptThis);//���庯��(����ʵ��)
	void (*SetName)(struct Employee *ptThis,char *i_strName);//���庯��(����ʵ��)
	int (*GetSalary)(struct Employee *ptThis);//���庯��(����ʵ��)
	void (*SetSalary)(struct Employee *ptThis,int i_iSalary);//���庯��(����ʵ��)
	//����ķ�����,��ѡ������ĸ�������//�����ڲ��Դ������ָ��ǿ��ת��
	void (*Accept)(struct Employee *ptThis,T_Visitor i_tAcceptVisitor);//������(��һ��ʵ��)
}T_Employee;//Ա��������

typedef struct CommonEmployee
{
	T_Employee tEmployee;
	char  *(*GetJobContent)();//���庯��(����ʵ��)
	void (*SetJobContent)(char *i_strJobContent);//���庯��(����ʵ��)
}T_CommonEmployee;

typedef struct Manager
{
	T_Employee tEmployee;
	char  *(*GetPerformance)();//���庯��(����ʵ��)
	void (*SetPerformance)(char *i_strPerformance);//���庯��(����ʵ��)
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
//�궨���������ݲ����޸�
#define newManager {NULL,0,EmployeeGetName,EmployeeSetName,EmployeeGetSalary,EmployeeSetSalary,\
				     ManagerAccept,ManagerGetPerformance,ManagerSetPerformance}

void CommonEmployeeAccept(T_Employee *ptThis,T_Visitor i_tAcceptVisitor);
char * CommonEmployeeGetJobContent();
void CommonEmployeeSetJobContent(char *i_strJobContent);
//�궨���������ݲ����޸�
#define newCommonEmployee {NULL,0,EmployeeGetName,EmployeeSetName,EmployeeGetSalary,EmployeeSetSalary,\
				     		    CommonEmployeeAccept,CommonEmployeeGetJobContent,CommonEmployeeSetJobContent}

#endif

