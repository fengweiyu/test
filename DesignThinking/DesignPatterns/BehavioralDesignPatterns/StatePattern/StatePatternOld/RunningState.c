/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	RunningState.c
* Description		: 	����״̬�µĸ�����Ϊ
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
-Description	: ���в��ܴ�
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
-Description	: ���п϶��ر�
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
-Description	: ���к���
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
-Description	: ���к���
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
	tStateContext.SetState(&tState);//�л�״̬
	tStateContext.GetState(&tState);
	tState.Stop();//ִ�У��߼��Ϲ��� ����һ̬
}


