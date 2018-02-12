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
void ClosingStateOpen()
{
	T_StateContext tStateContext=newStateContext;
	T_State tState=newOpenningState;
	tStateContext.SetState(&tState);//�л�״̬
	tStateContext.GetState(&tState);
	tState.Open();//ִ�У��߼��Ϲ��� ����һ̬
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
void ClosingStateClose()
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
void ClosingStateRun()
{
	T_StateContext tStateContext=newStateContext;
	T_State tState=newRunningState;
	tStateContext.SetState(&tState);//�л�״̬
	tStateContext.GetState(&tState);
	tState.Run();//ִ�У��߼��Ϲ��� ����һ̬
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
void ClosingStateStop()
{
	T_StateContext tStateContext=newStateContext;
	T_State tState=newStoppingState;
	tStateContext.SetState(&tState);//�л�״̬
	tStateContext.GetState(&tState);
	tState.Stop();//ִ�У��߼��Ϲ��� ����һ̬
}

