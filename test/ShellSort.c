/*****************************************************************************
* Copyright (C) 2017-2020 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ShellSort.c
* Description		: 	ShellSort operation center

һ������˼��
ϣ�������ֳ�"��С��������",��Ҳ��һ���������������
���������Ļ���˼����:
�Ƚ��������ż�¼���зָ��Ϊ����������,�ֱ����ֱ��
�������򣬴����������еļ�¼"��������"ʱ���ٶ�ȫ��
��¼����һ��ֱ�Ӳ�������

��:
[yweifeng@localhost test]$ gcc -o ShellSort ShellSort.c 
[yweifeng@localhost test]$ ./ShellSort
����ǰ:
(49,1)(38,2)(65,3)(97,4)(76,5)(13,6)(27,7)(49,8)
ϣ�������:
(13,6)(27,7)(38,2)(49,1)(49,8)(65,3)(76,5)(97,4)
[yweifeng@localhost test]$ 


* Created			: 	2017.11.14.
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
static void ShellInsert(T_RecordSeqList *i_ptRecordSeqList,int i_iDk);
static void ShellSort(T_RecordSeqList *i_ptRecordSeqList,int *i_atDk,int i_DkLen);

/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_RecordType atRecord[RECORD_NUMBER]={{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}};
	T_RecordSeqList tSeqList1;
	int i;
	memcpy(&tSeqList1.atRecord[1],atRecord,sizeof(atRecord));
	tSeqList1.iLength=RECORD_NUMBER;
	int atDk[3]={5,3,1};

	
	printf("����ǰ:\n");
	TraverseRecordSeqList(&tSeqList1);
	ShellSort(&tSeqList1,atDk,sizeof(atDk)/sizeof(int));
	printf("ϣ�������:\n");
	TraverseRecordSeqList(&tSeqList1);

	return 0;
}


/*****************************************************************************
-Fuction		: ShellSort
-Description	: // ��˳���L��ϣ������

�������岽��
1. ���������������л���Ϊ����������
2. �ֱ��ÿ�������н���ֱ�Ӳ�������

8. ��С�����ظ���������

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void ShellSort(T_RecordSeqList *i_ptRecordSeqList,int *i_atDk,int i_DkLen)
{
	int i;
	for(i=0;i<i_DkLen;i++)
	{
		ShellInsert(i_ptRecordSeqList,i_atDk[i]);
	}
}

/*****************************************************************************
-Fuction		: ShellInsert
-Description	: // ��˳���L��ϣ������

�������岽��
3. ��������ȡ�������У������һ��������Ԫ��С��ǰһ��
4. �򽫸�Ԫ�ؿ������ݴ浥Ԫr[0],ͬʱѰ�Ҳ���λ��
5. ���r[0]�����������е�ĳ��Ԫ�أ���r[0]�ͷ��ڸ�Ԫ�غ���
6. ���򽫼�¼���ƣ�ͬʱ�����Ƚ�ֱ����һ��Ԫ��Ϊֹ
7. ����Ƚϵ�r[1]����û���ҵ���˵��r[0]��С,�ŵ�r[1]����


��: 	{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}
	{38,2},{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}
	{13,6},{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8}
	{13,6},{49,1},{38,2},{65,3},{97,4},{76,5},{38,2},{27,7},{49,8}

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void ShellInsert(T_RecordSeqList *i_ptRecordSeqList,int i_iDk)
{
	int i,j;
	for(i=i_iDk+1;i<=i_ptRecordSeqList->iLength;i++)//һ��ѭ��Ϊ��ͬ�����һ��������
	{
		if(i_ptRecordSeqList->atRecord[i].Key<i_ptRecordSeqList->atRecord[i-i_iDk].Key)//С����Ҫ���뵽���������ӱ�
		{
			memcpy(&i_ptRecordSeqList->atRecord[0],&i_ptRecordSeqList->atRecord[i],sizeof(T_RecordType));//ȡ��Ԫ���ݴ���r[0]
			for(j=i-i_iDk;j>0;j-=i_iDk)//Ѱ�Ҳ���λ���Լ������������ڽ�������
			{//��:��һ��ѭ��,j=i-i_iDk=i_iDk+1-i_iDk=1,�����Ǵ���������ȡ����Ԫ�ص�ǰһ��λ�ÿ�ʼ
				if(i_ptRecordSeqList->atRecord[0].Key>i_ptRecordSeqList->atRecord[j].Key)
				{//���r[0]�����������еĸ�Ԫ��,��˵���ҵ�����λ�ã��ŵ����λ�õĺ���
					break;
				}
				else
				{//��������
					memcpy(&i_ptRecordSeqList->atRecord[j+i_iDk],&i_ptRecordSeqList->atRecord[j],sizeof(T_RecordType));
				}
			}//����Ƚϵ�r[1]����û���ҵ���˵��r[0]��С,�ŵ�r[1]����
			memcpy(&i_ptRecordSeqList->atRecord[j+i_iDk],&i_ptRecordSeqList->atRecord[0],sizeof(T_RecordType));//����λ��
		}
		else
		{
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

