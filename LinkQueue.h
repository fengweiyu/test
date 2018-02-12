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

typedef struct QueueElement
{
	char cData;
	struct QueueElement *ptNext;
}T_QueueElement,*PT_QueueElement;

typedef struct LinkQueue
{
	T_QueueElement *ptFront;
	T_QueueElement *ptRear;
}T_LinkQueue,*PT_LinkQueue;



int InitLinkQueue(T_LinkQueue *i_pptLinkQueue);
int EnterLinkQueue(T_LinkQueue *i_ptLinkQueue,char i_cElement);
int ExitLinkQueue(T_LinkQueue *i_ptLinkQueue,char *i_pcElement);

#endif
