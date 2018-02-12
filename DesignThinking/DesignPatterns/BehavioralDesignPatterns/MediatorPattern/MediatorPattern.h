/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	MediatorPattern.h
* Description		: 	�н���ģʽ
									
* Created			: 	2017.07.28.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef MEDIATOR_PATTERN_H
#define MEDIATOR_PATTERN_H

struct Mediator;

typedef struct Purchase
{
	struct Mediator *ptMediator;//˽�б������ⲿ��ֹ����
	void (*BuyIBMComputer)(struct Purchase *i_ptThis,int i_iNum);
	void (*RefuseBuyIBM)();
}T_Purchase;

typedef struct Stock
{
	struct Mediator *ptMediator;//˽�б������ⲿ��ֹ����
	void (*Increase)(struct Stock*i_ptThis,int i_iNum);
	void (*Decrease)(struct Stock*i_ptThis,int i_iNum);
	int (*GetStockNum)(struct Stock*i_ptThis);
	void (*ClearStock)(struct Stock*i_ptThis);
}T_Stock;

typedef struct Sale
{
	struct Mediator *ptMediator;//˽�б������ⲿ��ֹ����
	void (*SellIBMComputer)(struct Sale *i_ptThis,int i_iNum);
	int (*GetSaleStatus)(struct Sale *i_ptThis);
	void (*OffSale)(struct Sale *i_ptThis);
}T_Sale;

typedef struct Mediator
{
	T_Purchase tPurchase;//˽�б������ⲿ��ֹ����
	T_Stock tStock;//˽�б������ⲿ��ֹ����
	T_Sale tSale;//˽�б������ⲿ��ֹ����
	void (*Execute)(struct Mediator *i_ptThis,char *i_strCmd,int i_iNum);
}T_Mediator;

void BuyIBMComputer(T_Purchase *i_ptThis,int i_iNum);
void RefuseBuyIBM();
#define newPurchase(Mediator) {Mediator,BuyIBMComputer,RefuseBuyIBM}

void Increase(T_Stock *i_ptThis,int i_iNum);
void Decrease(T_Stock *i_ptThis,int i_iNum);
int GetStockNumber(T_Stock *i_ptThis);
void ClearStock(T_Stock *i_ptThis);
#define newStock(Mediator) {Mediator,Increase,Decrease,GetStockNumber,ClearStock}

void SellIBMComputer(T_Sale *i_ptThis,int i_iNum);
int GetSaleStatus(T_Sale *i_ptThis);
void OffSale(T_Sale *i_ptThis);
#define newSale(Mediator) {Mediator,SellIBMComputer,GetSaleStatus,OffSale}



void MediatorExecute(T_Mediator *i_ptThis,char *i_strCmd,int i_iNum);
#define newMediator(Mediator) {newPurchase(Mediator),newStock(Mediator),newSale(Mediator),MediatorExecute}

#endif

