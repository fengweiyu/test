/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	InsertSort.c
* Description		: 	InsertSort operation center

һ������˼��
ֱ�Ӳ���������һ����򵥵����򷽷������Ļ���������
��һ����¼���뵽���ź����������У��Ӷ��õ�һ����
�ġ���¼����1�������
�ʼ���ź���������ֻ��һ��Ԫ�أ�����һ��Ԫ�ء�

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

static void TraverseRecordSeqList(T_RecordSeqList *i_ptRecordSeqList);
static void InsertSort(T_RecordSeqList *i_ptRecordSeqList);

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
	InsertSort(&tSeqList1);
	printf("ֱ�Ӳ��������:\n");
	TraverseRecordSeqList(&tSeqList1);

	return 0;
}

/*****************************************************************************
-Fuction		: InsertSort
-Description	: // ��˳���L��ֱ�Ӳ�������

�������岽��
1. �ӵ�һ��Ԫ�ؿ�ʼ�������һ��Ԫ�ر�ǰһ��С����
2. ���Ƶ��ڱ���
3. ����ڱ�Ԫ��С��������Ԫ�أ���ò������������
4. �������λ�õĺ�һ��λ�þ���Ҫ�����λ��

��: 	{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}
	{38,2},{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}
	{38,2},{49,1},{49,1},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}
	{38,2},{38,2},{49,1},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}
	
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void InsertSort(T_RecordSeqList *i_ptRecordSeqList)
{
	int i,j;
	for(i=2;i<=i_ptRecordSeqList->iLength;i++)
	{
		if(i_ptRecordSeqList->atRecord[i].Key<i_ptRecordSeqList->atRecord[i-1].Key)// "<",�轫L.r[i]���������ӱ�
		{
			memcpy(&i_ptRecordSeqList->atRecord[0],&i_ptRecordSeqList->atRecord[i],sizeof(T_RecordType));// ��������Խ��,����Ϊ�ڱ�
			for(j=i-1;(i_ptRecordSeqList->atRecord[0].Key<i_ptRecordSeqList->atRecord[j].Key);j--)
			{// ��¼����,ͬʱ�ҵ������λ��
				memcpy(&i_ptRecordSeqList->atRecord[j+1],&i_ptRecordSeqList->atRecord[j],sizeof(T_RecordType));// ��¼����
			}
			memcpy(&i_ptRecordSeqList->atRecord[j+1],&i_ptRecordSeqList->atRecord[0],sizeof(T_RecordType));// ���뵽��ȷλ��
		}
		else
		{
		}
	}
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

