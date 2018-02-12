/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ObserverPattern.h
* Description		: 	观察者模式
									
* Created			: 	2017.07.13.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef OBSERVER_PATTERN_H
#define OBSERVER_PATTERN_H

#define MAX_OBSERVER_NUM	5
typedef struct Observer
{
	void (*Update)(char *i_strContext);
}T_Observer;//抽象出观察者

typedef struct Observable
{
	int (*AddObserver)(T_Observer *i_ptObserver);//传参，接口,也就是抽象耦合
	int (*DeleteObserver)(T_Observer *i_ptObserver);
	void (*NotifyObservers)(char *i_strContext);
}T_Observable;//抽象出被观察者

typedef struct Hanfeizi//C的局限,使用继承(覆写)代替实现两个接口更好
{//(少定义一个实现类,封装性也更好)
	T_Observable *ptObservable;
	void (*HaveBreakfast)();
	void (*HaveFun)();
}T_Hanfeizi;//被观察者接口


int HanfeiziAddObserver(T_Observer *i_ptObserver);
int HanfeiziDeleteObserver(T_Observer *i_ptObserver);
void HanfeiziNotifyObservers(char *i_strContext);
void HanfeiziHaveBreakfast();
void HanfeiziHaveFun();
#define newHanfeiziObservable {HanfeiziAddObserver,HanfeiziDeleteObserver,HanfeiziNotifyObservers}
#define newHanfeizi(Observable) {Observable,HanfeiziHaveBreakfast,HanfeiziHaveFun}


void LisiUpdate(char *i_strContext);
#define newLisiObserver {LisiUpdate}

void WangsiUpdate(char *i_strContext);
#define newWangsiObserver {WangsiUpdate}


#endif

