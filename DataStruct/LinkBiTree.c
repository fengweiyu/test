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

#define ClearLinkBiTree 	DestroyLinkBiTree 	// 清空二叉树和销毁二叉树的操作一样
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
	printf("构造空二叉树后,树空否？%d(0:是1:否)树的深度=%d\n",IsLinkBiTreeEmpty(ptLinkBiTree),GetLinkBiTreeDepth(ptLinkBiTree));
	cData=GetLinkBiTreeRootData(ptLinkBiTree);
	if(cData!=NIL)
	printf("二叉树的根为%c\r\n",cData);
	else
	printf("树空，无根\n");
	printf("请先序输入二叉树(如:ab三个空格表示a为根结点,b为左子树的二叉树)\n");
	CreateLinkBiTree(&ptLinkBiTree);
	printf("构造二叉树后,树空否？%d(0:是1:否)树的深度=%d\n",IsLinkBiTreeEmpty(ptLinkBiTree),GetLinkBiTreeDepth(ptLinkBiTree));
	cData=GetLinkBiTreeRootData(ptLinkBiTree);
	if(cData!=NIL)
	printf("二叉树的根为%c\r\n",cData);
	else
	printf("树空，无根\n");
	printf("中序递归遍历二叉树:\n");
	InOrderTraverseLinkBiTree(ptLinkBiTree);
	printf("\n后序递归遍历二叉树:\n");
	PostOrderTraverseLinkBiTree(ptLinkBiTree);

	printf("\n请输入一个结点的值: ");
	scanf("%*c%c",&cData);//%*c吃掉回车符
	ptLinkBiTreeNode=GetLinkBiTreeNodePoint(ptLinkBiTree,cData); // p为e1的指针
	printf("结点的值为%c\n",GetLinkBiTreeNodeData(ptLinkBiTreeNode));
	printf("欲改变此结点的值，请输入新值: ");
	scanf("%*c%c%*c",&cData); // 后一个%*c吃掉回车符，%*c不赋值任何变量,为调用CreateBiTree()做准备
	AssignToLinkBiTreeNode(ptLinkBiTreeNode,cData);//"*"表示该输入项读入后不赋予任何变量，即跳过该输入值
	printf("层序遍历二叉树:\n");
	LevelOrderTraverseLinkBiTree(ptLinkBiTree);

	cOtherData=GetLinkBiTreeParentData(ptLinkBiTree,cData);
	if(cOtherData!=NIL)
	printf("%c的双亲是%c\n",cData,cOtherData);
	else
	printf("%c没有双亲\n",cData);
	cOtherData=GetLinkBiTreeLeftChildData(ptLinkBiTree,cData);
	if(cOtherData!=NIL)
	printf("%c的左孩子是%c\n",cData,cOtherData);
	else
	printf("%c没有左孩子\n",cData);
	cOtherData=GetLinkBiTreeRightChildData(ptLinkBiTree,cData);
	if(cOtherData!=NIL)
	printf("%c的右孩子是%c\n",cData,cOtherData);
	else
	printf("%c没有右孩子\n",cData);
	cOtherData=GetLinkBiTreeLeftSiblingData(ptLinkBiTree,cData);
	if(cOtherData!=NIL)
	printf("%c的左兄弟是%c\n",cData,cOtherData);
	else
	printf("%c没有左兄弟\n",cData);
	cOtherData=GetLinkBiTreeRightSiblingData(ptLinkBiTree,cData);
	if(cOtherData!=NIL)
	printf("%c的右兄弟是%c\n",cData,cOtherData);
	else
	printf("%c没有右兄弟\n",cData);

	
	InitLinkBiTree(&ptLinkBiTreeNoRightChild);
	printf("构造一个右子树为空的二叉树c:\n");
	printf("请先序输入二叉树(如:ab三个空格表示a为根结点,b为左子树的二叉树)\n");
	CreateLinkBiTree(&ptLinkBiTreeNoRightChild);
	printf("先序递归遍历二叉树c:\n");
	PreOrderTraverseLinkBiTree(ptLinkBiTreeNoRightChild);
	printf("\n层序遍历二叉树c:\n");
	LevelOrderTraverseLinkBiTree(ptLinkBiTreeNoRightChild);

	printf("树c插到树T中,请输入树T中树c的双亲结点   c为左(0)或右(1)子树: ");
	scanf("%*c%c,%d",&cData,&iLeftOrRight);	
	ptLinkBiTreeNode=GetLinkBiTreeNodePoint(ptLinkBiTree,cData);  // p是T中树c的双亲结点指针
	InsertChildInLinkBiTree(ptLinkBiTreeNode,iLeftOrRight,ptLinkBiTreeNoRightChild);
	printf("先序递归遍历二叉树:\n");
	PreOrderTraverseLinkBiTree(ptLinkBiTree);
	printf("\n中序非递归遍历二叉树:\n");
	UseStackInOrderTraverseLinkBiTree(ptLinkBiTree);
	
	printf("删除子树,请输入待删除子树的双亲结点    左(0)或右(1)子树: ");
	scanf("%*c%c,%d",&cData,&iLeftOrRight);	
	ptLinkBiTreeNode=GetLinkBiTreeNodePoint(ptLinkBiTree,cData); 
	DeleteChildInLinkBiTree(ptLinkBiTreeNode,iLeftOrRight);
	printf("先序递归遍历二叉树:\n");
	PreOrderTraverseLinkBiTree(ptLinkBiTree);
	printf("\n中序非递归遍历二叉树(另一种方法):\n");
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
-Description	: 按先序次序输入二叉树中结点的值(为字符型)
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
	if(cData==NIL)//Nil表示空(子)树
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
// 初始条件：二叉树T存在，Visit是对结点操作的应用函数
// 操作结果：层序递归遍历T(利用队列)，对每个结点调用函数Visit一次且仅一次
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
			EnterLinkQueue(&tLinkQueue,tQueueElement);//左右孩子入队后，如果该结点还有兄弟没处理，
		}//接下来处理的就是之前入队的兄弟结点
	}
	printf("\r\n");
}
/*****************************************************************************
-Fuction		: UseStackInOrderTraverseLinkBiTree
-Description	: // 中序遍历二叉树T的非递归算法(利用栈)，
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
		if(NULL!=tStackElement.ptData)//指针不为空一直入栈
		{
			PushSeqStack(&tSeqStack,&tStackElement);
			tStackElement.ptData=tStackElement.ptData->ptLeftChild;//先放左子树
		}
		else
		{//当左子树为空则出栈为左子树的父结点
			PopSeqStack(&tSeqStack,&tStackElement);//当为右孩子为空则出栈为根结点
			printf("%c ",tStackElement.ptData->cData);
		//当左子树时，右孩子为空不会被入栈
			tStackElement.ptData=tStackElement.ptData->ptRightChild;//当为根结点时右孩子入栈
		}
	}
	printf("\r\n");
}
/*****************************************************************************
-Fuction		: OptimizeUseStackInOrderTraverseLinkBiTree
-Description	: 先PUSH
// 中序遍历二叉树T的非递归算法(利用栈)，
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
	PushSeqStack(&tSeqStack,&tStackElement);//先PUSH
	while(0!=IsSeqStackEmpty(&tSeqStack))
	{
		while(0==GetSeqStackTopElement(&tSeqStack,&tStackElement)&&NULL!=tStackElement.ptData)
		{
			tStackElement.ptData=tStackElement.ptData->ptLeftChild;// 向左走到尽头,左优先
			PushSeqStack(&tSeqStack,&tStackElement);
		}
		PopSeqStack(&tSeqStack,&tStackElement);// 空指针退栈
		if(0!=IsSeqStackEmpty(&tSeqStack))// 访问结点，向右一步
		{//由于前面空指针退栈，再次出栈就是左孩子了
			PopSeqStack(&tSeqStack,&tStackElement);//当为右孩子为空前面有空出栈,
			printf("%c ",tStackElement.ptData->cData);//所以出栈为根结点
		//当左子树时，右孩子为空前面会出栈
			tStackElement.ptData=tStackElement.ptData->ptRightChild;//当为根结点时右孩子入栈
			PushSeqStack(&tSeqStack,&tStackElement);//当右孩子子树为空则访问右孩子，实现中序遍历
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
		iTreeDepth=0;// 空树深度为0
	}
	else
	{
		if(NULL==i_ptLinkBiTree->ptLeftChild)
		{
			iLeftTreeDepth=0;//就一个时就本身时，深度为1，后面就会要加一
		}
		else
		{
			iLeftTreeDepth=GetLinkBiTreeDepth(i_ptLinkBiTree->ptLeftChild);// 为左子树的深度
		}//求得子树的深度，需要加上本身的深度，所以后面也会要加一
		if(NULL==i_ptLinkBiTree->ptRightChild)
		{
			iRightTreeDepth=0;
		}
		else
		{
			iRightTreeDepth=GetLinkBiTreeDepth(i_ptLinkBiTree->ptRightChild);// 为右子树的深度
		}
		iTreeDepth=iLeftTreeDepth>iRightTreeDepth?iLeftTreeDepth+1:iRightTreeDepth+1;
		// T的深度为其左右子树的深度中的大者+1
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
-Description	: // 返回二叉树T中指向元素值为s的结点的指针
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
	if(NULL==i_ptLinkBiTree)// 非空树
	{
	}
	else
	{
		InitLinkQueue(&tLinkQueue);
		tEnterQueueElement.ptData=i_ptLinkBiTree;
		EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// 根指针入队
		while(0!=IsLinkQueueEmpty(&tLinkQueue))// 队不空// 出队
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
					EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// 入队左孩子
					//printf("1EnterLinkQueue:%c\r\n",tEnterQueueElement.ptData->cData);
				}
				if(NULL==tExitQueueElement.ptData->ptRightChild)
				{
				}
				else
				{
					tEnterQueueElement.ptData=tExitQueueElement.ptData->ptRightChild;
					EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// 入队右孩子
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
// 操作结果：若i_cData是T的非根结点，则返回它的双亲，否则返回“空”
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
		EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// 根指针入队
		while(0!=IsLinkQueueEmpty(&tLinkQueue))// 队不空// 出队
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
					EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// 入队左孩子
				}
				if(NULL==tExitQueueElement.ptData->ptRightChild)
				{
				}
				else
				{
					tEnterQueueElement.ptData=tExitQueueElement.ptData->ptRightChild;
					EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// 入队右孩子
				}
			}
		}
	}
	return cData;
}
/*****************************************************************************
-Fuction		: GetLinkBiTreeLeftChildData
-Description	: 
// 初始条件：二叉树存在，i_cData是树中某个结点数据。
操作结果：返回i_cData的左孩子。若i_cData无左孩子,则返回“空”
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
// 初始条件：二叉树存在，i_cData是树中某个结点数据。
操作结果：返回i_cData的左孩子。若i_cData无左孩子,则返回“空”
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
// 初始条件：二叉树存在，i_cData是树中某个结点数据。
操作结果：返回i_cData的左孩子。若i_cData无左孩子,则返回“空”
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
// 初始条件：二叉树存在，i_cData是树中某个结点数据。
操作结果：返回i_cData的左孩子。若i_cData无左孩子,则返回“空”
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
// 初始条件：二叉树T存在，i_ptLinkBiTreeNode指向T中某个结点，
i_iLeftOrRight为0或1，非空二叉树i_ptInsertLinkBiTree与T不相交且右子树为空
// 操作结果：根据i_iLeftOrRight为0或1，插入i_ptInsertLinkBiTree为T中
i_ptLinkBiTreeNode所指结点的左或右子树。i_ptLinkBiTreeNode所指结点的
// 原有左或右子树则成为i_ptInsertLinkBiTree的右子树
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
// 初始条件：二叉树T存在，i_ptLinkBiTreeNode指向T中某个结点，i_iLeftOrRight为0或1
// 操作结果：根据i_iLeftOrRight为0或1，删除T中i_ptLinkBiTreeNode所指结点的左或右子树
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




