/*****************************************************************************
* Copyright (C) 2017-2020 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	RadixSort.c
* Description		: 	RadixSort operation center

一、基本思想
基数排序是一种借助多关键字排序的思想对单逻辑关键字
进行排序的方法。
基数排序是借助分配和收集两种操作对单逻辑关键字进行
排序的一种内部排序方法。
有的逻辑关键字可以看成由若干个关键字复合而成的。
例如，若关键字是数值，且其值都在0<=k<=999范围内，则可
把每一个十进制数字看成一个关键字，即可认为K由3个关键
字(k0,k1,k2)组成，其中K0是百位数,k1是十位数,k2是个位数;又若
关键字K是由5个字母组成的单词,则可看成是5个关键字组成

例:
[yweifeng@localhost test]$ gcc -lm -o RadixSort RadixSort.c
[yweifeng@localhost test]$ ./RadixSort                     
Before Sort(next域还没赋值):
keynum=3 recnum=10
keys=278 otheritems=1 next=0
keys=109 otheritems=2 next=0
keys=063 otheritems=3 next=0
keys=930 otheritems=4 next=0
keys=589 otheritems=5 next=0
keys=184 otheritems=6 next=0
keys=505 otheritems=7 next=0
keys=269 otheritems=8 next=0
keys=008 otheritems=9 next=0
keys=083 otheritems=10 next=0
第1趟收集后:
930 063 083 184 505 278 008 109 589 269 
第2趟收集后:
505 008 109 930 063 269 278 083 184 589 
第3趟收集后:
008 063 083 109 184 269 278 505 589 930 
After RadixSort(静态链表):
keynum=3 recnum=10
keys=278 otheritems=1 next=7
keys=109 otheritems=2 next=6
keys=063 otheritems=3 next=10
keys=930 otheritems=4 next=0
keys=589 otheritems=5 next=4
keys=184 otheritems=6 next=8
keys=505 otheritems=7 next=5
keys=269 otheritems=8 next=1
keys=008 otheritems=9 next=3
keys=083 otheritems=10 next=2
排序后(重排记录):
keynum=3 recnum=10
keys=008 otheritems=9 next=3
keys=063 otheritems=3 next=10
keys=083 otheritems=10 next=2
keys=109 otheritems=2 next=6
keys=184 otheritems=6 next=8
keys=269 otheritems=8 next=1
keys=278 otheritems=1 next=7
keys=505 otheritems=7 next=5
keys=589 otheritems=5 next=4
keys=930 otheritems=4 next=0
[yweifeng@localhost test]$ 


* Created			: 	2017.11.15.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	//代码还有疑问以及优化的地方，有两处line 195 196
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

#define MAX_NUM_OF_KEY 		8 // 关键字项数的最大值
#define RADIX 					10 // 关键字基数，此时是十进制整数的基数
#define MAX_SPACE 				1000

typedef char KeysType; // 定义关键字类型为字符型

typedef struct SeqListCell // 静态链表的结点类型
{
	KeysType atKeys[MAX_NUM_OF_KEY]; // 关键字
	int iOtherItems; // 其它数据项
	int iNext;
}T_SeqListCell;

typedef struct SeqList // 静态链表类型
{
	T_SeqListCell atRecord[MAX_SPACE]; // 静态链表的可利用空间，r[0]为头结点
	int iKeyNum; // 记录的关键字个数
	int iRecNum; // 静态链表的当前长度
}T_SeqList;


#define RECORD_NUMBER				10

typedef int KeyType;

typedef struct RecordType
{
	KeyType Key;
	int OtherInfo;
}T_RecordType,*PT_RecordType;


static void TraverseSeqList(T_SeqList *i_ptSeqList);
static void PrintSeqList(T_SeqList *i_ptSeqList);
static void StaticlLinkListSort(T_SeqList *m_ptSeqList,int *i_aiOrderNum);
static void GetOrderNum(T_SeqList *i_ptSeqList,int *o_aiOrderNum);
static void Collect(T_SeqListCell *i_atRecord,int *i_aiFront,int *i_aiRear);
static void Distribute(T_SeqListCell *i_atRecord,int i_iKeyNum,int *i_aiFront,int *i_aiRear);
static void RadixSort(T_SeqList *i_ptSeqList);
void InitList(T_SeqList *o_ptSeqList,T_RecordType *i_atRecord,int i_iRecordLen);


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
	T_RecordType atRecord[RECORD_NUMBER]={{278,1},{109,2},{63,3},{930,4},{589,5},{184,6},{505,7},{269,8},{8,9},{83,10}};
	T_SeqList tSeqList={0};
	InitList(&tSeqList,atRecord,RECORD_NUMBER);
	
	printf("Before Sort(next域还没赋值):\n");
	TraverseSeqList(&tSeqList);
	
	RadixSort(&tSeqList);
	printf("After RadixSort(静态链表):\n");
	TraverseSeqList(&tSeqList);

	int aiOrderNum[MAX_SPACE]={0};
	GetOrderNum(&tSeqList,aiOrderNum);
	StaticlLinkListSort(&tSeqList,aiOrderNum);
	printf("排序后(重排记录):\n");
	TraverseSeqList(&tSeqList);



	
	return 0;
}


/*****************************************************************************
-Fuction		: InitList
-Description	: // 初始化静态链表L(把数组D中的数据存于L中)
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void InitList(T_SeqList *o_ptSeqList,T_RecordType *i_atRecord,int i_iRecordLen)
{
	char acKey[MAX_NUM_OF_KEY] = {0};
	char acTempKey[MAX_NUM_OF_KEY] = {0};
	int i,j;
	int iMaxKey=i_atRecord[0].Key; // max为关键字的最大值
	for(i=1;i<i_iRecordLen;i++)
	{
		if(iMaxKey<i_atRecord[i].Key)
		iMaxKey=i_atRecord[i].Key;
	}
	//ceil 返回大于或者等于指定表达式的最小整数// 取上整，返回不比x小的最小整数
	o_ptSeqList->iKeyNum = (int)ceil(log10(iMaxKey));
	o_ptSeqList->iRecNum = i_iRecordLen;

	for(i=1;i<=i_iRecordLen;i++)
	{
		o_ptSeqList->atRecord[i].iOtherItems=i_atRecord[i-1].OtherInfo;
		//itoa是非标准C语言和C++语言扩展函数,win包含stdlib.h即可,但是在linux中没有定义,所以注释掉
		//itoa(i_atRecord[i-1].Key,acKey,10); // 将10进制整型转化为字符型，存入c
		snprintf(acKey,sizeof(acKey),"%d",i_atRecord[i-1].Key);// 将10进制整型转化为字符型，存入c
		for(j=strlen(acKey);j<o_ptSeqList->iKeyNum;j++) // 若c的长度<max的位数，在c前补'0'
		{
			strcpy(acTempKey,"0");
			strcat(acTempKey,acKey);
			strcpy(acKey,acTempKey);
		}
		for(j=0;j<o_ptSeqList->iKeyNum;j++)
		{
			o_ptSeqList->atRecord[i].atKeys[j]=acKey[o_ptSeqList->iKeyNum-j-1];//这里是字符型，换成非字符?
		}//next值这里没初始化，可否放这里初始化?
	}
}


/*****************************************************************************
-Fuction		: RadixSort
-Description	: 
// L是采用静态链表表示的顺序表。对L作基数排序，
使得L成为按关键字自小到大的有序静态链表
// L.r[0]为头结点。


二、具体步骤
1. 以静态链表存储待排记录，并令表头指向第一个记录
2. 第一趟分配对个位数进行，改变记录的指针值将链表中
的记录分配到10个链队列中去,即让链队列中的元素指针指向对应的记录
(如:第5个链队列的元素指针指向的是个位数为5的记录),
各个队列中的记录关键字的个位数相等(个位数相同的记录由同一个队列中的记录的next指针链接)

(基数排序中的基指的就是队列的取值范围,比如这里的基就是10，如果是字母则基是26)
3. 第一趟收集是改变所有非空队列的队尾记录的指针域，
令其指向下一个非空队列的队头记录，重新将10个队列中的
记录链成一个链表
4. 第二趟第三趟分别是对十位数和百位数进行的，过程和个
位数相同


-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void RadixSort(T_SeqList *i_ptSeqList)
{
	int i=0;
	int atFront[RADIX]={0};
	int atRear[RADIX]={0};
	for(i=0;i<i_ptSeqList->iRecNum;i++)
	{
		i_ptSeqList->atRecord[i].iNext=i+1;
	}
	i_ptSeqList->atRecord[i_ptSeqList->iRecNum].iNext=0;// 将L改造为静态链表
	for(i=0;i<i_ptSeqList->iKeyNum;i++)
	{// 按最低位优先依次对各关键字进行分配和收集
		Distribute(i_ptSeqList->atRecord,i,atFront,atRear); // 第i趟分配
		Collect(i_ptSeqList->atRecord,atFront,atRear); // 第i趟收集
		printf("第%d趟收集后:\n",i+1);
		PrintSeqList(i_ptSeqList);
		printf("\n");
	}
}

/*****************************************************************************
-Fuction		: Distribute
-Description	: 将链表中的记录分配到10个链队列(使用头尾指针表示)中去

// 静态键表L的r域中记录已按(keys[0]，.，keys[i-1])有序。本算法按
// 第i个关键字keys[i]建立RADIX个子表(队列)，使同一子表(队列)中记录的keys[i]相同。
// i_aiFront[0..RADIX-1]和i_aiRear[0..RADIX-1]分别存放指向各子表中第一个和最后一个记录的指针


-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void Distribute(T_SeqListCell *i_atRecord,int i_iKeyNum,int *i_aiFront,int *i_aiRear) 
{ 
	int i,p;
	for(i=0;i<RADIX;++i)
		i_aiFront[i]=0; // 各子表初始化为空表
	for(p=i_atRecord[0].iNext;p;p=i_atRecord[p].iNext)
	{
		i=i_atRecord[p].atKeys[i_iKeyNum]-'0'; // 将记录中第i个关键字映射到[0..RADIX-1]
		if(!i_aiFront[i])
			i_aiFront[i]=p;//第j个队列的头指针指向p所指节点
		else
			i_atRecord[i_aiRear[i]].iNext=p;//第j个队列的尾指针所指节点的下一节点为p所指节点
		i_aiRear[i]=p; // 将p所指的结点插入第j个子表中//第j个队列的尾指针指向p所指节点
	}
}

/*****************************************************************************
-Fuction		: Collect
-Description	: 收集是改变所有非空队列的队尾记录的指针域，令其指向下一个非空队列的队头记录，
重新将10个队列中的记录链成一个链表


// 本算法按keys[i]自小至大地将i_aiFront[0..RADIX-1]所指各子表(队列)依次链接成一个链表，
// i_aiRear[0..RADIX-1]为各子表(队列)的尾指针。

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void Collect(T_SeqListCell *i_atRecord,int *i_aiFront,int *i_aiRear)
{ 
	int i,t;
	for(i=0;!i_aiFront[i];i++); // 找第一个非空子表，
		i_atRecord[0].iNext=i_aiFront[i];// r[0].next指向第一个非空子表中第一个结点
	t=i_aiRear[i]; // 第一个非空子表中的尾指针//同一个非空子表中的元素不用链接,因为分配的时候已经链接好了
	while(i<RADIX-1)
	{
		for(++i;i<RADIX-1&&!i_aiFront[i];i++); // 找下一个非空子表
		if(i_aiFront[i])
		{ // 链接两个非空子表
			i_atRecord[t].iNext=i_aiFront[i];//尾和头链接起来
			t=i_aiRear[i];//更新尾//同一个非空子表中的元素不用链接,因为分配的时候已经链接好了
		}
	}
	i_atRecord[t].iNext=0; // t指向最后一个非空子表中的最后一个结点
}



/*****************************************************************************
-Fuction		: GetOrderNum
-Description	: //获取有序的数组下标,即链表指针值
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void GetOrderNum(T_SeqList *i_ptSeqList,int *o_aiOrderNum)
{// 求得o_aiOrderNum[1..L.length]，
	int i=1;
	int p;
	p=i_ptSeqList->atRecord[0].iNext;
	while(p!=0)
	{
		o_aiOrderNum[i++]=p;
		p=i_ptSeqList->atRecord[p].iNext;
	}
}



/*****************************************************************************
-Fuction		: StaticlLinkListSort
-Description	: //有序的静态链表排序成顺序表

这种方式会浪费空间，但是结构简单,可阅读性强。

如果使用交换的方式，节省空间，但逻辑复杂,
同时还需再次修改输入有序数组i_aiOrderNum的值，但见p439

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void StaticlLinkListSort(T_SeqList *m_ptSeqList,int *i_aiOrderNum)
{
	T_SeqList tSeqList={0};
	int i=1;
	for(i=1;i<=m_ptSeqList->iRecNum;i++)
	{
		memcpy(&tSeqList.atRecord[i],&m_ptSeqList->atRecord[i_aiOrderNum[i]],sizeof(T_SeqListCell));
	}
	tSeqList.iKeyNum=m_ptSeqList->iKeyNum;
	tSeqList.iRecNum=m_ptSeqList->iRecNum;
	memcpy(m_ptSeqList,&tSeqList,sizeof(T_SeqList));
}

/*****************************************************************************
-Fuction		: PrintSeqList
-Description	: // 按链表输出静态链表
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void PrintSeqList(T_SeqList *i_ptSeqList)
{
	int i=i_ptSeqList->atRecord[0].iNext,j;
	while(i)
	{
		for(j=i_ptSeqList->iKeyNum-1;j>=0;j--)
			printf("%c",i_ptSeqList->atRecord[i].atKeys[j]);
		printf(" ");
		i=i_ptSeqList->atRecord[i].iNext;
	}
}

/*****************************************************************************
-Fuction		: TraverseSeqList
-Description	: // 按数组序号输出静态链表
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void TraverseSeqList(T_SeqList *i_ptSeqList)
{
	int i,j;
	printf("keynum=%d recnum=%d\n",i_ptSeqList->iKeyNum,i_ptSeqList->iRecNum);
	for(i=1;i<=i_ptSeqList->iRecNum;i++)
	{
		printf("keys=");
		for(j=i_ptSeqList->iKeyNum-1;j>=0;j--)
			printf("%c",i_ptSeqList->atRecord[i].atKeys[j]);
		printf(" otheritems=%d next=%d\n",i_ptSeqList->atRecord[i].iOtherItems,i_ptSeqList->atRecord[i].iNext);
	}
}

