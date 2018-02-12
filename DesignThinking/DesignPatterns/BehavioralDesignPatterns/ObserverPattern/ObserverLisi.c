/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ObserverLisi.c
* Description		: 	观察者李斯
						本文件是观察者实现类李斯的动作
* Created			: 	2017.07.13.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"ObserverPattern.h"

/*****************************************************************************
-Fuction		: LisiReportToQinshihuang
-Description	: 私有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/13	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void LisiReportToQinshihuang(char *i_strContext)
{
	printf("李斯:报告,秦老板,韩非子有活动了-->%s\r\n",i_strContext);
}

/*****************************************************************************
-Fuction		: LisiUpdate
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/13	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void LisiUpdate(char *i_strContext)
{
	printf("李斯:观察到韩非子活动,开始向秦老板汇报\r\n");
	LisiReportToQinshihuang(i_strContext);
	printf("李斯:汇报完毕...\r\n");
}



