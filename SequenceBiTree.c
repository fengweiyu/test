/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SeqBiTree.c
* Description		: 	SeqBiTree operation center
* Created			: 	2017.05.08.
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
#include "LinkQueue.c"

typedef struct SeqBiTreeElement
{
	//char cData;//NULL表示空元素也就是空结点
	int iData;//0表示空元素也就是空结点
}T_SeqBiTreeElement,*PT_SeqBiTreeElement;

typedef struct PositionInTree
{
	int iLevel;//元素处在的层次 从1开始
	int iOrder;//元素在本层中的序号  从1开始
}T_PositionInTree,*PT_PositionInTree;

#define MAX_SEQ_BINARY_TREE_LEN	100

static void InitSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree);
static void CreateSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree);
static void LevelOrderTraverseSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree);
static void PreOrderTraverseSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree);
static void InOrderTraverseSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree);
static void PostOrderTraverseSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree);
static T_SeqBiTreeElement GetSeqBiTreeElement(T_SeqBiTreeElement *i_ptSeqBiTree,T_PositionInTree *i_ptPos);
static int AssignToSeqBiTreeElement(T_SeqBiTreeElement *i_ptSeqBiTree,T_PositionInTree *i_ptPos,T_SeqBiTreeElement *i_ptValue);
static void PreOrderTraverseSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree);

static T_SeqBiTreeElement GetParentFromSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,T_SeqBiTreeElement *i_ptTreeElement);
static T_SeqBiTreeElement GetLeftChildFromSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,T_SeqBiTreeElement *i_ptTreeElement);
static T_SeqBiTreeElement GetRightChildFromSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,T_SeqBiTreeElement *i_ptTreeElement);
static T_SeqBiTreeElement GetLeftSiblingFromSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,T_SeqBiTreeElement *i_ptTreeElement);
static T_SeqBiTreeElement GetRightSiblingFromSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,T_SeqBiTreeElement *i_ptTreeElement);

static void PrintfSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree);
static void InsertChildInSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,T_SeqBiTreeElement *i_ptInsertNode,int i_iLeftOrRight,T_SeqBiTreeElement *i_ptInsertTree);
static int DeleteChildInSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,T_PositionInTree*i_ptDeleteNodePos,int i_iLeftOrRight);

