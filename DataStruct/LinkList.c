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

typedef struct LinkList
{
	char cData;
	struct LinkList *pNext;
}T_LinkList,*PT_LinkList;
#define LINK_LIST_LEN 10

static int CreatLinkList(PT_LinkList *o_ptLinkListHead);
static int LinkListInsert(T_LinkList *i_ptLinkListHead,int i_dwPosition,int i_dwElement);
static int LinkListDelete(T_LinkList *i_ptLinkListHead,int i_dwPosition,int *o_dwElement);
static int LinkListTraverse(T_LinkList *i_ptLinkListHead);
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
	int dwElement=0;
	PT_LinkList ptLinkListHead=NULL;
	CreatLinkList(&ptLinkListHead);
	LinkListInsert(ptLinkListHead,1,1);
	LinkListInsert(ptLinkListHead,2,23);
	LinkListInsert(ptLinkListHead,3,24);
	LinkListInsert(ptLinkListHead,4,26);
	LinkListInsert(ptLinkListHead,5,66);
	LinkListInsert(ptLinkListHead,6,99);
	
	printf("插入结果:");
	LinkListTraverse(ptLinkListHead);
	LinkListDelete(ptLinkListHead,6,&dwElement);
	LinkListDelete(ptLinkListHead,4,&dwElement);
	
	printf("删除结果:");
	LinkListTraverse(ptLinkListHead);
	
	printf("插入结果:");
	LinkListInsert(ptLinkListHead,3,5);
	LinkListTraverse(ptLinkListHead);
	return 0;
}
/*****************************************************************************
-Fuction		: CreatLinkList
-Description	: CreatLinkList
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int CreatLinkList(PT_LinkList *o_ptLinkListHead)
{//鐢熸垚涓�涓ご缁撶偣
	int ret=-1;
	*o_ptLinkListHead=(T_LinkList *)malloc(sizeof(T_LinkList));// 产生头结点，并使L指向此头结点
	if(NULL==*o_ptLinkListHead)
	{
		printf("LinkListErr\r\n");
		ret=-1;
	}
	else
	{
		(*o_ptLinkListHead)->pNext=NULL;
		ret=0;
	}
	return ret;
}
/*****************************************************************************
-Fuction		: LinkListInsert
-Description	: LinkListInsert
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int LinkListInsert(T_LinkList *i_ptLinkListHead,int i_dwPosition,int i_dwElement)
{
	int ret=-1;
	T_LinkList *pLinkListNode=i_ptLinkListHead;
	T_LinkList *pInsertListNode=NULL;	
	int j=0;
	while((pLinkListNode!=NULL)&&(j<i_dwPosition-1))//寻找插入位置的前一个结点(计算表长(包含头结点)进行比较)
	{//插入位置小于等于1直接退出，没有判断pLinkListNode!=NULL
		pLinkListNode=pLinkListNode->pNext;//计算表长，插入位置的前一个结点包括头结点(第一个位置的时候)，
		//所以长度包含头结点
		j++;//插入位置的前一个结点或者链表长度不够时表示链表长度
	}	
	if((pLinkListNode==NULL)||(j>i_dwPosition-1))
	{//链表长度不够为NULL，或者插入位置小于1异常，(第一个位置为1)
		ret=-1;		
		printf("InsertPositionErr,Len:%d,Pos:%d\r\n",j,i_dwPosition);
	}
	else
	{
		pInsertListNode=(T_LinkList *)malloc(sizeof(T_LinkList));
		if(NULL==pInsertListNode)
		{
			printf("pInsertListNodeMallocErr\r\n");
			ret=-1;
		}	
		else
		{
			pInsertListNode->pNext=NULL;
			pInsertListNode->cData=i_dwElement;
			pInsertListNode->pNext=pLinkListNode->pNext;
			pLinkListNode->pNext=pInsertListNode;
			ret=0;
		}
	}
	return ret;
}

/*****************************************************************************
-Fuction		: LinkListDelete
-Description	: LinkListDelete
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int LinkListDelete(T_LinkList *i_ptLinkListHead,int i_dwPosition,int *o_dwElement)
{
	int ret=-1;
	T_LinkList *ptLinkListNode=i_ptLinkListHead;
	T_LinkList *ptDeleteListNode=NULL;
	int j=0;
	while((ptLinkListNode->pNext!=NULL)&&(j<i_dwPosition-1))//找到删除点的前驱
	{
		ptLinkListNode=ptLinkListNode->pNext;
		j++;
	}
	if((NULL==ptLinkListNode->pNext)||(j>i_dwPosition-1))
	{
		ret=-1;
		printf("LinkListDeleteErr,Len:%d,Pos:%d\r\n",j,i_dwPosition);
	}
	else
	{
		ptDeleteListNode=ptLinkListNode->pNext;
		*o_dwElement=ptDeleteListNode->cData;
		ptLinkListNode->pNext=ptDeleteListNode->pNext;
		free(ptDeleteListNode);
		ret=0;
	}
	return ret;
}
/*****************************************************************************
-Fuction		: LinkListDelete
-Description	: LinkListDelete
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int LinkListTraverse(T_LinkList *i_ptLinkListHead)
{
	int ret=-1;
	T_LinkList *ptLinkListNode=i_ptLinkListHead;
	if(ptLinkListNode->pNext==NULL)
	{
		printf("LinkListTraverseErr,LinkListEmpty\r\n");
	}
	else
	{
		while(NULL!=ptLinkListNode->pNext)
		{
			ptLinkListNode=ptLinkListNode->pNext;
			printf("%d ",ptLinkListNode->cData);
		}
		printf("\r\n");
		ret=0;
	}
	return ret;
}

