/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	GamePlayer.c
* Description		: 	����ģʽ
						���ļ�����Ϸ��ɫ
						
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
-Description	: ���к���
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
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void GamePlayerLogin(char *i_strUserName,char *i_strPassword)
{
	printf("��¼��Ϊ%s���û�:%s,��¼�ɹ�!\r\n",i_strUserName,g_strGamePlayerName);
}

/*****************************************************************************
-Fuction		: GamePlayerKillBoss
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void GamePlayerKillBoss()
{
	printf("%s �ڴ��!\r\n",g_strGamePlayerName);
}

/*****************************************************************************
-Fuction		: GamePlayerUpgrade
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void GamePlayerUpgrade()
{
	printf("%s������һ��!\r\n",g_strGamePlayerName);
}


