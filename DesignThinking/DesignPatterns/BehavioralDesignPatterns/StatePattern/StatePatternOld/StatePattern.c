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
void SetState(T_State *i_ptState)
{
	memcpy(&g_tState,i_ptState,sizeof(T_State));
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
void GetState(T_State *o_ptState)
{
	memcpy(o_ptState,&g_tState,sizeof(T_State));
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
	g_tState.Open();
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
	g_tState.Close();
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
	g_tState.Run();
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
	g_tState.Stop();
}


