/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	DecoratorPattern.h
* Description		: 	װ��ģʽ
									
* Created			: 	2017.07.25.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef DECORATOR_PATTERN_H
#define DECORATOR_PATTERN_H

struct Decorator;

typedef struct SchoolReport
{
	void (*Report)(void *i_ptThis);//Ϊ����ͳһ,����i_ptThis,�ڲ��ɲ�ʹ��,
	void (*Sign)(void *i_ptThis,char *i_strName);//���ʹ�õ���,����ȥ��i_ptThis
}T_SchoolReport;//����i_ptThis��T_Decorator ʹ��,�ڲ�ʹ����Ҫת��ΪT_Decorator *,Ҳ���԰����ߵ�void *��Ϊstruct Decorator*

typedef struct Decorator
{
	T_SchoolReport tSchoolReport;//˽�б���,����ֱ�ӷ���
	T_SchoolReport tDecoratorReport;//����,��ǿ����

}T_Decorator;


void SchoolReportReport(void *i_ptThis);
void SchoolReportSign(void *i_ptThis,char *i_strName);
#define newFourthGradeSchoolReport {SchoolReportReport,SchoolReportSign}


void HighScoreDecoratorReport(void *i_ptThis);
void HighScoreDecoratorSign(void *i_ptThis,char *i_strName);
#define newHighScoreDecorator(SchoolReport) {SchoolReport,HighScoreDecoratorReport,HighScoreDecoratorSign}

void SortDecoratorReport(void *i_ptThis);
void SortDecoratorSign(void *i_ptThis,char *i_strName);
#define newSortDecorator(SchoolReport) {SchoolReport,SortDecoratorReport,SortDecoratorSign}

#endif

