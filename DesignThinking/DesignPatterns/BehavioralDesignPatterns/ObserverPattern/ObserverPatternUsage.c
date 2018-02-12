/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ObserverPatternUsage.c
* Description		: 	观察者模式的使用

book@book-desktop:/work/projects/test/DesignPatterns/ObserverPattern$ gcc -o ObserverPatternUsage ObserverLisi.c  ObserverWangsi.c  ObserverPattern.c ObserverPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/ObserverPattern$ ./ObserverPatternUsage 
韩非子:开始吃饭...
李斯:观察到韩非子活动,开始向秦老板汇报
李斯:报告,秦老板,韩非子有活动了-->韩非子在吃饭
李斯:汇报完毕...
王斯:观察到韩非子活动,自己也开始活动了...
王斯:因为韩非子在吃饭,所以我悲伤啊
王斯:哭死了...
韩非子:开始娱乐了...
李斯:观察到韩非子活动,开始向秦老板汇报
李斯:报告,秦老板,韩非子有活动了-->韩非子在娱乐
李斯:汇报完毕...

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


