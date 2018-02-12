/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SelectSort.c
* Description		: 	SelectSort operation center

һ������˼��
����������(��ʼΪ��������)��ѡ��һ����С�ķ��ڵ�һ��λ�ã�
Ȼ����������(��ʼ��Ԫ��)���ȼ�һ���������г��ȼ�һ

* Created			: 	2017.06.15.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"


#define RECORD_SEQ_LIST_MAX_LEN		20
#define RECORD_NUMBER				8

typedef int KeyType;

typedef struct RecordType
{
	KeyType Key;
	int OtherInfo;
}T_RecordType,*PT_RecordType;

typedef struct RecordSeqList
{
	T_RecordType atRecord[RECORD_SEQ_LIST_MAX_LEN+1];// r[0]���û������ڱ���Ԫ
	int iLength;
}T_RecordSeqList,*PT_RecordSeqList;

static int SelectMinKey(T_RecordSeqList *i_ptRecordSeqList,int i_iPos);

static void TraverseRecordSeqList(T_RecordSeqList *i_ptRecordSeqList);
static void SelectSort(T_RecordSeqList *i_ptRecordSeqList);


/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_RecordType atRecord[RECORD_NUMBER]={{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}};
	T_RecordSeqList tSeqList1, tSeqList2, tSeqList3;
	int i;
	for(i=0;i<RECORD_NUMBER;i++) // ��l1.r��ֵ
		tSeqList1.atRecord[i+1]=atRecord[i];
	tSeqList1.iLength=RECORD_NUMBER;
	tSeqList3=tSeqList2=tSeqList1; // ����˳���l2��l3��l1��ͬ
	printf("����ǰ:\n");
	TraverseRecordSeqList(&tSeqList1);
	SelectSort(&tSeqList1);
	printf("��ѡ�������:\n");
	TraverseRecordSeqList(&tSeqList1);

	return 0;
}

/*****************************************************************************
-Fuction		: SelectSort
-Description	: // ��˳���L����ѡ������

�������岽��
1. ѡ����������(��ʼΪ��������)��С�ؼ��ֵ�λ��
2. �ж�λ���Ƿ��������еĵ�һ��λ�ã������Ҫ����
3.��������(��ʼ��Ԫ��)��һ���������п�ʼλ��Ҳ��һ(����ƶ�һλ)

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void SelectSort(T_RecordSeqList *i_ptRecordSeqList)
{
	int i,j;
	T_RecordType tRecord={0};
	for(i=1;i<i_ptRecordSeqList->iLength;i++)//����Ǹ���Ȼ������
	{// ѡ���iС�ļ�¼����������λ(ѡ���iС�ķŵ�iλ)
		j=SelectMinKey(i_ptRecordSeqList,i);// ��L.r[i..L.length]��ѡ��key��С�ļ�¼
		if(i!=j)
		{// ���i����¼����
			tRecord=i_ptRecordSeqList->atRecord[i];
			i_ptRecordSeqList->atRecord[i]=i_ptRecordSeqList->atRecord[j];
			i_ptRecordSeqList->atRecord[j]=tRecord;
		}
		else
		{
		}
	}
}

/*****************************************************************************
-Fuction		: SelectMinKey
-Description	: // ������L.r[i..L.length]��key��С�ļ�¼�����
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int SelectMinKey(T_RecordSeqList *i_ptRecordSeqList,int i_iPos)
{
	int i,j;
	KeyType tMinKey={0};
	j=i_iPos;// ���i_iPos��Ϊ��С
	tMinKey=i_ptRecordSeqList->atRecord[i_iPos].Key;
	for(i=i_iPos+1;i<=i_ptRecordSeqList->iLength;i++)
	{
		if(i_ptRecordSeqList->atRecord[i].Key<tMinKey)// �ҵ���С��
		{
			j=i;
			tMinKey=i_ptRecordSeqList->atRecord[i].Key;
		}
		else
		{
		}
	}
	return j;
}

/*****************************************************************************
-Fuction		: TraverseRecordSeqList
-Description	: TraverseRecordSeqList
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void TraverseRecordSeqList(T_RecordSeqList *i_ptRecordSeqList)
{
	int i;
	for(i=1;i<=i_ptRecordSeqList->iLength;i++)
	{
		printf("(%d,%d)",i_ptRecordSeqList->atRecord[i].Key,i_ptRecordSeqList->atRecord[i].OtherInfo);
	}
	printf("\r\n");
}

