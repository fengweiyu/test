/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SortDecorator.c
* Description		: 	装饰模式
						本文件是排名类的具体实现
						
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
static void ReportSort()
{
	printf("排名第33\r\n");
}
/*****************************************************************************
-Fuction		: SortDecoratorReport
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void SortDecoratorReport(void *i_ptThis)
{
	T_Decorator *ptSortDecorator=(T_Decorator *)i_ptThis;
	ptSortDecorator->tSchoolReport.Report((void *)ptSortDecorator);
	ReportSort();
}

/*****************************************************************************
-Fuction		: SortDecoratorSign
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void SortDecoratorSign(void *i_ptThis,char *i_strName)
{	
	T_Decorator *ptSortDecorator=(T_Decorator *)i_ptThis;
	ptSortDecorator->tSchoolReport.Sign((void *)ptSortDecorator,i_strName);
}




