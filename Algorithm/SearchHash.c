/*****************************************************************************
* Copyright (C) 2017-2020 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SearchHash.c
* Description		: 	SearchHash (查找哈希表)operation center

一、基本思想
哈希表: 根据设定的哈希函数和处理冲突的方法将一组关键
字分别计算出相应的值,并以该值作为记录在表中的存储位置，
这种表便称为哈希表，这一过程称为哈希造表或散列，
计算所得存储位置称为哈希地址或散列地址。

若对于关键字集合中的任一个关键字，经哈希函数映像到地址
集合中任何一个地址的概率是相等的，则称此类哈希函数为
均匀的哈希函数。换句话说，就是使关键字经过哈希函数得到
一个"随机的地址",即唯一的地址，也就是说冲突最小。

设计哈希函数和处理冲突的方法应当以尽可能减少冲突为原则



例:
[yweifeng@localhost test]$ gcc -o SearchHash SearchHash.c
[yweifeng@localhost test]$ ./SearchHash
表中已有关键字为60的记录，无法再插入记录(60,9)
按哈希地址的顺序遍历哈希表:
哈希地址0～10
address=1 (1,5)
address=2 (2,6)
address=3 (3,7)
address=4 (4,8)
address=5 (60,2)
address=6 (17,1)
address=7 (29,3)
address=8 (38,4)
请输入待查找记录的关键字: 13
没找到
重建哈希表
按哈希地址的顺序遍历重建后的哈希表:
哈希地址0～18
address=0 (38,4)
address=1 (1,5)
address=2 (2,6)
address=3 (3,7)
address=4 (4,8)
address=6 (60,2)
address=10 (29,3)
address=13 (13,10)
address=17 (17,1)
请输入待查找记录的关键字: 13
address=13 (13,10)
[yweifeng@localhost test]$ 




* Created			: 	2017.11.15.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>


#define SUCCESS			0
#define UNSUCCESS		-1
#define DUPLICATE		-2

#define NULL_KEY 0 // 0为无记录标志


#define RECORD_NUMBER				10

typedef  int KeyType;// 设关键字域为整型

typedef struct ElementType
{
	KeyType Key;	// 仅有关键字域
	int iOrd;
}T_ElementType;

typedef struct HashTable
{
	T_ElementType *ptElement; // 数据元素存储基址，动态分配数组
	int iCount; // 当前数据元素个数
	int iSizeIndex; // hashsize[sizeindex]为当前容量
}T_HashTable;

static int g_aiHashSize[]={11,19,29,37}; // 哈希表容量递增表，一个合适的素数序列,用于当哈希表容量不够时进行扩展
static int g_iHashLength=0; // 哈希表表长，全局变量,后续优化掉



static void InitHashTable(T_HashTable *i_ptHashTable);
static int InsertHash(T_HashTable *m_ptHashTable,T_ElementType *i_ptElement);
static int SearchHash(T_HashTable *i_ptHashTable,KeyType *i_pKey,int *o_piSearchedIndex,int *o_piConflictCnt);
static int Hash(KeyType *i_pKey);
static void Collision(int *o_piSearchedIndex,int i_iConflictCnt);
static void RecreateHashTable(T_HashTable *m_ptHashTable);
static void TraverseHash(T_HashTable *i_ptHashTable);
static void DestroyHashTable(T_HashTable *i_ptHashTable);

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
	T_ElementType atRecord[RECORD_NUMBER]={{17,1},{60,2},{29,3},{38,4},{1,5},{2,6},{3,7},{4,8},{60,9},{13,10}};
	T_HashTable tHashTable ={0};
	int iRet;
	KeyType Key;
	int iConflictCnt;
	int iSearchedIndex;
	int i;
	
	/*初始化*/
	InitHashTable(&tHashTable);
	for(i=0;i<RECORD_NUMBER-1;i++)
	{ // 插入前N-1个记录
		iRet=InsertHash(&tHashTable,&atRecord[i]);
		if(iRet==DUPLICATE)
		printf("表中已有关键字为%d的记录，无法再插入记录(%d,%d)\n",atRecord[i].Key,atRecord[i].Key,atRecord[i].iOrd);
	}
	printf("按哈希地址的顺序遍历哈希表:\n");
	TraverseHash(&tHashTable);

	/*查找*/
	printf("请输入待查找记录的关键字: ");
	scanf("%d",&Key);
	iRet=SearchHash(&tHashTable,&Key,&iSearchedIndex,&iConflictCnt);
	if(iRet==SUCCESS)
		printf("address=%d (%d,%d)\n",iSearchedIndex,tHashTable.ptElement[iSearchedIndex].Key,tHashTable.ptElement[iSearchedIndex].iOrd);
	else
		printf("没找到\n");
	
	/*插入哈希表中不存在的记录*/
	iRet=InsertHash(&tHashTable,&atRecord[i]); // 插入第N-1个记录// 重建哈希表
	if(iRet==UNSUCCESS) // 失败表示重建了哈希表
		iRet=InsertHash(&tHashTable,&atRecord[i]); // 重建哈希表后重新插入
	printf("按哈希地址的顺序遍历重建后的哈希表:\n");
	TraverseHash(&tHashTable);

	/*再次查找*/
	printf("请输入待查找记录的关键字: ");
	scanf("%d",&Key);
	iRet=SearchHash(&tHashTable,&Key,&iSearchedIndex,&iConflictCnt);
	if(iRet==SUCCESS)
		printf("address=%d (%d,%d)\n",iSearchedIndex,tHashTable.ptElement[iSearchedIndex].Key,tHashTable.ptElement[iSearchedIndex].iOrd);
	else
		printf("没找到\n");
	
	DestroyHashTable(&tHashTable);

	return 0;
}


