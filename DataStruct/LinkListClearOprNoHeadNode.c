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
#include "AdjacencyListGraph.h"

/*typedef struct LinkListElement
{
	char cData;
}T_LinkListElement,*PT_LinkListElement;

typedef struct LinkList
{
	T_LinkListElement tData;
	struct LinkList *ptNext;
}T_LinkList,*PT_LinkList;*/
typedef T_ArcNode T_LinkList;

#define LINK_LIST_LEN 10

static int InsertNodeToLinkList(T_LinkList **i_pptLinkListHead,int i_dwPosition,T_LinkListElement *i_ptElement);
static int DeleteNodeFromLinkList(T_LinkList **i_pptLinkListHead,int i_dwPosition,T_LinkListElement *o_ptElement);
static int TraverseLinkList(T_LinkList *i_ptLinkListHead);
static void ClearLinkList(T_LinkList *i_ptLinkListHead);

#define DestroyLinkList ClearLinkList // DestroyList()��ClearList()�Ĳ�����һ����

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
/*int main(int argc,char **argv)
{
	PT_LinkList ptLinkListHead=NULL;
	T_LinkListElement tLinkListElement;
	tLinkListElement.cData=1;
	InsertNodeToLinkList(&ptLinkListHead,1,&tLinkListElement);
	tLinkListElement.cData=23;
	InsertNodeToLinkList(&ptLinkListHead,2,&tLinkListElement);
	tLinkListElement.cData=24;
	InsertNodeToLinkList(&ptLinkListHead,3,&tLinkListElement);
	tLinkListElement.cData=26;
	InsertNodeToLinkList(&ptLinkListHead,4,&tLinkListElement);
	tLinkListElement.cData=66;
	InsertNodeToLinkList(&ptLinkListHead,5,&tLinkListElement);
	tLinkListElement.cData=99;
	InsertNodeToLinkList(&ptLinkListHead,6,&tLinkListElement);
	
	printf("������:");
	TraverseLinkList(ptLinkListHead);
	DeleteNodeFromLinkList(&ptLinkListHead,6,&tLinkListElement);
	DeleteNodeFromLinkList(&ptLinkListHead,4,&tLinkListElement);
	
	printf("ɾ�����:");
	TraverseLinkList(ptLinkListHead);
	
	printf("������:");
	tLinkListElement.cData=5;
	InsertNodeToLinkList(&ptLinkListHead,3,&tLinkListElement);
	TraverseLinkList(ptLinkListHead);
	return 0;
}*/
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
	T_LinkList *ptLinkListNode=i_ptLinkListHead;
	if(NULL==ptLinkListNode)
	{
		//printf("ListNull\r\n");
	}
	else
	{
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
static int InsertNodeToLinkList(T_LinkList **i_pptLinkListHead,int i_dwPosition,T_LinkListElement *i_ptElement)
{
	int ret=-1;
	T_LinkList *ptLinkListNode=*i_pptLinkListHead;
	T_LinkList *ptInsertListNode=NULL;	
	int iLen=0;
	int iPreInsertPos=0;
	iLen=GetLinkListLength(ptLinkListNode);
	if(i_dwPosition<1||i_dwPosition-1>iLen)
	{// iֵ���Ϸ�// i���ڱ�+1
		ret=-1;		
		printf("InsertPositionErr,Len:%d,Pos:%d\r\n",iLen,i_dwPosition);
	}
	else
	{
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
			if(1==i_dwPosition)// ���ڱ�ͷ
			{
				ptInsertListNode->ptNext=*i_pptLinkListHead;
				*i_pptLinkListHead=ptInsertListNode;// �ı�L
			}
			else
			{
				iPreInsertPos=i_dwPosition-1;
				while(--iPreInsertPos)// Ѱ�ҵ�i-1����������ǰһ��λ��
				{//����ֱ���ò�����λ�ã���Ϊ�����ǰһ��λ�õ�nextָ��ҲҪ�޸�
					ptLinkListNode=ptLinkListNode->ptNext;//ǰһ������nextָ���޸ĺ������������
				}
				ptInsertListNode->ptNext=ptLinkListNode->ptNext;//ԭ�Ƚ��ŵ����ں���
				ptLinkListNode->ptNext=ptInsertListNode;//��ǰһ���������
			}
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
static int DeleteNodeFromLinkList(T_LinkList **i_pptLinkListHead,int i_dwPosition,T_LinkListElement *o_ptElement)
{
	int ret=-1;
	T_LinkList *ptLinkListNode=*i_pptLinkListHead;
	T_LinkList *ptDeleteListNode=NULL;
	int iLen=0;
	int iPreDeletePos=0;
	iLen=GetLinkListLength(ptLinkListNode);
	if(i_dwPosition<1||i_dwPosition>iLen||(0==iLen))
	{// iֵ���Ϸ�// i���ڱ�//�ձ�
		ret=-1;
		printf("LinkListDeleteErr,Len:%d,Pos:%d\r\n",iLen,i_dwPosition);
	}
	else
	{
		if(1==i_dwPosition)
		{
			memcpy(o_ptElement,&ptLinkListNode->tData,sizeof(T_LinkListElement));
			*i_pptLinkListHead=ptLinkListNode->ptNext;// L�ɵ�2����㿪ʼ
			free(ptLinkListNode);// ɾ�����ͷŵ�1�����
		}
		else
		{
			iPreDeletePos=i_dwPosition-1;
			while(--iPreDeletePos)//Ѱ�ҵ�i-1�����
			{
				ptLinkListNode=ptLinkListNode->ptNext;
			}
			ptDeleteListNode=ptLinkListNode->ptNext;// ɾ�����ͷŽ��
			memcpy(o_ptElement,&ptDeleteListNode->tData,sizeof(T_LinkListElement));
			ptLinkListNode->ptNext=ptDeleteListNode->ptNext;
			free(ptDeleteListNode);
		}
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
	if(ptLinkListNode==NULL)
	{
		printf("LinkListTraverseErr,LinkListEmpty\r\n");
	}
	else
	{
		while(NULL!=ptLinkListNode)
		{
			//printf("%d ",ptLinkListNode->tData.cData);
			ptLinkListNode=ptLinkListNode->ptNext;
		}
		printf("\r\n");
		ret=0;
	}
	return ret;
}

/*****************************************************************************
-Fuction		: ClearLinkList
-Description	: ClearLinkList
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void ClearLinkList(T_LinkList *i_ptLinkListHead)
{ // ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�(��ͼ213)
	T_LinkList *ptLinkListNode;
	while(i_ptLinkListHead) // L����
	{
		ptLinkListNode=i_ptLinkListHead; // pָ����Ԫ���
		i_ptLinkListHead=i_ptLinkListHead->ptNext; // Lָ���2�����(����Ԫ���)
		free(ptLinkListNode); // �ͷ���Ԫ���
	}
}

/*****************************************************************************
-Fuction		: GetLinkListNodeLocation
-Description	: GetLinkListNodeLocation
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int GetLinkListNodeLocation(T_LinkList *i_ptLinkListHead,T_LinkListElement *i_ptElement,int (*Compare)(T_LinkListElement *i_ptElement1,T_LinkListElement *i_ptElement2))
{
	int iLocation=0;
	T_LinkList *ptLinkListNode=i_ptLinkListHead;
	while(NULL!=ptLinkListNode)
	{
		iLocation++;
		if(0==Compare(&ptLinkListNode->tData,i_ptElement))
		{
			break;
		}
		else
		{
			ptLinkListNode=ptLinkListNode->ptNext;
		}
	}
	if(NULL==ptLinkListNode)
	{
		iLocation=0;//û�ҵ�����0
	}
	else
	{
	}
	return iLocation;
}

/*****************************************************************************
-Fuction		: GetLinkListNodePoint
-Description	: GetLinkListNodePoint
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static T_LinkList *GetLinkListNodePoint(T_LinkList *i_ptLinkListHead,T_LinkListElement *i_ptElement,int (*Compare)(T_LinkListElement *i_ptElement1,T_LinkListElement *i_ptElement2),T_LinkList **o_pptElementPreNode)
{
	int i,j;
	T_LinkList *ptLinkListNode=NULL;
	i=GetLinkListNodeLocation(i_ptLinkListHead,i_ptElement,Compare);
	if(0==i)
	{
	}
	else
	{
		if(1==i)
		{
			ptLinkListNode=i_ptLinkListHead;
			*o_pptElementPreNode=NULL;//ǰ��Ϊnull
		}
		else
		{
			ptLinkListNode=i_ptLinkListHead;	
			for(j=2;j<i;j++)
			{
				ptLinkListNode=ptLinkListNode->ptNext;
			}
			*o_pptElementPreNode=ptLinkListNode;
			ptLinkListNode=ptLinkListNode->ptNext;
		}
	}
	return ptLinkListNode;
}

/*****************************************************************************
-Fuction		: DeleteElementFromLinkList
-Description	: DeleteElementFromLinkList
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int DeleteElementFromLinkList(T_LinkList *i_ptLinkListHead,T_LinkListElement *m_ptElement,int (*Compare)(T_LinkListElement *i_ptElement1,T_LinkListElement *i_ptElement2))
{
	int iRet=-1;
	T_LinkList *ptLinkListNode=NULL;
	T_LinkList *ptLinkListPreNode=NULL;
	
	ptLinkListNode=GetLinkListNodePoint(i_ptLinkListHead,m_ptElement,Compare,&ptLinkListPreNode);
	if(NULL==ptLinkListNode)
	{
		iRet=-1;
	}
	else// �ҵ��˽��
	{
		if(NULL==ptLinkListPreNode)// �ý������Ԫ���
		{
			DeleteNodeFromLinkList(&i_ptLinkListHead,1,m_ptElement);
		}
		else// �ý�㲻����Ԫ��㣬ptLinkListPreNodeָ����ǰ��
		{
			DeleteNodeFromLinkList(&ptLinkListPreNode,2,m_ptElement);
		}
		iRet=0;
	}
	return iRet;
}

