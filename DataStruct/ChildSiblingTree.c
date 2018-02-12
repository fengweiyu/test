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


#define 	ClearChildSiblingTree 	DestroyChildSiblingTree 	// ��ն����������ٶ������Ĳ���һ��
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
	printf("���������,���շ�? %d(1:��0:��) ����Ϊ%c �������Ϊ%d\r\n",IsChildSiblingTreeEmpty(ptChildSiblingTree),
		GetChildSiblingTreeRootData(ptChildSiblingTree),GetChildSiblingTreeDepth(ptChildSiblingTree));
	CreateChildSiblingTree(&ptChildSiblingTree);
	printf("������T��,���շ�? %d(1:��0:��) ����Ϊ%c �������Ϊ%d\r\n",IsChildSiblingTreeEmpty(ptChildSiblingTree),
		GetChildSiblingTreeRootData(ptChildSiblingTree),GetChildSiblingTreeDepth(ptChildSiblingTree));
	printf("�ȸ�������T:\n");
	PreOrderTraverseChildSiblingTree(ptChildSiblingTree);
	

	printf("\n��������޸ĵĽ���ֵ,��ֵ: ");
	scanf("%c,%c%*c",&cData,&cOtherData);
	AssignToChildSiblingTreeNode(ptChildSiblingTree,cData,cOtherData);
	printf("��������޸ĺ����T:\n");
	PostOrderTraverseChildSiblingTree(ptChildSiblingTree);
	printf("\n%c��˫����%c,������%c,��һ���ֵ���%c\n",cOtherData,GetChildSiblingTreeParentData(ptChildSiblingTree,cOtherData),
		GetChildSiblingTreeLeftChildData(ptChildSiblingTree,cOtherData),GetChildSiblingTreeRightSiblingData(ptChildSiblingTree,cOtherData));


	printf("������p:\n");
	InitChildSiblingTree(&ptChildSiblingTreeNoRightChildTree);
	CreateChildSiblingTree(&ptChildSiblingTreeNoRightChildTree);
	printf("���������p:\n");
	LevelOrderTraverseChildSiblingTree(ptChildSiblingTreeNoRightChildTree);

	printf("\n����p�嵽��T�У�������T��p��˫�׽��,�������: ");
	scanf("%c,%d%*c",&cData,&i);
	ptChildSiblingTreeNode=GetChildSiblingTreeNodePoint(ptChildSiblingTree,cData);
	InsertChildInChildSiblingTree(ptChildSiblingTree,ptChildSiblingTreeNode,i,ptChildSiblingTreeNoRightChildTree);
	printf("���������T:\n");
	LevelOrderTraverseChildSiblingTree(ptChildSiblingTree);

	printf("\nɾ����T�н��e�ĵ�i��������������e,i: ");
	scanf("%c,%d",&cData,&i);
	ptChildSiblingTreeNode=GetChildSiblingTreeNodePoint(ptChildSiblingTree,cData);
	DeleteChildInChildSiblingTree(ptChildSiblingTree,ptChildSiblingTreeNode,i);
	printf("���������T:\n");
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
	printf("����������(�ַ���,�ո�Ϊ��): ");
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
				printf("�밴����˳��������%c�����к���,������20��:",tExitQueueData.ptData->cData);
				memset(acData,0,sizeof(acData));
				//fgets��stdin�ж��ַ���ֱ���������з����ļ�����
				fgets(acData,sizeof(acData),stdin);//sizeof(acData)Ϊsize
				//���size����һ�е��ַ������ȣ���ô���������з�ʱ,
				//acData�������з����Һ��滹�����'\0'
				//���sizeС�ڵ���һ�е��ַ����ĳ��ȣ���ô����size-1���ַ�
				//acData�в��������з��������һλ����������'\0'
				iStringLen=strlen(acData)-1;//ȥ�����з�
				//�����gets,�������һ����Ϣ����acData�У�Ȼ�󽫻��з��û��ɴ���β��'\0'��
				//�û�Ҫ��֤�������ĳ��ȴ��ڻ���������г�
				if(iStringLen>0)// �к���
				{// �������ӽ��
					tExitQueueData.ptData->ptFirstChild=(T_ChildSiblingTreeNode *)malloc(sizeof(T_ChildSiblingTreeNode));
					if(NULL==tExitQueueData.ptData->ptFirstChild)
					{
					}
					else
					{
						tEnterQueueData.ptData=tExitQueueData.ptData->ptFirstChild;
						tEnterQueueData.ptData->cData=acData[0];
						for(i=1;i<iStringLen;i++)
						{// ������һ���ֵܽ��
							tEnterQueueData.ptData->ptFirstSibling=(T_ChildSiblingTreeNode *)malloc(sizeof(T_ChildSiblingTreeNode));
							if(NULL==tEnterQueueData.ptData->ptFirstSibling)
							{
							}
							else
							{
								EnterLinkQueue(&tLinkQueue,tEnterQueueData);// �����һ�����
								tEnterQueueData.ptData=tEnterQueueData.ptData->ptFirstSibling;
								tEnterQueueData.ptData->cData=acData[i];
							}
						}
						tEnterQueueData.ptData->ptFirstSibling=NULL;
						EnterLinkQueue(&tLinkQueue,tEnterQueueData);// ������һ�����
					}
				}
				else
				{
					tExitQueueData.ptData->ptFirstChild=NULL;// ����ָ��Ϊ��
					//�ֵܽ������һ�����ĺ���ȷ��
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
			ptTreeNode->cData=i_cNewData;// ����ֵ
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
		if(i_ptChildSiblingTree->cData==i_cCurData)// �����ֵΪi_cCurData
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
					if(i_cCurData==tExitQueueElement.ptData->ptFirstChild->cData)// ����Ϊi_cCurData
					{
						cData=tExitQueueElement.ptData->cData;// ����˫��
						break;
					}
					else
					{
						ptParent=tExitQueueElement.ptData;// ˫��ָ�븳��ptParent
						tEnterQueueElement.ptData=tExitQueueElement.ptData->ptFirstChild;// tEnterQueueElement.ptDataָ����
						EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// ��ӳ���
						while(NULL!=tEnterQueueElement.ptData->ptFirstSibling)//���ĺ����ж����˽����ж��ֵ�
						{
							tEnterQueueElement.ptData=tEnterQueueElement.ptData->ptFirstSibling;
							if(GetChildSiblingTreeNodeData(tEnterQueueElement.ptData)==i_cCurData)//�ֵ���ȣ�������Ϊ��ӦҪ�ҵ�����
							{
								cData=GetChildSiblingTreeNodeData(tExitQueueElement.ptData);//��Ӧ���ݵ�˫�׷���
								break;
							}
							else//û�ҵ�,��Ӹ��ֵܽ��
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
	if(NULL!=ptTreeNode&&NULL!=ptTreeNode->ptFirstChild)// �ҵ���� �ҽ�� �г���
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
	if(NULL!=ptTreeNode&&NULL!=ptTreeNode->ptFirstSibling)// �ҵ���� �ҽ�� �г���
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
// ��ʼ��������i_ptChildSiblingTree���ڣ�i_ptInsertNodeָ��i_ptChildSiblingTree��ĳ����㣬
1��i��p��ָ���Ķ�+1���ǿ���i_ptInsertTree��i_ptChildSiblingTree���ཻ
// �������������i_ptInsertTreeΪi_ptChildSiblingTree��i_ptInsertNode���ĵ�i������

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
	else// i_ptChildSiblingTree����
	{
		if(1==i)// ����i_ptInsertTreeΪi_ptInsertNode�ĳ���
		{
			i_ptInsertTree->ptFirstSibling=i_ptInsertNode->ptFirstChild;//�����ǵķ���������
			i_ptInsertNode->ptFirstChild=i_ptInsertTree;
			iRet=0;
		}
		else// �Ҳ����
		{
			i_ptInsertNode=i_ptInsertNode->ptFirstChild;
			j=2;//����������ָ����ӣ��ڶ������ӣ���Ϊ2
			while(NULL!=i_ptInsertNode&&j<i)//ʹ�û���Ҫi_ptInsertNode->ptFirstSibling��ʾ����
			{
				i_ptInsertNode=i_ptInsertNode->ptFirstSibling;//ָ���Ϊi-1�ĺ���
				j++;//ʹ�û���Ҫi_ptInsertNode->ptFirstSibling��ʾ��Ϊi�ĺ���
			}
			if(j==i)
			{
				i_ptInsertTree->ptFirstSibling=i_ptInsertNode->ptFirstSibling;
				i_ptInsertNode->ptFirstSibling=i_ptInsertTree;
				iRet=0;
			}
			else// ԭ�к�����С��i-1
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
// ��ʼ��������i_ptChildSiblingTree���ڣ�i_ptDeleteNodeָ��i_ptChildSiblingTree��ĳ����㣬
1��i��i_ptDeleteNode��ָ���Ķ�
// ���������ɾ��i_ptChildSiblingTree��i_ptDeleteNode��ָ���ĵ�i������
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
		if(1==i)// ɾ������
		{
			ptDeleteNode=i_ptDeleteNode->ptFirstChild;
			i_ptDeleteNode->ptFirstChild=ptDeleteNode->ptFirstSibling;// i_ptDeleteNode��ԭ�������ǳ���
			ptDeleteNode->ptFirstSibling=NULL;
			DestroyChildSiblingTree(ptDeleteNode);
			iRet=0;
		}
		else// ɾ���ǳ���
		{
			i_ptDeleteNode=i_ptDeleteNode->ptFirstChild;
			j=2;//����������ָ����ӣ��ڶ������ӣ���Ϊ2
			while(NULL!=i_ptDeleteNode&&j<i)//ʹ�û���Ҫi_ptDeleteNode->ptFirstSibling��ʾ����
			{
				i_ptDeleteNode=i_ptDeleteNode->ptFirstSibling;//ָ���Ϊi-1�ĺ���
				j++;//ʹ�û���Ҫi_ptInsertNode->ptFirstSibling��ʾ��Ϊi�ĺ���
			}
			if(j==i)// �ҵ���i������
			{
				ptDeleteNode=i_ptDeleteNode->ptFirstSibling;
				i_ptDeleteNode->ptFirstSibling=ptDeleteNode->ptFirstSibling;
				ptDeleteNode->ptFirstSibling=NULL;
				DestroyChildSiblingTree(ptDeleteNode);
				iRet=0;
			}
			else//ԭ�к�����С��i-1(j++���£�DestroyChildSiblingTree nullҲ����)
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
-Description	: �ȰѺ��ӱ���������ٷ��ʸ�
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
			ptTreeNode=i_ptChildSiblingTree->ptFirstChild->ptFirstSibling;// ָ���ӵ���һ���ֵ�
			while(NULL!=ptTreeNode)
			{
				PostOrderTraverseChildSiblingTree(ptTreeNode);
				ptTreeNode=ptTreeNode->ptFirstSibling;
			}
		}//���˳�ѭ��ʱptTreeNodeΪnull
		printf("%c ",GetChildSiblingTreeNodeData(i_ptChildSiblingTree));//�����ﲻ��ʹ��ptTreeNode
	}
}

/*****************************************************************************
-Fuction		: LevelOrderTraverseChildSiblingTree
-Description	: ����������ӡ��ֵܶ�������ṹ����
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
				EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// ��ӳ��ӽ���ָ��
				while(NULL!=tEnterQueueElement.ptData->ptFirstSibling)
				{
					tEnterQueueElement.ptData=tEnterQueueElement.ptData->ptFirstSibling;
					printf("%c ",tEnterQueueElement.ptData->cData);
					EnterLinkQueue(&tLinkQueue,tEnterQueueElement);// ����ֵܽ���ָ��
				}
			}
		}
	}
}










