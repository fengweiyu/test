/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ChildSiblingTree.c
* Description		: 	ChildSiblingTree operation center
* Created			: 	2017.05.23.
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
#include "ChildSiblingTree.h"
#include "LinkQueue.c"

static void InitChildSiblingTree(T_ChildSiblingTreeNode **i_pptChildSiblingTree);
static void DestroyChildSiblingTree(T_ChildSiblingTreeNode *i_ptChildSiblingTree);
static int IsChildSiblingTreeEmpty(T_ChildSiblingTreeNode *i_ptChildSiblingTree);
static int GetChildSiblingTreeDepth(T_ChildSiblingTreeNode *i_ptChildSiblingTree);
static char GetChildSiblingTreeNodeData(T_ChildSiblingTreeNode *i_ptChildSiblingTreeNode);
static char GetChildSiblingTreeRootData(T_ChildSiblingTreeNode *i_ptChildSiblingTree);
static int AssignToChildSiblingTreeNode(T_ChildSiblingTreeNode *i_ptChildSiblingBiTree,char i_cCurData,char i_cNewData);

static char GetChildSiblingTreeParentData(T_ChildSiblingTreeNode *i_ptChildSiblingTree,char i_cCurData);
static char GetChildSiblingTreeLeftChildData(T_ChildSiblingTreeNode *i_ptChildSiblingTree,char i_cCurData);
static char GetChildSiblingTreeRightSiblingData(T_ChildSiblingTreeNode *i_ptChildSiblingTree,char i_cCurData);


static void CreateChildSiblingTree(T_ChildSiblingTreeNode **i_pptChildSiblingTree);
static T_ChildSiblingTreeNode  *GetChildSiblingTreeNodePoint(T_ChildSiblingTreeNode *i_ptChildSiblingTree,char i_cData);
static int InsertChildInChildSiblingTree(T_ChildSiblingTreeNode *i_ptChildSiblingTree,T_ChildSiblingTreeNode *i_ptInsertNode,int i,T_ChildSiblingTreeNode *i_ptInsertTree);
static int DeleteChildInChildSiblingTree(T_ChildSiblingTreeNode *i_ptChildSiblingTree,T_ChildSiblingTreeNode *i_ptDeleteNode,int i);
static void PreOrderTraverseChildSiblingTree(T_ChildSiblingTreeNode *i_ptChildSiblingTree);
static void PostOrderTraverseChildSiblingTree(T_ChildSiblingTreeNode *i_ptChildSiblingTree);
static void LevelOrderTraverseChildSiblingTree(T_ChildSiblingTreeNode *i_ptChildSiblingTree);


