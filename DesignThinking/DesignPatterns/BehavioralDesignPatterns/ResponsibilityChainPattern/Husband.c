/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	Husband.c
* Description		: 	������ģʽ�еĽ�ɫ
						������(Ů�Ե��ɷ�)
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




static T_Handle g_tHusbandNextHandle={NULL};

/*****************************************************************************
-Fuction		: HusbandHandle
-Description	: ����������Ļ�Ӧ����
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void HusbandReponse(T_Woman *i_ptWoman)
{
	printf("�������ɷ���ʾ:\r\n");
	printf("%s\r\n",i_ptWoman->GetRequest());
	printf("�ɷ�Ĵ���:ͬ��\r\n");
}

/*****************************************************************************
-Fuction		: GetHusbandHandleLevel
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int GetHusbandHandleLevel()
{
	return HUSBAND_HANDLE_LEVEL;
}

/*****************************************************************************
-Fuction		: GetHusbandNextHandle
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
T_Handle *GetHusbandNextHandle()
{
	return &g_tHusbandNextHandle;
}

/*****************************************************************************
-Fuction		: SetHusbandNextHandle
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void SetHusbandNextHandle(T_Handle*i_ptHandle)
{
	memcpy(&g_tHusbandNextHandle,i_ptHandle,sizeof(T_Handle));
}





