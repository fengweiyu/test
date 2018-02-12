/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ProxyPattern.h
* Description		: 	����ģʽ
									
* Created			: 	2017.07.21.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef PROXY_PATTERN_H
#define PROXY_PATTERN_H


typedef struct IGamePlayer
{
	void (*Login)(char *i_strUserName,char *i_strPassword);
	void (*KillBoss)();
	void (*Upgrade)();
}T_IGamePlayer;

typedef struct GamePlayer
{
	T_IGamePlayer tIGamePlayer;//ʵ��ͬһ���ӿ�
	void (*SetName)(char *i_strName);//˽�б������ڲ������ⲿ��ԭ����
	//���ⲿ,��Ҫ�޸Ľӿ�,
}T_GamePlayer;

typedef struct GamePlayerProxy
{
	T_IGamePlayer tIGamePlayer;//ʵ��ͬһ���ӿ�
	void (*SetGamePlayer)(T_IGamePlayer i_tGamePlayer);//˽�б������ڲ������ⲿ��ԭ����
	//���ⲿ,��Ҫ�޸Ľӿ�,���½ӿ��ڷ������������Լ���ø���
}T_GamePlayerProxy;


const T_GamePlayerProxy g_tGamePlayerProxy;//˽�б������ڲ�,����ģʽ
//���������չ����������T_GamePlayerProxy������,�γ������޵Ķ���ģʽ(����ģʽ����չ,��Ϊʵ�������Ѿ�����õ�,�̶���)
//û���ṩnew����,�ⲿ������new������new������ֻ��ʹ�ù̶�����һ��(�򼸸�)ʵ��(�Ѿ�����õ�),����ǵ���ģʽ(��������չ)
const T_GamePlayer g_tGamePlayer;//˽�б������ڲ�,����ģʽ

#endif

