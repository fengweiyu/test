/*****************************************************************************
* Copyright (C) 2017-2020 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	RadixSort.c
* Description		: 	RadixSort operation center

һ������˼��
����������һ�ֽ�����ؼ��������˼��Ե��߼��ؼ���
��������ķ�����
���������ǽ���������ռ����ֲ����Ե��߼��ؼ��ֽ���
�����һ���ڲ����򷽷���
�е��߼��ؼ��ֿ��Կ��������ɸ��ؼ��ָ��϶��ɵġ�
���磬���ؼ�������ֵ������ֵ����0<=k<=999��Χ�ڣ����
��ÿһ��ʮ�������ֿ���һ���ؼ��֣�������ΪK��3���ؼ�
��(k0,k1,k2)��ɣ�����K0�ǰ�λ��,k1��ʮλ��,k2�Ǹ�λ��;����
�ؼ���K����5����ĸ��ɵĵ���,��ɿ�����5���ؼ������

��:
[yweifeng@localhost test]$ gcc -lm -o RadixSort RadixSort.c
[yweifeng@localhost test]$ ./RadixSort                     
Before Sort(next��û��ֵ):
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
��1���ռ���:
930 063 083 184 505 278 008 109 589 269 
��2���ռ���:
505 008 109 930 063 269 278 083 184 589 
��3���ռ���:
008 063 083 109 184 269 278 505 589 930 
After RadixSort(��̬����):
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
�����(���ż�¼):
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
* History			: 	//���뻹�������Լ��Ż��ĵط���������line 195 196
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

#define MAX_NUM_OF_KEY 		8 // �ؼ������������ֵ
#define RADIX 					10 // �ؼ��ֻ�������ʱ��ʮ���������Ļ���
#define MAX_SPACE 				1000

typedef char KeysType; // ����ؼ�������Ϊ�ַ���

typedef struct SeqListCell // ��̬����Ľ������
{
	KeysType atKeys[MAX_NUM_OF_KEY]; // �ؼ���
	int iOtherItems; // ����������
	int iNext;
}T_SeqListCell;

typedef struct SeqList // ��̬��������
{
	T_SeqListCell atRecord[MAX_SPACE]; // ��̬����Ŀ����ÿռ䣬r[0]Ϊͷ���
	int iKeyNum; // ��¼�Ĺؼ��ָ���
	int iRecNum; // ��̬����ĵ�ǰ����
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
	
	printf("Before Sort(next��û��ֵ):\n");
	TraverseSeqList(&tSeqList);
	
	RadixSort(&tSeqList);
	printf("After RadixSort(��̬����):\n");
	TraverseSeqList(&tSeqList);

	int aiOrderNum[MAX_SPACE]={0};
	GetOrderNum(&tSeqList,aiOrderNum);
	StaticlLinkListSort(&tSeqList,aiOrderNum);
	printf("�����(���ż�¼):\n");
	TraverseSeqList(&tSeqList);



	
	return 0;
}


/*****************************************************************************
-Fuction		: InitList
-Description	: // ��ʼ����̬����L(������D�е����ݴ���L��)
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
	int iMaxKey=i_atRecord[0].Key; // maxΪ�ؼ��ֵ����ֵ
	for(i=1;i<i_iRecordLen;i++)
	{
		if(iMaxKey<i_atRecord[i].Key)
		iMaxKey=i_atRecord[i].Key;
	}
	//ceil ���ش��ڻ��ߵ���ָ�����ʽ����С����// ȡ���������ز���xС����С����
	o_ptSeqList->iKeyNum = (int)ceil(log10(iMaxKey));
	o_ptSeqList->iRecNum = i_iRecordLen;

	for(i=1;i<=i_iRecordLen;i++)
	{
		o_ptSeqList->atRecord[i].iOtherItems=i_atRecord[i-1].OtherInfo;
		//itoa�ǷǱ�׼C���Ժ�C++������չ����,win����stdlib.h����,������linux��û�ж���,����ע�͵�
		//itoa(i_atRecord[i-1].Key,acKey,10); // ��10��������ת��Ϊ�ַ��ͣ�����c
		snprintf(acKey,sizeof(acKey),"%d",i_atRecord[i-1].Key);// ��10��������ת��Ϊ�ַ��ͣ�����c
		for(j=strlen(acKey);j<o_ptSeqList->iKeyNum;j++) // ��c�ĳ���<max��λ������cǰ��'0'
		{
			strcpy(acTempKey,"0");
			strcat(acTempKey,acKey);
			strcpy(acKey,acTempKey);
		}
		for(j=0;j<o_ptSeqList->iKeyNum;j++)
		{
			o_ptSeqList->atRecord[i].atKeys[j]=acKey[o_ptSeqList->iKeyNum-j-1];//�������ַ��ͣ����ɷ��ַ�?
		}//nextֵ����û��ʼ�����ɷ�������ʼ��?
	}
}


/*****************************************************************************
-Fuction		: RadixSort
-Description	: 
// L�ǲ��þ�̬�����ʾ��˳�����L����������
ʹ��L��Ϊ���ؼ�����С���������̬����
// L.r[0]Ϊͷ��㡣


�������岽��
1. �Ծ�̬����洢���ż�¼�������ͷָ���һ����¼
2. ��һ�˷���Ը�λ�����У��ı��¼��ָ��ֵ��������
�ļ�¼���䵽10����������ȥ,�����������е�Ԫ��ָ��ָ���Ӧ�ļ�¼
(��:��5�������е�Ԫ��ָ��ָ����Ǹ�λ��Ϊ5�ļ�¼),
���������еļ�¼�ؼ��ֵĸ�λ�����(��λ����ͬ�ļ�¼��ͬһ�������еļ�¼��nextָ������)

(���������еĻ�ָ�ľ��Ƕ��е�ȡֵ��Χ,��������Ļ�����10���������ĸ�����26)
3. ��һ���ռ��Ǹı����зǿն��еĶ�β��¼��ָ����
����ָ����һ���ǿն��еĶ�ͷ��¼�����½�10�������е�
��¼����һ������
4. �ڶ��˵����˷ֱ��Ƕ�ʮλ���Ͱ�λ�����еģ����̺͸�
λ����ͬ


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
	i_ptSeqList->atRecord[i_ptSeqList->iRecNum].iNext=0;// ��L����Ϊ��̬����
	for(i=0;i<i_ptSeqList->iKeyNum;i++)
	{// �����λ�������ζԸ��ؼ��ֽ��з�����ռ�
		Distribute(i_ptSeqList->atRecord,i,atFront,atRear); // ��i�˷���
		Collect(i_ptSeqList->atRecord,atFront,atRear); // ��i���ռ�
		printf("��%d���ռ���:\n",i+1);
		PrintSeqList(i_ptSeqList);
		printf("\n");
	}
}

/*****************************************************************************
-Fuction		: Distribute
-Description	: �������еļ�¼���䵽10��������(ʹ��ͷβָ���ʾ)��ȥ

// ��̬����L��r���м�¼�Ѱ�(keys[0]��.��keys[i-1])���򡣱��㷨��
// ��i���ؼ���keys[i]����RADIX���ӱ�(����)��ʹͬһ�ӱ�(����)�м�¼��keys[i]��ͬ��
// i_aiFront[0..RADIX-1]��i_aiRear[0..RADIX-1]�ֱ���ָ����ӱ��е�һ�������һ����¼��ָ��


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
		i_aiFront[i]=0; // ���ӱ��ʼ��Ϊ�ձ�
	for(p=i_atRecord[0].iNext;p;p=i_atRecord[p].iNext)
	{
		i=i_atRecord[p].atKeys[i_iKeyNum]-'0'; // ����¼�е�i���ؼ���ӳ�䵽[0..RADIX-1]
		if(!i_aiFront[i])
			i_aiFront[i]=p;//��j�����е�ͷָ��ָ��p��ָ�ڵ�
		else
			i_atRecord[i_aiRear[i]].iNext=p;//��j�����е�βָ����ָ�ڵ����һ�ڵ�Ϊp��ָ�ڵ�
		i_aiRear[i]=p; // ��p��ָ�Ľ������j���ӱ���//��j�����е�βָ��ָ��p��ָ�ڵ�
	}
}

/*****************************************************************************
-Fuction		: Collect
-Description	: �ռ��Ǹı����зǿն��еĶ�β��¼��ָ��������ָ����һ���ǿն��еĶ�ͷ��¼��
���½�10�������еļ�¼����һ������


// ���㷨��keys[i]��С����ؽ�i_aiFront[0..RADIX-1]��ָ���ӱ�(����)�������ӳ�һ������
// i_aiRear[0..RADIX-1]Ϊ���ӱ�(����)��βָ�롣

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
	for(i=0;!i_aiFront[i];i++); // �ҵ�һ���ǿ��ӱ�
		i_atRecord[0].iNext=i_aiFront[i];// r[0].nextָ���һ���ǿ��ӱ��е�һ�����
	t=i_aiRear[i]; // ��һ���ǿ��ӱ��е�βָ��//ͬһ���ǿ��ӱ��е�Ԫ�ز�������,��Ϊ�����ʱ���Ѿ����Ӻ���
	while(i<RADIX-1)
	{
		for(++i;i<RADIX-1&&!i_aiFront[i];i++); // ����һ���ǿ��ӱ�
		if(i_aiFront[i])
		{ // ���������ǿ��ӱ�
			i_atRecord[t].iNext=i_aiFront[i];//β��ͷ��������
			t=i_aiRear[i];//����β//ͬһ���ǿ��ӱ��е�Ԫ�ز�������,��Ϊ�����ʱ���Ѿ����Ӻ���
		}
	}
	i_atRecord[t].iNext=0; // tָ�����һ���ǿ��ӱ��е����һ�����
}



/*****************************************************************************
-Fuction		: GetOrderNum
-Description	: //��ȡ����������±�,������ָ��ֵ
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void GetOrderNum(T_SeqList *i_ptSeqList,int *o_aiOrderNum)
{// ���o_aiOrderNum[1..L.length]��
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
-Description	: //����ľ�̬���������˳���

���ַ�ʽ���˷ѿռ䣬���ǽṹ��,���Ķ���ǿ��

���ʹ�ý����ķ�ʽ����ʡ�ռ䣬���߼�����,
ͬʱ�����ٴ��޸�������������i_aiOrderNum��ֵ������p439

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
-Description	: // �����������̬����
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
-Description	: // ��������������̬����
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

