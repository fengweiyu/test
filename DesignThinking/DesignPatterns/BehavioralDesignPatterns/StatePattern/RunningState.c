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
void RunningStateOpen(T_State *ptThis)
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
void RunningStateClose(T_State *ptThis)
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
void RunningStateRun(T_State *ptThis)
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
void RunningStateStop(T_State *ptThis)
{
	ptThis->tFatherState.GetContext().SetState(ptThis->tFatherState.GetContext().GetStoppingState(),ptThis->tFatherState.GetContext());//切换状态
	ptThis->tFatherState.GetContext().Stop();//执行，逻辑上过度 到下一态
}


