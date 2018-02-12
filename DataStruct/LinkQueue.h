/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	LinkQueue.h
* Description		: 	LinkQueue operation center
* Created			: 	2017.04.24.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef _LINK_QUEUE_H
#define _LINK_QUEUE_H

//#include "ChildSiblingTree.h"
typedef struct QueueDataElement
{
//	T_ChildSiblingTreeNode *ptData;
	int iData;
}T_QueueDataElement,*PT_QueueDataElement;


typedef struct QueueElement
{
	T_QueueDataElement tData;
	struct QueueElement *ptNext;
}T_QueueElement,*PT_QueueElement;

typedef struct LinkQueue
{
	T_QueueElement *ptFront;
	T_QueueElement *ptRear;
}T_LinkQueue,*PT_LinkQueue;



int InitLinkQueue(T_LinkQueue *i_pptLinkQueue);
int EnterLinkQueue(T_LinkQueue *i_ptLinkQueue,T_QueueDataElement i_tElement);
int ExitLinkQueue(T_LinkQueue *i_ptLinkQueue,T_QueueDataElement *o_ptElement);

#endif
