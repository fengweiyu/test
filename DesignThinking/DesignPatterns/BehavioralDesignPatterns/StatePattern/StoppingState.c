/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	StoppingState.c
* Description		: 	ֹͣ״̬�µĸ�����Ϊ
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
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void StoppingStateOpen(T_State *ptThis)
{
	ptThis->tFatherState.GetContext().SetState(ptThis->tFatherState.GetContext().GetOpenningState(),ptThis->tFatherState.GetContext());//�л�״̬
	ptThis->tFatherState.GetContext().Open();//ִ�У��߼��Ϲ��� ����һ̬

}
/*****************************************************************************
-Fuction		: StoppingStateClose
-Description	: ֹͣ�����ž��ǹص�
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void StoppingStateClose(T_State *ptThis)
{

}
/*****************************************************************************
-Fuction		: StoppingStateRun
-Description	: ֹͣ������������
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void StoppingStateRun(T_State *ptThis)
{
	ptThis->tFatherState.GetContext().SetState(ptThis->tFatherState.GetContext().GetRunningState(),ptThis->tFatherState.GetContext());//�л�״̬
	ptThis->tFatherState.GetContext().Run();//ִ�У��߼��Ϲ��� ����һ̬
}
/*****************************************************************************
-Fuction		: StoppingStateStop
-Description	: ֹͣ�����õ�ֹͣ״̬
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void StoppingStateStop(T_State *ptThis)
{
	printf("Lift door stop!\r\n");
}


