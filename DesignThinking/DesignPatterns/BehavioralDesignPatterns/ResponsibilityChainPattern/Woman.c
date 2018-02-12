/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	Woman.c
* Description		: 	责任链模式中的角色
						请求者(女性)
* Created			: 	2017.07.14.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"ResponsibilityChainPattern.h"



static int g_iType=FATHER_HANDLE_LEVEL;
static char *g_strRequest="女儿的请求是:我要出去逛街";
/*****************************************************************************
-Fuction		: GetRequest
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14 	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
char *GetRequest()
{
	return g_strRequest;
}
/*****************************************************************************
-Fuction		: GetType
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14 	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int GetType()
{
	return g_iType;
}
/*****************************************************************************
-Fuction		: SetType
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14 	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void SetType(int i_iType)
{
	g_iType=i_iType;
}



