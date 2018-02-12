/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	DecoratorPattern.h
* Description		: 	装饰模式
									
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
	void (*Report)(void *i_ptThis);//为保持统一,加入i_ptThis,内部可不使用,
	void (*Sign)(void *i_ptThis,char *i_strName);//如果使用单例,可以去掉i_ptThis
}T_SchoolReport;//由于i_ptThis是T_Decorator 使用,内部使用是要转换为T_Decorator *,也可以把上诉的void *改为struct Decorator*

typedef struct Decorator
{
	T_SchoolReport tSchoolReport;//私有变量,不能直接访问
	T_SchoolReport tDecoratorReport;//修饰,加强功能

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

