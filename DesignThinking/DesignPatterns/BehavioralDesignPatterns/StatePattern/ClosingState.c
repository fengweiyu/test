/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ClosingState.c
* Description		: 	�ر�״̬�µĸ�����Ϊ
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
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void ClosingStateOpen(T_State *ptThis)
{
	ptThis->tFatherState.GetContext().SetState(ptThis->tFatherState.GetContext().GetOpenningState(),ptThis->tFatherState.GetContext());//�л�״̬
	ptThis->tFatherState.GetContext().Open();//ִ�У��߼��Ϲ��� ����һ̬
}
/*****************************************************************************
-Fuction		: ClosingStateClose
-Description	: ���к���
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
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void ClosingStateRun(T_State *ptThis)
{
	ptThis->tFatherState.GetContext().SetState(ptThis->tFatherState.GetContext().GetRunningState(),ptThis->tFatherState.GetContext());//�л�״̬
	ptThis->tFatherState.GetContext().Run();//ִ�У��߼��Ϲ��� ����һ̬
}
/*****************************************************************************
-Fuction		: ClosingStateStop
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void ClosingStateStop(T_State *ptThis)
{
	ptThis->tFatherState.GetContext().SetState(ptThis->tFatherState.GetContext().GetStoppingState(),ptThis->tFatherState.GetContext());//�л�״̬
	ptThis->tFatherState.GetContext().Stop();//ִ�У��߼��Ϲ��� ����һ̬
}

