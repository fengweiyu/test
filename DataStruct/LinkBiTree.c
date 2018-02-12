/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	LinkBiTree.c
* Description		: 	LinkBiTree operation center
* Created			: 	2017.05.11.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "LinkBiTree.h"
#include "LinkQueue.c"
#include "SequenceStack.c"





static void InitLinkBiTree(T_LinkBiTreeNode **i_pptLinkBiTree);
static void DestroyLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTree);
static int IsLinkBiTreeEmpty(T_LinkBiTreeNode *i_ptLinkBiTree);
static int GetLinkBiTreeDepth(T_LinkBiTreeNode *i_ptLinkBiTree);
static char GetLinkBiTreeRootData(T_LinkBiTreeNode *i_ptLinkBiTree);
static char GetLinkBiTreeNodeData(T_LinkBiTreeNode *i_ptLinkBiTreeNode);
static void AssignToLinkBiTreeNode(T_LinkBiTreeNode *i_ptLinkBiTreeNode,char i_cData);

static char GetLinkBiTreeParentData(T_LinkBiTreeNode *i_ptLinkBiTree,char i_cData);
static char GetLinkBiTreeLeftChildData(T_LinkBiTreeNode *i_ptLinkBiTree,char i_cData);
static char GetLinkBiTreeRightChildData(T_LinkBiTreeNode *i_ptLinkBiTree,char i_cData);
static char GetLinkBiTreeLeftSiblingData(T_LinkBiTreeNode *i_ptLinkBiTree,char i_cData);
static char GetLinkBiTreeRightSiblingData(T_LinkBiTreeNode *i_ptLinkBiTree,char i_cData);


static int CreateLinkBiTree(T_LinkBiTreeNode **i_pptLinkBiTree);
static T_LinkBiTreeNode *GetLinkBiTreeNodePoint(T_LinkBiTreeNode *i_ptLinkBiTree,char i_cData);
static int InsertChildInLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTreeNode,int i_iLeftOrRight,T_LinkBiTreeNode *i_ptInsertLinkBiTree);
static int DeleteChildInLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTreeNode,int i_iLeftOrRight);
static void PreOrderTraverseLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTree);
static void InOrderTraverseLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTree);
static void PostOrderTraverseLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTree);
static void LevelOrderTraverseLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTree);
static void UseStackInOrderTraverseLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTree);
static void OptimizeUseStackInOrderTraverseLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTree);

