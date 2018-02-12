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
	printf("进入队列结果:");
	TraverseLinkQueue(&tLinkQueue);
	
	ExitLinkQueue(&tLinkQueue,&cElementData);
	printf("退出队列元素:%d\r\n",cElementData);
	ExitLinkQueue(&tLinkQueue,&cElementData);
	printf("退出队列元素:%d\r\n",cElementData);
	ExitLinkQueue(&tLinkQueue,&cElementData);
	printf("退出队列元素:%d\r\n",cElementData);
	
	printf("退出队列结果:");
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
-Description	: 考虑满的问题，不满则考虑插入到里面没有元素
				  的情况，即空的情况也就是最开始的时候
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int EnterLinkQueue(T_LinkQueue *i_ptLinkQueue,char i_cElement)
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
		ptQueueNode->cData=i_cElement;//最开始ptRear指向头结点
		ptQueueNode->ptNext=NULL;//头结点不放元素
		i_ptLinkQueue->ptRear->ptNext=ptQueueNode;//所以只能放在头结点的下一个元素
		i_ptLinkQueue->ptRear=ptQueueNode;
		iRet=0;
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: ExitLinkQueue
-Description	: 考虑空的问题，不空则考虑删除的是最后一个
				  元素的情况，即删除后为空的情况
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int ExitLinkQueue(T_LinkQueue *i_ptLinkQueue,char *i_pcElement)
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
		*i_pcElement=ptQueueNode->cData;
		i_ptLinkQueue->ptFront->ptNext=ptQueueNode->ptNext;//最开始时
		if(ptQueueNode==i_ptLinkQueue->ptRear)//当取出的是队列仅有的一个元素，即剩下只有队头元素(头结点)
		{//队列里没有元素了，则对头和队尾要相等
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
		printf("%d",ptQueueNode->cData);
		ptQueueNode=ptQueueNode->ptNext;
	}
	printf("\r\n");
}


