/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BridgePattern.h
* Description		: 	����ģʽ
									
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

}T_Product;//ʵ�ֻ���ɫ

typedef struct Corp
{
	T_Product tProduct;//��ͬ��˾��ͬ��Ʒ,���Զ���������//���촫�룬ͬʱ˽�б�������ֱ�ӷ���
	
	void (*MakeMoney)(struct Corp *ptThis);//�������˾��ְ�� ׬Ǯ
}T_Corp;//���󻯽�ɫ

typedef struct HouseCorp
{
	T_Corp tFatherCorp;//�̳�
	void (*MakeMoney)(struct HouseCorp *ptThis);
}T_HouseCorp;//�������󻯽�ɫ

typedef struct ShanzhaiCorp
{
	T_Corp tFatherCorp;
	void (*MakeMoney)(struct ShanzhaiCorp *ptThis);
}T_ShanzhaiCorp;//�������󻯽�ɫ

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

