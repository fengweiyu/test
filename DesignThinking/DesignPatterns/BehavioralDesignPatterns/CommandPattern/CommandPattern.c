/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	CommandPattern.c
* Description		: 	命令模式
						本文件是调用者(接收命令、执行命令)的实现
						(以客户给项目组发布命令举例,即项目接头人
						,接收客户发过来的命令,执行客户的命令)
									
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

static T_Command g_tCommand;//私有权限


const T_Invoker g_tInvoker={//单例，一个项目一个接头人
	.SetCommand	=SetCommand,
	.Action		=Action,
};
/*****************************************************************************
-Fuction		: SetCommand
-Description	: 公有函数
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
-Description	: 公有函数
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


