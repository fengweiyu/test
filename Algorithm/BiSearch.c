/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BiSearch.c
* Description		: 	BiSearch operation center
* Created			: 	2017.06.14.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"

#define ELEMENT_NUM	11

typedef  int KeyType;// ��ؼ�����Ϊ����

typedef struct SeqTableElement
{
	KeyType key;	// ���йؼ�����
}T_SeqTableElement,*PT_SeqTableElement;

typedef struct SeqTable
{
	T_SeqTableElement *ptElement;
	int iLength;
}T_SeqTable,*PT_SeqTable;

static void CreateOrderSeqTable(T_SeqTableElement i_atElement[],int i_iNum,T_SeqTable *o_ptSeqTable);
static void TraverseOrderSeqTable(T_SeqTable *i_ptSeqTable);
static int BiSearch(T_SeqTable *i_ptSeqTable,KeyType i_Key);
static void DestroyOrderSeqTable(T_SeqTable *i_ptSeqTable);
/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	int i;
	KeyType	KeyElement=0;
	T_SeqTableElement atElement[ELEMENT_NUM]={5,13,19,21,37,56,64,75,80,88,92};
	T_SeqTable tSeqTable={0};
	CreateOrderSeqTable(atElement,ELEMENT_NUM,&tSeqTable);
	TraverseOrderSeqTable(&tSeqTable);
	printf("�����������ֵ�Ĺؼ���: ");
	scanf("%d",&KeyElement);
	i=BiSearch(&tSeqTable,KeyElement); // �۰���������
	if(i)
	printf("%d �ǵ�%d����¼�Ĺؼ���\n",tSeqTable.ptElement[i].key,i);
	else
	printf("û�ҵ�\n");
	DestroyOrderSeqTable(&tSeqTable);

	return 0;
}



/*****************************************************************************
-Fuction		: CreateSeqTable
-Description	: 
// ����������ɺ�n������Ԫ�ص�����r���쾲̬˳����ұ�ST

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void CreateOrderSeqTable(T_SeqTableElement i_atElement[],int i_iNum,T_SeqTable *o_ptSeqTable)
{
	int i;
	//��malloc������,calloc�ڶ�̬�������ڴ���Զ���ʼ�����ڴ�ռ�Ϊ�㣬��malloc����ʼ�������������������������ݡ�
	o_ptSeqTable->ptElement=(T_SeqTableElement *)calloc(i_iNum+1,sizeof(T_SeqTableElement));// ��̬����n+1������Ԫ�ؿռ�(0�ŵ�Ԫ����)
	if(NULL==o_ptSeqTable->ptElement)
	{
		printf("CreareSeqTable err,calloc fail\r\n");
	}
	else
	{
		for(i=1;i<=i_iNum;i++)
		{//�����1��λ�ü����0��λ�ò����,��Ϊλ�ô�1��ʼ,ͬʱ������ҷ���ֵ����
			memcpy(&o_ptSeqTable->ptElement[i],&i_atElement[i-1],sizeof(T_SeqTableElement));
		}
		//memcpy(o_ptSeqTable->ptElement,i_atElement,sizeof(i_atElement));//������ǵ�ַ������������
		o_ptSeqTable->iLength=i_iNum;
	}
}

/*****************************************************************************
-Fuction		: BiSearch
-Description	: 
// �������ST���۰������ؼ��ֵ���key������Ԫ�ء����ҵ����򷵻�
// ��Ԫ���ڱ��е�λ�ã����򷵻�0��
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int BiSearch(T_SeqTable *i_ptOrderSeqTable,KeyType i_Key)
{
	int iPos=0;
	int iLow,iHigh,iMid;
	iLow=1;
	iHigh=i_ptOrderSeqTable->iLength;
	while(iLow<=iHigh)
	{
		iMid=(iLow+iHigh)/2;
		if(i_Key==i_ptOrderSeqTable->ptElement[iMid].key)
		{
			iPos=iMid;
			break;
		}
		else if(i_Key<i_ptOrderSeqTable->ptElement[iMid].key)
		{
			iHigh=iMid-1;
		}
		else
		{
			iLow=iMid+1;
		}
	}
	return iPos;
}

/*****************************************************************************
-Fuction		: TraverseOrderSeqTable
-Description	: TraverseOrderSeqTable
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void TraverseOrderSeqTable(T_SeqTable *i_ptSeqTable)
{
	int i=0;
	for(i=1;i<=i_ptSeqTable->iLength;i++)
	{
		printf("%d ",i_ptSeqTable->ptElement[i].key);
	}
	printf("\r\n");
}

/*****************************************************************************
-Fuction		: DestroyOrderSeqTable
-Description	: DestroyOrderSeqTable
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void DestroyOrderSeqTable(T_SeqTable *i_ptSeqTable)
{
	free(i_ptSeqTable->ptElement);
	i_ptSeqTable->ptElement=NULL;
	i_ptSeqTable->iLength=0;
}