#define 	ClearChildSiblingTree 	DestroyChildSiblingTree 	// 清空二叉树和销毁二叉树的操作一样
#define 	NIL 			' '
/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_ChildSiblingTreeNode *ptChildSiblingTree=NULL;	
	T_ChildSiblingTreeNode *ptChildSiblingTreeNoRightChildTree=NULL;
	T_ChildSiblingTreeNode *ptChildSiblingTreeNode=NULL;
	int i=0;
	char cData;
	char cOtherData;
	InitChildSiblingTree(&ptChildSiblingTree);
	printf("构造空树后,树空否? %d(1:是0:否) 树根为%c 树的深度为%d\r\n",IsChildSiblingTreeEmpty(ptChildSiblingTree),
		GetChildSiblingTreeRootData(ptChildSiblingTree),GetChildSiblingTreeDepth(ptChildSiblingTree));
	CreateChildSiblingTree(&ptChildSiblingTree);
	printf("构造树T后,树空否? %d(1:是0:否) 树根为%c 树的深度为%d\r\n",IsChildSiblingTreeEmpty(ptChildSiblingTree),
		GetChildSiblingTreeRootData(ptChildSiblingTree),GetChildSiblingTreeDepth(ptChildSiblingTree));
	printf("先根遍历树T:\n");
	PreOrderTraverseChildSiblingTree(ptChildSiblingTree);
	

	printf("\n请输入待修改的结点的值,新值: ");
	scanf("%c,%c%*c",&cData,&cOtherData);
	AssignToChildSiblingTreeNode(ptChildSiblingTree,cData,cOtherData);
	printf("后根遍历修改后的树T:\n");
	PostOrderTraverseChildSiblingTree(ptChildSiblingTree);
	printf("\n%c的双亲是%c,长子是%c,下一个兄弟是%c\n",cOtherData,GetChildSiblingTreeParentData(ptChildSiblingTree,cOtherData),
		GetChildSiblingTreeLeftChildData(ptChildSiblingTree,cOtherData),GetChildSiblingTreeRightSiblingData(ptChildSiblingTree,cOtherData));


	printf("建立树p:\n");
	InitChildSiblingTree(&ptChildSiblingTreeNoRightChildTree);
	CreateChildSiblingTree(&ptChildSiblingTreeNoRightChildTree);
	printf("层序遍历树p:\n");
	LevelOrderTraverseChildSiblingTree(ptChildSiblingTreeNoRightChildTree);

	printf("\n将树p插到树T中，请输入T中p的双亲结点,子树序号: ");
	scanf("%c,%d%*c",&cData,&i);
	ptChildSiblingTreeNode=GetChildSiblingTreeNodePoint(ptChildSiblingTree,cData);
	InsertChildInChildSiblingTree(ptChildSiblingTree,ptChildSiblingTreeNode,i,ptChildSiblingTreeNoRightChildTree);
	printf("层序遍历树T:\n");
	LevelOrderTraverseChildSiblingTree(ptChildSiblingTree);

	printf("\n删除树T中结点e的第i棵子树，请输入e,i: ");
	scanf("%c,%d",&cData,&i);
	ptChildSiblingTreeNode=GetChildSiblingTreeNodePoint(ptChildSiblingTree,cData);
	DeleteChildInChildSiblingTree(ptChildSiblingTree,ptChildSiblingTreeNode,i);
	printf("层序遍历树T:\n");
	LevelOrderTraverseChildSiblingTree(ptChildSiblingTree);

	DestroyChildSiblingTree(ptChildSiblingTree);

	return 0;
}