#define ClearSeqBiTree 	InitSeqBiTree 	// 在顺序存储结构中，两函数完全一样
#define DestroySeqBiTree 	InitSeqBiTree		 // 在顺序存储结构中，两函数完全一样
#define NIL 0
static int IsSeqBiTreeEmpty(T_SeqBiTreeElement *i_ptSeqBiTree);
static int GetSeqBiTreeDepth(T_SeqBiTreeElement *i_ptSeqBiTree);
/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_SeqBiTreeElement atSeqBiTree[MAX_SEQ_BINARY_TREE_LEN]={0};
	T_SeqBiTreeElement atSeqBiTreeRightTreeNull[MAX_SEQ_BINARY_TREE_LEN]={0};
	T_PositionInTree tPos={0};
	T_SeqBiTreeElement tElement={0};
	T_SeqBiTreeElement tOtherElement={0};
	int iLeftOrRight;
	
	CreateSeqBiTree(atSeqBiTree);
	printf("建立二叉树后,树空否？%d(1:是0:否) 树的深度=%d\r\n",IsSeqBiTreeEmpty(atSeqBiTree),GetSeqBiTreeDepth(atSeqBiTree));
	printf("层序遍历二叉树:");
	LevelOrderTraverseSeqBiTree(atSeqBiTree);
	printf("中序遍历二叉树:");
	InOrderTraverseSeqBiTree(atSeqBiTree);
	printf("后序遍历二叉树:");
	PostOrderTraverseSeqBiTree(atSeqBiTree);
	
	printf("请输入待修改结点的层号,本层序号:");
	scanf("%d,%d",&tPos.iLevel,&tPos.iOrder);
	tElement=GetSeqBiTreeElement(atSeqBiTree,&tPos);
	printf("待修改结点的原值为%d,请输入新值:",tElement.iData);
	scanf("%d",&tElement.iData);
	AssignToSeqBiTreeElement(atSeqBiTree,&tPos,&tElement);
	printf("先序遍历二叉树:");
	PreOrderTraverseSeqBiTree(atSeqBiTree);

	tOtherElement=GetParentFromSeqBiTree(atSeqBiTree,&tElement);
	printf("结点%d的双亲为%d\r\n",tElement.iData,tOtherElement.iData);
	tOtherElement=GetLeftChildFromSeqBiTree(atSeqBiTree,&tElement);
	printf("结点%d的左孩子为%d\r\n",tElement.iData,tOtherElement.iData);
	tOtherElement=GetRightChildFromSeqBiTree(atSeqBiTree,&tElement);
	printf("结点%d的右孩子为%d\r\n",tElement.iData,tOtherElement.iData);
	tOtherElement=GetLeftSiblingFromSeqBiTree(atSeqBiTree,&tElement);
	printf("结点%d的左兄弟为%d\r\n",tElement.iData,tOtherElement.iData);
	tOtherElement=GetRightSiblingFromSeqBiTree(atSeqBiTree,&tElement);
	printf("结点%d的右兄弟为%d\r\n",tElement.iData,tOtherElement.iData);
	
	printf("建立右子树为空的树s:");
	CreateSeqBiTree(atSeqBiTreeRightTreeNull);
	printf("层序遍历二叉树:");
	LevelOrderTraverseSeqBiTree(atSeqBiTreeRightTreeNull);
	printf("树s插到树T中,请输入树T中树s的双亲结点,s为左(0)或右(1)子树:");
	scanf("%d,%d",&tElement.iData,&iLeftOrRight);
	InsertChildInSeqBiTree(atSeqBiTree,&tElement,iLeftOrRight,atSeqBiTreeRightTreeNull);
	PrintfSeqBiTree(atSeqBiTree);
	printf("删除子树,请输入待删除子树根结点的层号,本层序号,左(0)或右(1)子树:");
	scanf("%d,%d,%d",&tPos.iLevel,&tPos.iOrder,&iLeftOrRight);
	DeleteChildInSeqBiTree(atSeqBiTree,&tPos,iLeftOrRight);
	PrintfSeqBiTree(atSeqBiTree);

	ClearSeqBiTree(atSeqBiTree);
	printf("清除二叉树后,树空否？%d(1:是0:否) 树的深度=%d\r\n",IsSeqBiTreeEmpty(atSeqBiTree),GetSeqBiTreeDepth(atSeqBiTree));
	
	return 0;
}
/*****************************************************************************
-Fuction		: InitSeqBiTree
-Description	: InitSeqBiTree
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void InitSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree)
{
	int i;
	for(i=0;i<MAX_SEQ_BINARY_TREE_LEN;i++)
	{
		i_ptSeqBiTree[i].iData=0;//初始化，没有元素为0
	}

}
/*****************************************************************************
-Fuction		: CreateSeqBiTree
-Description	: CreateSeqBiTree
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void CreateSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree)
{
	int i;
	int iData=0;
	char acBiTreeElement[MAX_SEQ_BINARY_TREE_LEN]={0};
	InitSeqBiTree(i_ptSeqBiTree);
	/*printf("请按层序输入结点的值(字符)，空格表示空结点，结点数:%d\r\n",MAX_SEQ_BINARY_TREE_LEN);
	for(i=0;i<MAX_SEQ_BINARY_TREE_LEN;i++)
	{
		iData=getchar();
		if(iData==EOF)
		{
			break;
		}
		else
		{
			i_ptSeqBiTree[i].cData=(char)iData;
		}
	}*/
	printf("请按层序输入结点的值(整型)，0表示空结点，输999结束。结点数:%d\r\n",MAX_SEQ_BINARY_TREE_LEN);
	for(i=0;i<MAX_SEQ_BINARY_TREE_LEN;i++)
	{
		scanf("%d",&iData);
		if(iData==999)
		{
			i_ptSeqBiTree[i].iData=0;
			break;
		}
		else
		{
			i_ptSeqBiTree[i].iData=iData;
		}
	}
	for(i=1;i<MAX_SEQ_BINARY_TREE_LEN;i++)
	{
		if((i!=0)&&(i_ptSeqBiTree[i].iData!=0)&&(i_ptSeqBiTree[(i+1)/2-1].iData==0))
		{
			printf("出现结点(不空)无双亲且不是根,程序退出\r\n");
			exit(-1);
		}
		else
		{
		}
	}
}
/*****************************************************************************
-Fuction		: InitSeqBiTree
-Description	: InitSeqBiTree
-Input			: 
-Output 		: 1代表空
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int IsSeqBiTreeEmpty(T_SeqBiTreeElement *i_ptSeqBiTree)
{
	int iRet=0;
	if(i_ptSeqBiTree[0].iData!=0)
	{
		iRet=0;
	}
	else
	{
		iRet=1;
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: GetSeqBiTreeDepth
-Description	: GetSeqBiTreeDepth
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int GetSeqBiTreeDepth(T_SeqBiTreeElement *i_ptSeqBiTree)
{
	int iDepth;
	int i,j;
	for(i=MAX_SEQ_BINARY_TREE_LEN-1;i>=0;i--)//中间可能出现空节点
	{
		if(i_ptSeqBiTree[i].iData==0)
		{
		}
		else
		{
			break;//指向最后一个非空结点为其序号
		}
	}
	i++;//树的长度，或者从1开始算的序号
	//这样算树每层第一个序号就是1,2,4,8,方便比较计算
	j=-1;//没有根节点，即结点为空时，深度为0,所以从-1开始
	do{
		j++;
	}while(i>=pow(2,j));
	return j;
}
/*****************************************************************************
-Fuction		: GetSeqBiTreeElement
-Description	: GetSeqBiTreeElement
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static T_SeqBiTreeElement GetSeqBiTreeElement(T_SeqBiTreeElement *i_ptSeqBiTree,T_PositionInTree *i_ptPos)
{
	T_SeqBiTreeElement tTreeElement={0};
	tTreeElement=i_ptSeqBiTree[(int)(pow(2,i_ptPos->iLevel-1)+i_ptPos->iOrder-2)];
	return tTreeElement;
}
/*****************************************************************************
-Fuction		: AssignToSeqBiTreeElement
-Description	:
// 操作结果：给处于位置e(层,本层序号)的结点赋新值value
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int AssignToSeqBiTreeElement(T_SeqBiTreeElement *i_ptSeqBiTree,T_PositionInTree *i_ptPos,T_SeqBiTreeElement *i_ptValue)
{
	int iRet=0;
	int i=0;
	i=(int)(pow(2,i_ptPos->iLevel-1)+i_ptPos->iOrder-2);// 将层、本层序号转为数组的序号
	if((i_ptValue->iData!=0)&&(i_ptSeqBiTree[(i+1)/2-1].iData==0))// 给叶子赋非空值但双亲为空
	{
		iRet=-1;
		printf("DataNull,ButElementParentNull err\r\n");
	}
	else if((i_ptValue->iData==0)&&((i_ptSeqBiTree[2*i+1].iData!=0)||(i_ptSeqBiTree[2*i+2].iData!=0)))// 给双亲赋空值但有叶子(不空)
	{
		iRet=-1;
		printf("DataNull,ButHaveChildNotNull err\r\n");
	}
	else
	{
		memcpy(&i_ptSeqBiTree[i],i_ptValue,sizeof(T_SeqBiTreeElement));
		iRet=0;
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: GetParentFromSeqBiTree
-Description	:
// 操作结果：若e是T的非根结点，则返回它的双亲；否则返回“空”
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static T_SeqBiTreeElement GetParentFromSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,T_SeqBiTreeElement *i_ptTreeElement)
{
	T_SeqBiTreeElement tSeqBiTreeElement={0};
	tSeqBiTreeElement.iData=0;
	int i=0;
	if(i_ptSeqBiTree[0].iData==0)// 空树
	{
	}
	else
	{
		for(i=1;i<MAX_SEQ_BINARY_TREE_LEN;i++)
		{
			if(i_ptSeqBiTree[i].iData==i_ptTreeElement->iData)// 找到
			{
				memcpy(&tSeqBiTreeElement,&i_ptSeqBiTree[(i+1)/2-1],sizeof(T_SeqBiTreeElement));
			}
			else
			{
			}
		}
	}
	return tSeqBiTreeElement;
}
/*****************************************************************************
-Fuction		: GetLeftChildFromSeqBiTree
-Description	:
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static T_SeqBiTreeElement GetLeftChildFromSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,T_SeqBiTreeElement *i_ptTreeElement)
{
	T_SeqBiTreeElement tSeqBiTreeElement={0};
	tSeqBiTreeElement.iData=0;
	int i=0;
	if(i_ptSeqBiTree[0].iData==0)// 空树
	{
	}
	else
	{
		for(i=0;i<MAX_SEQ_BINARY_TREE_LEN;i++)
		{
			if(i_ptSeqBiTree[i].iData==i_ptTreeElement->iData)// 找到
			{
				memcpy(&tSeqBiTreeElement,&i_ptSeqBiTree[2*i+1],sizeof(T_SeqBiTreeElement));
			}
			else
			{
			}
		}
	}
	return tSeqBiTreeElement;
}
/*****************************************************************************
-Fuction		: GetRightChildFromSeqBiTree
-Description	:
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static T_SeqBiTreeElement GetRightChildFromSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,T_SeqBiTreeElement *i_ptTreeElement)
{
	T_SeqBiTreeElement tSeqBiTreeElement={0};
	tSeqBiTreeElement.iData=0;
	int i=0;
	if(i_ptSeqBiTree[0].iData==0)// 空树
	{
	}
	else
	{
		for(i=0;i<MAX_SEQ_BINARY_TREE_LEN;i++)
		{
			if(i_ptSeqBiTree[i].iData==i_ptTreeElement->iData)// 找到
			{
				memcpy(&tSeqBiTreeElement,&i_ptSeqBiTree[2*i+2],sizeof(T_SeqBiTreeElement));
			}
			else
			{
			}
		}
	}
	return tSeqBiTreeElement;
}
/*****************************************************************************
-Fuction		: GetLeftSiblingFromSeqBiTree
-Description	:
// 操作结果：返回e的左兄弟。若e是T的左孩子或无左兄弟，则返回“空”
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static T_SeqBiTreeElement GetLeftSiblingFromSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,T_SeqBiTreeElement *i_ptTreeElement)
{
	T_SeqBiTreeElement tSeqBiTreeElement={0};
	tSeqBiTreeElement.iData=0;
	int i=0;
	if(i_ptSeqBiTree[0].iData==0)// 空树
	{
	}
	else
	{
		for(i=0;i<MAX_SEQ_BINARY_TREE_LEN;i++)
		{
			if((i_ptSeqBiTree[i].iData==i_ptTreeElement->iData)&&(i%2==0))
			{// 找到e且其序号为偶数(是右孩子)
				memcpy(&tSeqBiTreeElement,&i_ptSeqBiTree[i-1],sizeof(T_SeqBiTreeElement));
			}
			else
			{
			}
		}
	}
	return tSeqBiTreeElement;
}
/*****************************************************************************
-Fuction		: GetRightSiblingFromSeqBiTree
-Description	:
// 操作结果：返回e的右兄弟。若e是T的右孩子或无右兄弟，则返回“空”
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static T_SeqBiTreeElement GetRightSiblingFromSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,T_SeqBiTreeElement *i_ptTreeElement)
{
	T_SeqBiTreeElement tSeqBiTreeElement={0};
	tSeqBiTreeElement.iData=0;
	int i=0;
	if(i_ptSeqBiTree[0].iData==0)// 空树
	{
	}
	else
	{
		for(i=0;i<MAX_SEQ_BINARY_TREE_LEN;i++)
		{
			if((i_ptSeqBiTree[i].iData==i_ptTreeElement->iData)&&(i%2!=0))
			{// 找到e且其序号为奇数(是左孩子)
				memcpy(&tSeqBiTreeElement,&i_ptSeqBiTree[i+1],sizeof(T_SeqBiTreeElement));
			}
			else
			{
			}
		}
	}
	return tSeqBiTreeElement;
}
/*****************************************************************************
-Fuction		: MoveSeqBiTree
-Description	:
// 把从src的i_dwSrcPos结点开始的子树移为从dst的i_dwDstPos结点开始的子树
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void MoveSeqBiTree(T_SeqBiTreeElement *i_ptSrcSeqBiTree,int i_dwSrcPos,T_SeqBiTreeElement *i_ptDstSeqBiTree,int i_dwDstPos)
{
	if(i_ptSrcSeqBiTree[2*i_dwSrcPos+1].iData!=0)// 把q的j结点的左子树移为T的i结点的左子树
	{
		MoveSeqBiTree(i_ptSrcSeqBiTree,2*i_dwSrcPos+1,i_ptDstSeqBiTree,2*i_dwDstPos+1);
	}
	else
	{
	}
	if(i_ptSrcSeqBiTree[2*i_dwSrcPos+2].iData!=0)// 把q的j结点的右子树移为T的i结点的右子树
	{
		MoveSeqBiTree(i_ptSrcSeqBiTree,2*i_dwSrcPos+2,i_ptDstSeqBiTree,2*i_dwDstPos+2);
	}
	else
	{
	}
	memcpy(&i_ptDstSeqBiTree[i_dwDstPos],&i_ptSrcSeqBiTree[i_dwSrcPos],sizeof(T_SeqBiTreeElement));
	i_ptSrcSeqBiTree[i_dwSrcPos].iData=0;
}
/*****************************************************************************
-Fuction		: InsertChildInSeqBiTree
-Description	:
//操作结果:根据i_iLeftOrRight为0或1,插入i_ptInsertTree为i_ptSeqBiTree中
i_ptInsertNode结点的左或右子树。
i_ptInsertNode结点的原有左或右子树则成为i_ptInsertTree的右子树
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void InsertChildInSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,T_SeqBiTreeElement *i_ptInsertNode,int i_iLeftOrRight,T_SeqBiTreeElement *i_ptInsertTree)
{
	int i;
	int i_dwInsertChildPos=0;
	for(i=0;i<(int)(pow(2,GetSeqBiTreeDepth(i_ptSeqBiTree)))-1;i++)// 查找i_ptInsertNode的序号
	{
		if(0==memcmp(&i_ptSeqBiTree[i],i_ptInsertNode,sizeof(T_SeqBiTreeElement)))
		{
			break;
		}
		else
		{
		}
	}
	i_dwInsertChildPos=2*i+1+i_iLeftOrRight;//i_dwInsertChildPos为i_ptInsertNode的左或右孩子的序号
	if(i_ptSeqBiTree[i_dwInsertChildPos].iData!=0)
	{// 把从i_ptSeqBiTree的i_dwInsertChildPos结点开始的子树移为从i_dwInsertChildPos结点的右子树开始的子树
		MoveSeqBiTree(i_ptSeqBiTree,i_dwInsertChildPos,i_ptSeqBiTree,2*i_dwInsertChildPos+2);
		//结点开始的子树移动到结点孩子开始的子树,递归导致先执行最后结点移动到
		//目标的空节点上，此时原来元素已经保存，就可以继续移动结点，类似于
		//数组元素整体后移
	}
	else
	{
	}
	MoveSeqBiTree(i_ptInsertTree,0,i_ptSeqBiTree,i_dwInsertChildPos);// 把从i_ptInsertTree的开始的子树移为从i_ptSeqBiTree的i_dwInsertChildPos结点开始的子树
//由于前面的操作同时也导致了
//i_ptInsertNode结点的原有左或右子树则成为i_ptInsertTree的右子树
}
/*****************************************************************************
-Fuction		: DeleteChildInSeqBiTree
-Description	:
// 操作结果：根据LR为1或0，删除T中p所指结点的左或右子树
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int DeleteChildInSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,T_PositionInTree*i_ptDeleteNodePos,int i_iLeftOrRight)
{
	int iRet=0;
	int i;
	T_LinkQueue tLinkQueue={0};

	InitLinkQueue(&tLinkQueue);
	// 将层、本层序号转为矩阵的序号
	i=(int)pow(2,i_ptDeleteNodePos->iLevel-1)+i_ptDeleteNodePos->iOrder-2;// 将层、本层序号转为矩阵的序号
	if(i_ptSeqBiTree[i].iData==0)// 此结点空
	{
		iRet=-1;
		printf("DeleteNodeIsNull,err\r\n");
	}
	else
	{
		i=2*i+1+i_iLeftOrRight;// 待删除子树的根结点在矩阵中的序号
		//printf("DeleteNodePos:%d\r\n",i);
		while(iRet==0)
		{
			if(i_ptSeqBiTree[2*i+1].iData!=0)
			{
				EnterLinkQueue(&tLinkQueue,(char)(2*i+1));// 入队左结点的序号	
			}
			else{
			}
			if(i_ptSeqBiTree[2*i+2].iData!=0)
			{
				EnterLinkQueue(&tLinkQueue,(char)(2*i+2));	
			}
			else{
			}
			i_ptSeqBiTree[i].iData=0;
			iRet=ExitLinkQueue(&tLinkQueue,(char *)&i);// 队列不空
		}
		
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: PreTraverseSeqBiTree
-Description	:
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void PreTraverseSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,int i_dwPos)
{
	printf("%d ",i_ptSeqBiTree[i_dwPos].iData);
	if(i_ptSeqBiTree[i_dwPos*2+1].iData!=0)// 左子树不空
	{
		PreTraverseSeqBiTree(i_ptSeqBiTree,i_dwPos*2+1);
	}
	else{
	}
	if(i_ptSeqBiTree[i_dwPos*2+2].iData!=0)// 右子树不空
	{
		PreTraverseSeqBiTree(i_ptSeqBiTree,i_dwPos*2+2);
	}
	else{
	}
}
/*****************************************************************************
-Fuction		: PreOrderTraverseSeqBiTree
-Description	:
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void PreOrderTraverseSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree)
{
	if(IsSeqBiTreeEmpty(i_ptSeqBiTree))
	{
		printf("SeqBiTreeEmpty PreOrderTraverseSeqBiTree err\r\n");
	}
	else
	{
		PreTraverseSeqBiTree(i_ptSeqBiTree,0);
		printf("\r\n");
	}
}
/*****************************************************************************
-Fuction		: InTraverseSeqBiTree
-Description	:
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void InTraverseSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,int i_dwPos)
{
	if(i_ptSeqBiTree[i_dwPos*2+1].iData!=0)// 左子树不空
	{
		InTraverseSeqBiTree(i_ptSeqBiTree,i_dwPos*2+1);
	}
	else{
	}
	printf("%d ",i_ptSeqBiTree[i_dwPos].iData);
	if(i_ptSeqBiTree[i_dwPos*2+2].iData!=0)// 右子树不空
	{
		InTraverseSeqBiTree(i_ptSeqBiTree,i_dwPos*2+2);
	}
	else{
	}
}
/*****************************************************************************
-Fuction		: InOrderTraverseSeqBiTree
-Description	:
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void InOrderTraverseSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree)
{
	if(IsSeqBiTreeEmpty(i_ptSeqBiTree))
	{
		printf("SeqBiTreeEmpty InOrderTraverseSeqBiTree err\r\n");
	}
	else
	{
		InTraverseSeqBiTree(i_ptSeqBiTree,0);
		printf("\r\n");
	}
}
/*****************************************************************************
-Fuction		: PostTraverseSeqBiTree
-Description	:
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void PostTraverseSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree,int i_dwPos)
{
	if(i_ptSeqBiTree[i_dwPos*2+1].iData!=0)// 左子树不空
	{
		PostTraverseSeqBiTree(i_ptSeqBiTree,i_dwPos*2+1);
	}
	else{
	}
	if(i_ptSeqBiTree[i_dwPos*2+2].iData!=0)// 右子树不空
	{
		PostTraverseSeqBiTree(i_ptSeqBiTree,i_dwPos*2+2);
	}
	else{
	}
	printf("%d ",i_ptSeqBiTree[i_dwPos].iData);
}
/*****************************************************************************
-Fuction		: PostOrderTraverseSeqBiTree
-Description	:
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void PostOrderTraverseSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree)
{
	if(IsSeqBiTreeEmpty(i_ptSeqBiTree))
	{
		printf("SeqBiTreeEmpty PostOrderTraverseSeqBiTree err\r\n");
	}
	else
	{
		PostTraverseSeqBiTree(i_ptSeqBiTree,0);
		printf("\r\n");
	}
}
/*****************************************************************************
-Fuction		: LevelOrderTraverseSeqBiTree
-Description	:// 层序遍历二叉树
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void LevelOrderTraverseSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree)
{
	int i,j;
	i=MAX_SEQ_BINARY_TREE_LEN-1;
	while(i_ptSeqBiTree[i].iData==0)
	{
		i--;// 找到最后一个非空结点的序号
	}
	for(j=0;j<=i;j++)// 从根结点起，按层序遍历二叉树
	{
		if(0==i_ptSeqBiTree[j].iData)
		{
		}
		else
		{
			printf("%d ",i_ptSeqBiTree[j].iData);// 只遍历非空的结点
		}
	}
	printf("\r\n");
}
/*****************************************************************************
-Fuction		: PrintfSeqBiTree
-Description	:// 逐层、按本层序号输出二叉树
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void PrintfSeqBiTree(T_SeqBiTreeElement *i_ptSeqBiTree)
{
	int i,j;
	T_PositionInTree tPos={0};
	T_SeqBiTreeElement tSeqBiTreeElement={0};
	for(i=1;i<=GetSeqBiTreeDepth(i_ptSeqBiTree);i++)
	{
		printf("第%d层: ",i);
		for(j=1;j<=pow(2,i-1);j++)
		{
			tPos.iLevel=i;
			tPos.iOrder=j;
			tSeqBiTreeElement=GetSeqBiTreeElement(i_ptSeqBiTree,&tPos);
			if(0==tSeqBiTreeElement.iData)
			{
			}
			else
			{
				printf("%d:%d ",j,tSeqBiTreeElement.iData);
			}
		}
		printf("\r\n");
	}
}







