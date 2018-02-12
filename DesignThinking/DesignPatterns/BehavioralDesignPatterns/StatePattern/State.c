/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	State.c
* Description		: 	各种细分状态的父类,主要是切换状态的方法
						
						
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
#include"StatePattern.h"



static T_StateContext g_tStateContext;

/*****************************************************************************
-Fuction		: SetContext
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void SetContext(T_StateContext i_tStateContext)
{
	memcpy(&g_tStateContext,&i_tStateContext,sizeof(T_StateContext));
}

/*****************************************************************************
-Fuction		: SetState
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
T_StateContext GetContext()
{
	return g_tStateContext;
}



