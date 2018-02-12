/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	CommandPattern.c
* Description		: 	����ģʽ
						���ļ��ǵ�����(�������ִ������)��ʵ��
						(�Կͻ�����Ŀ�鷢���������,����Ŀ��ͷ��
						,���տͻ�������������,ִ�пͻ�������)
									
* Created			: 	2017.07.18.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"CommandPattern.h"

static void SetCommand(T_Command *i_ptCommand);
static void Action();

static T_Command g_tCommand;//˽��Ȩ��


const T_Invoker g_tInvoker={//������һ����Ŀһ����ͷ��
	.SetCommand	=SetCommand,
	.Action		=Action,
};
/*****************************************************************************
-Fuction		: SetCommand
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void SetCommand(T_Command *i_ptCommand)
{
	memcpy(&g_tCommand,i_ptCommand,sizeof(T_Command));
}
/*****************************************************************************
-Fuction		: SetCommand
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/17	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void Action()
{
	g_tCommand.Execute(&g_tCommand);
}