/*****************************************************************************
-Fuction		: InitChildSiblingTree
-Description	: InitChildSiblingTree
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void InitChildSiblingTree(T_ChildSiblingTreeNode **i_pptChildSiblingTree)
{
	*i_pptChildSiblingTree=NULL;
}

/*****************************************************************************
-Fuction		: DestroyChildSiblingTree
-Description	: DestroyChildSiblingTree
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void DestroyChildSiblingTree(T_ChildSiblingTreeNode *i_ptChildSiblingTree)
{
	if(NULL==i_ptChildSiblingTree)
	{
	}
	else
	{
		if(NULL==i_ptChildSiblingTree->ptFirstChild)
		{
		}
		else
		{
			DestroyChildSiblingTree(i_ptChildSiblingTree->ptFirstChild);
		}
		if(NULL==i_ptChildSiblingTree->ptFirstSibling)
		{
		}
		else
		{
			DestroyChildSiblingTree(i_ptChildSiblingTree->ptFirstSibling);
		}
		free(i_ptChildSiblingTree);
		i_ptChildSiblingTree=NULL;
	}
}

/*****************************************************************************
-Fuction		: CreateChildSiblingTree
-Description	: CreateChildSiblingTree
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void CreateChildSiblingTree(T_ChildSiblingTreeNode **i_pptChildSiblingTree)
{
	T_ChildSiblingTreeNode *ptTreeNodeFirstChild=NULL;
	char acData[20]={0};
	int iStringLen=0;
	int i;
	T_LinkQueue tLinkQueue={0};
	T_QueueDataElement tEnterQueueData={0};
	T_QueueDataElement tExitQueueData={0};

	InitLinkQueue(&tLinkQueue);
	printf("请输入根结点(字符型,空格为空): ");
	scanf("%c%*c",&acData[0]);
	if(NIL==acData[0])
	{
		*i_pptChildSiblingTree=NULL;
	}
	else
	{
		*i_pptChildSiblingTree=(T_ChildSiblingTreeNode *)malloc(sizeof(T_ChildSiblingTreeNode));
		if(NULL==*i_pptChildSiblingTree)
		{
		}
		else
		{
			(*i_pptChildSiblingTree)->cData=acData[0];
			(*i_pptChildSiblingTree)->ptFirstChild=NULL;
			(*i_pptChildSiblingTree)->ptFirstSibling=NULL;
			tEnterQueueData.ptData=*i_pptChildSiblingTree;
			EnterLinkQueue(&tLinkQueue,tEnterQueueData);
			while(0!=IsLinkQueueEmpty(&tLinkQueue))
			{
				ExitLinkQueue(&tLinkQueue,&tExitQueueData);
				printf("请按长幼顺序输入结点%c的所有孩子,不超过20个:",tExitQueueData.ptData->cData);
				memset(acData,0,sizeof(acData));
				//fgets从stdin中读字符，直至读到换行符或文件结束
				fgets(acData,sizeof(acData),stdin);//sizeof(acData)为size
				//如果size大于一行的字符串长度，那么当读到换行符时,
				//acData包含换行符并且后面还会加上'\0'
				//如果size小于等于一行的字符串的长度，那么读入size-1个字符
				//acData中不包含换行符并且最后一位保留用来放'\0'
				iStringLen=strlen(acData)-1;//去掉换行符
				//如果是gets,把输入的一行信息存入acData中，然后将换行符置换成串结尾符'\0'。
				//用户要保证缓冲区的长度大于或等于最大的行长
				if(iStringLen>0)// 有孩子
				{// 建立长子结点
					tExitQueueData.ptData->ptFirstChild=(T_ChildSiblingTreeNode *)malloc(sizeof(T_ChildSiblingTreeNode));
					if(NULL==tExitQueueData.ptData->ptFirstChild)
					{
					}
					else
					{
						tEnterQueueData.ptData=tExitQueueData.ptData->ptFirstChild;
						tEnterQueueData.ptData->cData=acData[0];
						for(i=1;i<iStringLen;i++)
						{// 建立下一个兄弟结点
							tEnterQueueData.ptData->ptFirstSibling=(T_ChildSiblingTreeNode *)malloc(sizeof(T_ChildSiblingTreeNode));
							if(NULL==tEnterQueueData.ptData->ptFirstSibling)
							{
							}
							else
							{
								EnterLinkQueue(&tLinkQueue,tEnterQueueData);// 入队上一个结点
								tEnterQueueData.ptData=tEnterQueueData.ptData->ptFirstSibling;
								tEnterQueueData.ptData->cData=acData[i];
							}
						}
						tEnterQueueData.ptData->ptFirstSibling=NULL;
						EnterLinkQueue(&tLinkQueue,tEnterQueueData);// 入队最后一个结点
					}
				}
				else
				{
					tExitQueueData.ptData->ptFirstChild=NULL;// 长子指针为空
					//兄弟结点由上一个结点的孩子确定
				}
			}
		}
	}
}

/*****************************************************************************
-Fuction		: IsChildSiblingTreeEmpty
-Description	: IsChildSiblingTreeEmpty
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int IsChildSiblingTreeEmpty(T_ChildSiblingTreeNode *i_ptChildSiblingTree)
{
	int iRet=-1;
	if(NULL==i_ptChildSiblingTree)
	{
		iRet=0;
	}
	else
	{
		iRet=-1;
	}
	return iRet;
}

/*****************************************************************************
-Fuction		: GetChildSiblingTreeDepth
-Description	: GetChildSiblingTreeDepth
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int GetChildSiblingTreeDepth(T_ChildSiblingTreeNode *i_ptChildSiblingTree)
{
	int iDepth=0,iMaxDepth=0;
	T_ChildSiblingTreeNode *ptTreeNode=NULL;
	if(NULL==i_ptChildSiblingTree)
	{
		iMaxDepth=0;
	}
	else if(NULL==i_ptChildSiblingTree->ptFirstChild)
	{
		iMaxDepth=1;
	}
	else
	{
		for(ptTreeNode=i_ptChildSiblingTree->ptFirstChild;NULL!=ptTreeNode;ptTreeNode=ptTreeNode->ptFirstSibling)
		{
			iDepth=GetChildSiblingTreeDepth(ptTreeNode);
			if(iDepth>iMaxDepth)
			{
				iMaxDepth=iDepth;
			}
			else
			{
			}
		}
		iMaxDepth++;
	}
	return iMaxDepth;
}

/*****************************************************************************
-Fuction		: GetChildSiblingTreeNodeData
-Description	: GetChildSiblingTreeNodeData
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static char GetChildSiblingTreeNodeData(T_ChildSiblingTreeNode *i_ptChildSiblingTreeNode)
{
	return i_ptChildSiblingTreeNode->cData;
}

/*****************************************************************************
-Fuction		: GetChildSiblingTreeRootData
-Description	: GetChildSiblingTreeRootData
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static char GetChildSiblingTreeRootData(T_ChildSiblingTreeNode *i_ptChildSiblingTree)
{
	if(NULL==i_ptChildSiblingTree)
	{
		return NIL;
	}
	else
	{
		return GetChildSiblingTreeNodeData(i_ptChildSiblingTree);
	}
}

/*****************************************************************************
-Fuction		: GetChildSiblingTreeNodePoint
-Description	: GetChildSiblingTreeNodePoint
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static T_ChildSiblingTreeNode  *GetChildSiblingTreeNodePoint(T_ChildSiblingTreeNode *i_ptChildSiblingTree,char i_cData)
{
	T_LinkQueue tLinkQueue={0};
	T_ChildSiblingTreeNode *ptTreeNode=NULL;
	T_QueueDataElement tEnterQueueData={0};
	T_QueueDataElement tExitQueueData={0};

	if(NULL==i_ptChildSiblingTree)
	{
		ptTreeNode=NULL;
	}
	else
	{
		InitLinkQueue(&tLinkQueue);
		tEnterQueueData.ptData=i_ptChildSiblingTree;
		EnterLinkQueue(&tLinkQueue,tEnterQueueData);
		while(0!=IsLinkQueueEmpty(&tLinkQueue))
		{
			ExitLinkQueue(&tLinkQueue,&tExitQueueData);
			if(tExitQueueData.ptData->cData==i_cData)
			{
				ptTreeNode=tExitQueueData.ptData;
				break;
			}
			else
			{
				if(NULL==tExitQueueData.ptData->ptFirstChild)
				{
				}
				else
				{
					tEnterQueueData.ptData=tExitQueueData.ptData->ptFirstChild;
					EnterLinkQueue(&tLinkQueue,tEnterQueueData);
				}
				
				if(NULL==tExitQueueData.ptData->ptFirstSibling)
				{
				}
				else
				{
					tEnterQueueData.ptData=tExitQueueData.ptData->ptFirstSibling;
					EnterLinkQueue(&tLinkQueue,tEnterQueueData);
				}
			}
		}
	}
	return ptTreeNode;
}

/*****************************************************************************
-Fuction		: AssignToChildSiblingTreeNode
-Description	: AssignToChildSiblingTreeNode
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int AssignToChildSiblingTreeNode(T_ChildSiblingTreeNode *i_ptChildSiblingBiTree,char i_cCurData,char i_cNewData)
{
	int iRet=-1;
	T_ChildSiblingTreeNode *ptTreeNode=NULL;
	if(NULL==i_ptChildSiblingBiTree)
	{
		iRet=-1;
	}
	else
	{
		ptTreeNode=GetChildSiblingTreeNodePoint(i_ptChildSiblingBiTree,i_cCurData);
		if(NULL==ptTreeNode)
		{
			iRet=-1;
		}
		else
		{
			ptTreeNode->cData=i_cNewData;// 赋新值
			iRet=0;
		}
	}
	return iRet;
}

/*****************************************************************************
-Fuction		: GetChildSiblingTreeParentData
-Description	: GetChildSiblingTreeParentData
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static char GetChildSiblingTreeParentData(T_ChildSiblingTreeNode *i_ptChildSiblingTree,char i_cCurData)
{
	char cData=NIL;
	T_ChildSiblingTreeNode *ptParent=NULL;
	T_LinkQueue tLinkQueue={0};
	T_QueueDataElement tEnterQueueElement={0}; 
	T_QueueDataElement tExitQueueElement={0};
	if(NULL==i_ptChildSiblingTree)
	{
		cData=NIL;
	}
	else
	{
		if(i_ptChildSiblingTree->cData==i_cCurData)// 根结点值为i_cCurData
		{
			cData==NIL;
		}
		else
		{
			InitLinkQueue(&tLinkQueue);
			tEnterQueueElement.ptData=i_ptChildSiblingTree;
			EnterLinkQueue(&tLinkQueue,tEnterQueueElement);
			while(0!=IsLinkQueueEmpty(&tLinkQueue))
			{
				ExitLinkQueue(&tLinkQueue,&tExitQueueElement);
				if(NULL==tExitQueueElement.ptData->ptFirstChild)
				{
					cData==NIL;
				}
				else
				{
					if(i_cCurData==tExitQueueElement.ptData->ptFirstChild->cData)// 长子为i_cCurData
					{
						cData=tExitQueueElement.ptData->cData;// 返回双亲
						break;
					}
					else
					{
						ptParent=tExitQueueElement.ptData;// 双亲指针赋给ptParent
						tEnterQueueElement.ptData=tExitQueueElement.ptData->ptFirstChild;// tEnterQueueElement.ptData指向长子
						EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// 入队长子
						while(NULL!=tEnterQueueElement.ptData->ptFirstSibling)//结点的孩子判断完了接着判断兄弟
						{
							tEnterQueueElement.ptData=tEnterQueueElement.ptData->ptFirstSibling;
							if(GetChildSiblingTreeNodeData(tEnterQueueElement.ptData)==i_cCurData)//兄弟相等，即次子为对应要找的数据
							{
								cData=GetChildSiblingTreeNodeData(tExitQueueElement.ptData);//对应数据的双亲返回
								break;
							}
							else//没找到,入队该兄弟结点
							{
								EnterLinkQueue(&tLinkQueue,tEnterQueueElement);
							}
						}			
					}
				}
			}
		}
	}
	return cData;
}

/*****************************************************************************
-Fuction		: GetChildSiblingTreeLeftChildData
-Description	: GetChildSiblingTreeLeftChildData
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static char GetChildSiblingTreeLeftChildData(T_ChildSiblingTreeNode *i_ptChildSiblingTree,char i_cCurData)
{
	char cData=NIL;
	T_ChildSiblingTreeNode *ptTreeNode=NULL;
	ptTreeNode=GetChildSiblingTreeNodePoint(i_ptChildSiblingTree,i_cCurData);
	if(NULL!=ptTreeNode&&NULL!=ptTreeNode->ptFirstChild)// 找到结点 且结点 有长子
	{
		cData=ptTreeNode->ptFirstChild->cData;
	}
	else
	{
		cData=NIL;
	}
	return cData;
}

/*****************************************************************************
-Fuction		: GetChildSiblingTreeRightSiblingData
-Description	: GetChildSiblingTreeRightSiblingData
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static char GetChildSiblingTreeRightSiblingData(T_ChildSiblingTreeNode *i_ptChildSiblingTree,char i_cCurData)
{
	char cData=NIL;
	T_ChildSiblingTreeNode *ptTreeNode=NULL;
	ptTreeNode=GetChildSiblingTreeNodePoint(i_ptChildSiblingTree,i_cCurData);
	if(NULL!=ptTreeNode&&NULL!=ptTreeNode->ptFirstSibling)// 找到结点 且结点 有长子
	{
		cData=ptTreeNode->ptFirstSibling->cData;
	}
	else
	{
		cData=NIL;
	}
	return cData;
}

/*****************************************************************************
-Fuction		: InsertChildInChildSiblingTree
-Description	: 
// 初始条件：树i_ptChildSiblingTree存在，i_ptInsertNode指向i_ptChildSiblingTree中某个结点，
1≤i≤p所指结点的度+1，非空树i_ptInsertTree与i_ptChildSiblingTree不相交
// 操作结果：插入i_ptInsertTree为i_ptChildSiblingTree中i_ptInsertNode结点的第i棵子树

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int InsertChildInChildSiblingTree(T_ChildSiblingTreeNode *i_ptChildSiblingTree,T_ChildSiblingTreeNode *i_ptInsertNode,int i,T_ChildSiblingTreeNode *i_ptInsertTree)
{
	int iRet=-1;
	int j=0;
	if(NULL==i_ptChildSiblingTree)
	{
		iRet=-1;
	}
	else// i_ptChildSiblingTree不空
	{
		if(1==i)// 插入i_ptInsertTree为i_ptInsertNode的长子
		{
			i_ptInsertTree->ptFirstSibling=i_ptInsertNode->ptFirstChild;//被覆盖的放在右子树
			i_ptInsertNode->ptFirstChild=i_ptInsertTree;
			iRet=0;
		}
		else// 找插入点
		{
			i_ptInsertNode=i_ptInsertNode->ptFirstChild;
			j=2;//到这里至少指向次子，第二个儿子，度为2
			while(NULL!=i_ptInsertNode&&j<i)//使用还需要i_ptInsertNode->ptFirstSibling表示次子
			{
				i_ptInsertNode=i_ptInsertNode->ptFirstSibling;//指向度为i-1的孩子
				j++;//使用还需要i_ptInsertNode->ptFirstSibling表示度为i的孩子
			}
			if(j==i)
			{
				i_ptInsertTree->ptFirstSibling=i_ptInsertNode->ptFirstSibling;
				i_ptInsertNode->ptFirstSibling=i_ptInsertTree;
				iRet=0;
			}
			else// 原有孩子数小于i-1
			{
				iRet=-1;
			}
		}
	}
	return iRet;
}

/*****************************************************************************
-Fuction		: DeleteChildInChildSiblingTree
-Description	: 
// 初始条件：树i_ptChildSiblingTree存在，i_ptDeleteNode指向i_ptChildSiblingTree中某个结点，
1≤i≤i_ptDeleteNode所指结点的度
// 操作结果：删除i_ptChildSiblingTree中i_ptDeleteNode所指结点的第i棵子树
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int DeleteChildInChildSiblingTree(T_ChildSiblingTreeNode *i_ptChildSiblingTree,T_ChildSiblingTreeNode *i_ptDeleteNode,int i)
{
	int iRet=-1;
	int j;
	T_ChildSiblingTreeNode *ptDeleteNode=NULL;
	if(NULL==i_ptChildSiblingTree)
	{
		iRet=-1;
	}
	else
	{
		if(1==i)// 删除长子
		{
			ptDeleteNode=i_ptDeleteNode->ptFirstChild;
			i_ptDeleteNode->ptFirstChild=ptDeleteNode->ptFirstSibling;// i_ptDeleteNode的原次子现是长子
			ptDeleteNode->ptFirstSibling=NULL;
			DestroyChildSiblingTree(ptDeleteNode);
			iRet=0;
		}
		else// 删除非长子
		{
			i_ptDeleteNode=i_ptDeleteNode->ptFirstChild;
			j=2;//到这里至少指向次子，第二个儿子，度为2
			while(NULL!=i_ptDeleteNode&&j<i)//使用还需要i_ptDeleteNode->ptFirstSibling表示次子
			{
				i_ptDeleteNode=i_ptDeleteNode->ptFirstSibling;//指向度为i-1的孩子
				j++;//使用还需要i_ptInsertNode->ptFirstSibling表示度为i的孩子
			}
			if(j==i)// 找到第i棵子树
			{
				ptDeleteNode=i_ptDeleteNode->ptFirstSibling;
				i_ptDeleteNode->ptFirstSibling=ptDeleteNode->ptFirstSibling;
				ptDeleteNode->ptFirstSibling=NULL;
				DestroyChildSiblingTree(ptDeleteNode);
				iRet=0;
			}
			else//原有孩子数小于i-1(j++导致，DestroyChildSiblingTree null也可以)
			{
				iRet=-1;
			}
		}
	}
	return iRet;
}

/*****************************************************************************
-Fuction		: PreOrderTraverseChildSiblingTree
-Description	: PreOrderTraverseChildSiblingTree
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void PreOrderTraverseChildSiblingTree(T_ChildSiblingTreeNode *i_ptChildSiblingTree)
{
	if(NULL==i_ptChildSiblingTree)
	{
	}
	else
	{
		printf("%c ",i_ptChildSiblingTree->cData);
		PreOrderTraverseChildSiblingTree(i_ptChildSiblingTree->ptFirstChild);
		PreOrderTraverseChildSiblingTree(i_ptChildSiblingTree->ptFirstSibling);
	}
}

/*****************************************************************************
-Fuction		: PostOrderTraverseChildSiblingTree
-Description	: 先把孩子遍历完最后再访问根
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void PostOrderTraverseChildSiblingTree(T_ChildSiblingTreeNode *i_ptChildSiblingTree)
{
	T_ChildSiblingTreeNode *ptTreeNode=NULL;
	if(NULL==i_ptChildSiblingTree)
	{
	}
	else
	{
		if(NULL==i_ptChildSiblingTree->ptFirstChild)
		{
		}
		else
		{
			PostOrderTraverseChildSiblingTree(i_ptChildSiblingTree->ptFirstChild);
			ptTreeNode=i_ptChildSiblingTree->ptFirstChild->ptFirstSibling;// 指向长子的下一个兄弟
			while(NULL!=ptTreeNode)
			{
				PostOrderTraverseChildSiblingTree(ptTreeNode);
				ptTreeNode=ptTreeNode->ptFirstSibling;
			}
		}//当退出循环时ptTreeNode为null
		printf("%c ",GetChildSiblingTreeNodeData(i_ptChildSiblingTree));//即这里不能使用ptTreeNode
	}
}

/*****************************************************************************
-Fuction		: LevelOrderTraverseChildSiblingTree
-Description	: 层序遍历孩子—兄弟二叉链表结构的树
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/25	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void LevelOrderTraverseChildSiblingTree(T_ChildSiblingTreeNode *i_ptChildSiblingTree)
{
	T_ChildSiblingTreeNode *ptTreeNode=NULL;
	T_LinkQueue tLinkQueue;
	T_QueueDataElement tEnterQueueElement;
	T_QueueDataElement tExitQueueElement;
	InitLinkQueue(&tLinkQueue);
	if(NULL==i_ptChildSiblingTree)
	{
	}
	else
	{
		tEnterQueueElement.ptData=i_ptChildSiblingTree;
		printf("%c ",tEnterQueueElement.ptData->cData);
		EnterLinkQueue(&tLinkQueue,tEnterQueueElement);
		while(0!=IsLinkQueueEmpty(&tLinkQueue))
		{
			ExitLinkQueue(&tLinkQueue,&tExitQueueElement);
			if(NULL==tExitQueueElement.ptData->ptFirstChild)
			{
			}
			else
			{
				tEnterQueueElement.ptData=tExitQueueElement.ptData->ptFirstChild;
				printf("%c ",tEnterQueueElement.ptData->cData);
				EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// 入队长子结点的指针
				while(NULL!=tEnterQueueElement.ptData->ptFirstSibling)
				{
					tEnterQueueElement.ptData=tEnterQueueElement.ptData->ptFirstSibling;
					printf("%c ",tEnterQueueElement.ptData->cData);
					EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// 入队兄弟结点的指针
				}
			}
		}
	}
}










