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
void ClosingStateOpen()
{
	T_StateContext tStateContext=newStateContext;
	T_State tState=newOpenningState;
	tStateContext.SetState(&tState);//切换状态
	tStateContext.GetState(&tState);
	tState.Open();//执行，逻辑上过度 到下一态
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
void ClosingStateClose()
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
void ClosingStateRun()
{
	T_StateContext tStateContext=newStateContext;
	T_State tState=newRunningState;
	tStateContext.SetState(&tState);//切换状态
	tStateContext.GetState(&tState);
	tState.Run();//执行，逻辑上过度 到下一态
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
void ClosingStateStop()
{
	T_StateContext tStateContext=newStateContext;
	T_State tState=newStoppingState;
	tStateContext.SetState(&tState);//切换状态
	tStateContext.GetState(&tState);
	tState.Stop();//执行，逻辑上过度 到下一态
}

