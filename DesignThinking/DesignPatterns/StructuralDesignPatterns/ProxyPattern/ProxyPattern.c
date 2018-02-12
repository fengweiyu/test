/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ProxyPattern.c
* Description		: 	代理模式
						本文件是代理角色
						以游戏代理举例	
						
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

static void SetGamePlayer(T_IGamePlayer i_tGamePlayer);
static void ProxyLogin(char *i_strUserName,char *i_strPassword);
static void ProxyKillBoss();
static void ProxyUpgrade();

static T_IGamePlayer g_tIGamePlayer;

const T_GamePlayerProxy g_tGamePlayerProxy={
	.SetGamePlayer	=SetGamePlayer,
	.tIGamePlayer		={ProxyLogin,ProxyKillBoss,ProxyUpgrade},
};
/*****************************************************************************
-Fuction		: SetGamePlayer
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void SetGamePlayer(T_IGamePlayer i_tGamePlayer)
{//具体T_GamePlayer为只读,所以不能传址，使用传值形式,即拷贝了副本
	memcpy(&g_tIGamePlayer,&i_tGamePlayer,sizeof(T_IGamePlayer));//这里就可以取址了
}

/*****************************************************************************
-Fuction		: ProxyLogin
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void ProxyLogin(char *i_strUserName,char *i_strPassword)
{
	g_tIGamePlayer.Login(i_strUserName,i_strPassword);
}

/*****************************************************************************
-Fuction		: ProxyKillBoss
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void ProxyKillBoss()
{
	g_tIGamePlayer.KillBoss();
}

/*****************************************************************************
-Fuction		: ProxyUpgrade
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void ProxyUpgrade()
{
	g_tIGamePlayer.Upgrade();
}

