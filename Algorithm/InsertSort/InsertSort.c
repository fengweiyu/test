/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	InsertSort.c
* Description		: 	InsertSort operation center

一、基本思想
直接插入排序是一种最简单的排序方法，它的基本操作是
将一个记录插入到已排好序的有序表中，从而得到一个新
的、记录数增1的有序表。
最开始已排好序的有序表只有一个元素，即第一个元素。

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
	T_RecordType atRecord[RECORD_SEQ_LIST_MAX_LEN+1];// r[0]闲置或用作哨兵单元
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
	for(i=0;i<RECORD_NUMBER;i++) // 给l1.r赋值
		tSeqList1.atRecord[i+1]=atRecord[i];
	tSeqList1.iLength=RECORD_NUMBER;
	tSeqList3=tSeqList2=tSeqList1; // 复制顺序表l2、l3与l1相同
	printf("排序前:\n");
	TraverseRecordSeqList(&tSeqList1);
	InsertSort(&tSeqList1);
	printf("直接插入排序后:\n");
	TraverseRecordSeqList(&tSeqList1);

	return 0;
}

/*****************************************************************************
-Fuction		: InsertSort
-Description	: // 对顺序表L作直接插入排序

二、具体步骤
1. 从第一个元素开始，如果后一个元素比前一个小，则
2. 复制到哨兵，
3. 如果哨兵元素小于有序表的元素，则该部分有序表右移
4. 否则，这个位置的后一个位置就是要插入的位置

例: 	{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}
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
		if(i_ptRecordSeqList->atRecord[i].Key<i_ptRecordSeqList->atRecord[i-1].Key)// "<",需将L.r[i]插入有序子表
		{
			memcpy(&i_ptRecordSeqList->atRecord[0],&i_ptRecordSeqList->atRecord[i],sizeof(T_RecordType));// 避免数组越界,复制为哨兵
			for(j=i-1;(i_ptRecordSeqList->atRecord[0].Key<i_ptRecordSeqList->atRecord[j].Key);j--)
			{// 记录后移,同时找到插入的位置
				memcpy(&i_ptRecordSeqList->atRecord[j+1],&i_ptRecordSeqList->atRecord[j],sizeof(T_RecordType));// 记录后移
			}
			memcpy(&i_ptRecordSeqList->atRecord[j+1],&i_ptRecordSeqList->atRecord[0],sizeof(T_RecordType));// 插入到正确位置
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

