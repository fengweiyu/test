/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SequenceStack.c
* Description		: 	SequenceStack operation center
* Created			: 	2017.04.22.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"

typedef struct StackElement
{
	T_LinkBiTreeNode *ptData;
	
}T_StackElement,*PT_StackElement;
typedef struct SeqStack
{
	T_StackElement *ptBase; 
	T_StackElement *ptTop; 
	int iLen;
}T_SeqStack,*PT_SeqStack;

#define MAX_STACK_LENGTH				100
#define INCREMENT_STACK_LENGTH		(2)

/*****************************************************************************
-Fuction		: InitStack
-Description	: InitStack
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int InitSeqStack(T_SeqStack *i_ptSeqStack)
{
	int iRet=-1;
	i_ptSeqStack->ptBase=(T_StackElement *)malloc(MAX_STACK_LENGTH*sizeof(T_StackElement));
	if(NULL==i_ptSeqStack->ptBase)
	{
		iRet=-1;
		printf("mallocFail,InitStack err");
		exit(-1);
	}
	else
	{
		i_ptSeqStack->ptTop=i_ptSeqStack->ptBase;
		i_ptSeqStack->iLen=MAX_STACK_LENGTH;
		iRet=0;
	}
	return iRet;
}

/*****************************************************************************
-Fuction		: Push
-Description	: Push
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int PushSeqStack(T_SeqStack *i_ptSeqStack,T_StackElement *i_ptStackElement)
{
	int iRet=-1;
	if((i_ptSeqStack->ptTop-i_ptSeqStack->ptBase)==i_ptSeqStack->iLen)
	{//׷���ڴ棬���ص�ַ�������µģ�����ԭ�������ݱ��ֲ���(�´��)
		i_ptSeqStack->ptBase=(T_StackElement *)realloc(i_ptSeqStack->ptBase,(i_ptSeqStack->iLen+INCREMENT_STACK_LENGTH)*
							sizeof(T_StackElement));
		if(NULL==i_ptSeqStack->ptBase)
		{
			iRet=-1;
			printf("StackFull,ReallocFail,Push err");
			exit(-1);
		}
		else
		{//�����ڴ��ַ���ܻ�䣬����ԭ�ȵ���
			i_ptSeqStack->ptTop=i_ptSeqStack->ptBase+i_ptSeqStack->iLen;
			i_ptSeqStack->iLen=i_ptSeqStack->iLen+INCREMENT_STACK_LENGTH;
		}
	}
	else
	{
	}
	memcpy(i_ptSeqStack->ptTop,i_ptStackElement,sizeof(T_StackElement));
	i_ptSeqStack->ptTop++;
	iRet=0;
	return iRet;
}

/*****************************************************************************
-Fuction		: Pop
-Description	: Pop
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int PopSeqStack(T_SeqStack *i_ptSeqStack,T_StackElement *o_ptStackElement)
{
	int iRet=-1;
	if(i_ptSeqStack->ptTop==i_ptSeqStack->ptBase)
	{
		iRet=-1;
		printf("StackEmpty,Pop err");
	}
	else
	{
		i_ptSeqStack->ptTop--;
		memcpy(o_ptStackElement,i_ptSeqStack->ptTop,sizeof(T_StackElement));
		iRet=0;
	}
	return iRet;
}


/*****************************************************************************
-Fuction		: SeqStackEmpty
-Description	: SeqStackEmpty
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int IsSeqStackEmpty(T_SeqStack *i_ptSeqStack)
{
	int iRet=-1;
	if(i_ptSeqStack->ptTop==i_ptSeqStack->ptBase)
	{
		iRet=0;
		//printf("StackEmpty\r\n");
	}
	else
	{
		iRet=-1;
	}
	return iRet;
}


/*****************************************************************************
-Fuction		: GetSeqStackTopElement
-Description	: 
// ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int GetSeqStackTopElement(T_SeqStack *i_ptSeqStack,T_StackElement *o_ptStackElement)
{
	int iRet=-1;
	if(i_ptSeqStack->ptTop>i_ptSeqStack->ptBase)
	{
		 memcpy(o_ptStackElement,i_ptSeqStack->ptTop-1,sizeof(T_StackElement));
		 iRet=0;
	}
	else
	{
		iRet=-1;
	}
	return iRet;
}

