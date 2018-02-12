/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	Father.c
* Description		: 	责任链模式中的角色
						处理者(女性的父亲)
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

static T_Handle g_tFatherNextHandle={NULL};

/*****************************************************************************
-Fuction		: FatherHandle
-Description	: 对女儿请求的回应处理
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void FatherReponse(T_Woman *i_ptWoman)
{
	printf("女儿向父亲请示:\r\n");
	printf("%s\r\n",i_ptWoman->GetRequest());
	printf("父亲的答复是:同意\r\n");
}

/*****************************************************************************
-Fuction		: GetFatherHandleLevel
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int GetFatherHandleLevel()
{
	return FATHER_HANDLE_LEVEL;
}

/*****************************************************************************
-Fuction		: GetFatherNextHandle
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
T_Handle *GetFatherNextHandle()
{
	return &g_tFatherNextHandle;
}

/*****************************************************************************
-Fuction		: SetFatherNextHandle
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void SetFatherNextHandle(T_Handle*i_ptHandle)
{
	memcpy(&g_tFatherNextHandle,i_ptHandle,sizeof(T_Handle));
}



