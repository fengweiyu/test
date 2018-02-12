/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	AdapterPattern.h
* Description		: 	适配器模式
									
* Created			: 	2017.07.26.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef ADAPTER_PATTERN_H
#define ADAPTER_PATTERN_H

typedef struct Duck
{//ptThis有的实现类要用,有的不用,为统一使用void *
	void (*Cry)(void *ptThis);//由于void *外部调用者无法确定传入什么类型(要根据具体实现类使用情况判断,
	void (*Appearance)(void *ptThis);//一般都是直接传入本对象,而不是本对象的子类对象)
	void (*Behavior)(void *ptThis);//如果不考虑统一性,可不使用void *，用具体类型代替,如T_UglyDuckling *
}T_Duck;//目标角色

typedef struct Swan
{
	void (*Cry)();//叫声
	void (*Appearance)();//外观
	void (*Fly)();
}T_Swan;//源角色

typedef struct UglyDuckling//适配器角色,
{
	T_Swan tFatherSwan;;//源角色(通过继承获取源角色信息)
	T_Duck tDuck;//目标角色(利用继承的信息实现鸭子接口,也就适配出鸭子)
}T_UglyDuckling;//适配器角色,把白天鹅适配成鸭子,


void DucklingCry(void *i_ptThis);
void DucklingAppearance(void *i_ptThis);
void DucklingBehavior(void *i_ptThis);
#define newDuckling {DucklingCry,DucklingAppearance,DucklingBehavior}

void WhiteSwanCry();
void WhiteSwanAppearance();
void WhiteSwanFly();
#define newWhiteSwanFly {WhiteSwanCry,WhiteSwanAppearance,WhiteSwanFly}

void UglyDucklingCry(void *i_ptThis);
void UglyDucklingAppearance(void *i_ptThis);
void UglyDucklingBehavior(void *i_ptThis);
#define newUglyDuckling {newWhiteSwanFly,UglyDucklingCry,UglyDucklingAppearance,UglyDucklingBehavior}

#endif

