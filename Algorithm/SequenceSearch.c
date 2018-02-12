/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SequenceSearch.c
* Description		: 	SequenceSearch operation center
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

#define ELEMENT_NUM	3

#define Key dwNumber	// 定义关键字为准考证号
typedef unsigned int KeyType;// 设关键字域为整型

typedef struct SeqTableElement
{
	unsigned int dwNumber;
	char strName[9]; // 姓名(4个汉字加1个串结束标志)
}T_SeqTableElement,*PT_SeqTableElement;


typedef struct SeqTable
{
	T_SeqTableElement *ptElement;
	int iLength;
}T_SeqTable,*PT_SeqTable;

static void CreateSeqTable(T_SeqTableElement i_atElement[],int i_iNum,T_SeqTable *o_ptSeqTable);
static int SequenceSearch(T_SeqTable *i_ptSeqTable,KeyType i_Key);
static void TraverseSeqTable(T_SeqTable *i_ptSeqTable);
static void DestroySeqTable(T_SeqTable *i_ptSeqTable);

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
	T_SeqTableElement atElement[ELEMENT_NUM]={{123456,"LiMing"},{123467,"XiaoMing"},{123477,"LiHua"}};
	T_SeqTable tSeqTable={0};
	CreateSeqTable(atElement,ELEMENT_NUM,&tSeqTable);
	TraverseSeqTable(&tSeqTable);
	printf("请输入待查找人的考号: ");
	scanf("%d",&KeyElement);
	i=SequenceSearch(&tSeqTable,KeyElement); // 顺序查找
	if(i)
	printf("%8d%8s\r\n",tSeqTable.ptElement[i].dwNumber,tSeqTable.ptElement[i].strName);
	else
	printf("没找到\n");
	DestroySeqTable(&tSeqTable);

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
static void CreateSeqTable(T_SeqTableElement i_atElement[],int i_iNum,T_SeqTable *o_ptSeqTable)
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
		{
			memcpy(&o_ptSeqTable->ptElement[i],&i_atElement[i-1],sizeof(T_SeqTableElement));
		}
		o_ptSeqTable->iLength=i_iNum;
	}
}

/*****************************************************************************
-Fuction		: SequenceSearch
-Description	: 
// 在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则返回
// 该元素在表中的位置；否则返回0。
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int SequenceSearch(T_SeqTable *i_ptSeqTable,KeyType i_Key)
{
	int i=0;
	i_ptSeqTable->ptElement[0].Key=i_Key;// 哨兵
	for(i=i_ptSeqTable->iLength;i_Key!=i_ptSeqTable->ptElement[i].Key;i--);// 从后往前找
	return i;// 找不到时，i为0
}

/*****************************************************************************
-Fuction		: TraverseSeqTable
-Description	: TraverseSeqTable
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void TraverseSeqTable(T_SeqTable *i_ptSeqTable)
{
	int i=0;
	for(i=1;i<=i_ptSeqTable->iLength;i++)
	{
		printf("%8d%8s\r\n",i_ptSeqTable->ptElement[i].dwNumber,i_ptSeqTable->ptElement[i].strName);
	}
}

/*****************************************************************************
-Fuction		: DestroySeqTable
-Description	: DestroySeqTable
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void DestroySeqTable(T_SeqTable *i_ptSeqTable)
{
	free(i_ptSeqTable->ptElement);
	i_ptSeqTable->ptElement=NULL;
	i_ptSeqTable->iLength=0;
}

