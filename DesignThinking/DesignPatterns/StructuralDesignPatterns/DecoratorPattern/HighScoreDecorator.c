/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	HighScoreDecorator.c
* Description		: 	װ��ģʽ
						���ļ��Ǹ߷�������ľ���ʵ��
						
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
-Fuction		: ReportHighScore
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void ReportHighScore()
{
	printf("������Ŀ��������75,��ѧ��78,��Ȼ��80\r\n");
}

/*****************************************************************************
-Fuction		: HighScoreDecoratorReport
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void HighScoreDecoratorReport(void *i_ptThis)
{
	T_Decorator *ptHighScoreDecorator=(T_Decorator *)i_ptThis;
	ReportHighScore();
	ptHighScoreDecorator->tSchoolReport.Report((void *)ptHighScoreDecorator);
}

/*****************************************************************************
-Fuction		: DecoratorSign
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void HighScoreDecoratorSign(void *i_ptThis,char *i_strName)
{	
	T_Decorator *ptHighScoreDecorator=(T_Decorator *)i_ptThis;
	ptHighScoreDecorator->tSchoolReport.Sign((void *)ptHighScoreDecorator,i_strName);
}


