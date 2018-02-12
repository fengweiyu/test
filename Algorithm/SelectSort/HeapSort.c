/*****************************************************************************
* Copyright (C) 2017-2020 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	HeapSort.c
* Description		: 	HeapSort operation center

һ������˼��
�ѵĺ����������ȫ�����������з��ն˽ڵ��ֵ��������
(��С��)�����Һ��ӽڵ��ֵ���ɴˣ��������Ƕѣ����
��Ԫ��(����ȫ�������ĸ�)��Ϊ������n��Ԫ�ص���Сֵ(���ֵ)

1. �����һ���������н���һ����?
2���ԶѶ���Ҷ�ӵĵ������̳�Ϊ"ɸѡ"��
��һ���������н��ѵĹ��̾���һ������"ɸѡ"�Ĺ��̣�������
���п�����һ����ȫ������(���������)�������һ�����ն�
�ڵ��ǵ�n/2��Ԫ�أ��ɴ�"ɸѡ"ֻ��ӵ�n/2��Ԫ�ؿ�ʼ(�����ڵ�
����)

2. ���������Ѷ�Ԫ��֮��,����ʣ��Ԫ�س�Ϊһ���µĶ�?
��������Ѷ�Ԫ��֮���Զ������һ��Ԫ�����֮��
��ʱ���ڵ������������Ϊ�ѣ���������϶��½��е������ɡ�
�����ԶѶ�Ԫ�غ��������������ڵ��ֵ�Ƚϣ������������ڵ�
С�����������ڵ��ֵ��С�ڸ��ڵ��ֵ(ȡ��С��)������С��
�Ǹ��ڵ�����ڵ㽻��,���������ƻ����������Ķ������������
��ͬ�ĵ���


��:
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
	T_RecordType atRecord[RECORD_SEQ_LIST_MAX_LEN+1];// r[0]���û������ڱ���Ԫ
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
-Description	: // ��˳���L��������

�������岽��
1. �������������н����ɴ󶥶�
2. ���󶥶Ѹ�Ԫ�غ��������Ľ�����ͬʱ�����г��ȼ�һ
������ʣ��Ԫ��(��ȥ����������)Ϊ��,ֱ��ʣ��Ԫ��Ϊ1��

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
	for(i=i_ptRecordSeqList->iLength/2;i>0;i--)// ��H.r[1..H.length]���ɴ󶥶�
	{
		HeapAdjust(i_ptRecordSeqList,i,i_ptRecordSeqList->iLength);//��n/2Ԫ�ؿ�ʼ����,ֱ�����ڵ�
	}
	for(i=i_ptRecordSeqList->iLength;i>1;i--)
	{// ���Ѷ���¼�͵�ǰδ������������H.r[1..i]�����һ����¼�໥����
		memcpy(&tRecord,&i_ptRecordSeqList->atRecord[i],sizeof(T_RecordType));
		memcpy(&i_ptRecordSeqList->atRecord[i],&i_ptRecordSeqList->atRecord[1],sizeof(T_RecordType));//ȡ������(�Ѷ�)�����������
		memcpy(&i_ptRecordSeqList->atRecord[1],&tRecord,sizeof(T_RecordType));//(ԭ�����ķŵ��Ѷ�ȥ)
		//ͬʱ�����г��ȼ�һ//�ظ�ֱ�������г���Ϊ1
		HeapAdjust(i_ptRecordSeqList,1,i-1); // ��H.r[1..i-1]���µ���Ϊ�󶥶�
	}
}

/*****************************************************************************
-Fuction		: HeapAdjust
-Description	: 
// ��֪H.r[s..m]�м�¼�Ĺؼ��ֳ�H.r[s].key֮�������ѵĶ��壬������
// ����H.r[s]�Ĺؼ��֣�ʹH.r[s..m]��Ϊһ���󶥶�(�����м�¼�Ĺؼ��ֶ���)

�������岽��

3. ����
���ȱȽϵĸ��ڵ�(�������Ľڵ�))���������ӣ�ȡ�ϴ��
�����ڵ�(�������Ľڵ�)���ڽϴ�ĺ��ӣ�����ڵ�(�������Ľڵ�)
Ӧ�����ڸú��ӵĸ�λ���ϡ�
�����ƶ��ú��ӵ��丸λ����(�����ƶ�)��
���ڵ�(�������Ľڵ�)�������±Ƚ�

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
	for(i=2*i_iLow;i<=i_iHigh;i*=2)// ��key�ϴ�ĺ��ӽ������ɸѡ
	{
		if(i<i_iHigh&&i_ptRecordSeqList->atRecord[i].Key<i_ptRecordSeqList->atRecord[i+1].Key)
		{//ȡ�ϴ�ĺ���
			i++;
		}
		if(tRecord.Key>i_ptRecordSeqList->atRecord[i].Key)
		{
			break;// rcӦ������λ��i_iLow��,�����ӵĸ��ڵ���
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

