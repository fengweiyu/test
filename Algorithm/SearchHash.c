/*****************************************************************************
* Copyright (C) 2017-2020 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SearchHash.c
* Description		: 	SearchHash (���ҹ�ϣ��)operation center

һ������˼��
��ϣ��: �����趨�Ĺ�ϣ�����ʹ����ͻ�ķ�����һ��ؼ�
�ֱַ�������Ӧ��ֵ,���Ը�ֵ��Ϊ��¼�ڱ��еĴ洢λ�ã�
���ֱ���Ϊ��ϣ����һ���̳�Ϊ��ϣ����ɢ�У�
�������ô洢λ�ó�Ϊ��ϣ��ַ��ɢ�е�ַ��

�����ڹؼ��ּ����е���һ���ؼ��֣�����ϣ����ӳ�񵽵�ַ
�������κ�һ����ַ�ĸ�������ȵģ���ƴ����ϣ����Ϊ
���ȵĹ�ϣ���������仰˵������ʹ�ؼ��־�����ϣ�����õ�
һ��"����ĵ�ַ",��Ψһ�ĵ�ַ��Ҳ����˵��ͻ��С��

��ƹ�ϣ�����ʹ����ͻ�ķ���Ӧ���Ծ����ܼ��ٳ�ͻΪԭ��



��:
[yweifeng@localhost test]$ gcc -o SearchHash SearchHash.c
[yweifeng@localhost test]$ ./SearchHash
�������йؼ���Ϊ60�ļ�¼���޷��ٲ����¼(60,9)
����ϣ��ַ��˳�������ϣ��:
��ϣ��ַ0��10
address=1 (1,5)
address=2 (2,6)
address=3 (3,7)
address=4 (4,8)
address=5 (60,2)
address=6 (17,1)
address=7 (29,3)
address=8 (38,4)
����������Ҽ�¼�Ĺؼ���: 13
û�ҵ�
�ؽ���ϣ��
����ϣ��ַ��˳������ؽ���Ĺ�ϣ��:
��ϣ��ַ0��18
address=0 (38,4)
address=1 (1,5)
address=2 (2,6)
address=3 (3,7)
address=4 (4,8)
address=6 (60,2)
address=10 (29,3)
address=13 (13,10)
address=17 (17,1)
����������Ҽ�¼�Ĺؼ���: 13
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

#define NULL_KEY 0 // 0Ϊ�޼�¼��־


#define RECORD_NUMBER				10

typedef  int KeyType;// ��ؼ�����Ϊ����

typedef struct ElementType
{
	KeyType Key;	// ���йؼ�����
	int iOrd;
}T_ElementType;

typedef struct HashTable
{
	T_ElementType *ptElement; // ����Ԫ�ش洢��ַ����̬��������
	int iCount; // ��ǰ����Ԫ�ظ���
	int iSizeIndex; // hashsize[sizeindex]Ϊ��ǰ����
}T_HashTable;

static int g_aiHashSize[]={11,19,29,37}; // ��ϣ������������һ�����ʵ���������,���ڵ���ϣ����������ʱ������չ
static int g_iHashLength=0; // ��ϣ�����ȫ�ֱ���,�����Ż���



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
	
	/*��ʼ��*/
	InitHashTable(&tHashTable);
	for(i=0;i<RECORD_NUMBER-1;i++)
	{ // ����ǰN-1����¼
		iRet=InsertHash(&tHashTable,&atRecord[i]);
		if(iRet==DUPLICATE)
		printf("�������йؼ���Ϊ%d�ļ�¼���޷��ٲ����¼(%d,%d)\n",atRecord[i].Key,atRecord[i].Key,atRecord[i].iOrd);
	}
	printf("����ϣ��ַ��˳�������ϣ��:\n");
	TraverseHash(&tHashTable);

	/*����*/
	printf("����������Ҽ�¼�Ĺؼ���: ");
	scanf("%d",&Key);
	iRet=SearchHash(&tHashTable,&Key,&iSearchedIndex,&iConflictCnt);
	if(iRet==SUCCESS)
		printf("address=%d (%d,%d)\n",iSearchedIndex,tHashTable.ptElement[iSearchedIndex].Key,tHashTable.ptElement[iSearchedIndex].iOrd);
	else
		printf("û�ҵ�\n");
	
	/*�����ϣ���в����ڵļ�¼*/
	iRet=InsertHash(&tHashTable,&atRecord[i]); // �����N-1����¼// �ؽ���ϣ��
	if(iRet==UNSUCCESS) // ʧ�ܱ�ʾ�ؽ��˹�ϣ��
		iRet=InsertHash(&tHashTable,&atRecord[i]); // �ؽ���ϣ������²���
	printf("����ϣ��ַ��˳������ؽ���Ĺ�ϣ��:\n");
	TraverseHash(&tHashTable);

	/*�ٴβ���*/
	printf("����������Ҽ�¼�Ĺؼ���: ");
	scanf("%d",&Key);
	iRet=SearchHash(&tHashTable,&Key,&iSearchedIndex,&iConflictCnt);
	if(iRet==SUCCESS)
		printf("address=%d (%d,%d)\n",iSearchedIndex,tHashTable.ptElement[iSearchedIndex].Key,tHashTable.ptElement[iSearchedIndex].iOrd);
	else
		printf("û�ҵ�\n");
	
	DestroyHashTable(&tHashTable);

	return 0;
}


