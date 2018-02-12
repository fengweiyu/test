/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BiInsertSort.c
* Description		: 	BiInsertSort operation center

一、基本思想
由于插入排序的基本操作是将一个记录插入到已排好序的有序表中，
在已排好序的有序表中查找插入点的操作可利用折半查找来实现，
由此进行的插入排序称为折半插入排序


* Created			: 	2017.06.16.
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
static void BiInsertSort(T_RecordSeqList *i_ptRecordSeqList);

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
	BiInsertSort(&tSeqList1);
	printf("折半插入排序后:\n");
	TraverseRecordSeqList(&tSeqList1);

	return 0;
}
/*****************************************************************************
-Fuction		: BiInsertSort
-Description	: // 对顺序表L作折半插入排序


二、具体步骤
1. 复制到哨兵，
2. 在有序表中折半查找要插入的位置//high=i-1;//从1开始逐渐有序
3. 要插入的位置的记录包括其后面的记录整体进行后移
4. 待插的记录插入

例:
[yweifeng@localhost test]$ gcc -o BiInsertSort BiInsertSort.c
[yweifeng@localhost test]$ ./BiInsertSort                    
排序前:
(49,1)(38,2)(65,3)(97,4)(76,5)(13,6)(27,7)(49,8)
折半插入排序后:
(13,6)(27,7)(38,2)(49,1)(49,8)(65,3)(76,5)(97,4)
[yweifeng@localhost test]$ 


-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void BiInsertSort(T_RecordSeqList *i_ptRecordSeqList)
{ // 对顺序表L作折半插入排序。
	int i,j,m,low,high;
	for(i=2;i<=i_ptRecordSeqList->iLength;++i)
	{
		i_ptRecordSeqList->atRecord[0]=i_ptRecordSeqList->atRecord[i]; // 将L.r[i]暂存到L.r[0]
		low=1;
		high=i-1;//从1开始逐渐有序
		while(low<=high)//查找算法的条件。//以保证high指向查找点位置的前一个
		{ // 在r[low..high]中折半查找有序插入的位置
			m=(low+high)/2; // 折半
			if(i_ptRecordSeqList->atRecord[0].Key<i_ptRecordSeqList->atRecord[m].Key)
				high=m-1; // 插入点在低半区
			else
				low=m+1; // 插入点在高半区
		}
		for(j=i-1;j>=high+1;--j)
			i_ptRecordSeqList->atRecord[j+1]=i_ptRecordSeqList->atRecord[j]; // 记录后移
		i_ptRecordSeqList->atRecord[high+1]=i_ptRecordSeqList->atRecord[0]; // 插入
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


