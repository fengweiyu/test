/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	LinkQueue.c
* Description		: 	LinkQueue operation center
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
#include "LinkQueue.h"

static void TraverseLinkQueue(T_LinkQueue *i_ptLinkQueue);

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
/*int main(int argc,char **argv)
{
	T_LinkQueue tLinkQueue={0};
	char cElementData=0;
	InitLinkQueue(&tLinkQueue);
	
	EnterLinkQueue(&tLinkQueue,1);
	EnterLinkQueue(&tLinkQueue,2);
	EnterLinkQueue(&tLinkQueue,3);
	EnterLinkQueue(&tLinkQueue,4);
	EnterLinkQueue(&tLinkQueue,5);
	printf("������н��:");
	TraverseLinkQueue(&tLinkQueue);
	
	ExitLinkQueue(&tLinkQueue,&cElementData);
	printf("�˳�����Ԫ��:%d\r\n",cElementData);
	ExitLinkQueue(&tLinkQueue,&cElementData);
	printf("�˳�����Ԫ��:%d\r\n",cElementData);
	ExitLinkQueue(&tLinkQueue,&cElementData);
	printf("�˳�����Ԫ��:%d\r\n",cElementData);
	
	printf("�˳����н��:");
	TraverseLinkQueue(&tLinkQueue);
	
	return 0;
}*/
/*****************************************************************************
-Fuction		: InitLinkQueue
-Description	: InitLinkQueue
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int InitLinkQueue(T_LinkQueue *i_ptLinkQueue)
{
	int iRet=-1;
	i_ptLinkQueue->ptFront=(T_QueueElement *)malloc(sizeof(T_QueueElement));
	if(NULL==i_ptLinkQueue->ptFront)
	{
		iRet=-1;
		printf("InitLinkQueue Malloc err\r\n");
		exit(-1);
	}
	else
	{
		i_ptLinkQueue->ptRear=i_ptLinkQueue->ptFront;
		i_ptLinkQueue->ptRear->ptNext=NULL;
		iRet=0;
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: EnterLinkQueue
-Description	: �����������⣬�������ǲ��뵽����û��Ԫ��
				  ����������յ����Ҳ�����ʼ��ʱ��
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int EnterLinkQueue(T_LinkQueue *i_ptLinkQueue,T_QueueDataElement i_tElement)
{
	int iRet=-1;
	T_QueueElement *ptQueueNode=NULL;
	ptQueueNode=(T_QueueElement *)malloc(sizeof(T_QueueElement));
	if(NULL==ptQueueNode)
	{
		iRet=-1;
		printf("EnterLinkQueue Malloce err");
	}
	else
	{	
		memcpy(&ptQueueNode->tData,&i_tElement,sizeof(T_QueueElement));//�ʼptRearָ��ͷ���
		ptQueueNode->ptNext=NULL;//ͷ��㲻��Ԫ��
		i_ptLinkQueue->ptRear->ptNext=ptQueueNode;//����ֻ�ܷ���ͷ������һ��Ԫ��
		i_ptLinkQueue->ptRear=ptQueueNode;
		iRet=0;
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: ExitLinkQueue
-Description	: ���ǿյ����⣬��������ɾ���������һ��
				  Ԫ�ص��������ɾ����Ϊ�յ����
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int ExitLinkQueue(T_LinkQueue *i_ptLinkQueue,T_QueueDataElement *o_ptElement)
{
	int iRet=-1;
	T_QueueElement *ptQueueNode=NULL;
	if(i_ptLinkQueue->ptFront==i_ptLinkQueue->ptRear)
	{
		iRet=-1;
		printf("LinkQueueEmpty Exit err\r\n");
	}
	else
	{
		ptQueueNode=i_ptLinkQueue->ptFront->ptNext;
		memcpy(o_ptElement,&ptQueueNode->tData,sizeof(T_QueueElement));
		i_ptLinkQueue->ptFront->ptNext=ptQueueNode->ptNext;//�ʼʱ
		if(ptQueueNode==i_ptLinkQueue->ptRear)//��ȡ�����Ƕ��н��е�һ��Ԫ�أ���ʣ��ֻ�ж�ͷԪ��(ͷ���)
		{//������û��Ԫ���ˣ����ͷ�Ͷ�βҪ���
			i_ptLinkQueue->ptRear=i_ptLinkQueue->ptFront;//
		}
		else{
		}
		free(ptQueueNode);
		iRet=0;
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: ExitLinkQueue
-Description	: ���ǿյ����⣬��������ɾ���������һ��
				  Ԫ�ص��������ɾ����Ϊ�յ����
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int IsLinkQueueEmpty(T_LinkQueue *i_ptLinkQueue)
{
	int iRet=-1;
	T_QueueElement *ptQueueNode=NULL;
	if(i_ptLinkQueue->ptFront!=i_ptLinkQueue->ptRear)
	{
		iRet=-1;
	}
	else
	{
		iRet=0;
	}
	return iRet;
}

/*****************************************************************************
-Fuction		: TraverseLinkQueue
-Description	: TraverseLinkQueue
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void TraverseLinkQueue(T_LinkQueue *i_ptLinkQueue)
{
	T_QueueElement *ptQueueNode=NULL;
	ptQueueNode=i_ptLinkQueue->ptFront->ptNext;
	while(NULL!=ptQueueNode)
	{
		//printf("%d",ptQueueNode->tData);
		ptQueueNode=ptQueueNode->ptNext;
	}
	printf("\r\n");
}


