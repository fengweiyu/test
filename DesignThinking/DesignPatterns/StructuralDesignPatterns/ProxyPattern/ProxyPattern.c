/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ProxyPattern.c
* Description		: 	����ģʽ
						���ļ��Ǵ����ɫ
						����Ϸ�������	
						
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
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void SetGamePlayer(T_IGamePlayer i_tGamePlayer)
{//����T_GamePlayerΪֻ��,���Բ��ܴ�ַ��ʹ�ô�ֵ��ʽ,�������˸���
	memcpy(&g_tIGamePlayer,&i_tGamePlayer,sizeof(T_IGamePlayer));//����Ϳ���ȡַ��
}

/*****************************************************************************
-Fuction		: ProxyLogin
-Description	: ���к���
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
-Description	: ���к���
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
-Description	: ���к���
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

