/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	Son.c
* Description		: 	责任链模式中的角色
						处理者(女性的儿子)
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


static T_Handle g_tSonNextHandle={NULL};

/*****************************************************************************
-Fuction		: SonHandle
-Description	: 对母亲请求的回应处理
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void SonReponse(T_Woman *i_ptWoman)
{
	printf("母亲向儿子请示:\r\n");
	printf("%s\r\n",i_ptWoman->GetRequest());
	printf("儿子的答复是:同意\r\n");
}

/*****************************************************************************
-Fuction		: GetSonHandleLevel
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int GetSonHandleLevel()
{
	return SON_HANDLE_LEVEL;
}

/*****************************************************************************
-Fuction		: GetSonNextHandle
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
T_Handle *GetSonNextHandle()
{
	return &g_tSonNextHandle;
}

/*****************************************************************************
-Fuction		: SetSonNextHandle
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void SetSonNextHandle(T_Handle*i_ptHandle)
{
	memcpy(&g_tSonNextHandle,i_ptHandle,sizeof(T_Handle));
}



