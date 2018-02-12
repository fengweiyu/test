/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ObserverWangsi.c
* Description		: 	观察者王斯
						本文件是观察者实现类王斯的动作
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
-Fuction		: WangsiCry
-Description	: 私有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/13	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void WangsiCry(char *i_strContext)
{
	printf("王斯:因为%s,所以我悲伤啊\r\n",i_strContext);
}

/*****************************************************************************
-Fuction		: WangsiUpdate
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/13	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void WangsiUpdate(char *i_strContext)
{
	printf("王斯:观察到韩非子活动,自己也开始活动了...\r\n");
	WangsiCry(i_strContext);
	printf("王斯:哭死了...\r\n");
}




