/*****************************************************************************
* Copyright (C) 2017-2020 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ShellSort.c
* Description		: 	ShellSort operation center

一、基本思想
希尔排序又称"缩小增量排序",它也是一种属插入排序类的
方法，它的基本思想是:
先将整个待排记录序列分割成为若干子序列,分别进行直接
插入排序，待整个序列中的记录"基本有序"时，再对全体
记录进行一次直接插入排序

例:
[yweifeng@localhost test]$ gcc -o ShellSort ShellSort.c 
[yweifeng@localhost test]$ ./ShellSort
排序前:
(49,1)(38,2)(65,3)(97,4)(76,5)(13,6)(27,7)(49,8)
希尔排序后:
(13,6)(27,7)(38,2)(49,1)(49,8)(65,3)(76,5)(97,4)
[yweifeng@localhost test]$ 


* Created			: 	2017.11.14.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"malloc.h"


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
static void ShellInsert(T_RecordSeqList *i_ptRecordSeqList,int i_iDk);
static void ShellSort(T_RecordSeqList *i_ptRecordSeqList,int *i_atDk,int i_DkLen);

/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_RecordType atRecord[RECORD_NUMBER]={{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}};
	T_RecordSeqList tSeqList1;
	int i;
	memcpy(&tSeqList1.atRecord[1],atRecord,sizeof(atRecord));
	tSeqList1.iLength=RECORD_NUMBER;
	int atDk[3]={5,3,1};

	
	printf("排序前:\n");
	TraverseRecordSeqList(&tSeqList1);
	ShellSort(&tSeqList1,atDk,sizeof(atDk)/sizeof(int));
	printf("希尔排序后:\n");
	TraverseRecordSeqList(&tSeqList1);

	return 0;
}


/*****************************************************************************
-Fuction		: ShellSort
-Description	: // 对顺序表L作希尔排序

二、具体步骤
1. 按照增量，将序列划分为各个子序列
2. 分别对每个子序列进行直接插入排序

8. 缩小增量重复上述步骤

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void ShellSort(T_RecordSeqList *i_ptRecordSeqList,int *i_atDk,int i_DkLen)
{
	int i;
	for(i=0;i<i_DkLen;i++)
	{
		ShellInsert(i_ptRecordSeqList,i_atDk[i]);
	}
}

/*****************************************************************************
-Fuction		: ShellInsert
-Description	: // 对顺序表L作希尔排序

二、具体步骤
3. 按照增量取出子序列，如果后一个子序列元素小于前一个
4. 则将该元素拷贝的暂存单元r[0],同时寻找插入位置
5. 如果r[0]大于子序列中的某个元素，则r[0]就放在该元素后面
6. 否则将记录后移，同时继续比较直到第一个元素为止
7. 如果比较到r[1]，还没有找到，说明r[0]最小,放到r[1]即可


例: 	{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}
	{38,2},{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}
	{13,6},{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}
	{13,6},{49,1},{38,2},{65,3},{97,4},{76,5},{38,2},{27,7},{49,8}

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void ShellInsert(T_RecordSeqList *i_ptRecordSeqList,int i_iDk)
{
	int i,j;
	for(i=i_iDk+1;i<=i_ptRecordSeqList->iLength;i++)//一次循环为相同间隔的一个子序列
	{
		if(i_ptRecordSeqList->atRecord[i].Key<i_ptRecordSeqList->atRecord[i-i_iDk].Key)//小于则要插入到有序增量子表
		{
			memcpy(&i_ptRecordSeqList->atRecord[0],&i_ptRecordSeqList->atRecord[i],sizeof(T_RecordType));//取出元素暂存在r[0]
			for(j=i-i_iDk;j>0;j-=i_iDk)//寻找插入位置以及各个子序列内进行右移
			{//例:第一次循环,j=i-i_iDk=i_iDk+1-i_iDk=1,所以是从子序列中取出的元素的前一个位置开始
				if(i_ptRecordSeqList->atRecord[0].Key>i_ptRecordSeqList->atRecord[j].Key)
				{//如果r[0]大于子序列中的该元素,则说明找到插入位置，放到这个位置的后面
					break;
				}
				else
				{//进行右移
					memcpy(&i_ptRecordSeqList->atRecord[j+i_iDk],&i_ptRecordSeqList->atRecord[j],sizeof(T_RecordType));
				}
			}//如果比较到r[1]，还没有找到，说明r[0]最小,放到r[1]即可
			memcpy(&i_ptRecordSeqList->atRecord[j+i_iDk],&i_ptRecordSeqList->atRecord[0],sizeof(T_RecordType));//插入位置
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

