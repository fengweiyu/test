/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SequenceList.c
* Description		: 	SequenceList operation center
* Created			: 	2017.05.22.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"

typedef struct SeqListElement//顺序表结点里只有数据元素
{
	char cData;
}T_SeqListElement,*PT_SeqListElement;//结点等同于数据元素

typedef struct SeqList
{
	T_SeqListElement *ptBase;//所以为了方便,直接表元素代替表结点
	int iCurLength;
	int iMaxLength;
}T_SeqList,*PT_SeqList;

#define LIST_INIT_SIZE 10 // 线性表存储空间的初始分配量
#define LIST_INCREMENT 2 // 线性表存储空间的分配增量


static int InitSeqList(T_SeqList *m_ptSeqList);
static int IsSeqListEmpty(T_SeqList *i_ptSeqList);
static int InsertElementToSeqList(T_SeqList *i_ptSeqList,int i_dwInsertPos,T_SeqListElement *i_ptInsertElement);
static int DeleteElementFromSeqList(T_SeqList *i_ptSeqList,int i_dwInsertPos,T_SeqListElement *o_ptDeleteElement);
static int TraverseSequenceList(T_SeqList *i_ptSeqList);
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
	T_SeqListElement tElement={0};
	T_SeqList tSeqList={0};
	InitSeqList(&tSeqList);
	tElement.cData=1;
	InsertElementToSeqList(&tSeqList,1,&tElement);
	tElement.cData=23;
	InsertElementToSeqList(&tSeqList,2,&tElement);
	tElement.cData=24;
	InsertElementToSeqList(&tSeqList,3,&tElement);
	tElement.cData=26;
	InsertElementToSeqList(&tSeqList,4,&tElement);
	tElement.cData=66;
	InsertElementToSeqList(&tSeqList,5,&tElement);
	tElement.cData=99;
	InsertElementToSeqList(&tSeqList,6,&tElement);
	printf("插入结果:");
	TraverseSequenceList(&tSeqList);
	
	DeleteElementFromSeqList(&tSeqList,6,&tElement);
	DeleteElementFromSeqList(&tSeqList,4,&tElement);
	printf("删除结果:");
	TraverseSequenceList(&tSeqList);
	
	printf("插入结果:");
	tElement.cData=5;
	InsertElementToSeqList(&tSeqList,3,&tElement);
	TraverseSequenceList(&tSeqList);
	return 0;
}


/*****************************************************************************
-Fuction		: InitSeqList
-Description	: InitSeqList
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int InitSeqList(T_SeqList *m_ptSeqList)
{
	int ret=-1;
	m_ptSeqList->ptBase=(T_SeqListElement *)malloc(sizeof(T_SeqListElement)*LIST_INIT_SIZE);
	if(NULL==m_ptSeqList->ptBase)
	{
		printf("InitSeqList Err\r\n");
		ret=-1;
	}
	else
	{
		m_ptSeqList->iCurLength=0;
		m_ptSeqList->iMaxLength=LIST_INIT_SIZE;
		ret=0;
	}
	return ret;
}

/*****************************************************************************
-Fuction		: IsSeqListEmpty
-Description	: IsSeqListEmpty
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int IsSeqListEmpty(T_SeqList *i_ptSeqList)
{
	int ret=-1;
	if(0==i_ptSeqList->iCurLength)
	{
		ret=0;
	}
	else
	{
		ret=-1;
	}
	return ret;
}

/*****************************************************************************
-Fuction		: InsertSeqList
-Description	: InsertSeqList
-Input			: i_dwInsertPos 从1 开始算的
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int InsertElementToSeqList(T_SeqList *i_ptSeqList,int i_dwInsertPos,T_SeqListElement *i_ptInsertElement)
{
	int ret=-1;
	T_SeqListElement *ptNewBase=NULL;
	T_SeqListElement *ptInsertElement=NULL;
	T_SeqListElement *ptSeqListElement=NULL;
	if(i_dwInsertPos<1||i_dwInsertPos>i_ptSeqList->iCurLength+1)// i_dwInsertPos值不合法
	{
		ret=-1;
	}
	else
	{
		if(i_ptSeqList->iCurLength>=i_ptSeqList->iMaxLength)// 当前存储空间已满,增加分配
		{
			ptNewBase=(T_SeqListElement *)realloc(i_ptSeqList->ptBase,(i_ptSeqList->iMaxLength+LIST_INCREMENT)*sizeof(T_SeqListElement));
			if(NULL==ptNewBase)
			{
				printf("InsertSeqList realloc err\r\n");
				ret=-1;
				exit(-1);
			}
			else
			{
				i_ptSeqList->ptBase=ptNewBase;
				i_ptSeqList->iMaxLength+=LIST_INCREMENT;
			}
		}
		else
		{
		}
		ptInsertElement=i_ptSeqList->ptBase+i_dwInsertPos-1;//从0开始算等价于i_ptSeqList->ptBase[i_dwInsertPos-1]
		for(ptSeqListElement=i_ptSeqList->ptBase+i_ptSeqList->iCurLength-1;ptSeqListElement>=ptInsertElement;ptSeqListElement--)
		{// 插入位置及之后的元素右移
			memcpy(ptSeqListElement+1,ptSeqListElement,sizeof(T_SeqListElement));
		}
		memcpy(ptInsertElement,i_ptInsertElement,sizeof(T_SeqListElement));
		i_ptSeqList->iCurLength++;
		ret=0;
	}
	return ret;
}

/*****************************************************************************
-Fuction		: DeleteElementFromSeqList
-Description	: DeleteElementFromSeqList
-Input			: i_dwInsertPos 从1 开始算的
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int DeleteElementFromSeqList(T_SeqList *i_ptSeqList,int i_dwInsertPos,T_SeqListElement *o_ptDeleteElement)
{
	int ret=-1;
	T_SeqListElement *ptNewBase=NULL;
	T_SeqListElement *ptDeleteElement=NULL;
	T_SeqListElement *ptSeqListElement=NULL;
	if(i_dwInsertPos<1||i_dwInsertPos>i_ptSeqList->iCurLength)// i_dwInsertPos值不合法
	{
		ret=-1;
	}
	else
	{
		ptDeleteElement=i_ptSeqList->ptBase+i_dwInsertPos-1;//从0开始算等价于i_ptSeqList->ptBase[i_dwInsertPos-1]
		memcpy(o_ptDeleteElement,ptDeleteElement,sizeof(T_SeqListElement));
		for(ptSeqListElement=ptDeleteElement+1;ptSeqListElement<=i_ptSeqList->ptBase+i_ptSeqList->iCurLength-1;ptSeqListElement++)
		{// 被删除元素之后的元素左移
			memcpy(ptSeqListElement-1,ptSeqListElement,sizeof(T_SeqListElement));
		}
		i_ptSeqList->iCurLength--;
		ret=0;
	}
	return ret;
}

/*****************************************************************************
-Fuction		: TraverseSequenceList
-Description	: TraverseSequenceList
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int TraverseSequenceList(T_SeqList *i_ptSeqList)
{
	int ret=-1;
	int i;
	for(i=0;i<i_ptSeqList->iCurLength;i++)
	{
		printf("%d ",i_ptSeqList->ptBase[i].cData);
	}
	printf("\r\n");
	return ret;
}

