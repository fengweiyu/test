/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	LinkList.c
* Description		: 	LinkList operation center
* Created			: 	2017.03.02.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"

typedef struct LinkListElement
{
	char cData;
}T_LinkListElement,*PT_LinkListElement;

typedef struct LinkList
{
	T_LinkListElement tData;
	struct LinkList *ptNext;
}T_LinkList,*PT_LinkList;
#define LINK_LIST_LEN 10

static int InitLinkList(PT_LinkList *o_pptLinkListHead);
static int InsertNodeToLinkList(T_LinkList *i_ptLinkListHead,int i_dwPosition,T_LinkListElement *i_ptElement);
static int DeleteNodeFromLinkList(T_LinkList *i_ptLinkListHead,int i_dwPosition,T_LinkListElement *o_ptElement);
static int TraverseLinkList(T_LinkList *i_ptLinkListHead);
/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	PT_LinkList ptLinkListHead=NULL;
	T_LinkListElement tLinkListElement;
	InitLinkList(&ptLinkListHead);
	tLinkListElement.cData=1;
	InsertNodeToLinkList(ptLinkListHead,1,&tLinkListElement);
	tLinkListElement.cData=23;
	InsertNodeToLinkList(ptLinkListHead,2,&tLinkListElement);
	tLinkListElement.cData=24;
	InsertNodeToLinkList(ptLinkListHead,3,&tLinkListElement);
	tLinkListElement.cData=26;
	InsertNodeToLinkList(ptLinkListHead,4,&tLinkListElement);
	tLinkListElement.cData=66;
	InsertNodeToLinkList(ptLinkListHead,5,&tLinkListElement);
	tLinkListElement.cData=99;
	InsertNodeToLinkList(ptLinkListHead,6,&tLinkListElement);
	
	printf("插入结果:");
	TraverseLinkList(ptLinkListHead);
	DeleteNodeFromLinkList(ptLinkListHead,6,&tLinkListElement);
	DeleteNodeFromLinkList(ptLinkListHead,4,&tLinkListElement);
	
	printf("删除结果:");
	TraverseLinkList(ptLinkListHead);
	
	printf("插入结果:");
	tLinkListElement.cData=5;
	InsertNodeToLinkList(ptLinkListHead,3,&tLinkListElement);
	TraverseLinkList(ptLinkListHead);
	return 0;
}
/*****************************************************************************
-Fuction		: InitLinkList
-Description	: InitLinkList
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int InitLinkList(PT_LinkList *o_pptLinkListHead)
{//生成一个头结点
	int ret=-1;
	*o_pptLinkListHead=(T_LinkList *)malloc(sizeof(T_LinkList));// 产生头结点，并使L指向此头结点
	if(NULL==*o_pptLinkListHead)
	{
		printf("LinkListErr\r\n");
		ret=-1;
	}
	else
	{
		(*o_pptLinkListHead)->ptNext=NULL;
		ret=0;
	}
	return ret;
}
/*****************************************************************************
-Fuction		: GetLinkListLength
-Description	: GetLinkListLength
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int GetLinkListLength(T_LinkList *i_ptLinkListHead)
{
	int iLength=0;
	T_LinkList *ptLinkListNode=NULL;
	if(NULL==i_ptLinkListHead)
	{
		printf("ListNull,GetLinkListLength err\r\n");
	}
	else
	{
		ptLinkListNode=i_ptLinkListHead->ptNext;//头结点指向的下一个为开始放结点的地方
		while(NULL!=ptLinkListNode)
		{
			iLength++;
			ptLinkListNode=ptLinkListNode->ptNext;
		}
	}
	return iLength;
}

/*****************************************************************************
-Fuction		: InsertNodeToLinkList
-Description	: InsertNodeToLinkList
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int InsertNodeToLinkList(T_LinkList *i_ptLinkListHead,int i_dwPosition,T_LinkListElement *i_ptElement)
{
	int ret=-1;
	T_LinkList *ptLinkListNode=i_ptLinkListHead;
	T_LinkList *ptInsertListNode=NULL;	
	int iLen=0;
	iLen=GetLinkListLength(i_ptLinkListHead);
	if(i_dwPosition<1||i_dwPosition-1>iLen)
	{
		ret=-1;		
		printf("InsertPositionErr,Len:%d,Pos:%d\r\n",iLen,i_dwPosition);
	}
	else
	{
		while(--i_dwPosition)
		{
			ptLinkListNode=ptLinkListNode->ptNext;
		}
		ptInsertListNode=(T_LinkList *)malloc(sizeof(T_LinkList));
		if(NULL==ptInsertListNode)
		{
			printf("pInsertListNodeMallocErr\r\n");
			ret=-1;
		}	
		else
		{
			ptInsertListNode->ptNext=NULL;
			memcpy(&ptInsertListNode->tData,i_ptElement,sizeof(T_LinkListElement));
			ptInsertListNode->ptNext=ptLinkListNode->ptNext;
			ptLinkListNode->ptNext=ptInsertListNode;
			ret=0;
		}
	}
	return ret;
}

/*****************************************************************************
-Fuction		: DeleteNodeFromLinkList
-Description	: DeleteNodeFromLinkList
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int DeleteNodeFromLinkList(T_LinkList *i_ptLinkListHead,int i_dwPosition,T_LinkListElement *o_ptElement)
{
	int ret=-1;
	T_LinkList *ptLinkListNode=i_ptLinkListHead;
	T_LinkList *ptDeleteListNode=NULL;
	int iLen=0;
	iLen=GetLinkListLength(i_ptLinkListHead);
	if(i_dwPosition<1||i_dwPosition>iLen)
	{
		ret=-1;
		printf("LinkListDeleteErr,Len:%d,Pos:%d\r\n",iLen,i_dwPosition);
	}
	else
	{
		while(--i_dwPosition)
		{
			ptLinkListNode=ptLinkListNode->ptNext;
		}
		ptDeleteListNode=ptLinkListNode->ptNext;
		memcpy(o_ptElement,&ptDeleteListNode->tData,sizeof(T_LinkListElement));
		ptLinkListNode->ptNext=ptDeleteListNode->ptNext;
		free(ptDeleteListNode);
		ret=0;
	}
	return ret;
}
/*****************************************************************************
-Fuction		: TraverseLinkList
-Description	: TraverseLinkList
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int TraverseLinkList(T_LinkList *i_ptLinkListHead)
{
	int ret=-1;
	T_LinkList *ptLinkListNode=i_ptLinkListHead;
	if(ptLinkListNode->ptNext==NULL)
	{
		printf("LinkListTraverseErr,LinkListEmpty\r\n");
	}
	else
	{
		while(NULL!=ptLinkListNode->ptNext)
		{
			ptLinkListNode=ptLinkListNode->ptNext;
			printf("%d ",ptLinkListNode->tData.cData);
		}
		printf("\r\n");
		ret=0;
	}
	return ret;
}

