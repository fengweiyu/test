/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ObserverPatternUsage.c
* Description		: 	�۲���ģʽ��ʹ��

book@book-desktop:/work/projects/test/DesignPatterns/ObserverPattern$ gcc -o ObserverPatternUsage ObserverLisi.c  ObserverWangsi.c  ObserverPattern.c ObserverPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/ObserverPattern$ ./ObserverPatternUsage 
������:��ʼ�Է�...
��˹:�۲쵽�����ӻ,��ʼ�����ϰ�㱨
��˹:����,���ϰ�,�������л��-->�������ڳԷ�
��˹:�㱨���...
��˹:�۲쵽�����ӻ,�Լ�Ҳ��ʼ���...
��˹:��Ϊ�������ڳԷ�,�����ұ��˰�
��˹:������...
������:��ʼ������...
��˹:�۲쵽�����ӻ,��ʼ�����ϰ�㱨
��˹:����,���ϰ�,�������л��-->������������
��˹:�㱨���...

* Created			: 	2017.07.13.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"ObserverPattern.h"




/*****************************************************************************
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/13    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_Observer Lisi=newLisiObserver;
	T_Observer Wangsi=newWangsiObserver;
	
	T_Observable tObserver=newHanfeiziObservable;
	T_Hanfeizi Hanfeizi=newHanfeizi(&tObserver);

	Hanfeizi.ptObservable->AddObserver(&Lisi);
	Hanfeizi.ptObservable->AddObserver(&Wangsi);
	Hanfeizi.HaveBreakfast();

	Hanfeizi.ptObservable->DeleteObserver(&Wangsi);
	Hanfeizi.HaveFun();

	
	return 0;
}


