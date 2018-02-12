/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	StatePattern.c
* Description		: 	状态模式
						对各个状态进行管理，也可以改名为StateManage.c
						为统一名称,本文件也是状态模式的核心故还是
						命名为StatePattern.c
						
						
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



static T_State g_tState;
static const T_State g_tClosingState=newClosingState;
static const T_State g_tStoppingState=newStoppingState;
static const T_State g_tRunningState=newRunningState;
static const T_State g_tOpenningState=newOpenningState;


/*****************************************************************************
-Fuction		: GetClosingState
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
T_State GetClosingState()
{
	return g_tClosingState;
}

/*****************************************************************************
-Fuction		: GetStoppingState
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
T_State GetStoppingState()
{
	return g_tStoppingState;
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
T_State GetRunningState()
{
	return g_tRunningState;
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
T_State GetOpenningState()
{
	return g_tOpenningState;
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
void SetState(T_State i_tState,T_StateContext i_tStateContext)
{
	memcpy(&g_tState,&i_tState,sizeof(T_State));//
	g_tState.tFatherState.SetContext(i_tStateContext);//内部是引用,方便子类调用先实例化
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
T_State GetState()
{
	return g_tState;
}
/*****************************************************************************
-Fuction		: Open
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void Open()
{
	g_tState.Open(&g_tState);
}
/*****************************************************************************
-Fuction		: Close
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void Close()
{
	g_tState.Close(&g_tState);
}
/*****************************************************************************
-Fuction		: Run
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void Run()
{
	g_tState.Run(&g_tState);
}
/*****************************************************************************
-Fuction		: Stop
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void Stop()
{
	g_tState.Stop(&g_tState);
}


