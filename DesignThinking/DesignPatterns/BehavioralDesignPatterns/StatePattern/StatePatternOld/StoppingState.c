/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	StoppingState.c
* Description		: 	停止状态下的各种行为
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
-Fuction		: StoppingStateOpen
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void StoppingStateOpen()
{
	T_StateContext tStateContext=newStateContext;
	T_State tState=newOpenningState;
	tStateContext.SetState(&tState);//切换状态
	tStateContext.GetState(&tState);
	tState.Open();//执行，逻辑上过度 到下一态

}
/*****************************************************************************
-Fuction		: StoppingStateClose
-Description	: 停止本来门就是关的
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void StoppingStateClose()
{

}
/*****************************************************************************
-Fuction		: StoppingStateRun
-Description	: 停止接下来再运行
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void StoppingStateRun()
{
	T_StateContext tStateContext=newStateContext;
	T_State tState=newRunningState;
	tStateContext.SetState(&tState);//切换状态
	tStateContext.GetState(&tState);
	tState.Run();//执行，逻辑上过度 到下一态
}
/*****************************************************************************
-Fuction		: StoppingStateStop
-Description	: 停止动作得到停止状态
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void StoppingStateStop()
{
	printf("Lift door stop!\r\n");
}


