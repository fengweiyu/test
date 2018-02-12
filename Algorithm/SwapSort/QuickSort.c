/*****************************************************************************
* Copyright (C) 2017-2020 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	QuickSort.c
* Description		: 	QuickSort operation center

һ������˼��
��Ҫʹ���˵ݹ�˼��,���ϵ�ȷ��ÿ��Ԫ�ص�λ�á�
����,��һ��Ԫ��(һ���ǵ�һ��Ԫ��)��
Ȼ��,ȷ����Ԫ�ص�λ��(������õ����������е�λ��)
����,�Ը�Ԫ��ȷ���õ�λ�ý����л���Ϊ����,ÿһ������
����һ��Ԫ�أ�Ȼ��ȷ��λ�ã������ٻ���,�����ظ�(�ݹ�)
ֱ��ȷ������һ��Ԫ��(�����ٻ���)�� �ò��ֵݹ������
ֱ��ȷ���������һ��Ԫ��(�����ٻ���)�������������

��:
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
	T_RecordType atRecord[RECORD_SEQ_LIST_MAX_LEN+1];// r[0]���û������ڱ���Ԫ
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
-Description	: // ��˳���L����������

�������岽��
1. ȷ��ĳ��Ԫ��λ��,Ȼ���Ը�λ�û�������(��ȷ����λ��
��Ȼ������),�ֱ���еݹ���ȷ����������ĳ��Ԫ��λ��,
ֱ������������ֻ��һ��Ԫ��,�����е�Ԫ��λ����ȷ��

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
	{//�˳��ݹ������,�������е�Ԫ��λ����ȷ��(ֻʣһ��Ԫ��)���˳�
		iPos=FindPos(i_ptRecordSeqList,i_iLow,i_iHigh);// ��L.r[low..high]һ��Ϊ��
		QuickSort(i_ptRecordSeqList,i_iLow,iPos-1);// �Ե��ӱ�ݹ�����iPos������λ��
		QuickSort(i_ptRecordSeqList,iPos+1,i_iHigh);// �Ը��ӱ�ݹ�����
	}
}


/*****************************************************************************
-Fuction		: FindPos
-Description	: 
//ȷ����һ��Ԫ�ص�λ��(������ͬ,���¿��ŵ�ϸ�ڲ�ͬ)

�������岽��
2. ����λ��ָ��l/h�ֱ�ָ�����е���β,ȡ��һ��Ԫ��Ϊ�Ƚ�Ԫ��

3. ��hָ���Ԫ�رȱȽ�Ԫ�ص�ֵ��,h���������ƶ�;����,
hָ��ĸ�ֵ��lָ���,Ȼ��h����,ִ�в���4
4. ��lָ���Ԫ�رȱȽ�Ԫ�ص�ֵС,l���������ƶ�;����,
lָ��ĸ�ֵ��hָ���,Ȼ��l����,ִ�в���3

5. ��l=hʱ����ȷ���˱Ƚ�Ԫ�ص�λ��

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int FindPos(T_RecordSeqList *i_ptRecordSeqList,int i_iLow,int i_iHigh)
{
#if 1//������Ǵӵ�һ��Ԫ�ؿ�ʼ����һ��ʼ����h�����ƶ�,���������
		T_RecordType tVal;
		memcpy(&tVal,&i_ptRecordSeqList->atRecord[i_iLow],sizeof(T_RecordType));//��һ����¼�����Ƚ�Ԫ��
		while(i_iLow<i_iHigh)
		{
			while(i_iLow<i_iHigh&&i_ptRecordSeqList->atRecord[i_iHigh].Key>=tVal.Key)
			{//i_iLow<i_iHigh ��ֹԽ��
				i_iHigh--;//��������
			}//�����ڴӵ�һ��Ԫ�ؿ�ʼ������һ��ʼ��h�����ƶ�,�ſ��Բ��ý�����ֱ�Ӹ�ֵ
			memcpy(&i_ptRecordSeqList->atRecord[i_iLow],&i_ptRecordSeqList->atRecord[i_iHigh],sizeof(T_RecordType));//�˳�ѭ��,��ֵ,�ƶ������ָ��
			while(i_iLow<i_iHigh&&i_ptRecordSeqList->atRecord[i_iLow].Key<=tVal.Key)
			{//i_iLow<i_iHigh ��ֹԽ��
				i_iLow++;//��������
			}//���ڴӵ�һ��Ԫ�ؿ�ʼ������һ��ʼ��h�����ƶ�,�ſ��Բ��ý�����ֱ�Ӹ�ֵ
			memcpy(&i_ptRecordSeqList->atRecord[i_iHigh],&i_ptRecordSeqList->atRecord[i_iLow],sizeof(T_RecordType));//�˳�ѭ��,��ֵ,�ƶ������ָ��
			//������Ǵӵ�һ��Ԫ�ؿ�ʼ����һ��ʼ����h�����ƶ�,���������
		}
		memcpy(&i_ptRecordSeqList->atRecord[i_iLow],&tVal,sizeof(T_RecordType));//i_iLow=i_iHighȷ��λ��
		return i_iLow;//i_iLow ����i_iHigh����

#else//������Ǵӵ�һ��Ԫ�ؿ�ʼ����һ��ʼ����h�����ƶ�,���������
		int iVal=i_ptRecordSeqList->atRecord[i_iLow].Key;//��һ����¼�����Ƚ�Ԫ��
		T_RecordType tVal;
		while(i_iLow<i_iHigh)
		{//������Ǵӵ�һ��Ԫ�ؿ�ʼ����һ��ʼ����h�����ƶ�,���������,�������ַ�ʽ����׳
			while(i_iLow<i_iHigh&&i_ptRecordSeqList->atRecord[i_iHigh].Key>=iVal)
			{//i_iLow<i_iHigh ��ֹԽ��
				i_iHigh--;//��������
			}//�˳�ѭ��,// ���������¼С�ļ�¼�������Ͷ�,�ƶ������ָ��
			memcpy(&tVal,&i_ptRecordSeqList->atRecord[i_iLow],sizeof(T_RecordType));
			memcpy(&i_ptRecordSeqList->atRecord[i_iLow],&i_ptRecordSeqList->atRecord[i_iHigh],sizeof(T_RecordType));
			memcpy(&i_ptRecordSeqList->atRecord[i_iHigh],&tVal,sizeof(T_RecordType));
			
			while(i_iLow<i_iHigh&&i_ptRecordSeqList->atRecord[i_iLow].Key<=iVal)
			{//i_iLow<i_iHigh ��ֹԽ��
				i_iLow++;//��������
			}//�˳�ѭ��,// ���������¼��ļ�¼�������߶�,�ƶ������ָ��
			memcpy(&tVal,&i_ptRecordSeqList->atRecord[i_iHigh],sizeof(T_RecordType));
			memcpy(&i_ptRecordSeqList->atRecord[i_iHigh],&i_ptRecordSeqList->atRecord[i_iLow],sizeof(T_RecordType));
			memcpy(&i_ptRecordSeqList->atRecord[i_iLow],&tVal,sizeof(T_RecordType));
		}//i_iLow=i_iHighȷ��λ��
		//�Ƚ�Ԫ���Ѿ�������ȷ��λ��,�������ﲻ��Ҫ�ٴθ�ֵ
		return i_iLow;//����ȷ����λ�� ��i_iLow ����i_iHigh����
#endif


#if 0//������Ǵӵ�һ��Ԫ�ؿ�ʼ����һ��ʼ����h�����ƶ�,���������
	T_RecordType tVal;
	T_RecordType tTempVal;
	memcpy(&tVal,&i_ptRecordSeqList->atRecord[i_iLow],sizeof(T_RecordType));//��һ����¼�����Ƚ�Ԫ��
	while(i_iLow<i_iHigh)
	{//������Ǵӵ�һ��Ԫ�ؿ�ʼ����һ��ʼ����h�����ƶ�,���������
		while(i_iLow<i_iHigh&&i_ptRecordSeqList->atRecord[i_iHigh].Key>=tVal.Key)
		{//i_iLow<i_iHigh ��ֹԽ��
			i_iHigh--;//��������
		}//�˳�ѭ��,// ���������¼С�ļ�¼�������Ͷ�,�ƶ������ָ��
		memcpy(&tTempVal,&i_ptRecordSeqList->atRecord[i_iLow],sizeof(T_RecordType));
		memcpy(&i_ptRecordSeqList->atRecord[i_iLow],&i_ptRecordSeqList->atRecord[i_iHigh],sizeof(T_RecordType));
		memcpy(&i_ptRecordSeqList->atRecord[i_iHigh],&tTempVal,sizeof(T_RecordType));
		
		while(i_iLow<i_iHigh&&i_ptRecordSeqList->atRecord[i_iLow].Key<=tVal.Key)
		{//i_iLow<i_iHigh ��ֹԽ��
			i_iLow++;//��������
		}//�˳�ѭ��,// ���������¼��ļ�¼�������߶�,�ƶ������ָ��
		memcpy(&tTempVal,&i_ptRecordSeqList->atRecord[i_iHigh],sizeof(T_RecordType));
		memcpy(&i_ptRecordSeqList->atRecord[i_iHigh],&i_ptRecordSeqList->atRecord[i_iLow],sizeof(T_RecordType));
		memcpy(&i_ptRecordSeqList->atRecord[i_iLow],&tTempVal,sizeof(T_RecordType));
	}//i_iLow=i_iHighȷ��λ��
	//�Ƚ�Ԫ���Ѿ�������ȷ��λ��,�������ﲻ��Ҫ�ٴθ�ֵ
	
	//���渳ֵû��Ч��,��Ȼ����һ��ʼ���ƶ�˳��(�����h��ʼ)
	//memcpy(&i_ptRecordSeqList->atRecord[i_iLow],&tVal,sizeof(T_RecordType));//i_iLow=i_iHighȷ��λ��

	return i_iLow;//����ȷ����λ�� ��i_iLow ����i_iHigh����
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

