/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	OpenningState.c
* Description		: 	开门状态下的各种行为
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
-Fuction		: OpenningStateOpen
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void OpenningStateOpen(T_State *ptThis)
{
	printf("Lift door open!\r\n");
}
/*****************************************************************************
-Fuction		: OpenningStateClose
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void OpenningStateClose(T_State *ptThis)
{
	ptThis->tFatherState.GetContext().SetState(ptThis->tFatherState.GetContext().GetClosingState(),ptThis->tFatherState.GetContext());//切换状态
	ptThis->tFatherState.GetContext().Close();//执行，逻辑上过度 到下一态
}
/*****************************************************************************
-Fuction		: OpenningStateRun
-Description	: 门开肯定不运行
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void OpenningStateRun(T_State *ptThis)
{

}
/*****************************************************************************
-Fuction		: OpenningStateStop
-Description	: 门开肯定停止了
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void OpenningStateStop(T_State *ptThis)
{

}


