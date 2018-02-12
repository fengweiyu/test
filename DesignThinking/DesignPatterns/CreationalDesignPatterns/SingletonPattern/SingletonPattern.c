/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SingletonPattern.c
* Description		: 	����ģʽ
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


static char *g_strSingleton="Singleton";//˽�б���
static int g_iId=0;//˽�б���



//����ģʽ�õ���ʱ��ų�ʼ��,�̲߳���ȫ(Ҫ�������)
//һ��ʹ�ö���ģʽ,�ǳ������Ȳ�����Ҳ����һ��ʼ������(��ʼ����)
const T_Singleton g_tSingleton={
	.PrintInfo	=PrintInfo,
	.SetId	=SetId,
	.GetId	=GetId,
};


/*****************************************************************************
-Fuction		: PrintInfo
-Description	: ���к���(����ģʽ���Բż���static)
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
-Description	: ���к���(����ģʽ���Բż���static)
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
-Description	: ���к���(����ģʽ���Բż���static)
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


