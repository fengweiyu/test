/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ResponsibilityChainPattern.c
* Description		: 	������ģʽ
						�ԹŴ�Ů�������ĵ¾���,Ů����������,
						���ײ��������ɷ���,�ɷ򲻴��������
						����,�������ֱ�ӷ���

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


//static T_Handle g_tNextHandle[HANDLE_NUMBER]={NULL};//����C���еĳ�Ա�����Ǿ�̬��,���Էŵ�������
//static int g_iHandleNum=0;//������ڸ���,����Ҫ����Ϊ���鲢���峤����ʹ�ó���
/*****************************************************************************
-Fuction		: HandleMessage
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void HandleMessage(T_Woman *i_ptWoman,T_Handle *i_ptThis)
{
	if(i_ptThis->GetLevel()==i_ptWoman->GetType())
	{
		i_ptThis->Handle(i_ptWoman);//��������Ĵ���
	}
	else
	{
		if(i_ptThis->GetNextHandle()!=NULL)
		{
			i_ptThis->GetNextHandle()->tFatherHandle.HandleMessage(i_ptWoman,i_ptThis->GetNextHandle());
		}
		else
		{
			printf("û�ط���ʾ �ˣ�����ͬ�⴦��\r\n");
		}
	}
}


