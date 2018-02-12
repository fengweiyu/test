/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	MergeSort.c
* Description		: 	MergeSort operation center

一、基本思想
整个序列分为左右两半且要都是有序的,然后再归并
左半部分又分为两半且要都是有序的,然后再归并
右半部分又分为两半且要都是有序的,然后再归并(分割的子问题有和父问题是一样的处理考虑用递归)
(递归中先前半部分(左边)变为有序,再后半部分(右边)变为有序)
直到左右两半都只有一个元素即有序了再向上归并(子序列元素扩大,子序列数目减少)

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



#define SEQ_LIST_RECORD_MAX_LEN		20
#define RECORD_NUMBER				8

typedef int KeyType;

typedef struct RecordType
{
	KeyType Key;
	int OtherInfo;
}T_RecordType,*PT_RecordType;

typedef struct RecordSeqList
{
	T_RecordType atRecord[SEQ_LIST_RECORD_MAX_LEN+1];// r[0]闲置或用作哨兵单元
	int iLength;
}T_RecordSeqList,*PT_RecordSeqList;
static void Merge(T_RecordType i_atSrcRecord[],T_RecordType o_atDstRecord[],int i_iLow,int i_iMid,int i_iHigh);
static void MSort(T_RecordType i_atSrcRecord[],T_RecordType o_atDstRecord[],int i_iLow, int i_iHigh);



static void MergeSort(T_RecordSeqList *i_ptRecordSeqList);
static void TraverseRecordSeqList(T_RecordSeqList *i_ptRecordSeqList);

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
	MergeSort(&tSeqList1);
	printf("归并排序后:\n");
	TraverseRecordSeqList(&tSeqList1);

	return 0;
}

/*****************************************************************************
-Fuction		: MergeSort
-Description	: 对顺序表L作归并排序
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void MergeSort(T_RecordSeqList *i_ptRecordSeqList)
{
	MSort(i_ptRecordSeqList->atRecord,i_ptRecordSeqList->atRecord,1,i_ptRecordSeqList->iLength);//0不放元素所以传1(从1开始
}

/*****************************************************************************
-Fuction		: MSort
-Description	: // 将i_atSrcRecord[s(i_iLow)..t(i_iHigh)]归并排序为o_atDstRecord[s..t]。

二、具体步骤
1. 递归地将左半部分归并为有序,即将i_atSrcRecord左半部分归并到atRecord
2. 递归地将右半部分归并为有序,即将i_atSrcRecord右半部分归并到atRecord
直到左右两半都只有一个元素即有序了再向上归并
3. 归并左右两半为有序序列,即将atRecord的左右两半归并到o_atDstRecord

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void MSort(T_RecordType i_atSrcRecord[],T_RecordType o_atDstRecord[],int i_iLow, int i_iHigh)
{
	int iMid;
	T_RecordType atRecord[SEQ_LIST_RECORD_MAX_LEN+1]={0};
	if(i_iLow==i_iHigh)
	{
		o_atDstRecord[i_iLow]=i_atSrcRecord[i_iLow];
	}
	else//atRecord通过递归左右两边各自变为有序部分并不断增大
	{//最后归并左右两半部分为有序(递归中先前半部分(左边)变为有序,再后半部分(右边)变为有序)
		iMid=(i_iLow+i_iHigh)/2; // 将i_atSrcRecord[s..t]平分为i_atSrcRecord[s..m]和i_atSrcRecord[m+1..t]
		MSort(i_atSrcRecord,atRecord,i_iLow,iMid); // 递归地将i_atSrcRecord[s..m]归并为有序的atRecord[s..m]
		MSort(i_atSrcRecord,atRecord,iMid+1,i_iHigh); // 递归地将i_atSrcRecord[m+1..t]归并为有序的atRecord[m+1..t]
		Merge(atRecord,o_atDstRecord,i_iLow,iMid,i_iHigh); // 将atRecord[s..m]和atRecord[m+1..t]归并到o_atDstRecord[s..t]
	}
}

/*****************************************************************************
-Fuction		: Merge
-Description	: 
// 将有序的i_atSrcRecord[i_iLow..i_iMid]和i_atSrcRecord[i_iMid+1..i_iHigh]归并为有序的TR[i..n]

二、具体步骤
3. 合并两个有序序列(一个序列的左右两部分)为一个有序序列
3.1. 左右两边取小的部分保存
左边更小保存起来，同时左边的指针i_iLow后移进行再次比较
右边更小保存起来，同时右边的指针iRight后移进行再次比较
3.2. 复制剩下的
左边还有剩的，剩的部分都比右边的大,即都比已保存的大
右边还有剩的，剩的部分都比左边的大,即都比已保存的大
	
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void Merge(T_RecordType i_atSrcRecord[],T_RecordType o_atDstRecord[],int i_iLow,int i_iMid,int i_iHigh)
{
	int iRight;
	int i,j;
	for(iRight=i_iMid+1,i=i_iLow;i_iLow<=i_iMid&&iRight<=i_iHigh;++i) // 将SR中记录由小到大地并入TR
	{
		if (i_atSrcRecord[i_iLow].Key<i_atSrcRecord[iRight].Key)//两边取小的部分保存到o_atDstRecord
		{
			o_atDstRecord[i]=i_atSrcRecord[i_iLow++];//左边更小保存起来，同时左边的指针i_iLow后移进行再次比较
		}
		else
		{
			o_atDstRecord[i]=i_atSrcRecord[iRight++];;//右边更小保存起来，同时右边的指针i后移进行再次比较
		}
	}
	//复制剩下的
	if(i_iLow<=i_iMid)//左边还有剩的，即剩的部分都比右边的大
	{
		for(j=0;j<=i_iMid-i_iLow;j++)
		{
			o_atDstRecord[i+j]=i_atSrcRecord[i_iLow+j]; // 将剩余的i_atSrcRecord[i_iLow..i_iMid]复制到o_atDstRecord
		}
	}
	if(iRight<=i_iHigh)//右边还有剩的，即剩的部分都比左边的大
	{
		for(j=0;j<=i_iHigh-iRight;j++)
		{
			o_atDstRecord[i+j]=i_atSrcRecord[iRight+j]; // 将剩余的i_atSrcRecord[iRight..i_iHigh]复制到o_atDstRecord
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

