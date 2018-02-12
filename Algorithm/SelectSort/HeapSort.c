/*****************************************************************************
* Copyright (C) 2017-2020 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	HeapSort.c
* Description		: 	HeapSort operation center

一、基本思想
堆的含义表明，完全二叉树中所有非终端节点的值均不大于
(或不小于)其左右孩子节点的值。由此，若序列是堆，则堆
顶元素(或完全二叉树的根)必为序列中n个元素的最小值(最大值)

1. 如何由一个无序序列建成一个堆?
2中自堆顶到叶子的调整过程称为"筛选"，
从一个无序序列建堆的过程就是一个反复"筛选"的过程，若将此
序列看成是一个完全二叉树(层序列组成)，则最后一个非终端
节点是第n/2个元素，由此"筛选"只需从第n/2个元素开始(到根节点
结束)

2. 如何在输出堆顶元素之后,调整剩余元素成为一个新的堆?
假设输出堆顶元素之后，以堆中最后一个元素替代之。
此时根节点的左右子树均为堆，则仅需自上而下进行调整即可。
首先以堆顶元素和其左右子树根节点的值比较，若右子树根节点
小于左子树根节点的值且小于根节点的值(取最小的)，则将最小的
那个节点与根节点交换,交换后若破坏了右子树的堆则需进行上述
相同的调整


例:
[yweifeng@localhost test]$ gcc -o HeapSort HeapSort.c 
[yweifeng@localhost test]$ ./HeapSort
Before Sort:
(49,1)(38,2)(65,3)(97,4)(76,5)(13,6)(27,7)(49,8)
After HeapSort:
(13,6)(27,7)(38,2)(49,1)(49,8)(65,3)(76,5)(97,4)
[yweifeng@localhost test]$ 

* Created			: 	2017.11.15.
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
static void HeapAdjust(T_RecordSeqList *i_ptRecordSeqList,int i_iLow,int i_iHigh);
static void HeapSort(T_RecordSeqList *i_ptRecordSeqList);


/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_RecordType atRecord[RECORD_NUMBER]={{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}};
	T_RecordSeqList tSeqList1;
	memcpy(&tSeqList1.atRecord[1],atRecord,sizeof(atRecord));
	tSeqList1.iLength=RECORD_NUMBER;

	
	printf("Before Sort:\n");
	TraverseRecordSeqList(&tSeqList1);
	HeapSort(&tSeqList1);
	printf("After HeapSort:\n");
	TraverseRecordSeqList(&tSeqList1);

	return 0;
}



/*****************************************************************************
-Fuction		: HeapSort
-Description	: // 对顺序表L作堆排序

二、具体步骤
1. 将整个无序序列建立成大顶堆
2. 将大顶堆根元素和序列最后的交换，同时堆序列长度减一
并调整剩下元素(减去交换到最后的)为堆,直到剩下元素为1个

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void HeapSort(T_RecordSeqList *i_ptRecordSeqList)
{
	T_RecordType tRecord;
	int i;
	for(i=i_ptRecordSeqList->iLength/2;i>0;i--)// 把H.r[1..H.length]建成大顶堆
	{
		HeapAdjust(i_ptRecordSeqList,i,i_ptRecordSeqList->iLength);//从n/2元素开始调整,直到根节点
	}
	for(i=i_ptRecordSeqList->iLength;i>1;i--)
	{// 将堆顶记录和当前未经排序子序列H.r[1..i]中最后一个记录相互交换
		memcpy(&tRecord,&i_ptRecordSeqList->atRecord[i],sizeof(T_RecordType));
		memcpy(&i_ptRecordSeqList->atRecord[i],&i_ptRecordSeqList->atRecord[1],sizeof(T_RecordType));//取出最大的(堆顶)放在序列最后
		memcpy(&i_ptRecordSeqList->atRecord[1],&tRecord,sizeof(T_RecordType));//(原先最后的放到堆顶去)
		//同时堆序列长度减一//重复直到堆序列长度为1
		HeapAdjust(i_ptRecordSeqList,1,i-1); // 将H.r[1..i-1]重新调整为大顶堆
	}
}

/*****************************************************************************
-Fuction		: HeapAdjust
-Description	: 
// 已知H.r[s..m]中记录的关键字除H.r[s].key之外均满足堆的定义，本函数
// 调整H.r[s]的关键字，使H.r[s..m]成为一个大顶堆(对其中记录的关键字而言)

二、具体步骤

3. 调整
首先比较的根节点(待调整的节点))的两个孩子，取较大的
若根节点(待调整的节点)大于较大的孩子，则根节点(待调整的节点)
应当放在该孩子的父位置上。
否则，移动该孩子到其父位置上(向上移动)，
根节点(待调整的节点)继续向下比较

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void HeapAdjust(T_RecordSeqList *i_ptRecordSeqList,int i_iLow,int i_iHigh)
{
	T_RecordType tRecord;
	int i;
	memcpy(&tRecord,&i_ptRecordSeqList->atRecord[i_iLow],sizeof(T_RecordType));
	for(i=2*i_iLow;i<=i_iHigh;i*=2)// 沿key较大的孩子结点向下筛选
	{
		if(i<i_iHigh&&i_ptRecordSeqList->atRecord[i].Key<i_ptRecordSeqList->atRecord[i+1].Key)
		{//取较大的孩子
			i++;
		}
		if(tRecord.Key>i_ptRecordSeqList->atRecord[i].Key)
		{
			break;// rc应插入在位置i_iLow上,即大孩子的父节点上
		}
		memcpy(&i_ptRecordSeqList->atRecord[i_iLow],&i_ptRecordSeqList->atRecord[i],sizeof(T_RecordType));
		i_iLow=i;
		
	}
	memcpy(&i_ptRecordSeqList->atRecord[i_iLow],&tRecord,sizeof(T_RecordType));
}


/*****************************************************************************
-Fuction		: TraverseRecordSeqList
-Description	: TraverseRecordSeqList
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
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

