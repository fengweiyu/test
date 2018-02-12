/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	TemplateMethodPattern.c
* Description		: 	模版方法模式
						主要放模版方法，同时模版方法调用各个基本方法
						，所以也可以改名为TemplateMethod.c
						为统一名称,本文件也是模版方法模式的核心故还是
						命名为TemplateMethodPattern.c
									
* Created			: 	2017.07.12.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"TemplateMethodPattern.h"


/*****************************************************************************
-Fuction		: HummerRun
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void HummerRun(T_HummerModel *i_ptHummerModel)
{
	i_ptHummerModel->Start();
	i_ptHummerModel->EngineBoom();
	i_ptHummerModel->Alarm();
	i_ptHummerModel->Stop();
}


