/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	GamePlayer.c
* Description		: 	代理模式
						本文件是游戏角色
						
* Created			: 	2017.07.21.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"ProxyPattern.h"

static void SetGamePlayerName(char *i_strName);
static void GamePlayerLogin(char *i_strUserName,char *i_strPassword);
static void GamePlayerKillBoss();
static void GamePlayerUpgrade();
static char *g_strGamePlayerName=NULL;


const T_GamePlayer g_tGamePlayer={
	.SetName			=SetGamePlayerName,
	.tIGamePlayer		={GamePlayerLogin,GamePlayerKillBoss,GamePlayerUpgrade},
};
/*****************************************************************************
-Fuction		: SetGamePlayerName
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void SetGamePlayerName(char *i_strName)
{
	g_strGamePlayerName=i_strName;
}

/*****************************************************************************
-Fuction		: GamePlayerLogin
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void GamePlayerLogin(char *i_strUserName,char *i_strPassword)
{
	printf("登录名为%s的用户:%s,登录成功!\r\n",i_strUserName,g_strGamePlayerName);
}

/*****************************************************************************
-Fuction		: GamePlayerKillBoss
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void GamePlayerKillBoss()
{
	printf("%s 在打怪!\r\n",g_strGamePlayerName);
}

/*****************************************************************************
-Fuction		: GamePlayerUpgrade
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void GamePlayerUpgrade()
{
	printf("%s又升了一级!\r\n",g_strGamePlayerName);
}


