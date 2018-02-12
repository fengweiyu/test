/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ObserverPattern.c
* Description		: 	观察者模式
						本文件是被观察者实现类
						以韩非子的活动被李斯,王斯观察举例,显然
						韩非子是被观察者
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


static T_Observer g_atObserver[MAX_OBSERVER_NUM]={NULL};
static int g_iObserverLen=0;

/*****************************************************************************
-Fuction		: HanfeiziAddObserver
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/13	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int HanfeiziAddObserver(T_Observer *i_ptObserver)
{
	int iRet=-1;
	if(g_iObserverLen>=MAX_OBSERVER_NUM)
	{
		printf("ObserverArray full!\r\n");
		iRet=-1;
	}
	else
	{
		memcpy(&g_atObserver[g_iObserverLen],i_ptObserver,sizeof(T_Observer));
		g_iObserverLen++;
		//printf("ObserverLen:%d\r\n",g_iObserverLen);
		iRet=0;
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: HanfeiziAddObserver
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/13	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int HanfeiziDeleteObserver(T_Observer *i_ptObserver)
{
	int iRet=-1;
	int i;
	if(g_iObserverLen==0)
	{
		printf("ObserverArray empty!\r\n");
		iRet=-1;
	}
	else
	{
		for(i=0;i<g_iObserverLen;i++)
		{
			if(0==memcmp(&g_atObserver[i],i_ptObserver,sizeof(T_Observer)))
			{
				break;
			}
			else
			{
			}
		}
		if(i>=g_iObserverLen)
		{
			printf("HanfeiziDeleteObserver err!\r\n");
			iRet=-1;
		}
		else
		{
			for(;i<g_iObserverLen-1;i++)
			{
				memcpy(&g_atObserver[i],&g_atObserver[i+1],sizeof(T_Observer));
			}
			g_iObserverLen--;
			iRet=0;
		}
	}
	return iRet;
}

/*****************************************************************************
-Fuction		: HanfeiziNotifyObservers
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/13	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void HanfeiziNotifyObservers(char *i_strContext)
{
	int i;
	for(i=0;i<g_iObserverLen;i++)
	{//通知所有观察这
		g_atObserver[i].Update(i_strContext);
	}
}


/*****************************************************************************
-Fuction		: HanfeiziHaveBreakfast
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/13	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void HanfeiziHaveBreakfast()
{
	printf("韩非子:开始吃饭...\r\n");
	//通知所有观察者
	HanfeiziNotifyObservers("韩非子在吃饭");
}

/*****************************************************************************
-Fuction		: HanfeiziHaveFun
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/13	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void HanfeiziHaveFun()
{
	printf("韩非子:开始娱乐了...\r\n");
	//通知所有观察者
	HanfeiziNotifyObservers("韩非子在娱乐");
}


