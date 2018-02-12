/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BiInsertSort.c
* Description		: 	BiInsertSort operation center

һ������˼��
���ڲ�������Ļ��������ǽ�һ����¼���뵽���ź����������У�
�����ź����������в��Ҳ����Ĳ����������۰������ʵ�֣�
�ɴ˽��еĲ��������Ϊ�۰��������


* Created			: 	2017.06.16.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
	
	
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
static void BiInsertSort(T_RecordSeqList *i_ptRecordSeqList);

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
	for(i=0;i<RECORD_NUMBER;i++) // ��l1.r��ֵ
		tSeqList1.atRecord[i+1]=atRecord[i];
	tSeqList1.iLength=RECORD_NUMBER;
	tSeqList3=tSeqList2=tSeqList1; // ����˳���l2��l3��l1��ͬ
	printf("����ǰ:\n");
	TraverseRecordSeqList(&tSeqList1);
	BiInsertSort(&tSeqList1);
	printf("�۰���������:\n");
	TraverseRecordSeqList(&tSeqList1);

	return 0;
}
/*****************************************************************************
-Fuction		: BiInsertSort
-Description	: // ��˳���L���۰��������


�������岽��
1. ���Ƶ��ڱ���
2. ����������۰����Ҫ�����λ��//high=i-1;//��1��ʼ������
3. Ҫ�����λ�õļ�¼���������ļ�¼������к���
4. ����ļ�¼����

��:
[yweifeng@localhost test]$ gcc -o BiInsertSort BiInsertSort.c
[yweifeng@localhost test]$ ./BiInsertSort                    
����ǰ:
(49,1)(38,2)(65,3)(97,4)(76,5)(13,6)(27,7)(49,8)
�۰���������:
(13,6)(27,7)(38,2)(49,1)(49,8)(65,3)(76,5)(97,4)
[yweifeng@localhost test]$ 


-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void BiInsertSort(T_RecordSeqList *i_ptRecordSeqList)
{ // ��˳���L���۰��������
	int i,j,m,low,high;
	for(i=2;i<=i_ptRecordSeqList->iLength;++i)
	{
		i_ptRecordSeqList->atRecord[0]=i_ptRecordSeqList->atRecord[i]; // ��L.r[i]�ݴ浽L.r[0]
		low=1;
		high=i-1;//��1��ʼ������
		while(low<=high)//�����㷨��������//�Ա�֤highָ����ҵ�λ�õ�ǰһ��
		{ // ��r[low..high]���۰������������λ��
			m=(low+high)/2; // �۰�
			if(i_ptRecordSeqList->atRecord[0].Key<i_ptRecordSeqList->atRecord[m].Key)
				high=m-1; // ������ڵͰ���
			else
				low=m+1; // ������ڸ߰���
		}
		for(j=i-1;j>=high+1;--j)
			i_ptRecordSeqList->atRecord[j+1]=i_ptRecordSeqList->atRecord[j]; // ��¼����
		i_ptRecordSeqList->atRecord[high+1]=i_ptRecordSeqList->atRecord[0]; // ����
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


