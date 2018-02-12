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
	//char cData;//NULL��ʾ��Ԫ��Ҳ���ǿս��
	int iData;//0��ʾ��Ԫ��Ҳ���ǿս��
}T_SeqBiTreeElement,*PT_SeqBiTreeElement;

typedef struct PositionInTree
{
	int iLevel;//Ԫ�ش��ڵĲ�� ��1��ʼ
	int iOrder;//Ԫ���ڱ����е����  ��1��ʼ
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

#define ClearSeqBiTree 	InitSeqBiTree 	// ��˳��洢�ṹ�У���������ȫһ��
#define DestroySeqBiTree 	InitSeqBiTree		 // ��˳��洢�ṹ�У���������ȫһ��
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
	printf("������������,���շ�%d(1:��0:��) �������=%d\r\n",IsSeqBiTreeEmpty(atSeqBiTree),GetSeqBiTreeDepth(atSeqBiTree));
	printf("�������������:");
	LevelOrderTraverseSeqBiTree(atSeqBiTree);
	printf("�������������:");
	InOrderTraverseSeqBiTree(atSeqBiTree);
	printf("�������������:");
	PostOrderTraverseSeqBiTree(atSeqBiTree);
	
	printf("��������޸Ľ��Ĳ��,�������:");
	scanf("%d,%d",&tPos.iLevel,&tPos.iOrder);
	tElement=GetSeqBiTreeElement(atSeqBiTree,&tPos);
	printf("���޸Ľ���ԭֵΪ%d,��������ֵ:",tElement.iData);
	scanf("%d",&tElement.iData);
	AssignToSeqBiTreeElement(atSeqBiTree,&tPos,&tElement);
	printf("�������������:");
	PreOrderTraverseSeqBiTree(atSeqBiTree);

	tOtherElement=GetParentFromSeqBiTree(atSeqBiTree,&tElement);
	printf("���%d��˫��Ϊ%d\r\n",tElement.iData,tOtherElement.iData);
	tOtherElement=GetLeftChildFromSeqBiTree(atSeqBiTree,&tElement);
	printf("���%d������Ϊ%d\r\n",tElement.iData,tOtherElement.iData);
	tOtherElement=GetRightChildFromSeqBiTree(atSeqBiTree,&tElement);
	printf("���%d���Һ���Ϊ%d\r\n",tElement.iData,tOtherElement.iData);
	tOtherElement=GetLeftSiblingFromSeqBiTree(atSeqBiTree,&tElement);
	printf("���%d�����ֵ�Ϊ%d\r\n",tElement.iData,tOtherElement.iData);
	tOtherElement=GetRightSiblingFromSeqBiTree(atSeqBiTree,&tElement);
	printf("���%d�����ֵ�Ϊ%d\r\n",tElement.iData,tOtherElement.iData);
	
	printf("����������Ϊ�յ���s:");
	CreateSeqBiTree(atSeqBiTreeRightTreeNull);
	printf("�������������:");
	LevelOrderTraverseSeqBiTree(atSeqBiTreeRightTreeNull);
	printf("��s�嵽��T��,��������T����s��˫�׽��,sΪ��(0)����(1)����:");
	scanf("%d,%d",&tElement.iData,&iLeftOrRight);
	InsertChildInSeqBiTree(atSeqBiTree,&tElement,iLeftOrRight,atSeqBiTreeRightTreeNull);
	PrintfSeqBiTree(atSeqBiTree);
	printf("ɾ������,�������ɾ�����������Ĳ��,�������,��(0)����(1)����:");
	scanf("%d,%d,%d",&tPos.iLevel,&tPos.iOrder,&iLeftOrRight);
	DeleteChildInSeqBiTree(atSeqBiTree,&tPos,iLeftOrRight);
	PrintfSeqBiTree(atSeqBiTree);

	ClearSeqBiTree(atSeqBiTree);
	printf("�����������,���շ�%d(1:��0:��) �������=%d\r\n",IsSeqBiTreeEmpty(atSeqBiTree),GetSeqBiTreeDepth(atSeqBiTree));
	
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
		i_ptSeqBiTree[i].iData=0;//��ʼ����û��Ԫ��Ϊ0
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
	/*printf("�밴�����������ֵ(�ַ�)���ո��ʾ�ս�㣬�����:%d\r\n",MAX_SEQ_BINARY_TREE_LEN);
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
	printf("�밴�����������ֵ(����)��0��ʾ�ս�㣬��999�����������:%d\r\n",MAX_SEQ_BINARY_TREE_LEN);
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
			printf("���ֽ��(����)��˫���Ҳ��Ǹ�,�����˳�\r\n");
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
-Output 		: 1�����
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
	for(i=MAX_SEQ_BINARY_TREE_LEN-1;i>=0;i--)//�м���ܳ��ֿսڵ�
	{
		if(i_ptSeqBiTree[i].iData==0)
		{
		}
		else
		{
			break;//ָ�����һ���ǿս��Ϊ�����
		}
	}
	i++;//���ĳ��ȣ����ߴ�1��ʼ������
	//��������ÿ���һ����ž���1,2,4,8,����Ƚϼ���
	j=-1;//û�и��ڵ㣬�����Ϊ��ʱ�����Ϊ0,���Դ�-1��ʼ
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
// ���������������λ��e(��,�������)�Ľ�㸳��ֵvalue
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
	i=(int)(pow(2,i_ptPos->iLevel-1)+i_ptPos->iOrder-2);// ���㡢�������תΪ��������
	if((i_ptValue->iData!=0)&&(i_ptSeqBiTree[(i+1)/2-1].iData==0))// ��Ҷ�Ӹ��ǿ�ֵ��˫��Ϊ��
	{
		iRet=-1;
		printf("DataNull,ButElementParentNull err\r\n");
	}
	else if((i_ptValue->iData==0)&&((i_ptSeqBiTree[2*i+1].iData!=0)||(i_ptSeqBiTree[2*i+2].iData!=0)))// ��˫�׸���ֵ����Ҷ��(����)
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
// �����������e��T�ķǸ���㣬�򷵻�����˫�ף����򷵻ء��ա�
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
	if(i_ptSeqBiTree[0].iData==0)// ����
	{
	}
	else
	{
		for(i=1;i<MAX_SEQ_BINARY_TREE_LEN;i++)
		{
			if(i_ptSeqBiTree[i].iData==i_ptTreeElement->iData)// �ҵ�
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
	if(i_ptSeqBiTree[0].iData==0)// ����
	{
	}
	else
	{
		for(i=0;i<MAX_SEQ_BINARY_TREE_LEN;i++)
		{
			if(i_ptSeqBiTree[i].iData==i_ptTreeElement->iData)// �ҵ�
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
	if(i_ptSeqBiTree[0].iData==0)// ����
	{
	}
	else
	{
		for(i=0;i<MAX_SEQ_BINARY_TREE_LEN;i++)
		{
			if(i_ptSeqBiTree[i].iData==i_ptTreeElement->iData)// �ҵ�
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
// �������������e�����ֵܡ���e��T�����ӻ������ֵܣ��򷵻ء��ա�
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
	if(i_ptSeqBiTree[0].iData==0)// ����
	{
	}
	else
	{
		for(i=0;i<MAX_SEQ_BINARY_TREE_LEN;i++)
		{
			if((i_ptSeqBiTree[i].iData==i_ptTreeElement->iData)&&(i%2==0))
			{// �ҵ�e�������Ϊż��(���Һ���)
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
// �������������e�����ֵܡ���e��T���Һ��ӻ������ֵܣ��򷵻ء��ա�
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
	if(i_ptSeqBiTree[0].iData==0)// ����
	{
	}
	else
	{
		for(i=0;i<MAX_SEQ_BINARY_TREE_LEN;i++)
		{
			if((i_ptSeqBiTree[i].iData==i_ptTreeElement->iData)&&(i%2!=0))
			{// �ҵ�e�������Ϊ����(������)
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
// �Ѵ�src��i_dwSrcPos��㿪ʼ��������Ϊ��dst��i_dwDstPos��㿪ʼ������
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/05/08	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void MoveSeqBiTree(T_SeqBiTreeElement *i_ptSrcSeqBiTree,int i_dwSrcPos,T_SeqBiTreeElement *i_ptDstSeqBiTree,int i_dwDstPos)
{
	if(i_ptSrcSeqBiTree[2*i_dwSrcPos+1].iData!=0)// ��q��j������������ΪT��i����������
	{
		MoveSeqBiTree(i_ptSrcSeqBiTree,2*i_dwSrcPos+1,i_ptDstSeqBiTree,2*i_dwDstPos+1);
	}
	else
	{
	}
	if(i_ptSrcSeqBiTree[2*i_dwSrcPos+2].iData!=0)// ��q��j������������ΪT��i����������
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
//�������:����i_iLeftOrRightΪ0��1,����i_ptInsertTreeΪi_ptSeqBiTree��
i_ptInsertNode���������������
i_ptInsertNode����ԭ��������������Ϊi_ptInsertTree��������
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
	for(i=0;i<(int)(pow(2,GetSeqBiTreeDepth(i_ptSeqBiTree)))-1;i++)// ����i_ptInsertNode�����
	{
		if(0==memcmp(&i_ptSeqBiTree[i],i_ptInsertNode,sizeof(T_SeqBiTreeElement)))
		{
			break;
		}
		else
		{
		}
	}
	i_dwInsertChildPos=2*i+1+i_iLeftOrRight;//i_dwInsertChildPosΪi_ptInsertNode������Һ��ӵ����
	if(i_ptSeqBiTree[i_dwInsertChildPos].iData!=0)
	{// �Ѵ�i_ptSeqBiTree��i_dwInsertChildPos��㿪ʼ��������Ϊ��i_dwInsertChildPos������������ʼ������
		MoveSeqBiTree(i_ptSeqBiTree,i_dwInsertChildPos,i_ptSeqBiTree,2*i_dwInsertChildPos+2);
		//��㿪ʼ�������ƶ�����㺢�ӿ�ʼ������,�ݹ鵼����ִ��������ƶ���
		//Ŀ��Ŀսڵ��ϣ���ʱԭ��Ԫ���Ѿ����棬�Ϳ��Լ����ƶ���㣬������
		//����Ԫ���������
	}
	else
	{
	}
	MoveSeqBiTree(i_ptInsertTree,0,i_ptSeqBiTree,i_dwInsertChildPos);// �Ѵ�i_ptInsertTree�Ŀ�ʼ��������Ϊ��i_ptSeqBiTree��i_dwInsertChildPos��㿪ʼ������
//����ǰ��Ĳ���ͬʱҲ������
//i_ptInsertNode����ԭ��������������Ϊi_ptInsertTree��������
}
/*****************************************************************************
-Fuction		: DeleteChildInSeqBiTree
-Description	:
// �������������LRΪ1��0��ɾ��T��p��ָ�������������
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
	// ���㡢�������תΪ��������
	i=(int)pow(2,i_ptDeleteNodePos->iLevel-1)+i_ptDeleteNodePos->iOrder-2;// ���㡢�������תΪ��������
	if(i_ptSeqBiTree[i].iData==0)// �˽���
	{
		iRet=-1;
		printf("DeleteNodeIsNull,err\r\n");
	}
	else
	{
		i=2*i+1+i_iLeftOrRight;// ��ɾ�������ĸ�����ھ����е����
		//printf("DeleteNodePos:%d\r\n",i);
		while(iRet==0)
		{
			if(i_ptSeqBiTree[2*i+1].iData!=0)
			{
				EnterLinkQueue(&tLinkQueue,(char)(2*i+1));// �����������	
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
			iRet=ExitLinkQueue(&tLinkQueue,(char *)&i);// ���в���
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
	if(i_ptSeqBiTree[i_dwPos*2+1].iData!=0)// ����������
	{
		PreTraverseSeqBiTree(i_ptSeqBiTree,i_dwPos*2+1);
	}
	else{
	}
	if(i_ptSeqBiTree[i_dwPos*2+2].iData!=0)// ����������
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
	if(i_ptSeqBiTree[i_dwPos*2+1].iData!=0)// ����������
	{
		InTraverseSeqBiTree(i_ptSeqBiTree,i_dwPos*2+1);
	}
	else{
	}
	printf("%d ",i_ptSeqBiTree[i_dwPos].iData);
	if(i_ptSeqBiTree[i_dwPos*2+2].iData!=0)// ����������
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
	if(i_ptSeqBiTree[i_dwPos*2+1].iData!=0)// ����������
	{
		PostTraverseSeqBiTree(i_ptSeqBiTree,i_dwPos*2+1);
	}
	else{
	}
	if(i_ptSeqBiTree[i_dwPos*2+2].iData!=0)// ����������
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
-Description	:// �������������
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
		i--;// �ҵ����һ���ǿս������
	}
	for(j=0;j<=i;j++)// �Ӹ�����𣬰��������������
	{
		if(0==i_ptSeqBiTree[j].iData)
		{
		}
		else
		{
			printf("%d ",i_ptSeqBiTree[j].iData);// ֻ�����ǿյĽ��
		}
	}
	printf("\r\n");
}
/*****************************************************************************
-Fuction		: PrintfSeqBiTree
-Description	:// ��㡢������������������
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
		printf("��%d��: ",i);
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







