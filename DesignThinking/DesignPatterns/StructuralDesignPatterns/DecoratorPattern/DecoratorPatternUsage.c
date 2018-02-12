/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	DecoratorPatternUsage.c
* Description		: 	װ��ģʽ��ʹ��

book@book-desktop:/work/projects/test/DesignPatterns/DecoratorPattern$ gcc -o DecoratorPatternUsage HighScoreDecorator.c SortDecorator.c DecoratorPattern.c DecoratorPatternUsage.c
book@book-desktop:/work/projects/test/DesignPatterns/DecoratorPattern$ ./DecoratorPatternUsage 
������Ŀ��������75,��ѧ��78,��Ȼ��80
�𾴵�XXX�ҳ�:
.......................................
����62����ѧ65������98����Ȼ63
.......................................
                                 �ҳ�ǩ��                       
�ҳ�ǩ��Ϊ:����
�𾴵�XXX�ҳ�:
.......................................
����62����ѧ65������98����Ȼ63
.......................................
                                 �ҳ�ǩ��                       
������33
�ҳ�ǩ��Ϊ:����

* Created			: 	2017.07.25.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"DecoratorPattern.h"




/*****************************************************************************
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/25    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_SchoolReport tSchoolReport=newFourthGradeSchoolReport;

	T_Decorator tDecorator=newHighScoreDecorator(tSchoolReport);
	tDecorator.tDecoratorReport.Report(&tDecorator);
	tDecorator.tDecoratorReport.Sign(&tDecorator,"����");
	//��������ת�ͱȽ���ʵ��,�ݲ�֧�ֶ�������
	tDecorator=(T_Decorator)newSortDecorator(tSchoolReport);
	tDecorator.tDecoratorReport.Report(&tDecorator);
	tDecorator.tDecoratorReport.Sign(&tDecorator,"����");
	return 0;
}


