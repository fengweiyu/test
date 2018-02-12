/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	MergeSort.c
* Description		: 	MergeSort operation center

һ������˼��
�������з�Ϊ����������Ҫ���������,Ȼ���ٹ鲢
��벿���ַ�Ϊ������Ҫ���������,Ȼ���ٹ鲢
�Ұ벿���ַ�Ϊ������Ҫ���������,Ȼ���ٹ鲢(�ָ���������к͸�������һ���Ĵ������õݹ�)
(�ݹ�����ǰ�벿��(���)��Ϊ����,�ٺ�벿��(�ұ�)��Ϊ����)
ֱ���������붼ֻ��һ��Ԫ�ؼ������������Ϲ鲢(������Ԫ������,��������Ŀ����)

* Created			: 	2017.06.15.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"



#define SEQ_LIST_RECORD_MAX_LEN		20
#define RECORD_NUMBER				8

typedef int KeyType;

typedef struct RecordType
{
	KeyType Key;
	int OtherInfo;
}T_RecordType,*PT_RecordType;

typedef struct RecordSeqList
{
	T_RecordType atRecord[SEQ_LIST_RECORD_MAX_LEN+1];// r[0]���û������ڱ���Ԫ
	int iLength;
}T_RecordSeqList,*PT_RecordSeqList;
static void Merge(T_RecordType i_atSrcRecord[],T_RecordType o_atDstRecord[],int i_iLow,int i_iMid,int i_iHigh);
static void MSort(T_RecordType i_atSrcRecord[],T_RecordType o_atDstRecord[],int i_iLow, int i_iHigh);



static void MergeSort(T_RecordSeqList *i_ptRecordSeqList);
static void TraverseRecordSeqList(T_RecordSeqList *i_ptRecordSeqList);

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
	MergeSort(&tSeqList1);
	printf("�鲢�����:\n");
	TraverseRecordSeqList(&tSeqList1);

	return 0;
}

/*****************************************************************************
-Fuction		: MergeSort
-Description	: ��˳���L���鲢����
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void MergeSort(T_RecordSeqList *i_ptRecordSeqList)
{
	MSort(i_ptRecordSeqList->atRecord,i_ptRecordSeqList->atRecord,1,i_ptRecordSeqList->iLength);//0����Ԫ�����Դ�1(��1��ʼ
}

/*****************************************************************************
-Fuction		: MSort
-Description	: // ��i_atSrcRecord[s(i_iLow)..t(i_iHigh)]�鲢����Ϊo_atDstRecord[s..t]��

�������岽��
1. �ݹ�ؽ���벿�ֹ鲢Ϊ����,����i_atSrcRecord��벿�ֹ鲢��atRecord
2. �ݹ�ؽ��Ұ벿�ֹ鲢Ϊ����,����i_atSrcRecord�Ұ벿�ֹ鲢��atRecord
ֱ���������붼ֻ��һ��Ԫ�ؼ������������Ϲ鲢
3. �鲢��������Ϊ��������,����atRecord����������鲢��o_atDstRecord

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void MSort(T_RecordType i_atSrcRecord[],T_RecordType o_atDstRecord[],int i_iLow, int i_iHigh)
{
	int iMid;
	T_RecordType atRecord[SEQ_LIST_RECORD_MAX_LEN+1]={0};
	if(i_iLow==i_iHigh)
	{
		o_atDstRecord[i_iLow]=i_atSrcRecord[i_iLow];
	}
	else//atRecordͨ���ݹ��������߸��Ա�Ϊ���򲿷ֲ���������
	{//���鲢�������벿��Ϊ����(�ݹ�����ǰ�벿��(���)��Ϊ����,�ٺ�벿��(�ұ�)��Ϊ����)
		iMid=(i_iLow+i_iHigh)/2; // ��i_atSrcRecord[s..t]ƽ��Ϊi_atSrcRecord[s..m]��i_atSrcRecord[m+1..t]
		MSort(i_atSrcRecord,atRecord,i_iLow,iMid); // �ݹ�ؽ�i_atSrcRecord[s..m]�鲢Ϊ�����atRecord[s..m]
		MSort(i_atSrcRecord,atRecord,iMid+1,i_iHigh); // �ݹ�ؽ�i_atSrcRecord[m+1..t]�鲢Ϊ�����atRecord[m+1..t]
		Merge(atRecord,o_atDstRecord,i_iLow,iMid,i_iHigh); // ��atRecord[s..m]��atRecord[m+1..t]�鲢��o_atDstRecord[s..t]
	}
}

/*****************************************************************************
-Fuction		: Merge
-Description	: 
// �������i_atSrcRecord[i_iLow..i_iMid]��i_atSrcRecord[i_iMid+1..i_iHigh]�鲢Ϊ�����TR[i..n]

�������岽��
3. �ϲ�������������(һ�����е�����������)Ϊһ����������
3.1. ��������ȡС�Ĳ��ֱ���
��߸�С����������ͬʱ��ߵ�ָ��i_iLow���ƽ����ٴαȽ�
�ұ߸�С����������ͬʱ�ұߵ�ָ��iRight���ƽ����ٴαȽ�
3.2. ����ʣ�µ�
��߻���ʣ�ģ�ʣ�Ĳ��ֶ����ұߵĴ�,�������ѱ���Ĵ�
�ұ߻���ʣ�ģ�ʣ�Ĳ��ֶ�����ߵĴ�,�������ѱ���Ĵ�
	
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void Merge(T_RecordType i_atSrcRecord[],T_RecordType o_atDstRecord[],int i_iLow,int i_iMid,int i_iHigh)
{
	int iRight;
	int i,j;
	for(iRight=i_iMid+1,i=i_iLow;i_iLow<=i_iMid&&iRight<=i_iHigh;++i) // ��SR�м�¼��С����ز���TR
	{
		if (i_atSrcRecord[i_iLow].Key<i_atSrcRecord[iRight].Key)//����ȡС�Ĳ��ֱ��浽o_atDstRecord
		{
			o_atDstRecord[i]=i_atSrcRecord[i_iLow++];//��߸�С����������ͬʱ��ߵ�ָ��i_iLow���ƽ����ٴαȽ�
		}
		else
		{
			o_atDstRecord[i]=i_atSrcRecord[iRight++];;//�ұ߸�С����������ͬʱ�ұߵ�ָ��i���ƽ����ٴαȽ�
		}
	}
	//����ʣ�µ�
	if(i_iLow<=i_iMid)//��߻���ʣ�ģ���ʣ�Ĳ��ֶ����ұߵĴ�
	{
		for(j=0;j<=i_iMid-i_iLow;j++)
		{
			o_atDstRecord[i+j]=i_atSrcRecord[i_iLow+j]; // ��ʣ���i_atSrcRecord[i_iLow..i_iMid]���Ƶ�o_atDstRecord
		}
	}
	if(iRight<=i_iHigh)//�ұ߻���ʣ�ģ���ʣ�Ĳ��ֶ�����ߵĴ�
	{
		for(j=0;j<=i_iHigh-iRight;j++)
		{
			o_atDstRecord[i+j]=i_atSrcRecord[iRight+j]; // ��ʣ���i_atSrcRecord[iRight..i_iHigh]���Ƶ�o_atDstRecord
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

