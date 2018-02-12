/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BiSearch.c
* Description		: 	BiSearch operation center
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

#define ELEMENT_NUM	11

typedef  int KeyType;// 设关键字域为整型

typedef struct SeqTableElement
{
	KeyType key;	// 仅有关键字域
}T_SeqTableElement,*PT_SeqTableElement;

typedef struct SeqTable
{
	T_SeqTableElement *ptElement;
	int iLength;
}T_SeqTable,*PT_SeqTable;

static void CreateOrderSeqTable(T_SeqTableElement i_atElement[],int i_iNum,T_SeqTable *o_ptSeqTable);
static void TraverseOrderSeqTable(T_SeqTable *i_ptSeqTable);
static int BiSearch(T_SeqTable *i_ptSeqTable,KeyType i_Key);
static void DestroyOrderSeqTable(T_SeqTable *i_ptSeqTable);
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
	T_SeqTableElement atElement[ELEMENT_NUM]={5,13,19,21,37,56,64,75,80,88,92};
	T_SeqTable tSeqTable={0};
	CreateOrderSeqTable(atElement,ELEMENT_NUM,&tSeqTable);
	TraverseOrderSeqTable(&tSeqTable);
	printf("请输入待查找值的关键字: ");
	scanf("%d",&KeyElement);
	i=BiSearch(&tSeqTable,KeyElement); // 折半查找有序表
	if(i)
	printf("%d 是第%d个记录的关键字\n",tSeqTable.ptElement[i].key,i);
	else
	printf("没找到\n");
	DestroyOrderSeqTable(&tSeqTable);

	return 0;
}



/*****************************************************************************
-Fuction		: CreateSeqTable
-Description	: 
// 操作结果：由含n个数据元素的数组r构造静态顺序查找表ST

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void CreateOrderSeqTable(T_SeqTableElement i_atElement[],int i_iNum,T_SeqTable *o_ptSeqTable)
{
	int i;
	//与malloc的区别,calloc在动态分配完内存后，自动初始化该内存空间为零，而malloc不初始化，里边数据是随机的垃圾数据。
	o_ptSeqTable->ptElement=(T_SeqTableElement *)calloc(i_iNum+1,sizeof(T_SeqTableElement));// 动态生成n+1个数据元素空间(0号单元不用)
	if(NULL==o_ptSeqTable->ptElement)
	{
		printf("CreareSeqTable err,calloc fail\r\n");
	}
	else
	{
		for(i=1;i<=i_iNum;i++)
		{//数组第1个位置即序号0的位置不存放,因为位置从1开始,同时方便查找返回值处理
			memcpy(&o_ptSeqTable->ptElement[i],&i_atElement[i-1],sizeof(T_SeqTableElement));
		}
		//memcpy(o_ptSeqTable->ptElement,i_atElement,sizeof(i_atElement));//传入的是地址这样拷贝不行
		o_ptSeqTable->iLength=i_iNum;
	}
}

/*****************************************************************************
-Fuction		: BiSearch
-Description	: 
// 在有序表ST中折半查找其关键字等于key的数据元素。若找到，则返回
// 该元素在表中的位置；否则返回0。
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int BiSearch(T_SeqTable *i_ptOrderSeqTable,KeyType i_Key)
{
	int iPos=0;
	int iLow,iHigh,iMid;
	iLow=1;
	iHigh=i_ptOrderSeqTable->iLength;
	while(iLow<=iHigh)
	{
		iMid=(iLow+iHigh)/2;
		if(i_Key==i_ptOrderSeqTable->ptElement[iMid].key)
		{
			iPos=iMid;
			break;
		}
		else if(i_Key<i_ptOrderSeqTable->ptElement[iMid].key)
		{
			iHigh=iMid-1;
		}
		else
		{
			iLow=iMid+1;
		}
	}
	return iPos;
}

/*****************************************************************************
-Fuction		: TraverseOrderSeqTable
-Description	: TraverseOrderSeqTable
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void TraverseOrderSeqTable(T_SeqTable *i_ptSeqTable)
{
	int i=0;
	for(i=1;i<=i_ptSeqTable->iLength;i++)
	{
		printf("%d ",i_ptSeqTable->ptElement[i].key);
	}
	printf("\r\n");
}

/*****************************************************************************
-Fuction		: DestroyOrderSeqTable
-Description	: DestroyOrderSeqTable
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void DestroyOrderSeqTable(T_SeqTable *i_ptSeqTable)
{
	free(i_ptSeqTable->ptElement);
	i_ptSeqTable->ptElement=NULL;
	i_ptSeqTable->iLength=0;
}

