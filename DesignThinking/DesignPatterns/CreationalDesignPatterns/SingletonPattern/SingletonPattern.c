/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SingletonPattern.c
* Description		: 	单例模式
* Created			: 	2017.07.02.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"SingletonPattern.h"

static void PrintInfo();
static void SetId(int i_iId);
static int GetId();


static char *g_strSingleton="Singleton";//私有变量
static int g_iId=0;//私有变量



//懒汉模式用到的时候才初始化,线程不安全(要加锁解决)
//一般使用饿汉模式,非常饿，迫不及待也就是一开始就做了(初始化了)
const T_Singleton g_tSingleton={
	.PrintInfo	=PrintInfo,
	.SetId	=SetId,
	.GetId	=GetId,
};


/*****************************************************************************
-Fuction		: PrintInfo
-Description	: 公有函数(单例模式所以才加了static)
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void PrintInfo()
{
	printf("This is:%s\r\n",g_strSingleton);
}

/*****************************************************************************
-Fuction		: SetId
-Description	: 公有函数(单例模式所以才加了static)
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void SetId(int i_iId)
{
	g_iId=i_iId;
}

/*****************************************************************************
-Fuction		: GetId
-Description	: 公有函数(单例模式所以才加了static)
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int GetId()
{
	return g_iId;
}


