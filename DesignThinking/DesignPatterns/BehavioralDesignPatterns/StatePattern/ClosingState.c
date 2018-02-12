/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ClosingState.c
* Description		: 	关闭状态下的各种行为
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





/*****************************************************************************
-Fuction		: ClosingStateOpen
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void ClosingStateOpen(T_State *ptThis)
{
	ptThis->tFatherState.GetContext().SetState(ptThis->tFatherState.GetContext().GetOpenningState(),ptThis->tFatherState.GetContext());//切换状态
	ptThis->tFatherState.GetContext().Open();//执行，逻辑上过度 到下一态
}
/*****************************************************************************
-Fuction		: ClosingStateClose
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void ClosingStateClose(T_State *ptThis)
{
	printf("Lift door close!\r\n");
}
/*****************************************************************************
-Fuction		: ClosingStateRun
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void ClosingStateRun(T_State *ptThis)
{
	ptThis->tFatherState.GetContext().SetState(ptThis->tFatherState.GetContext().GetRunningState(),ptThis->tFatherState.GetContext());//切换状态
	ptThis->tFatherState.GetContext().Run();//执行，逻辑上过度 到下一态
}
/*****************************************************************************
-Fuction		: ClosingStateStop
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void ClosingStateStop(T_State *ptThis)
{
	ptThis->tFatherState.GetContext().SetState(ptThis->tFatherState.GetContext().GetStoppingState(),ptThis->tFatherState.GetContext());//切换状态
	ptThis->tFatherState.GetContext().Stop();//执行，逻辑上过度 到下一态
}

