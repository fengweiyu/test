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
void StoppingStateOpen()
{
	T_StateContext tStateContext=newStateContext;
	T_State tState=newOpenningState;
	tStateContext.SetState(&tState);//�л�״̬
	tStateContext.GetState(&tState);
	tState.Open();//ִ�У��߼��Ϲ��� ����һ̬

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
void StoppingStateClose()
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
void StoppingStateRun()
{
	T_StateContext tStateContext=newStateContext;
	T_State tState=newRunningState;
	tStateContext.SetState(&tState);//�л�״̬
	tStateContext.GetState(&tState);
	tState.Run();//ִ�У��߼��Ϲ��� ����һ̬
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
void StoppingStateStop()
{
	printf("Lift door stop!\r\n");
}


