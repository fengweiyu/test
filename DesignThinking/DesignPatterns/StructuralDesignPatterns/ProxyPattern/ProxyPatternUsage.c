/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ProxyPatternUsage.c
* Description		: 	����ģʽ��ʹ��

book@book-desktop:/work/projects/test/DesignPatterns/ProxyPattern$ gcc -o ProxyPatternUsage GamePlayer.c ProxyPattern.c ProxyPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/ProxyPattern$ ./ProxyPatternUsage 
-----------------��ʼ����Ϸ----------------
��¼��ΪZhangSan���û�:����,��¼�ɹ�!
���� �ڴ��!
����������һ��!

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
	g_tGamePlayer.SetName("����");//�������
	g_tGamePlayerProxy.SetGamePlayer(g_tGamePlayer.tIGamePlayer);//���ô�����(��ʾ����˭)
	
	printf("-----------------��ʼ����Ϸ----------------\r\n");
	g_tGamePlayerProxy.tIGamePlayer.Login("ZhangSan","Password");
	g_tGamePlayerProxy.tIGamePlayer.KillBoss();
	g_tGamePlayerProxy.tIGamePlayer.Upgrade();
	
	return 0;
}


