/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	HighScoreDecorator.c
* Description		: 	装饰模式
						本文件是高分修饰类的具体实现
						
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
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void ReportHighScore()
{
	printf("这次语文考试最高是75,数学是78,自然是80\r\n");
}

/*****************************************************************************
-Fuction		: HighScoreDecoratorReport
-Description	: 公有函数
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
-Description	: 公有函数
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


