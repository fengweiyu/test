/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	DualLinkList.c
* Description		: 	DualLinkList operation center
* Created			: 	2017.04.02.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"

typedef struct DualLinkList
{
	char cData;	
	struct DualLinkList *ptPrior;
	struct DualLinkList *ptNext;
}T_DualLinkList,*PT_DualLinkList;

static int ListLength(T_DualLinkList *i_ptDualLinkListHead);
static int GetElementPoint(T_DualLinkList *i_ptDualLinkListHead,int i_dwPosition,T_DualLinkList **o_pptElementPoint);
static int ListInit(T_DualLinkList **i_pptDualLinkListHead);
static int ListInsert(T_DualLinkList *i_ptDualLinkListHead,int i_dwPosition,int i_dwElement);
static int ListDelete(T_DualLinkList *i_ptDualLinkListHead,int i_dwPosition,int *o_dwElement);
static int ListTraverse(T_DualLinkList *i_ptDualLinkListHead);
static int ListSortOneCmpOne(T_DualLinkList *i_ptDualLinkListHead);
static int ListSortOneCmpAll(T_DualLinkList *i_ptDualLinkListHead);

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
	T_DualLinkList *ptLinkListHead=NULL;
	ListInit(&ptLinkListHead);
	ListInsert(ptLinkListHead,1,1);
	ListInsert(ptLinkListHead,2,99);
	ListInsert(ptLinkListHead,3,24);
	ListInsert(ptLinkListHead,4,26);
	ListInsert(ptLinkListHead,5,8);
	ListInsert(ptLinkListHead,6,33);
	printf("插入结果:");
	ListTraverse(ptLinkListHead);
	
	ListSortOneCmpOne(ptLinkListHead);
	printf("两两比较冒泡排序结果:");
	ListTraverse(ptLinkListHead);
	
	ListDelete(ptLinkListHead,4,&dwElement);	
	printf("删除结果:");
	ListTraverse(ptLinkListHead);
	
	printf("插入结果:");
	ListInsert(ptLinkListHead,3,5);
	ListTraverse(ptLinkListHead);
	
	ListSortOneCmpAll(ptLinkListHead);
	printf("一对多比较冒泡排序结果:");
	ListTraverse(ptLinkListHead);
	
	return 0;
}
/*****************************************************************************
-Fuction		: ListInit
-Description	: ListInit
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int ListInit(T_DualLinkList **i_pptDualLinkListHead)
{
	int iRet=0;
	T_DualLinkList *ptListNode=NULL; 
	ptListNode=(T_DualLinkList *)malloc(sizeof(T_DualLinkList));
	if(NULL==ptListNode)
	{
		iRet=-1;
		printf("ListInitMallocErr,ListInitFail!\r\n");
		exit(-1);
	}
	else
	{
		ptListNode->ptNext=ptListNode->ptPrior=ptListNode;
		*i_pptDualLinkListHead=ptListNode;
		iRet=0;
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: ListInit
-Description	: ListInit
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int ListInsert(T_DualLinkList *i_ptDualLinkListHead,int i_dwPosition,int i_dwElement)
{
	int iRet=0;
	T_DualLinkList *ptListNode=i_ptDualLinkListHead; 
	T_DualLinkList *ptListInsertNode=NULL;
	if((i_dwPosition<1)||(i_dwPosition>ListLength(i_ptDualLinkListHead)+1))
	{
		printf("ListInserErr\r\n");
		iRet=-1;
	}
	else
	{
		if(0!=GetElementPoint(i_ptDualLinkListHead,i_dwPosition-1,&ptListNode))//找插入点的前驱
		{//或者找插入点位置也是可以的
			printf("ListInsertGetElementPoint Err\r\n");
			iRet=-1;
		}
		else
		{
			ptListInsertNode=(T_DualLinkList *)malloc(sizeof(T_DualLinkList));
			if(NULL==ptListInsertNode)
			{
				iRet=-1;
				printf("ListInsertMallocErr\r\n");
			}
			else
			{
				ptListInsertNode->cData=i_dwElement;
				ptListInsertNode->ptNext=ptListNode->ptNext;
				ptListInsertNode->ptPrior=ptListNode;
				ptListNode->ptNext->ptPrior=ptListInsertNode;
				ptListNode->ptNext=ptListInsertNode;
				iRet=0;
			}
		}
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: ListInit
-Description	: ListInit
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int ListDelete(T_DualLinkList *i_ptDualLinkListHead,int i_dwPosition,int *o_dwElement)
{
	int iRet=0;
	T_DualLinkList *ptListNode=NULL; 
	if((i_dwPosition<1)||(i_dwPosition>ListLength(i_ptDualLinkListHead)))
	{
		printf("ListDelete Err\r\n");
		iRet=-1;
	}
	else
	{
		if(0!=GetElementPoint(i_ptDualLinkListHead,i_dwPosition,&ptListNode))//找删除点位置
		{
			printf("ListDeleteGetElementPoint Err\r\n");
			iRet=-1;
		}
		else
		{
			*o_dwElement=ptListNode->cData;
			ptListNode->ptPrior->ptNext=ptListNode->ptNext;
			ptListNode->ptNext->ptPrior=ptListNode->ptPrior;
			free(ptListNode);
			iRet=0;
		}
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: ListInit
-Description	: ListInit
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int ListTraverse(T_DualLinkList *i_ptDualLinkListHead)
{
	int iRet=0;
	T_DualLinkList *ptListNode=NULL; 
	if(NULL==i_ptDualLinkListHead)
	{
		iRet=-1;
		printf("ListTraverse Err,HeadNull\r\n");
	}
	else
	{
		ptListNode=i_ptDualLinkListHead->ptNext;
		while(i_ptDualLinkListHead!=ptListNode)
		{
			printf("%d ",ptListNode->cData);
			ptListNode=ptListNode->ptNext;
		}
		printf("\r\n");
		iRet=0;
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: ListInit
-Description	: ListInit
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int ListSortOneCmpOne(T_DualLinkList *i_ptDualLinkListHead)
{
	int iRet=0;
	char cData;
	int i=0,j=0;
	T_DualLinkList *ptListSortNode=NULL;
	if(NULL==i_ptDualLinkListHead)
	{
		iRet=-1;
		printf("ListSortOneCmpOne Err,HeadNull\r\n");
	}
	else
	{
		for(i=0;i<ListLength(i_ptDualLinkListHead)-1;i++)
		{
			ptListSortNode=i_ptDualLinkListHead->ptNext;//最大的在后面所以最后一个不需要比较
			for(j=0;j<ListLength(i_ptDualLinkListHead)-i-1;j++)//但是第一个也就是前面还要比较
			{
				if(ptListSortNode->cData>ptListSortNode->ptNext->cData)//两两比较找出最大的放最后面
				{//大的放后面
					cData=ptListSortNode->cData;
					ptListSortNode->cData=ptListSortNode->ptNext->cData;
					ptListSortNode->ptNext->cData=cData;
				}
				ptListSortNode=ptListSortNode->ptNext;
			}
		}
		iRet=0;
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: ListInit
-Description	: ListInit
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int ListSortOneCmpAll(T_DualLinkList *i_ptDualLinkListHead)
{
	int iRet=0;
	char cData;
	int i=0,j=0;
	T_DualLinkList *ptListNode=i_ptDualLinkListHead; 
	T_DualLinkList *ptListSortNode=NULL;
	if(NULL==i_ptDualLinkListHead)
	{
		iRet=-1;
		printf("ListSortOneCmpAll Err,HeadNull\r\n");
	}
	else
	{
		for(i=0;i<ListLength(i_ptDualLinkListHead)-1;i++)
		{
			ptListSortNode=ptListNode=ptListNode->ptNext;
			for(j=0;j<ListLength(i_ptDualLinkListHead)-i-1;j++)
			{
				if(ptListNode->cData>ptListSortNode->ptNext->cData)//一比较多找出最小的放最前面
				{//小的放前面
					cData=ptListNode->cData;
					ptListNode->cData=ptListSortNode->ptNext->cData;
					ptListSortNode->ptNext->cData=cData;
				}
				ptListSortNode=ptListSortNode->ptNext;
			}
		}
		iRet=0;
	}
	return iRet;
}

/*****************************************************************************
-Fuction		: GetElementPoint
-Description	: GetElementPoint
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int GetElementPoint(T_DualLinkList *i_ptDualLinkListHead,int i_dwPosition,T_DualLinkList **o_pptElementPoint)
{
	int iRet=0;	
	int j=0;
	T_DualLinkList *ptDualLinkListNode=i_ptDualLinkListHead;
	if((i_dwPosition<0)||(i_dwPosition>ListLength(i_ptDualLinkListHead)))
	{
		iRet=-1;
		printf("GetElementPoint Err\r\n");
	}
	else
	{
		for(j=0;j<i_dwPosition;j++)
		{
			ptDualLinkListNode=ptDualLinkListNode->ptNext;
		}
		*o_pptElementPoint=ptDualLinkListNode;
		iRet=0;
	}
	return iRet;
}

/*****************************************************************************
-Fuction		: ListLength
-Description	: 双向链表是循环链表遍历长度需要比对的是头
结点
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int ListLength(T_DualLinkList *i_ptDualLinkListHead)
{
	int iLength=0;
	T_DualLinkList *ptDualLinkListNode=i_ptDualLinkListHead->ptNext;
	while(i_ptDualLinkListHead!=ptDualLinkListNode)//双向循环链表区别
	{
		iLength++;
		ptDualLinkListNode=ptDualLinkListNode->ptNext;
	}
	return iLength;
}

