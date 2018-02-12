/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SequenceQueue.c
* Description		: 	SequenceQueue operation center
˳���ʾ�Ķ���һ����ѭ������
��Ϊ˳���ʾ�Ķ���Ҫʹ���Ѿ����ӵĿռ�ͱ���ʹ��
ѭ���ķ���ָ���Ѿ����ӵĿռ�
* Created			: 	2017.04.24.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"

typedef struct SeqQueueElement//˳����н����ֻ������Ԫ��
{
	char cData;
}T_SeqQueueElement,*PT_SeqQueueElement;//����ͬ������Ԫ��

typedef struct SeqQueue
{
	T_SeqQueueElement *ptBase;//����Ϊ�˷���,ֱ�Ӷ���Ԫ�ش�����н��
	int iFront;
	int iRear;
}T_SeqQueue,*PT_SeqQueue;

#define SEQUENCE_QUEUE_MAX_LEN	5
static int InitSeqQueue(T_SeqQueue *i_ptSeqQueue);
static int EnterSeqQueue(T_SeqQueue *i_ptSeqQueue,T_SeqQueueElement i_tElement);
static int ExitSeqQueue(T_SeqQueue *i_ptSeqQueue,T_SeqQueueElement *o_ptElement);
static void TraverseSeqQueue(T_SeqQueue *i_ptSeqQueue);

/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_SeqQueue tSeqQueue={0};
	T_SeqQueueElement tElementData={0};
	InitSeqQueue(&tSeqQueue);
	tElementData.cData=1;
	EnterSeqQueue(&tSeqQueue,tElementData);
	tElementData.cData=2;
	EnterSeqQueue(&tSeqQueue,tElementData);
	tElementData.cData=5;
	EnterSeqQueue(&tSeqQueue,tElementData);
	tElementData.cData=6;
	EnterSeqQueue(&tSeqQueue,tElementData);
	printf("������н��:");
	TraverseSeqQueue(&tSeqQueue);
	
	ExitSeqQueue(&tSeqQueue,&tElementData);
	printf("�˳�����Ԫ��:%d\r\n",tElementData.cData);
	ExitSeqQueue(&tSeqQueue,&tElementData);
	printf("�˳�����Ԫ��:%d\r\n",tElementData.cData);
	ExitSeqQueue(&tSeqQueue,&tElementData);
	printf("�˳�����Ԫ��:%d\r\n",tElementData.cData);
	
	printf("�˳����н��:");
	TraverseSeqQueue(&tSeqQueue);
	return 0;
}
/*****************************************************************************
-Fuction		: InitSeqQueue
-Description	: InitSeqQueue
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int InitSeqQueue(T_SeqQueue *i_ptSeqQueue)
{
	int iRet=-1;
	i_ptSeqQueue->ptBase=(T_SeqQueueElement *)malloc(sizeof(T_SeqQueueElement)*SEQUENCE_QUEUE_MAX_LEN);
	if(NULL==i_ptSeqQueue->ptBase)
	{
		printf("InitSeqQueue MallocErr\r\n");
		exit(-1);
	}
	else
	{
		i_ptSeqQueue->iRear=i_ptSeqQueue->iFront=0;
		iRet=0;
	}
	return iRet;
}

/*****************************************************************************
-Fuction		: EnterSeqQueue
-Description	: �����������⣬�������ǲ��뵽����û��Ԫ��
				  ����������յ����Ҳ�����ʼ��ʱ��
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int EnterSeqQueue(T_SeqQueue *i_ptSeqQueue,T_SeqQueueElement i_tElement)
{
	int iRet=-1;
	if((i_ptSeqQueue->iRear+1)%SEQUENCE_QUEUE_MAX_LEN==i_ptSeqQueue->iFront)
	{//Ҫ��Ԫ�ص���һ��λ��,����β����һ��λ��������ڶ�ͷ����
		printf("EnterSeqQueue err,SeqQueueFull\r\n");
		iRet=-1;
	}
	else
	{
		i_ptSeqQueue->ptBase[i_ptSeqQueue->iRear]=i_tElement;//iRearָ�����Ԫ�ص�λ��
		i_ptSeqQueue->iRear=(i_ptSeqQueue->iRear+1)%SEQUENCE_QUEUE_MAX_LEN;
		iRet=0;
	}
	return iRet;
}

/*****************************************************************************
-Fuction		: ExitSeqQueue
-Description	: ���ǿյ����⣬��������ɾ���������һ��
				  Ԫ�ص��������ɾ����Ϊ�յ����
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int ExitSeqQueue(T_SeqQueue *i_ptSeqQueue,T_SeqQueueElement *o_ptElement)
{
	int iRet=-1;
	if(i_ptSeqQueue->iFront==i_ptSeqQueue->iRear)
	{
		printf("EnterSeqQueue err,SeqQueueEmpty\r\n");
	}
	else
	{
		*o_ptElement=i_ptSeqQueue->ptBase[i_ptSeqQueue->iFront];
		i_ptSeqQueue->iFront=(i_ptSeqQueue->iFront+1)%SEQUENCE_QUEUE_MAX_LEN;
		iRet=0;
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: TraverseSeqQueue
-Description	: ����ֱ�����һ��Ԫ��,��������ѭ������һ�㿼��
				  ���һ��Ԫ��ʱ������
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void TraverseSeqQueue(T_SeqQueue *i_ptSeqQueue)
{
	int i=i_ptSeqQueue->iFront;
	while(i!=i_ptSeqQueue->iRear)
	{
		printf("%d ",i_ptSeqQueue->ptBase[i].cData);
		i=(i+1)%SEQUENCE_QUEUE_MAX_LEN;
	}
	printf("\n");
}