/*****************************************************************************
-Fuction		: SearchHash
-Description	: 
// 在开放定址哈希表H中查找关键码为i_pKey的元素，若查找成功，
// 以o_piSearchedIndex指示待查数据元素在表中位置，并返回SUCCESS；
否则，以o_piSearchedIndex指示插入位置，并返回UNSUCCESS
// o_piConflictCnt用以计冲突次数，其初值置零，供建表插入时参考


二、具体步骤
1. 在哈希表上进行查找的过程合哈希造表的过程基本一致。
2. 给定K值，根据造表时设定的哈希函数求得哈希地址，若
表中此位置上没有记录，则查找不成功；否则比较关键字，
若和给定值相等，则查找成功；
3. 否则根据造表时给定的处理冲突的方法找"下一地址"，直
到哈希表中某个位置为"空"或者表中所填记录的关键字等于
给定值时为止。


-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int SearchHash(T_HashTable *i_ptHashTable,KeyType *i_pKey,int *o_piSearchedIndex,int *o_piConflictCnt)
{
	int iRet=UNSUCCESS;
	int iSearchedIndex;
	int iConflictCnt=0;
	iSearchedIndex=Hash(i_pKey);// 求得哈希地址
	while(i_ptHashTable->ptElement[iSearchedIndex].Key!=NULL_KEY&&i_ptHashTable->ptElement[iSearchedIndex].Key!=*i_pKey)
	{// 该位置中填有记录．并且关键字不相等
		iConflictCnt++;
		if(iConflictCnt<g_iHashLength)
		{
			Collision(&iSearchedIndex,iConflictCnt); // 求得下一探查地址p
		}
		else
		{
			break;
		}
	}
	if(i_ptHashTable->ptElement[iSearchedIndex].Key==*i_pKey)
	{
		iRet=SUCCESS;// 查找成功，p返回待查数据元素位置
	}
	else
	{
		iRet=UNSUCCESS;// 查找不成功(H.elem[p].key==NULL_KEY)，p返回的是插入位置
	}
	*o_piSearchedIndex=iSearchedIndex;
	*o_piConflictCnt =iConflictCnt;
	return iRet;
}

/*****************************************************************************
-Fuction		: Hash
-Description	: // 一个简单的哈希函数(g_iHashLength为表长，全局变量)
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int Hash(KeyType *i_pKey)
{
	return *i_pKey%g_iHashLength;
}

/*****************************************************************************
-Fuction		: Collision
-Description	: // 开放定址法处理冲突// 线性探测再散列
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void Collision(int *o_piSearchedIndex,int i_iConflictCnt)
{
	*o_piSearchedIndex=(*o_piSearchedIndex+i_iConflictCnt)%g_iHashLength;
}

/*****************************************************************************
-Fuction		: InitHashTable
-Description	:  // 操作结果：构造一个空的哈希表
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void InitHashTable(T_HashTable *i_ptHashTable)
{
	int i;
	i_ptHashTable->iCount=0;// 当前元素个数为0
	i_ptHashTable->iSizeIndex=0;// 初始存储容量为hashsize[0]

	g_iHashLength=g_aiHashSize[0];
	i_ptHashTable->ptElement=(T_ElementType *)malloc(g_iHashLength*sizeof(T_ElementType));
	if(i_ptHashTable->ptElement!=NULL)
	{
		for(i=0;i<g_iHashLength;i++)
		{
			i_ptHashTable->ptElement[i].Key=NULL_KEY; // 未填记录的标志
		}
	}
	else
	{ // 存储分配失败
		exit(OVERFLOW);
	}
}

/*****************************************************************************
-Fuction		: DestroyHashTable
-Description	: // 初始条件：哈希表H存在。操作结果：销毁哈希表H
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void DestroyHashTable(T_HashTable *i_ptHashTable)
{
	i_ptHashTable->iCount=0;
	i_ptHashTable->iSizeIndex=0;
	free(i_ptHashTable->ptElement);
	i_ptHashTable->ptElement=NULL;
}

/*****************************************************************************
-Fuction		: InsertHash
-Description	:
// 查找不成功时插入数据元素i_ptElement到开放定址哈希表H中，
并返回OK；
// 若冲突次数过大，则重建哈希表，

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int InsertHash(T_HashTable *m_ptHashTable,T_ElementType *i_ptElement)
{
	int iRet=UNSUCCESS;
	int iSearchedIndex=0;
	int iConflictCnt=0;
	if(SUCCESS==SearchHash(m_ptHashTable,&i_ptElement->Key,&iSearchedIndex,&iConflictCnt)) // 表中已有与i_ptElement有相同关键字的元素
	{
		iRet=DUPLICATE;
	}
	else if(iConflictCnt<g_aiHashSize[m_ptHashTable->iSizeIndex]/2) // 冲突次数c未达到上限，(c的阀值可调),现在的阀值时当前容量的一半
	{ // 插入e
		memcpy(&m_ptHashTable->ptElement[iSearchedIndex],i_ptElement,sizeof(T_ElementType));
		m_ptHashTable->iCount++;
		iRet=SUCCESS;
	}
	else
	{
		RecreateHashTable(m_ptHashTable); // 重建哈希表
		iRet=UNSUCCESS;
	}
	return iRet;
}

/*****************************************************************************
-Fuction		: RecreateHashTable
-Description	:  // 重建哈希表
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void RecreateHashTable(T_HashTable *m_ptHashTable)
{
	int i;
	int iCount=m_ptHashTable->iCount;
	
	T_ElementType *ptTempElement;
	T_ElementType *ptElement;
	ptElement=(T_ElementType *)malloc(iCount * sizeof(T_ElementType));
	ptTempElement=ptElement;	
	printf("重建哈希表\n");
	for(i=0;i<g_iHashLength;i++) // 保存原有的数据到i_ptElement中
	{
		if(m_ptHashTable->ptElement[i].Key!=NULL_KEY) // 该单元有数据
		{
			memcpy(ptTempElement,&m_ptHashTable->ptElement[i],sizeof(T_ElementType));
			ptTempElement++;
		}
	}
	
	m_ptHashTable->iCount=0;
	m_ptHashTable->iSizeIndex++;// 增大存储容量

	g_iHashLength=g_aiHashSize[m_ptHashTable->iSizeIndex];
	//realloc是从堆上分配内存的.当扩大一块内存空间时，realloc()试图直接从堆上现存的数据后面的那些字节中获得附加的字节
	ptTempElement=(T_ElementType *)realloc(m_ptHashTable->ptElement,g_iHashLength*sizeof(T_ElementType));//新分配的内存大小为g_iHashLength，不包括ptElement指向的内存大小
	if(NULL!=ptTempElement)
	{
		m_ptHashTable->ptElement =ptTempElement;//realloc并不保证调整后的内存空间和原来的内存空间保持同一内存地址
		for(i=0;i<g_iHashLength;i++)
			m_ptHashTable->ptElement[i].Key=NULL_KEY; // 未填记录的标志(初始化)
		for(ptTempElement=ptElement;ptTempElement<ptElement+iCount;ptTempElement++) // 将原有的数据按照新的表长插入到重建的哈希表中
			InsertHash(m_ptHashTable,ptTempElement);
	}
	else
	{
		exit(OVERFLOW); // 存储分配失败
	}
}

/*****************************************************************************
-Fuction		: TraverseHash
-Description	:  // 按哈希地址的顺序遍历哈希表
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void TraverseHash(T_HashTable *i_ptHashTable)
{ 
	int i;
	printf("哈希地址0～%d\n",g_iHashLength-1);
	for(i=0;i<g_iHashLength;i++)
		if(i_ptHashTable->ptElement[i].Key!=NULL_KEY) // 有数据
			printf("address=%d (%d,%d)\n",i,i_ptHashTable->ptElement[i].Key,i_ptHashTable->ptElement[i].iOrd);
}

