/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ProxyPatternUsage.c
* Description		: 	代理模式的使用

book@book-desktop:/work/projects/test/DesignPatterns/ProxyPattern$ gcc -o ProxyPatternUsage GamePlayer.c ProxyPattern.c ProxyPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/ProxyPattern$ ./ProxyPatternUsage 
-----------------开始打游戏----------------
登录名为ZhangSan的用户:张三,登录成功!
张三 在打怪!
张三又升了一级!

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




/*****************************************************************************
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/19    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	g_tGamePlayer.SetName("张三");//设置玩家
	g_tGamePlayerProxy.SetGamePlayer(g_tGamePlayer.tIGamePlayer);//设置代理者(表示代理谁)
	
	printf("-----------------开始打游戏----------------\r\n");
	g_tGamePlayerProxy.tIGamePlayer.Login("ZhangSan","Password");
	g_tGamePlayerProxy.tIGamePlayer.KillBoss();
	g_tGamePlayerProxy.tIGamePlayer.Upgrade();
	
	return 0;
}