#define ClearLinkBiTree 	DestroyLinkBiTree 	// ��ն����������ٶ������Ĳ���һ��
#define 	NIL 	' '
/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_LinkBiTreeNode *ptLinkBiTree=NULL;	
	T_LinkBiTreeNode *ptLinkBiTreeNoRightChild=NULL;
	T_LinkBiTreeNode *ptLinkBiTreeNode=NULL;
	int iLeftOrRight=0;
	char cData;
	char cOtherData;
	InitLinkBiTree(&ptLinkBiTree);
	printf("����ն�������,���շ�%d(0:��1:��)�������=%d\n",IsLinkBiTreeEmpty(ptLinkBiTree),GetLinkBiTreeDepth(ptLinkBiTree));
	cData=GetLinkBiTreeRootData(ptLinkBiTree);
	if(cData!=NIL)
	printf("�������ĸ�Ϊ%c\r\n",cData);
	else
	printf("���գ��޸�\n");
	printf("���������������(��:ab�����ո��ʾaΪ�����,bΪ�������Ķ�����)\n");
	CreateLinkBiTree(&ptLinkBiTree);
	printf("�����������,���շ�%d(0:��1:��)�������=%d\n",IsLinkBiTreeEmpty(ptLinkBiTree),GetLinkBiTreeDepth(ptLinkBiTree));
	cData=GetLinkBiTreeRootData(ptLinkBiTree);
	if(cData!=NIL)
	printf("�������ĸ�Ϊ%c\r\n",cData);
	else
	printf("���գ��޸�\n");
	printf("����ݹ����������:\n");
	InOrderTraverseLinkBiTree(ptLinkBiTree);
	printf("\n����ݹ����������:\n");
	PostOrderTraverseLinkBiTree(ptLinkBiTree);

	printf("\n������һ������ֵ: ");
	scanf("%*c%c",&cData);//%*c�Ե��س���
	ptLinkBiTreeNode=GetLinkBiTreeNodePoint(ptLinkBiTree,cData); // pΪe1��ָ��
	printf("����ֵΪ%c\n",GetLinkBiTreeNodeData(ptLinkBiTreeNode));
	printf("���ı�˽���ֵ����������ֵ: ");
	scanf("%*c%c%*c",&cData); // ��һ��%*c�Ե��س�����%*c����ֵ�κα���,Ϊ����CreateBiTree()��׼��
	AssignToLinkBiTreeNode(ptLinkBiTreeNode,cData);//"*"��ʾ�����������󲻸����κα�����������������ֵ
	printf("�������������:\n");
	LevelOrderTraverseLinkBiTree(ptLinkBiTree);

	cOtherData=GetLinkBiTreeParentData(ptLinkBiTree,cData);
	if(cOtherData!=NIL)
	printf("%c��˫����%c\n",cData,cOtherData);
	else
	printf("%cû��˫��\n",cData);
	cOtherData=GetLinkBiTreeLeftChildData(ptLinkBiTree,cData);
	if(cOtherData!=NIL)
	printf("%c��������%c\n",cData,cOtherData);
	else
	printf("%cû������\n",cData);
	cOtherData=GetLinkBiTreeRightChildData(ptLinkBiTree,cData);
	if(cOtherData!=NIL)
	printf("%c���Һ�����%c\n",cData,cOtherData);
	else
	printf("%cû���Һ���\n",cData);
	cOtherData=GetLinkBiTreeLeftSiblingData(ptLinkBiTree,cData);
	if(cOtherData!=NIL)
	printf("%c�����ֵ���%c\n",cData,cOtherData);
	else
	printf("%cû�����ֵ�\n",cData);
	cOtherData=GetLinkBiTreeRightSiblingData(ptLinkBiTree,cData);
	if(cOtherData!=NIL)
	printf("%c�����ֵ���%c\n",cData,cOtherData);
	else
	printf("%cû�����ֵ�\n",cData);

	
	InitLinkBiTree(&ptLinkBiTreeNoRightChild);
	printf("����һ��������Ϊ�յĶ�����c:\n");
	printf("���������������(��:ab�����ո��ʾaΪ�����,bΪ�������Ķ�����)\n");
	CreateLinkBiTree(&ptLinkBiTreeNoRightChild);
	printf("����ݹ����������c:\n");
	PreOrderTraverseLinkBiTree(ptLinkBiTreeNoRightChild);
	printf("\n�������������c:\n");
	LevelOrderTraverseLinkBiTree(ptLinkBiTreeNoRightChild);

	printf("��c�嵽��T��,��������T����c��˫�׽��   cΪ��(0)����(1)����: ");
	scanf("%*c%c,%d",&cData,&iLeftOrRight);	
	ptLinkBiTreeNode=GetLinkBiTreeNodePoint(ptLinkBiTree,cData);  // p��T����c��˫�׽��ָ��
	InsertChildInLinkBiTree(ptLinkBiTreeNode,iLeftOrRight,ptLinkBiTreeNoRightChild);
	printf("����ݹ����������:\n");
	PreOrderTraverseLinkBiTree(ptLinkBiTree);
	printf("\n����ǵݹ����������:\n");
	UseStackInOrderTraverseLinkBiTree(ptLinkBiTree);
	
	printf("ɾ������,�������ɾ��������˫�׽��    ��(0)����(1)����: ");
	scanf("%*c%c,%d",&cData,&iLeftOrRight);	
	ptLinkBiTreeNode=GetLinkBiTreeNodePoint(ptLinkBiTree,cData); 
	DeleteChildInLinkBiTree(ptLinkBiTreeNode,iLeftOrRight);
	printf("����ݹ����������:\n");
	PreOrderTraverseLinkBiTree(ptLinkBiTree);
	printf("\n����ǵݹ����������(��һ�ַ���):\n");
	OptimizeUseStackInOrderTraverseLinkBiTree(ptLinkBiTree);
	DestroyLinkBiTree(ptLinkBiTree);
}





