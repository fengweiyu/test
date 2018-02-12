/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SelectSort.c
* Description		: 	SelectSort operation center

一、基本思想
在无序序列(初始为整个序列)中选择一个最小的放在第一个位置，
然后有序序列(初始无元素)长度加一，无序序列长度减一

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
	for(i=0;i<RECORD_NUMBER;i++) // 给l1.r赋值
		tSeqList1.atRecord[i+1]=atRecord[i];
	tSeqList1.iLength=RECORD_NUMBER;
	tSeqList3=tSeqList2=tSeqList1; // 复制顺序表l2、l3与l1相同
	printf("排序前:\n");
	TraverseRecordSeqList(&tSeqList1);
	SelectSort(&tSeqList1);
	printf("简单选择排序后:\n");
	TraverseRecordSeqList(&tSeqList1);

	return 0;
}

/*****************************************************************************
-Fuction		: SelectSort
-Description	: // 对顺序表L作简单选择排序

二、具体步骤
1. 选择无序序列(初始为整个序列)最小关键字的位置
2. 判断位置是否是无序中的第一个位置，否则就要交换
3.有序序列(初始无元素)加一，无序序列开始位置也加一(向后移动一位)

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
	for(i=1;i<i_ptRecordSeqList->iLength;i++)//最后那个必然是最大的
	{// 选择第i小的记录，并交换到位(选择第i小的放第i位)
		j=SelectMinKey(i_ptRecordSeqList,i);// 在L.r[i..L.length]中选择key最小的记录
		if(i!=j)
		{// 与第i个记录交换
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
-Description	: // 返回在L.r[i..L.length]中key最小的记录的序号
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
	j=i_iPos;// 设第i_iPos个为最小
	tMinKey=i_ptRecordSeqList->atRecord[i_iPos].Key;
	for(i=i_iPos+1;i<=i_ptRecordSeqList->iLength;i++)
	{
		if(i_ptRecordSeqList->atRecord[i].Key<tMinKey)// 找到更小的
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

