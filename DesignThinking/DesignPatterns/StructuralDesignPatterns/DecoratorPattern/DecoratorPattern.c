/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	DecoratorPattern.c
* Description		: 	装饰模式
						本文件是成绩单的具体实现(未被修饰)
						以修饰成绩单举例	
						
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
-Fuction		: SchoolReportReport
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void SchoolReportReport(void *i_ptThis)
{
	printf("尊敬的XXX家长:\r\n");
	printf(".......................................\r\n");
	printf("语文62，数学65，体育98，自然63\r\n");
	printf(".......................................\r\n");
	printf("                                 家长签名                       \r\n");
}

/*****************************************************************************
-Fuction		: SchoolReportSign
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void SchoolReportSign(void *i_ptThis,char *i_strName)
{	
	printf("家长签名为:%s\r\n",i_strName);
}


