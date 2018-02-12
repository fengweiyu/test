/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ProxyPattern.h
* Description		: 	代理模式
									
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
	T_IGamePlayer tIGamePlayer;//实现同一个接口
	void (*SetName)(char *i_strName);//私有变量放内部不放外部的原因是
	//放外部,则要修改接口,
}T_GamePlayer;

typedef struct GamePlayerProxy
{
	T_IGamePlayer tIGamePlayer;//实现同一个接口
	void (*SetGamePlayer)(T_IGamePlayer i_tGamePlayer);//私有变量放内部不放外部的原因是
	//放外部,则要修改接口,导致接口内方法参数增加以及变得复杂
}T_GamePlayerProxy;


const T_GamePlayerProxy g_tGamePlayerProxy;//私有变量放内部,单例模式
//如果考虑扩展，可以再以T_GamePlayerProxy来构造,形成有上限的多例模式(单例模式的扩展,因为实例都是已经构造好的,固定的)
//没有提供new方法,外部不能想new几个就new几个，只能使用固定的那一个(或几个)实例(已经构造好的),因此是单例模式(或是其扩展)
const T_GamePlayer g_tGamePlayer;//私有变量放内部,单例模式

#endif

