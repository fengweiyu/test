/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BridgePattern.h
* Description		: 	桥梁模式
									
* Created			: 	2017.07.20.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef BRIDGE_PATTERN_H
#define BRIDGE_PATTERN_H

typedef struct Product
{
	void (*BeProducted)();
	void (*BeSelled)();

}T_Product;//实现化角色

typedef struct Corp
{
	T_Product tProduct;//不同公司不同产品,所以定义在外面//构造传入，同时私有变量不可直接访问
	
	void (*MakeMoney)(struct Corp *ptThis);//抽象出公司的职责 赚钱
}T_Corp;//抽象化角色

typedef struct HouseCorp
{
	T_Corp tFatherCorp;//继承
	void (*MakeMoney)(struct HouseCorp *ptThis);
}T_HouseCorp;//修正抽象化角色

typedef struct ShanzhaiCorp
{
	T_Corp tFatherCorp;
	void (*MakeMoney)(struct ShanzhaiCorp *ptThis);
}T_ShanzhaiCorp;//修正抽象化角色

void MakeMoney(T_Corp *i_ptThis);

void ShanzhaiCorpMakeMoney(T_ShanzhaiCorp *i_ptThis);
#define newShanzhaiCorp(Product) {Product,MakeMoney,ShanzhaiCorpMakeMoney}

void HouseCorpMakeMoney(T_HouseCorp *i_ptThis);
#define newHouseCorp(Product) {Product,MakeMoney,HouseCorpMakeMoney}


void HouseBeProducted();
void HouseBeSelled();
#define newHouseProduct {HouseBeProducted,HouseBeSelled}

void IPodBeProducted();
void IPodBeSelled();
#define newIPodProduct {IPodBeProducted,IPodBeSelled}

void ClothesBeProducted();
void ClothesBeSelled();
#define newClothesProduct {ClothesBeProducted,ClothesBeSelled}


#endif

