/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	StatePattern.c
* Description		: 	״̬ģʽ
						�Ը���״̬���й���Ҳ���Ը���ΪStateManage.c
						Ϊͳһ����,���ļ�Ҳ��״̬ģʽ�ĺ��Ĺʻ���
						����ΪStatePattern.c
						
						
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
-Description	: ���к���
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
-Description	: ���к���
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
-Description	: ���к���
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
-Description	: ���к���
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
-Description	: ���к���
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
	g_tState.tFatherState.SetContext(i_tStateContext);//�ڲ�������,�������������ʵ����
}

/*****************************************************************************
-Fuction		: SetState
-Description	: ���к���
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
-Description	: ���к���
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
-Description	: ���к���
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
-Description	: ���к���
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
-Description	: ���к���
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