/*****************************************************************************
-Fuction		: SearchHash
-Description	: 
// �ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���Ϊi_pKey��Ԫ�أ������ҳɹ���
// ��o_piSearchedIndexָʾ��������Ԫ���ڱ���λ�ã�������SUCCESS��
������o_piSearchedIndexָʾ����λ�ã�������UNSUCCESS
// o_piConflictCnt���ԼƳ�ͻ���������ֵ���㣬���������ʱ�ο�


�������岽��
1. �ڹ�ϣ���Ͻ��в��ҵĹ��̺Ϲ�ϣ���Ĺ��̻���һ�¡�
2. ����Kֵ���������ʱ�趨�Ĺ�ϣ������ù�ϣ��ַ����
���д�λ����û�м�¼������Ҳ��ɹ�������ȽϹؼ��֣�
���͸���ֵ��ȣ�����ҳɹ���
3. ����������ʱ�����Ĵ����ͻ�ķ�����"��һ��ַ"��ֱ
����ϣ����ĳ��λ��Ϊ"��"���߱��������¼�Ĺؼ��ֵ���
����ֵʱΪֹ��


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
	iSearchedIndex=Hash(i_pKey);// ��ù�ϣ��ַ
	while(i_ptHashTable->ptElement[iSearchedIndex].Key!=NULL_KEY&&i_ptHashTable->ptElement[iSearchedIndex].Key!=*i_pKey)
	{// ��λ�������м�¼�����ҹؼ��ֲ����
		iConflictCnt++;
		if(iConflictCnt<g_iHashLength)
		{
			Collision(&iSearchedIndex,iConflictCnt); // �����һ̽���ַp
		}
		else
		{
			break;
		}
	}
	if(i_ptHashTable->ptElement[iSearchedIndex].Key==*i_pKey)
	{
		iRet=SUCCESS;// ���ҳɹ���p���ش�������Ԫ��λ��
	}
	else
	{
		iRet=UNSUCCESS;// ���Ҳ��ɹ�(H.elem[p].key==NULL_KEY)��p���ص��ǲ���λ��
	}
	*o_piSearchedIndex=iSearchedIndex;
	*o_piConflictCnt =iConflictCnt;
	return iRet;
}

/*****************************************************************************
-Fuction		: Hash
-Description	: // һ���򵥵Ĺ�ϣ����(g_iHashLengthΪ����ȫ�ֱ���)
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
-Description	: // ���Ŷ�ַ�������ͻ// ����̽����ɢ��
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
-Description	:  // �������������һ���յĹ�ϣ��
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
	i_ptHashTable->iCount=0;// ��ǰԪ�ظ���Ϊ0
	i_ptHashTable->iSizeIndex=0;// ��ʼ�洢����Ϊhashsize[0]

	g_iHashLength=g_aiHashSize[0];
	i_ptHashTable->ptElement=(T_ElementType *)malloc(g_iHashLength*sizeof(T_ElementType));
	if(i_ptHashTable->ptElement!=NULL)
	{
		for(i=0;i<g_iHashLength;i++)
		{
			i_ptHashTable->ptElement[i].Key=NULL_KEY; // δ���¼�ı�־
		}
	}
	else
	{ // �洢����ʧ��
		exit(OVERFLOW);
	}
}

/*****************************************************************************
-Fuction		: DestroyHashTable
-Description	: // ��ʼ��������ϣ��H���ڡ�������������ٹ�ϣ��H
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
// ���Ҳ��ɹ�ʱ��������Ԫ��i_ptElement�����Ŷ�ַ��ϣ��H�У�
������OK��
// ����ͻ�����������ؽ���ϣ��

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
	if(SUCCESS==SearchHash(m_ptHashTable,&i_ptElement->Key,&iSearchedIndex,&iConflictCnt)) // ����������i_ptElement����ͬ�ؼ��ֵ�Ԫ��
	{
		iRet=DUPLICATE;
	}
	else if(iConflictCnt<g_aiHashSize[m_ptHashTable->iSizeIndex]/2) // ��ͻ����cδ�ﵽ���ޣ�(c�ķ�ֵ�ɵ�),���ڵķ�ֵʱ��ǰ������һ��
	{ // ����e
		memcpy(&m_ptHashTable->ptElement[iSearchedIndex],i_ptElement,sizeof(T_ElementType));
		m_ptHashTable->iCount++;
		iRet=SUCCESS;
	}
	else
	{
		RecreateHashTable(m_ptHashTable); // �ؽ���ϣ��
		iRet=UNSUCCESS;
	}
	return iRet;
}

/*****************************************************************************
-Fuction		: RecreateHashTable
-Description	:  // �ؽ���ϣ��
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
	printf("�ؽ���ϣ��\n");
	for(i=0;i<g_iHashLength;i++) // ����ԭ�е����ݵ�i_ptElement��
	{
		if(m_ptHashTable->ptElement[i].Key!=NULL_KEY) // �õ�Ԫ������
		{
			memcpy(ptTempElement,&m_ptHashTable->ptElement[i],sizeof(T_ElementType));
			ptTempElement++;
		}
	}
	
	m_ptHashTable->iCount=0;
	m_ptHashTable->iSizeIndex++;// ����洢����

	g_iHashLength=g_aiHashSize[m_ptHashTable->iSizeIndex];
	//realloc�ǴӶ��Ϸ����ڴ��.������һ���ڴ�ռ�ʱ��realloc()��ͼֱ�ӴӶ����ִ�����ݺ������Щ�ֽ��л�ø��ӵ��ֽ�
	ptTempElement=(T_ElementType *)realloc(m_ptHashTable->ptElement,g_iHashLength*sizeof(T_ElementType));//�·�����ڴ��СΪg_iHashLength��������ptElementָ����ڴ��С
	if(NULL!=ptTempElement)
	{
		m_ptHashTable->ptElement =ptTempElement;//realloc������֤��������ڴ�ռ��ԭ�����ڴ�ռ䱣��ͬһ�ڴ��ַ
		for(i=0;i<g_iHashLength;i++)
			m_ptHashTable->ptElement[i].Key=NULL_KEY; // δ���¼�ı�־(��ʼ��)
		for(ptTempElement=ptElement;ptTempElement<ptElement+iCount;ptTempElement++) // ��ԭ�е����ݰ����µı����뵽�ؽ��Ĺ�ϣ����
			InsertHash(m_ptHashTable,ptTempElement);
	}
	else
	{
		exit(OVERFLOW); // �洢����ʧ��
	}
}

/*****************************************************************************
-Fuction		: TraverseHash
-Description	:  // ����ϣ��ַ��˳�������ϣ��
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
	printf("��ϣ��ַ0��%d\n",g_iHashLength-1);
	for(i=0;i<g_iHashLength;i++)
		if(i_ptHashTable->ptElement[i].Key!=NULL_KEY) // ������
			printf("address=%d (%d,%d)\n",i,i_ptHashTable->ptElement[i].Key,i_ptHashTable->ptElement[i].iOrd);
}

