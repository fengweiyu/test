/*****************************************************************************
* Copyright (C) 2017-2020 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	QuickSort.c
* Description		: 	QuickSort operation center

一、基本思想
主要使用了递归思想,不断地确定每个元素的位置。
首先,找一个元素(一般是第一个元素)，
然后,确定该元素的位置(在排序好的有序序列中的位置)
接着,以该元素确定好的位置将序列划分为两半,每一半序列
再找一个元素，然后确定位置，接着再划分,不断重复(递归)
直到确定的是一个元素(不能再划分)则 该部分递归结束，
直到确定的是最后一个元素(不能再划分)，则排序结束。

例:
[yweifeng@localhost test]$ gcc -o QuickSort QuickSort.c 
[yweifeng@localhost test]$ ./QuickSort
Before Sort:
(49,1)(38,2)(65,3)(97,4)(76,5)(13,6)(27,7)(49,8)
After QuickSort:
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
static int FindPos(T_RecordSeqList *i_ptRecordSeqList,int i_iLow,int i_iHigh);
static void QuickSort(T_RecordSeqList *i_ptRecordSeqList,int i_iLow,int i_iHigh);

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
	QuickSort(&tSeqList1,1,tSeqList1.iLength);
	printf("After QuickSort:\n");
	TraverseRecordSeqList(&tSeqList1);

	return 0;
}


/*****************************************************************************
-Fuction		: QuickSort
-Description	: // 对顺序表L作快速排序

二、具体步骤
1. 确定某个元素位置,然后以该位置划分两半(已确定的位置
当然不划入),分别进行递归来确定子序列中某个元素位置,
直到所有子序列只有一个元素,即所有的元素位置已确定

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void QuickSort(T_RecordSeqList *i_ptRecordSeqList,int i_iLow,int i_iHigh)
{
	int iPos;
	if(i_iLow<i_iHigh)
	{//退出递归的条件,即当所有的元素位置已确定(只剩一个元素)则退出
		iPos=FindPos(i_ptRecordSeqList,i_iLow,i_iHigh);// 将L.r[low..high]一分为二
		QuickSort(i_ptRecordSeqList,i_iLow,iPos-1);// 对低子表递归排序，iPos是枢轴位置
		QuickSort(i_ptRecordSeqList,iPos+1,i_iHigh);// 对高子表递归排序
	}
}


/*****************************************************************************
-Fuction		: FindPos
-Description	: 
//确定第一个元素的位置(方法不同,导致快排的细节不同)

二、具体步骤
2. 两个位置指针l/h分别指向序列的首尾,取第一个元素为比较元素

3. 当h指向的元素比比较元素的值大,h不断向左移动;否则,
h指向的赋值给l指向的,然后h不动,执行步骤4
4. 当l指向的元素比比较元素的值小,l不断向右移动;否则,
l指向的赋值给h指向的,然后l不动,执行步骤3

5. 当l=h时，就确定了比较元素的位置

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int FindPos(T_RecordSeqList *i_ptRecordSeqList,int i_iLow,int i_iHigh)
{
#if 1//如果不是从第一个元素开始或者一开始不是h向左移动,则排序出错
		T_RecordType tVal;
		memcpy(&tVal,&i_ptRecordSeqList->atRecord[i_iLow],sizeof(T_RecordType));//第一个记录用作比较元素
		while(i_iLow<i_iHigh)
		{
			while(i_iLow<i_iHigh&&i_ptRecordSeqList->atRecord[i_iHigh].Key>=tVal.Key)
			{//i_iLow<i_iHigh 防止越界
				i_iHigh--;//不断左移
			}//依赖于从第一个元素开始，并且一开始是h向右移动,才可以不用交换，直接赋值
			memcpy(&i_ptRecordSeqList->atRecord[i_iLow],&i_ptRecordSeqList->atRecord[i_iHigh],sizeof(T_RecordType));//退出循环,赋值,移动另外的指针
			while(i_iLow<i_iHigh&&i_ptRecordSeqList->atRecord[i_iLow].Key<=tVal.Key)
			{//i_iLow<i_iHigh 防止越界
				i_iLow++;//不断右移
			}//由于从第一个元素开始，并且一开始是h向右移动,才可以不用交换，直接赋值
			memcpy(&i_ptRecordSeqList->atRecord[i_iHigh],&i_ptRecordSeqList->atRecord[i_iLow],sizeof(T_RecordType));//退出循环,赋值,移动另外的指针
			//如果不是从第一个元素开始或者一开始不是h向右移动,则排序出错
		}
		memcpy(&i_ptRecordSeqList->atRecord[i_iLow],&tVal,sizeof(T_RecordType));//i_iLow=i_iHigh确定位置
		return i_iLow;//i_iLow 或者i_iHigh都行

#else//如果不是从第一个元素开始或者一开始不是h向左移动,则排序出错
		int iVal=i_ptRecordSeqList->atRecord[i_iLow].Key;//第一个记录用作比较元素
		T_RecordType tVal;
		while(i_iLow<i_iHigh)
		{//如果不是从第一个元素开始或者一开始不是h向右移动,则排序出错,所以这种方式不健壮
			while(i_iLow<i_iHigh&&i_ptRecordSeqList->atRecord[i_iHigh].Key>=iVal)
			{//i_iLow<i_iHigh 防止越界
				i_iHigh--;//不断左移
			}//退出循环,// 将比枢轴记录小的记录交换到低端,移动另外的指针
			memcpy(&tVal,&i_ptRecordSeqList->atRecord[i_iLow],sizeof(T_RecordType));
			memcpy(&i_ptRecordSeqList->atRecord[i_iLow],&i_ptRecordSeqList->atRecord[i_iHigh],sizeof(T_RecordType));
			memcpy(&i_ptRecordSeqList->atRecord[i_iHigh],&tVal,sizeof(T_RecordType));
			
			while(i_iLow<i_iHigh&&i_ptRecordSeqList->atRecord[i_iLow].Key<=iVal)
			{//i_iLow<i_iHigh 防止越界
				i_iLow++;//不断右移
			}//退出循环,// 将比枢轴记录大的记录交换到高端,移动另外的指针
			memcpy(&tVal,&i_ptRecordSeqList->atRecord[i_iHigh],sizeof(T_RecordType));
			memcpy(&i_ptRecordSeqList->atRecord[i_iHigh],&i_ptRecordSeqList->atRecord[i_iLow],sizeof(T_RecordType));
			memcpy(&i_ptRecordSeqList->atRecord[i_iLow],&tVal,sizeof(T_RecordType));
		}//i_iLow=i_iHigh确定位置
		//比较元素已经交换到确定位置,所以这里不需要再次赋值
		return i_iLow;//返回确定的位置 ，i_iLow 或者i_iHigh都行
#endif


#if 0//如果不是从第一个元素开始或者一开始不是h向左移动,则排序出错
	T_RecordType tVal;
	T_RecordType tTempVal;
	memcpy(&tVal,&i_ptRecordSeqList->atRecord[i_iLow],sizeof(T_RecordType));//第一个记录用作比较元素
	while(i_iLow<i_iHigh)
	{//如果不是从第一个元素开始或者一开始不是h向右移动,则排序出错
		while(i_iLow<i_iHigh&&i_ptRecordSeqList->atRecord[i_iHigh].Key>=tVal.Key)
		{//i_iLow<i_iHigh 防止越界
			i_iHigh--;//不断左移
		}//退出循环,// 将比枢轴记录小的记录交换到低端,移动另外的指针
		memcpy(&tTempVal,&i_ptRecordSeqList->atRecord[i_iLow],sizeof(T_RecordType));
		memcpy(&i_ptRecordSeqList->atRecord[i_iLow],&i_ptRecordSeqList->atRecord[i_iHigh],sizeof(T_RecordType));
		memcpy(&i_ptRecordSeqList->atRecord[i_iHigh],&tTempVal,sizeof(T_RecordType));
		
		while(i_iLow<i_iHigh&&i_ptRecordSeqList->atRecord[i_iLow].Key<=tVal.Key)
		{//i_iLow<i_iHigh 防止越界
			i_iLow++;//不断右移
		}//退出循环,// 将比枢轴记录大的记录交换到高端,移动另外的指针
		memcpy(&tTempVal,&i_ptRecordSeqList->atRecord[i_iHigh],sizeof(T_RecordType));
		memcpy(&i_ptRecordSeqList->atRecord[i_iHigh],&i_ptRecordSeqList->atRecord[i_iLow],sizeof(T_RecordType));
		memcpy(&i_ptRecordSeqList->atRecord[i_iLow],&tTempVal,sizeof(T_RecordType));
	}//i_iLow=i_iHigh确定位置
	//比较元素已经交换到确定位置,所以这里不需要再次赋值
	
	//下面赋值没有效果,仍然依赖一开始的移动顺序(必须从h开始)
	//memcpy(&i_ptRecordSeqList->atRecord[i_iLow],&tVal,sizeof(T_RecordType));//i_iLow=i_iHigh确定位置

	return i_iLow;//返回确定的位置 ，i_iLow 或者i_iHigh都行
#endif

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

