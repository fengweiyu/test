/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	OpenningState.c
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
-Fuction		: OpenningStateOpen
-Description	: ���к���
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
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void OpenningStateClose(T_State *ptThis)
{
	ptThis->tFatherState.GetContext().SetState(ptThis->tFatherState.GetContext().GetClosingState(),ptThis->tFatherState.GetContext());//�л�״̬
	ptThis->tFatherState.GetContext().Close();//ִ�У��߼��Ϲ��� ����һ̬
}
/*****************************************************************************
-Fuction		: OpenningStateRun
-Description	: �ſ��϶�������
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
-Description	: �ſ��϶�ֹͣ��
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


