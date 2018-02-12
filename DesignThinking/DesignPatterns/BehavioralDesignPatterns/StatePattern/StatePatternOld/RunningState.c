/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	RunningState.c
* Description		: 	运行状态下的各种行为
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
-Fuction		: RunningStateOpen
-Description	: 运行不能打开
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void RunningStateOpen()
{
}
/*****************************************************************************
-Fuction		: RunningStateClose
-Description	: 运行肯定关闭
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void RunningStateClose()
{

}
/*****************************************************************************
-Fuction		: RunningStateRun
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void RunningStateRun()
{
	printf("Lift door run!\r\n");
}
/*****************************************************************************
-Fuction		: RunningStateStop
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void RunningStateStop()
{
	T_StateContext tStateContext=newStateContext;
	T_State tState=newStoppingState;
	tStateContext.SetState(&tState);//切换状态
	tStateContext.GetState(&tState);
	tState.Stop();//执行，逻辑上过度 到下一态
}


