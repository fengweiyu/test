/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SequenceSearch.c
* Description		: 	SequenceSearch operation center
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

#define ELEMENT_NUM	3

#define Key dwNumber	// ����ؼ���Ϊ׼��֤��
typedef unsigned int KeyType;// ��ؼ�����Ϊ����

typedef struct SeqTableElement
{
	unsigned int dwNumber;
	char strName[9]; // ����(4�����ּ�1����������־)
}T_SeqTableElement,*PT_SeqTableElement;


typedef struct SeqTable
{
	T_SeqTableElement *ptElement;
	int iLength;
}T_SeqTable,*PT_SeqTable;

static void CreateSeqTable(T_SeqTableElement i_atElement[],int i_iNum,T_SeqTable *o_ptSeqTable);
static int SequenceSearch(T_SeqTable *i_ptSeqTable,KeyType i_Key);
static void TraverseSeqTable(T_SeqTable *i_ptSeqTable);
static void DestroySeqTable(T_SeqTable *i_ptSeqTable);

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
	T_SeqTableElement atElement[ELEMENT_NUM]={{123456,"LiMing"},{123467,"XiaoMing"},{123477,"LiHua"}};
	T_SeqTable tSeqTable={0};
	CreateSeqTable(atElement,ELEMENT_NUM,&tSeqTable);
	TraverseSeqTable(&tSeqTable);
	printf("������������˵Ŀ���: ");
	scanf("%d",&KeyElement);
	i=SequenceSearch(&tSeqTable,KeyElement); // ˳�����
	if(i)
	printf("%8d%8s\r\n",tSeqTable.ptElement[i].dwNumber,tSeqTable.ptElement[i].strName);
	else
	printf("û�ҵ�\n");
	DestroySeqTable(&tSeqTable);

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
static void CreateSeqTable(T_SeqTableElement i_atElement[],int i_iNum,T_SeqTable *o_ptSeqTable)
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
		{
			memcpy(&o_ptSeqTable->ptElement[i],&i_atElement[i-1],sizeof(T_SeqTableElement));
		}
		o_ptSeqTable->iLength=i_iNum;
	}
}

/*****************************************************************************
-Fuction		: SequenceSearch
-Description	: 
// ��˳���ST��˳�������ؼ��ֵ���key������Ԫ�ء����ҵ����򷵻�
// ��Ԫ���ڱ��е�λ�ã����򷵻�0��
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int SequenceSearch(T_SeqTable *i_ptSeqTable,KeyType i_Key)
{
	int i=0;
	i_ptSeqTable->ptElement[0].Key=i_Key;// �ڱ�
	for(i=i_ptSeqTable->iLength;i_Key!=i_ptSeqTable->ptElement[i].Key;i--);// �Ӻ���ǰ��
	return i;// �Ҳ���ʱ��iΪ0
}

/*****************************************************************************
-Fuction		: TraverseSeqTable
-Description	: TraverseSeqTable
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void TraverseSeqTable(T_SeqTable *i_ptSeqTable)
{
	int i=0;
	for(i=1;i<=i_ptSeqTable->iLength;i++)
	{
		printf("%8d%8s\r\n",i_ptSeqTable->ptElement[i].dwNumber,i_ptSeqTable->ptElement[i].strName);
	}
}

/*****************************************************************************
-Fuction		: DestroySeqTable
-Description	: DestroySeqTable
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void DestroySeqTable(T_SeqTable *i_ptSeqTable)
{
	free(i_ptSeqTable->ptElement);
	i_ptSeqTable->ptElement=NULL;
	i_ptSeqTable->iLength=0;
}

