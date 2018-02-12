/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SequenceQueue.c
* Description		: 	SequenceQueue operation center
顺序表示的队列一定是循环队列
因为顺序表示的队列要使用已经出队的空间就必须使用
循环的方法指向已经出队的空间
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

typedef struct SeqQueueElement//顺序队列结点里只有数据元素
{
	char cData;
}T_SeqQueueElement,*PT_SeqQueueElement;//结点等同于数据元素

typedef struct SeqQueue
{
	T_SeqQueueElement *ptBase;//所以为了方便,直接队列元素代替队列结点
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
	printf("进入队列结果:");
	TraverseSeqQueue(&tSeqQueue);
	
	ExitSeqQueue(&tSeqQueue,&tElementData);
	printf("退出队列元素:%d\r\n",tElementData.cData);
	ExitSeqQueue(&tSeqQueue,&tElementData);
	printf("退出队列元素:%d\r\n",tElementData.cData);
	ExitSeqQueue(&tSeqQueue,&tElementData);
	printf("退出队列元素:%d\r\n",tElementData.cData);
	
	printf("退出队列结果:");
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
-Description	: 考虑满的问题，不满则考虑插入到里面没有元素
				  的情况，即空的情况也就是最开始的时候
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
	{//要放元素的下一个位置,即队尾的下一个位置如果等于队头则满
		printf("EnterSeqQueue err,SeqQueueFull\r\n");
		iRet=-1;
	}
	else
	{
		i_ptSeqQueue->ptBase[i_ptSeqQueue->iRear]=i_tElement;//iRear指向待放元素的位置
		i_ptSeqQueue->iRear=(i_ptSeqQueue->iRear+1)%SEQUENCE_QUEUE_MAX_LEN;
		iRet=0;
	}
	return iRet;
}

/*****************************************************************************
-Fuction		: ExitSeqQueue
-Description	: 考虑空的问题，不空则考虑删除的是最后一个
				  元素的情况，即删除后为空的情况
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
-Description	: 遍历直到最后一个元素,所以其中循环条件一般考虑
				  最后一个元素时的情形
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

