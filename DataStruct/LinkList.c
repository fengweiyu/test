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
	
	printf("������:");
	LinkListTraverse(ptLinkListHead);
	LinkListDelete(ptLinkListHead,6,&dwElement);
	LinkListDelete(ptLinkListHead,4,&dwElement);
	
	printf("ɾ�����:");
	LinkListTraverse(ptLinkListHead);
	
	printf("������:");
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
{//生成一个头结点
	int ret=-1;
	*o_ptLinkListHead=(T_LinkList *)malloc(sizeof(T_LinkList));// ����ͷ��㣬��ʹLָ���ͷ���
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
	while((pLinkListNode!=NULL)&&(j<i_dwPosition-1))//Ѱ�Ҳ���λ�õ�ǰһ�����(�����(����ͷ���)���бȽ�)
	{//����λ��С�ڵ���1ֱ���˳���û���ж�pLinkListNode!=NULL
		pLinkListNode=pLinkListNode->pNext;//�����������λ�õ�ǰһ��������ͷ���(��һ��λ�õ�ʱ��)��
		//���Գ��Ȱ���ͷ���
		j++;//����λ�õ�ǰһ�������������Ȳ���ʱ��ʾ������
	}	
	if((pLinkListNode==NULL)||(j>i_dwPosition-1))
	{//�����Ȳ���ΪNULL�����߲���λ��С��1�쳣��(��һ��λ��Ϊ1)
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
	while((ptLinkListNode->pNext!=NULL)&&(j<i_dwPosition-1))//�ҵ�ɾ�����ǰ��
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

