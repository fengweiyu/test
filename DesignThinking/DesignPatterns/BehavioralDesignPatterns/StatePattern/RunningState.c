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
void RunningStateOpen(T_State *ptThis)
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
void RunningStateClose(T_State *ptThis)
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
void RunningStateRun(T_State *ptThis)
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
void RunningStateStop(T_State *ptThis)
{
	ptThis->tFatherState.GetContext().SetState(ptThis->tFatherState.GetContext().GetStoppingState(),ptThis->tFatherState.GetContext());//�л�״̬
	ptThis->tFatherState.GetContext().Stop();//ִ�У��߼��Ϲ��� ����һ̬
}