/*****************************************************************************
-Fuction		: InitLinkBiTree
-Description	: InitLinkBiTree
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void InitLinkBiTree(T_LinkBiTreeNode **i_pptLinkBiTree)
{
	*i_pptLinkBiTree=NULL;
}
/*****************************************************************************
-Fuction		: CreateLinkBiTree
-Description	: �������������������н���ֵ(Ϊ�ַ���)
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int CreateLinkBiTree(T_LinkBiTreeNode **i_pptLinkBiTree)
{
	int iRet=0;
	char cData;
	scanf("%c",&cData);
	if(cData==NIL)//Nil��ʾ��(��)��
	{
		*i_pptLinkBiTree=NULL;
	}
	else
	{
		*i_pptLinkBiTree=(T_LinkBiTreeNode *)malloc(sizeof(T_LinkBiTreeNode));
		if(NULL==*i_pptLinkBiTree)
		{
			printf("CreateLinkBiTree malloc err\r\n");
			iRet=-1;
		}
		else
		{
			(*i_pptLinkBiTree)->cData=cData;
			CreateLinkBiTree(&(*i_pptLinkBiTree)->ptLeftChild);
			CreateLinkBiTree(&(*i_pptLinkBiTree)->ptRightChild);
		}
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: DestroyLinkBiTree
-Description	: DestroyLinkBiTree
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void DestroyLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTree)
{
	if(NULL==i_ptLinkBiTree)
	{
	}
	else
	{
		if(NULL==i_ptLinkBiTree->ptLeftChild)
		{
		}
		else
		{
			DestroyLinkBiTree(i_ptLinkBiTree->ptLeftChild);
		}
		if(NULL==i_ptLinkBiTree->ptRightChild)
		{
		}
		else
		{
			DestroyLinkBiTree(i_ptLinkBiTree->ptRightChild);
		}
		free(i_ptLinkBiTree);
		i_ptLinkBiTree=NULL;
	}
}
/*****************************************************************************
-Fuction		: PreOrderTraverseLinkBiTree
-Description	: PreOrderTraverseLinkBiTree
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void PreOrderTraverseLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTree)
{
	if(NULL==i_ptLinkBiTree)
	{
	}
	else
	{
		printf("%c ",i_ptLinkBiTree->cData);
		PreOrderTraverseLinkBiTree(i_ptLinkBiTree->ptLeftChild);
		PreOrderTraverseLinkBiTree(i_ptLinkBiTree->ptRightChild);
	}
}
/*****************************************************************************
-Fuction		: InOrderTraverseLinkBiTree
-Description	: InOrderTraverseLinkBiTree
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void InOrderTraverseLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTree)
{
	if(NULL==i_ptLinkBiTree)
	{
	}
	else
	{
		InOrderTraverseLinkBiTree(i_ptLinkBiTree->ptLeftChild);
		printf("%c ",i_ptLinkBiTree->cData);
		InOrderTraverseLinkBiTree(i_ptLinkBiTree->ptRightChild);
	}
}
/*****************************************************************************
-Fuction		: PostOrderTraverseLinkBiTree
-Description	: PostOrderTraverseLinkBiTree
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void PostOrderTraverseLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTree)
{
	if(NULL==i_ptLinkBiTree)
	{
	}
	else
	{
		PostOrderTraverseLinkBiTree(i_ptLinkBiTree->ptLeftChild);
		PostOrderTraverseLinkBiTree(i_ptLinkBiTree->ptRightChild);
		printf("%c ",i_ptLinkBiTree->cData);
	}
}
/*****************************************************************************
-Fuction		: LevelOrderTraverseLinkBiTree
-Description	: 
// ��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú���
// �������������ݹ����T(���ö���)����ÿ�������ú���Visitһ���ҽ�һ��
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void LevelOrderTraverseLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTree)
{
	T_LinkQueue tLinkQueue={0};
	T_LinkBiTreeNode *ptBiTreeNode=NULL;
	T_QueueDataElement tQueueElement;
	InitLinkQueue(&tLinkQueue);
	tQueueElement.ptData=i_ptLinkBiTree;
	EnterLinkQueue(&tLinkQueue,tQueueElement);
	while(0!=IsLinkQueueEmpty(&tLinkQueue))
	{
		ExitLinkQueue(&tLinkQueue,&tQueueElement);
		printf("%c ",tQueueElement.ptData->cData);
		ptBiTreeNode=tQueueElement.ptData;
		if(NULL==ptBiTreeNode->ptLeftChild)
		{
		}
		else
		{
			tQueueElement.ptData=ptBiTreeNode->ptLeftChild;
			EnterLinkQueue(&tLinkQueue,tQueueElement);
		}
		if(NULL==ptBiTreeNode->ptRightChild)
		{
		}
		else
		{
			tQueueElement.ptData=ptBiTreeNode->ptRightChild;
			EnterLinkQueue(&tLinkQueue,tQueueElement);//���Һ�����Ӻ�����ý�㻹���ֵ�û����
		}//����������ľ���֮ǰ��ӵ��ֵܽ��
	}
	printf("\r\n");
}
/*****************************************************************************
-Fuction		: UseStackInOrderTraverseLinkBiTree
-Description	: // �������������T�ķǵݹ��㷨(����ջ)��
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void UseStackInOrderTraverseLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTree)
{
	T_SeqStack tSeqStack={0};
	T_StackElement tStackElement={0};
	InitSeqStack(&tSeqStack);
	tStackElement.ptData=i_ptLinkBiTree;
	while(NULL!=tStackElement.ptData||0!=IsSeqStackEmpty(&tSeqStack))
	{
		if(NULL!=tStackElement.ptData)//ָ�벻Ϊ��һֱ��ջ
		{
			PushSeqStack(&tSeqStack,&tStackElement);
			tStackElement.ptData=tStackElement.ptData->ptLeftChild;//�ȷ�������
		}
		else
		{//��������Ϊ�����ջΪ�������ĸ����
			PopSeqStack(&tSeqStack,&tStackElement);//��Ϊ�Һ���Ϊ�����ջΪ�����
			printf("%c ",tStackElement.ptData->cData);
		//��������ʱ���Һ���Ϊ�ղ��ᱻ��ջ
			tStackElement.ptData=tStackElement.ptData->ptRightChild;//��Ϊ�����ʱ�Һ�����ջ
		}
	}
	printf("\r\n");
}
/*****************************************************************************
-Fuction		: OptimizeUseStackInOrderTraverseLinkBiTree
-Description	: ��PUSH
// �������������T�ķǵݹ��㷨(����ջ)��
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void OptimizeUseStackInOrderTraverseLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTree)
{
	T_SeqStack tSeqStack={0};
	T_StackElement tStackElement={0};
	InitSeqStack(&tSeqStack);
	tStackElement.ptData=i_ptLinkBiTree;
	PushSeqStack(&tSeqStack,&tStackElement);//��PUSH
	while(0!=IsSeqStackEmpty(&tSeqStack))
	{
		while(0==GetSeqStackTopElement(&tSeqStack,&tStackElement)&&NULL!=tStackElement.ptData)
		{
			tStackElement.ptData=tStackElement.ptData->ptLeftChild;// �����ߵ���ͷ,������
			PushSeqStack(&tSeqStack,&tStackElement);
		}
		PopSeqStack(&tSeqStack,&tStackElement);// ��ָ����ջ
		if(0!=IsSeqStackEmpty(&tSeqStack))// ���ʽ�㣬����һ��
		{//����ǰ���ָ����ջ���ٴγ�ջ����������
			PopSeqStack(&tSeqStack,&tStackElement);//��Ϊ�Һ���Ϊ��ǰ���пճ�ջ,
			printf("%c ",tStackElement.ptData->cData);//���Գ�ջΪ�����
		//��������ʱ���Һ���Ϊ��ǰ����ջ
			tStackElement.ptData=tStackElement.ptData->ptRightChild;//��Ϊ�����ʱ�Һ�����ջ
			PushSeqStack(&tSeqStack,&tStackElement);//���Һ�������Ϊ��������Һ��ӣ�ʵ���������
		}
		else
		{
		}
	}
	printf("\r\n");
}

/*****************************************************************************
-Fuction		: IsLinkBiTreeEmpty
-Description	: IsLinkBiTreeEmpty
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int IsLinkBiTreeEmpty(T_LinkBiTreeNode *i_ptLinkBiTree)
{
	int iRet=0;
	if(NULL==i_ptLinkBiTree)
	{
	}
	else
	{
		iRet=-1;
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: GetLinkBiTreeDepth
-Description	: GetLinkBiTreeDepth
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int GetLinkBiTreeDepth(T_LinkBiTreeNode *i_ptLinkBiTree)
{
	int iTreeDepth=0;
	int iLeftTreeDepth=0,iRightTreeDepth=0;
	if(NULL==i_ptLinkBiTree)
	{
		iTreeDepth=0;// �������Ϊ0
	}
	else
	{
		if(NULL==i_ptLinkBiTree->ptLeftChild)
		{
			iLeftTreeDepth=0;//��һ��ʱ�ͱ���ʱ�����Ϊ1������ͻ�Ҫ��һ
		}
		else
		{
			iLeftTreeDepth=GetLinkBiTreeDepth(i_ptLinkBiTree->ptLeftChild);// Ϊ�����������
		}//�����������ȣ���Ҫ���ϱ������ȣ����Ժ���Ҳ��Ҫ��һ
		if(NULL==i_ptLinkBiTree->ptRightChild)
		{
			iRightTreeDepth=0;
		}
		else
		{
			iRightTreeDepth=GetLinkBiTreeDepth(i_ptLinkBiTree->ptRightChild);// Ϊ�����������
		}
		iTreeDepth=iLeftTreeDepth>iRightTreeDepth?iLeftTreeDepth+1:iRightTreeDepth+1;
		// T�����Ϊ����������������еĴ���+1
	}

	return iTreeDepth;
}
/*****************************************************************************
-Fuction		: GetLinkBiTreeRootData
-Description	: GetLinkBiTreeRootData
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static char GetLinkBiTreeRootData(T_LinkBiTreeNode *i_ptLinkBiTree)
{
	char cData;
	if(0==IsLinkBiTreeEmpty(i_ptLinkBiTree))
	{
		cData=NIL;
	}
	else
	{
		cData=i_ptLinkBiTree->cData;
	}
	return cData;
}
/*****************************************************************************
-Fuction		: GetLinkBiTreeNodeData
-Description	: GetLinkBiTreeNodeData
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static char GetLinkBiTreeNodeData(T_LinkBiTreeNode *i_ptLinkBiTreeNode)
{
	return i_ptLinkBiTreeNode->cData;
}
/*****************************************************************************
-Fuction		: AssignToLinkBiTreeNode
-Description	: AssignToLinkBiTreeNode
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void AssignToLinkBiTreeNode(T_LinkBiTreeNode *i_ptLinkBiTreeNode,char i_cData)
{
	i_ptLinkBiTreeNode->cData=i_cData;
}
/*****************************************************************************
-Fuction		: GetLinkBiTreeNodePoint
-Description	: // ���ض�����T��ָ��Ԫ��ֵΪs�Ľ���ָ��
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static T_LinkBiTreeNode *GetLinkBiTreeNodePoint(T_LinkBiTreeNode *i_ptLinkBiTree,char i_cData)
{
	T_LinkQueue tLinkQueue={0};
	T_QueueDataElement tExitQueueElement={0};
	T_QueueDataElement tEnterQueueElement={0};
	T_LinkBiTreeNode *ptLinkBiTreeNode=NULL;
	if(NULL==i_ptLinkBiTree)// �ǿ���
	{
	}
	else
	{
		InitLinkQueue(&tLinkQueue);
		tEnterQueueElement.ptData=i_ptLinkBiTree;
		EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// ��ָ�����
		while(0!=IsLinkQueueEmpty(&tLinkQueue))// �Ӳ���// ����
		{
			ExitLinkQueue(&tLinkQueue,&tExitQueueElement);
			//printf("EnterData:%c\r\n",tExitQueueElement.ptData->cData);
			if(i_cData==tExitQueueElement.ptData->cData)
			{
				ptLinkBiTreeNode=tExitQueueElement.ptData;
				break;
			}
			else
			{
				if(NULL==tExitQueueElement.ptData->ptLeftChild)
				{
				}
				else
				{
					tEnterQueueElement.ptData=tExitQueueElement.ptData->ptLeftChild;
					EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// �������
					//printf("1EnterLinkQueue:%c\r\n",tEnterQueueElement.ptData->cData);
				}
				if(NULL==tExitQueueElement.ptData->ptRightChild)
				{
				}
				else
				{
					tEnterQueueElement.ptData=tExitQueueElement.ptData->ptRightChild;
					EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// ����Һ���
					//printf("2EnterLinkQueue:%c\r\n",tEnterQueueElement.ptData->cData);
				}
			}
		}
	}
	return ptLinkBiTreeNode;
}
/*****************************************************************************
-Fuction		: GetLinkBiTreeNodeParentData
-Description	: 
// �����������i_cData��T�ķǸ���㣬�򷵻�����˫�ף����򷵻ء��ա�
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static char GetLinkBiTreeParentData(T_LinkBiTreeNode *i_ptLinkBiTree,char i_cData)
{
	T_LinkQueue tLinkQueue={0};
	T_QueueDataElement tExitQueueElement;
	T_QueueDataElement tEnterQueueElement;
	char  cData=NIL;
	if(NULL==i_ptLinkBiTree)
	{
	}
	else
	{
		InitLinkQueue(&tLinkQueue);
		tEnterQueueElement.ptData=i_ptLinkBiTree;
		EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// ��ָ�����
		while(0!=IsLinkQueueEmpty(&tLinkQueue))// �Ӳ���// ����
		{
			ExitLinkQueue(&tLinkQueue,&tExitQueueElement);
			//printf("EnterParentData:%c\r\n",tExitQueueElement.ptData->cData);
			if(((NULL!=tExitQueueElement.ptData->ptLeftChild)&&(i_cData==tExitQueueElement.ptData->ptLeftChild->cData)) ||
			    ((NULL!=tExitQueueElement.ptData->ptRightChild)&&(i_cData==tExitQueueElement.ptData->ptRightChild->cData)))
			{
				cData=tExitQueueElement.ptData->cData;
				break;
			}
			else
			{
				if(NULL==tExitQueueElement.ptData->ptLeftChild)
				{
				}
				else
				{
					tEnterQueueElement.ptData=tExitQueueElement.ptData->ptLeftChild;
					EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// �������
				}
				if(NULL==tExitQueueElement.ptData->ptRightChild)
				{
				}
				else
				{
					tEnterQueueElement.ptData=tExitQueueElement.ptData->ptRightChild;
					EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// ����Һ���
				}
			}
		}
	}
	return cData;
}
/*****************************************************************************
-Fuction		: GetLinkBiTreeLeftChildData
-Description	: 
// ��ʼ���������������ڣ�i_cData������ĳ��������ݡ�
�������������i_cData�����ӡ���i_cData������,�򷵻ء��ա�
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static char GetLinkBiTreeLeftChildData(T_LinkBiTreeNode *i_ptLinkBiTree,char i_cData)
{
	T_LinkBiTreeNode *ptBiTreeNode=NULL;
	char  cData=NIL;
	if(NULL==i_ptLinkBiTree)
	{
	}
	else
	{
		ptBiTreeNode=GetLinkBiTreeNodePoint(i_ptLinkBiTree,i_cData);
		if(NULL!=ptBiTreeNode&&NULL!=ptBiTreeNode->ptLeftChild)
		{
			cData=ptBiTreeNode->ptLeftChild->cData;
		}
		else{
		}
	}
	return cData;
}
/*****************************************************************************
-Fuction		: GetLinkBiTreeRightChildData
-Description	: 
// ��ʼ���������������ڣ�i_cData������ĳ��������ݡ�
�������������i_cData�����ӡ���i_cData������,�򷵻ء��ա�
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static char GetLinkBiTreeRightChildData(T_LinkBiTreeNode *i_ptLinkBiTree,char i_cData)
{
	T_LinkBiTreeNode *ptBiTreeNode=NULL;
	char  cData=NIL;
	if(NULL==i_ptLinkBiTree)
	{
	}
	else
	{
		ptBiTreeNode=GetLinkBiTreeNodePoint(i_ptLinkBiTree,i_cData);
		if(NULL!=ptBiTreeNode&&NULL!=ptBiTreeNode->ptRightChild)
		{
			cData=ptBiTreeNode->ptRightChild->cData;
		}
		else{
		}
	}
	return cData;
}
/*****************************************************************************
-Fuction		: GetLinkBiTreeLeftSiblingData
-Description	: 
// ��ʼ���������������ڣ�i_cData������ĳ��������ݡ�
�������������i_cData�����ӡ���i_cData������,�򷵻ء��ա�
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static char GetLinkBiTreeLeftSiblingData(T_LinkBiTreeNode *i_ptLinkBiTree,char i_cData)
{
	T_LinkBiTreeNode *ptBiTreeNode=NULL;
	char cParentData=NIL;
	char  cData=NIL;
	if(NULL==i_ptLinkBiTree)
	{
	}
	else
	{
		cParentData=GetLinkBiTreeParentData(i_ptLinkBiTree,i_cData);
		if(NIL==cParentData)
		{
		}
		else
		{
			ptBiTreeNode=GetLinkBiTreeNodePoint(i_ptLinkBiTree,cParentData);
			if(NULL!=ptBiTreeNode&&NULL!=ptBiTreeNode->ptLeftChild
			    &&NULL!=ptBiTreeNode->ptRightChild &&i_cData==ptBiTreeNode->ptRightChild->cData)
			{
				cData=ptBiTreeNode->ptLeftChild->cData;
			}
			else{
			}
		}
	}
	return cData;
}
/*****************************************************************************
-Fuction		: GetLinkBiTreeRightSiblingData
-Description	: 
// ��ʼ���������������ڣ�i_cData������ĳ��������ݡ�
�������������i_cData�����ӡ���i_cData������,�򷵻ء��ա�
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static char GetLinkBiTreeRightSiblingData(T_LinkBiTreeNode *i_ptLinkBiTree,char i_cData)
{
	T_LinkBiTreeNode *ptBiTreeNode=NULL;
	char cParentData=NIL;
	char  cData=NIL;
	if(NULL==i_ptLinkBiTree)
	{
	}
	else
	{
		cParentData=GetLinkBiTreeParentData(i_ptLinkBiTree,i_cData);
		if(NIL==cParentData)
		{
		}
		else
		{
			ptBiTreeNode=GetLinkBiTreeNodePoint(i_ptLinkBiTree,cParentData);
			if(NULL!=ptBiTreeNode&&NULL!=ptBiTreeNode->ptLeftChild
			    &&NULL!=ptBiTreeNode->ptRightChild &&i_cData==ptBiTreeNode->ptLeftChild->cData)
			{
				cData=ptBiTreeNode->ptRightChild->cData;
			}
			else{
			}
		}
	}
	return cData;
}
/*****************************************************************************
-Fuction		: InsertChildInLinkBiTree
-Description	: 
// ��ʼ������������T���ڣ�i_ptLinkBiTreeNodeָ��T��ĳ����㣬
i_iLeftOrRightΪ0��1���ǿն�����i_ptInsertLinkBiTree��T���ཻ��������Ϊ��
// �������������i_iLeftOrRightΪ0��1������i_ptInsertLinkBiTreeΪT��
i_ptLinkBiTreeNode��ָ���������������i_ptLinkBiTreeNode��ָ����
// ԭ��������������Ϊi_ptInsertLinkBiTree��������
-Input			: 
-Output 		: 
-Return 		: -1 false         0 true
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int InsertChildInLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTreeNode,int i_iLeftOrRight,T_LinkBiTreeNode *i_ptInsertLinkBiTree)
{
	int iRet=-1;
	if(NULL==i_ptLinkBiTreeNode)
	{
		iRet=-1;
	}
	else
	{
		iRet=0;
		if(0==i_iLeftOrRight)
		{
			i_ptInsertLinkBiTree->ptRightChild=i_ptLinkBiTreeNode->ptLeftChild;
			i_ptLinkBiTreeNode->ptLeftChild=i_ptInsertLinkBiTree;
		}
		else if(1==i_iLeftOrRight)
		{
			i_ptInsertLinkBiTree->ptRightChild=i_ptLinkBiTreeNode->ptRightChild;
			i_ptLinkBiTreeNode->ptRightChild=i_ptInsertLinkBiTree;
		}
		else
		{
			printf("UnknowChild:%d,InsertChildInLinkBiTree err\r\n",i_iLeftOrRight);
			iRet=-1;
		}
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: InsertChildInLinkBiTree
-Description	: 
// ��ʼ������������T���ڣ�i_ptLinkBiTreeNodeָ��T��ĳ����㣬i_iLeftOrRightΪ0��1
// �������������i_iLeftOrRightΪ0��1��ɾ��T��i_ptLinkBiTreeNode��ָ�������������
-Input			: 
-Output 		: 
-Return 		: -1 false         0 true
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/15	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int DeleteChildInLinkBiTree(T_LinkBiTreeNode *i_ptLinkBiTreeNode,int i_iLeftOrRight)
{
	int iRet=-1;
	if(NULL==i_ptLinkBiTreeNode)
	{
		iRet=-1;
	}
	else
	{
		iRet=0;
		if(0==i_iLeftOrRight)
		{
			ClearLinkBiTree(i_ptLinkBiTreeNode->ptLeftChild);
		}
		else if(1==i_iLeftOrRight)
		{
			ClearLinkBiTree(i_ptLinkBiTreeNode->ptRightChild);
		}
		else
		{
			printf("UnknowChild:%d,DeleteChildInLinkBiTree err\r\n",i_iLeftOrRight);
			iRet=-1;
		}
	}
	return iRet;
}




