/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ObserverPattern.h
* Description		: 	�۲���ģʽ
									
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
}T_Observer;//������۲���

typedef struct Observable
{
	int (*AddObserver)(T_Observer *i_ptObserver);//���Σ��ӿ�,Ҳ���ǳ������
	int (*DeleteObserver)(T_Observer *i_ptObserver);
	void (*NotifyObservers)(char *i_strContext);
}T_Observable;//��������۲���

typedef struct Hanfeizi//C�ľ���,ʹ�ü̳�(��д)����ʵ�������ӿڸ���
{//(�ٶ���һ��ʵ����,��װ��Ҳ����)
	T_Observable *ptObservable;
	void (*HaveBreakfast)();
	void (*HaveFun)();
}T_Hanfeizi;//���۲��߽ӿ�


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

