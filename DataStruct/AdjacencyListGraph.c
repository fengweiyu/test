/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	AdjacencyListGraph.c
* Description		: 	AdjacencyListGraph operation center
* Created			: 	2017.06.02.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include "LinkListClearOprNoHeadNode.c"


static int PutVertexNewData(T_AdjacencyListGraph *i_ptAdjacencyListGraph,T_VertexData *i_ptVertexData,T_VertexData *i_ptVertexNewData);

static void InitAdjacencyListGraph(T_AdjacencyListGraph *i_ptAdjacencyListGraph);
static void InsertVertex(T_AdjacencyListGraph *i_ptAdjacencyListGraph,T_VertexData *i_ptVertexData);
static int InsertArc(T_AdjacencyListGraph *i_ptAdjacencyListGraph,T_VertexData *i_ptVertexData,T_VertexData *i_ptAdjVertexData);
static int DeleteArc(T_AdjacencyListGraph *i_ptAdjacencyListGraph,T_VertexData *i_ptVertexData,T_VertexData *i_ptAdjVertexData);
static int DeleteVertex(T_AdjacencyListGraph *i_ptAdjacencyListGraph,T_VertexData *i_ptVertexData);

static void DisplayGraph(T_AdjacencyListGraph *i_ptAdjacencyListGraph);
static void DestroyGraph(T_AdjacencyListGraph *i_ptAdjacencyListGraph);
/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/01	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
/*int main(int argc,char **argv)
{
	int i,j,k,n;
	T_AdjacencyListGraph tGraph;
	T_VertexData v1,v2;
	printf("��˳��ѡ������ͼ,������,����ͼ,������\n");
	for(i=0;i<4;i++) // ��֤4�����
	{
		InitAdjacencyListGraph(&tGraph);
		DisplayGraph(&tGraph);
		printf("�����¶��㣬�����붥���ֵ: ");
		scanf("%s",v1.acData);
		InsertVertex(&tGraph,&v1);
		printf("�������¶����йصĻ���ߣ������뻡�����: ");
		scanf("%d",&n);
		for(k=0;k<n;k++)
		{
			printf("��������һ�����ֵ: ");
			scanf("%s",v2.acData);
			if(tGraph.iKind<=1) // ����
			{
				printf("��������ͼ��������������һ����ķ���(0:��ͷ1:��β): ");
				scanf("%d",&j);
				if(j)
				InsertArc(&tGraph,&v2,&v1);
				else
				InsertArc(&tGraph,&v1,&v2);
			}
			else // ����
			{
				InsertArc(&tGraph,&v1,&v2);
			}
		}
		DisplayGraph(&tGraph);
		if(i==3)
		{
			printf("ɾ��һ���߻򻡣��������ɾ���߻򻡵Ļ�β��ͷ��");
			scanf("%s%s",v1.acData,v2.acData);
			DeleteArc(&tGraph,&v1,&v2);
			printf("�޸Ķ����ֵ��������ԭֵ��ֵ: ");
			scanf("%s%s",v1.acData,v2.acData);
			PutVertexNewData(&tGraph,&v1,&v2);
		}
		printf("ɾ�����㼰��صĻ���ߣ������붥���ֵ: ");
		scanf("%s",v1.acData);
		DeleteVertex(&tGraph,&v1);
		DisplayGraph(&tGraph);
		DestroyGraph(&tGraph);
	}
}*/

/*****************************************************************************
-Fuction		: LocateVertex
-Description	: 
// �����������G�д��ڶ���i_ptVertexData���򷵻ظö�����ͼ��λ��
�����򷵻�-1
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int LocateVertex(T_AdjacencyListGraph *i_ptAdjacencyListGraph,T_VertexData *i_ptVertexData)
{
	int i;
	for(i=0;i<i_ptAdjacencyListGraph->iVexNum;i++)
	{
		if(0==strncmp(i_ptAdjacencyListGraph->atVertexList[i].tData.acData,i_ptVertexData->acData,MAX_NAME))
		{
			break;
		}
		else
		{
		}
	}
	if(i<i_ptAdjacencyListGraph->iVexNum)
	{
	}
	else
	{
		i=-1;
	}
	return i;
}

/*****************************************************************************
-Fuction		: InitAdjacencyListGraph
-Description	: 
// �����ڽӱ�洢�ṹ������û�������Ϣͼ����G(��һ����������4��ͼ)

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void InitAdjacencyListGraph(T_AdjacencyListGraph *i_ptAdjacencyListGraph)
{
	int i,j,k,w; // w��Ȩֵ
	T_VertexNode tVa,tVb; // ���ӱ߻򻡵�2����
	T_LinkListElement tElement;
	printf("������ͼ������(����ͼ:0,������:1,����ͼ:2,������:3): ");
	scanf("%d",&i_ptAdjacencyListGraph->iKind);
	printf("������ͼ�Ķ�����,����: ");
	scanf("%d,%d",&i_ptAdjacencyListGraph->iVexNum,&i_ptAdjacencyListGraph->iArcNum);
	printf("������%d�������ֵ(<%d���ַ�):\n",i_ptAdjacencyListGraph->iVexNum,MAX_NAME);
	for(i=0;i<i_ptAdjacencyListGraph->iVexNum;++i) // ���춥������
	{
		scanf("%s",i_ptAdjacencyListGraph->atVertexList[i].tData.acData);
		i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode=NULL; // ��ʼ����ö����йصĳ�������
	}
	if(i_ptAdjacencyListGraph->iKind%2) // ��
	printf("������ÿ����(��)��Ȩֵ����β�ͻ�ͷ(�Կո���Ϊ���):\n");
	else // ͼ
	printf("������ÿ����(��)�Ļ�β�ͻ�ͷ(�Կո���Ϊ���):\n");
	for(k=0;k<i_ptAdjacencyListGraph->iArcNum;++k) // ������ػ�����
	{
		if(i_ptAdjacencyListGraph->iKind%2) // ��
		scanf("%d%s%s",&w,tVa.tData.acData,tVb.tData.acData);
		else // ͼ
		scanf("%s%s",tVa.tData.acData,tVb.tData.acData);
		i=LocateVertex(i_ptAdjacencyListGraph,&tVa.tData); // ��β
		j=LocateVertex(i_ptAdjacencyListGraph,&tVb.tData); // ��ͷ
		tElement.pcInfo=NULL; // ���������e��ֵ��ͼ��Ȩ
		tElement.iAdjvex=j; // ��ͷ
		if(i_ptAdjacencyListGraph->iKind%2) // ��
		{
			tElement.pcInfo=(T_InfoType *)malloc(sizeof(T_InfoType)); // ��̬���ɴ��Ȩֵ�Ŀռ�
			tElement.pcInfo->iWeight=w;
		}
		else{
		}
		InsertNodeToLinkList(&i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode,1,&tElement); // ���ڵ�i��Ԫ��(����)�ı�ͷ
		if(i_ptAdjacencyListGraph->iKind>=2) // ����ͼ������������2�����㣬�����ڵ�j��Ԫ��(�뻡)�ı�ͷ
		{//����
			tElement.iAdjvex=i; // e.info���䣬�����ٸ�ֵ
			InsertNodeToLinkList(&i_ptAdjacencyListGraph->atVertexList[j].ptFirstArcNode,1,&tElement); // ���ڵ�j��Ԫ�صı�ͷ
		}
		else
		{
		}
	}
}

/*****************************************************************************
-Fuction		: CreateAdjacencyListGraphFromFile
-Description	:
// �����ڽӱ�洢�ṹ�����ļ�����û�������Ϣͼ����G(��һ����������4��ͼ)
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void CreateAdjacencyListGraphFromFile(T_AdjacencyListGraph *i_ptAdjacencyListGraph)
{
	int i,j,k,w; // w��Ȩֵ
	T_VertexNode tVa,tVb; // ���ӱ߻򻡵�2����
	T_LinkListElement tElement;
	char strFileName[30]={0};
	FILE *fileGraphList;
	printf("�����������ļ���(f7-1.txt��f7-2.txt)��");
	scanf("%s",strFileName);
	printf("������ͼ������(����ͼ:0,������:1,����ͼ:2,������:3): ");
	scanf("%d",&i_ptAdjacencyListGraph->iKind);
	fileGraphList=fopen(strFileName,"r"); // �Զ��ķ�ʽ�������ļ�������fileGraphList��ʾ
	fscanf(fileGraphList,"%d",&i_ptAdjacencyListGraph->iVexNum);
	fscanf(fileGraphList,"%d",&i_ptAdjacencyListGraph->iArcNum);
	
	for(i=0;i<i_ptAdjacencyListGraph->iVexNum;++i) // ���춥������
	{
		fscanf(fileGraphList,"%s",i_ptAdjacencyListGraph->atVertexList[i].tData.acData);
		i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode=NULL; // ��ʼ����ö����йصĳ�������
	}
	for(k=0;k<i_ptAdjacencyListGraph->iArcNum;++k) // ������ػ�����
	{
		if(i_ptAdjacencyListGraph->iKind%2) // ��
		fscanf(fileGraphList,"%d%s%s",&w,tVa.tData.acData,tVb.tData.acData);
		else // ͼ
		fscanf(fileGraphList,"%s%s",tVa.tData.acData,tVb.tData.acData);
		i=LocateVertex(i_ptAdjacencyListGraph,&tVa.tData); // ��β
		j=LocateVertex(i_ptAdjacencyListGraph,&tVb.tData); // ��ͷ
		tElement.pcInfo=NULL; // ���������e��ֵ��ͼ��Ȩ
		tElement.iAdjvex=j; // ��ͷ
		if(i_ptAdjacencyListGraph->iKind%2) // ��
		{
			tElement.pcInfo=(T_InfoType *)malloc(sizeof(T_InfoType)); // ��̬���ɴ��Ȩֵ�Ŀռ�
			tElement.pcInfo->iWeight=w;
		}
		else{
		}
		InsertNodeToLinkList(&i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode,1,&tElement); // ���ڵ�i��Ԫ��(����)�ı�ͷ
		if(i_ptAdjacencyListGraph->iKind>=2) // ����ͼ������������2�����㣬�����ڵ�j��Ԫ��(�뻡)�ı�ͷ
		{//����
			tElement.iAdjvex=i; // e.info���䣬�����ٸ�ֵ
			InsertNodeToLinkList(&i_ptAdjacencyListGraph->atVertexList[j].ptFirstArcNode,1,&tElement); // ���ڵ�j��Ԫ�صı�ͷ
		}
		else
		{
		}
	}
	fclose(fileGraphList); // �ر������ļ�
}


/*****************************************************************************
-Fuction		: DestroyGraph
-Description	: 
// ��ʼ������ͼG���ڡ��������������ͼG
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void DestroyGraph(T_AdjacencyListGraph *i_ptAdjacencyListGraph)
{
	int i;
	T_LinkListElement tElement;
	for(i=0;i<i_ptAdjacencyListGraph->iVexNum;i++)
	{
		if(i_ptAdjacencyListGraph->iKind%2) // ��
		{
			while(i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode!=NULL)
			{
				DeleteNodeFromLinkList(&i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode,1,&tElement); // ɾ������ĵ�1����㣬����ֵ����e
				if(tElement.iAdjvex>i) // ÿ���������>i(��֤����һ�μ���֤��̬���ɵ�Ȩֵ�ռ�ֻ�ͷ�1��)
				free(tElement.pcInfo);
			}

		}
		else
		{
			DestroyLinkList(i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode); // ���ٻ����������bo2-8.cpp��
		}
	}
	i_ptAdjacencyListGraph->iVexNum=0; // ������Ϊ0
	i_ptAdjacencyListGraph->iArcNum=0; // �߻���Ϊ0
}


/*****************************************************************************
-Fuction		: GetVertexData
-Description	: 
// ��ʼ������ͼG���ڣ�v��G��ĳ���������š�
�������������v��ֵ
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int GetVertexData(T_AdjacencyListGraph *i_ptAdjacencyListGraph,int i_ptVertexNum,T_VertexData *o_ptVertexData)
{
	int iRet=-1;
	if(i_ptVertexNum<0||i_ptVertexNum>=i_ptAdjacencyListGraph->iVexNum)
	{
		iRet=-1;
		printf("GetVertexData err\r\n");
	}
	else
	{
		memcpy(o_ptVertexData,&i_ptAdjacencyListGraph->atVertexList[i_ptVertexNum].tData,sizeof(T_VertexData));
		iRet=0;
	}

	return iRet;
}


/*****************************************************************************
-Fuction		: PutVertexNewData
-Description	: 
// ��ʼ������ͼG���ڣ�v��G��ĳ�����㡣
�����������v����ֵvalue
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int PutVertexNewData(T_AdjacencyListGraph *i_ptAdjacencyListGraph,T_VertexData *i_ptVertexData,T_VertexData *i_ptVertexNewData)
{
	int iRet=-1;
	int iPos=-1;
	iPos=LocateVertex(i_ptAdjacencyListGraph,i_ptVertexData);
	if(iPos>-1) // v��G�Ķ���
	{
		memcpy(&i_ptAdjacencyListGraph->atVertexList[iPos].tData,i_ptVertexNewData,sizeof(T_VertexData));
		iRet=0;
	}
	else
	{
		iRet=-1;
		printf("PutVertexNewData err\r\n");
	}

	return iRet;
}



/*****************************************************************************
-Fuction		: GetFirstAdjacencyVertex
-Description	: 
// ��ʼ������ͼG���ڣ�v��G��ĳ������
// �������������v�ĵ�һ���ڽӶ������š���������G��û���ڽӶ��㣬�򷵻�-1
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int GetFirstAdjacencyVertex(T_AdjacencyListGraph *i_ptAdjacencyListGraph,T_VertexData *i_ptVertexData)
{
	int iNum=-1;
	T_ArcNode*ptArcNode=NULL;
	iNum=LocateVertex(i_ptAdjacencyListGraph,i_ptVertexData);
	if(-1==iNum)
	{	
	}
	else
	{
		ptArcNode=i_ptAdjacencyListGraph->atVertexList[iNum].ptFirstArcNode;
		if(NULL==ptArcNode)
		{
			iNum=-1;
		}
		else
		{
			iNum=ptArcNode->tData.iAdjvex;
		}
	}
	return iNum;
}


/*****************************************************************************
-Fuction		: EqualVertex
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int EqualVertex(T_LinkListElement *i_ptElement1,T_LinkListElement *i_ptElement2)
{
	int iRet=-1;
	if(i_ptElement1->iAdjvex!=i_ptElement2->iAdjvex)
	{
		iRet=-1;
	}
	else
	{
		iRet=0;
	}

	return iRet;
}



/*****************************************************************************
-Fuction		: GetNextAdjacencyVertex
-Description	: 
// ��ʼ������ͼG���ڣ�v(i_ptVertexData)��G��ĳ�����㣬w(i_ptAdjVertexData)��v���ڽӶ���
// �������������v��(�����w��)��һ���ڽӶ������š���w��v�����һ���ڽӵ㣬�򷵻�-1
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int GetNextAdjacencyVertex(T_AdjacencyListGraph *i_ptAdjacencyListGraph,T_VertexData *i_ptVertexData,T_VertexData *i_ptAdjVertexData)
{
	int iNum;
	int iAdjNextVertexNum=-1;
	T_LinkList *ptLinkListNode=NULL;
	T_LinkList *ptLinkListPreNode=NULL;
	T_LinkListElement tElement={0};
	iNum=LocateVertex(i_ptAdjacencyListGraph,i_ptVertexData);// iNumΪ����v��ͼG�е����
	tElement.iAdjvex=LocateVertex(i_ptAdjacencyListGraph,i_ptAdjVertexData);// tElement.adjvexΪ����w��ͼG�е����
	ptLinkListNode=GetLinkListNodePoint(i_ptAdjacencyListGraph->atVertexList[iNum].ptFirstArcNode,&tElement,EqualVertex,&ptLinkListPreNode);
	if(NULL==ptLinkListNode||NULL==ptLinkListNode->ptNext)// ptLinkListNodeָ�򶥵�v���������ڽӶ���Ϊw�Ľ��
	{// û�ҵ�w��w�����һ���ڽӵ�
		iAdjNextVertexNum=-1;
	}
	else
	{// ����v��(�����w��)��һ���ڽӶ�������
		iAdjNextVertexNum=ptLinkListNode->ptNext->tData.iAdjvex;
	}
	return iAdjNextVertexNum;

}



/*****************************************************************************
-Fuction		: InsertVertex
-Description	: 
// ��ʼ������ͼG���ڣ�v��ͼ�ж�������ͬ����
// �����������ͼG�������¶���v(�������붥����صĻ�������InsertArc()ȥ��)
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void InsertVertex(T_AdjacencyListGraph *i_ptAdjacencyListGraph,T_VertexData *i_ptVertexData)
{
	memcpy(&i_ptAdjacencyListGraph->atVertexList[i_ptAdjacencyListGraph->iVexNum].tData, i_ptVertexData,sizeof(T_VertexData));// �����¶�������
	i_ptAdjacencyListGraph->atVertexList[i_ptAdjacencyListGraph->iVexNum].ptFirstArcNode=NULL;
	i_ptAdjacencyListGraph->iVexNum++;// ͼG�Ķ�������1

}

/*****************************************************************************
-Fuction		: DeleteVertex
-Description	: 
// ��ʼ������ͼG���ڣ�v��G��ĳ�����㡣���������ɾ��G�ж���v������صĻ�
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int DeleteVertex(T_AdjacencyListGraph *i_ptAdjacencyListGraph,T_VertexData *i_ptVertexData)
{
	int iRet=-1;
	int i,j,k;	
	T_LinkList *ptLinkListNode=NULL;
	T_LinkList *ptLinkListPreNode=NULL;
	T_LinkListElement tElement={0};
	j=LocateVertex(i_ptAdjacencyListGraph,i_ptVertexData);
	if(j<0)
	{
		iRet=-1;
		printf("CannotFindVertex:%dr\r\n",j);
	}
	else
	{
		i=GetLinkListLength(i_ptAdjacencyListGraph->atVertexList[j].ptFirstArcNode);// ��vΪ���ȵĻ������
		i_ptAdjacencyListGraph->iArcNum-=i;// �߻���-i
		if(i_ptAdjacencyListGraph->iKind%2)//// ��
		{
			while(i_ptAdjacencyListGraph->atVertexList[j].ptFirstArcNode)// ��Ӧ�Ļ����������
			{
				DeleteNodeFromLinkList(&i_ptAdjacencyListGraph->atVertexList[j].ptFirstArcNode,1,&tElement);// ɾ������ĵ�1����㣬����ֵ����e
				free(tElement.pcInfo);// �ͷŶ�̬���ɵ�Ȩֵ�ռ�
			}
		}
		else// ͼ
		{
			DestroyLinkList(i_ptAdjacencyListGraph->atVertexList[j].ptFirstArcNode);// ���ٻ��������
		}
		i_ptAdjacencyListGraph->iVexNum--;// ��������1(j��0��ʼ������ǰ���һ)
		for(i=j;i<i_ptAdjacencyListGraph->iVexNum;i++)// ����v����Ķ���ǰ��
		{
			i_ptAdjacencyListGraph->atVertexList[i]=i_ptAdjacencyListGraph->atVertexList[i+1];
		}
		for(i=0;i<i_ptAdjacencyListGraph->iVexNum;i++)
		{// ɾ����vΪ��ȵĻ�����ұ�Ҫʱ�޸ı���Ķ���λ��ֵ
			tElement.iAdjvex=j;
			ptLinkListNode=GetLinkListNodePoint(i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode,&tElement,EqualVertex,&ptLinkListPreNode);
			if(NULL==ptLinkListNode)// ����i���ڽӱ�����vΪ��ȵĽ��
			{
			}
			else// ����i���ڽӱ�����vΪ��ȵĽ��
			{
				if(NULL==ptLinkListPreNode)// pָ����Ԫ���
				{
					i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode=ptLinkListNode->ptNext;// ͷָ��ָ����һ���
				}
				else// p1ָ��p��ָ����ǰ��
				{
					ptLinkListPreNode->ptNext=ptLinkListNode->ptNext;// ��������ɾ��p��ָ���
				}
				if(i_ptAdjacencyListGraph->iKind<2)// ����
				{
					i_ptAdjacencyListGraph->iArcNum--;// �߻���-1
					if(i_ptAdjacencyListGraph->iKind==1)// ������
					{
						free(ptLinkListNode->tData.pcInfo);// �ͷŶ�̬���ɵ�Ȩֵ�ռ�
					}
					else
					{
					}
				}
				else
				{
				}
				free(ptLinkListNode);	
			}
			for(k=j+1;k<=i_ptAdjacencyListGraph->iVexNum;k++)
			{// ����adjvex��>j�Ľ�㣬�����-1(��ָ����ָ�򶥵����(�����±�)ɾ����Ҫ��һ)
				tElement.iAdjvex=k;
				ptLinkListNode=GetLinkListNodePoint(i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode,&tElement,EqualVertex,&ptLinkListPreNode);
				if(NULL==ptLinkListNode)
				{
				}
				else
				{
					ptLinkListNode->tData.iAdjvex--;// ���-1(��Ϊǰ��)
				}
			}
		}
		iRet=0;
	}
	return iRet;
}


/*****************************************************************************
-Fuction		: InsertArc
-Description	: 
// ��ʼ������ͼG���ڣ�v(i_ptVertexData)��w(i_ptAdjVertexData)��G����������
// �����������G������<v,w>����G������ģ�������Գƻ�<w,v>
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int InsertArc(T_AdjacencyListGraph *i_ptAdjacencyListGraph,T_VertexData *i_ptVertexData,T_VertexData *i_ptAdjVertexData)
{
	int i,j;
	int iRet=-1;
	T_LinkListElement tElement={0};
	i=LocateVertex(i_ptAdjacencyListGraph,i_ptVertexData);// ��β��ߵ����
	j=LocateVertex(i_ptAdjacencyListGraph,i_ptAdjVertexData);// ��ͷ��ߵ����
	if(i<0||j<0)
	{
		iRet=-1;
	}
	else
	{
		i_ptAdjacencyListGraph->iArcNum++;
		tElement.iAdjvex=j;
		tElement.pcInfo=NULL;
		if(i_ptAdjacencyListGraph->iKind%2)//// ��
		{
			tElement.pcInfo=(T_InfoType *)malloc(sizeof(T_InfoType));
			printf("�����뻡(��)%s��%s��Ȩֵ: ",i_ptVertexData->acData,i_ptAdjVertexData->acData);
			scanf("%d",&tElement.pcInfo->iWeight);
		}
		else
		{
		}
		InsertNodeToLinkList(&i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode,1,&tElement);// ��tElement���ڻ�β�ı�ͷ
		if(i_ptAdjacencyListGraph->iKind>=2) // ����������һ������
		{
			tElement.iAdjvex=i; // e.info����
			InsertNodeToLinkList(&i_ptAdjacencyListGraph->atVertexList[j].ptFirstArcNode,1,&tElement);// ��e���ڻ�ͷ�ı�ͷ
		}
		else
		{
		}
		iRet=0;
	}
	return iRet;
}


/*****************************************************************************
-Fuction		: DeleteArc
-Description	: 
// ��ʼ������ͼG���ڣ�v��w��G����������
// �����������G��ɾ����<v,w>����G������ģ���ɾ���Գƻ�<w,v>
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int DeleteArc(T_AdjacencyListGraph *i_ptAdjacencyListGraph,T_VertexData *i_ptVertexData,T_VertexData *i_ptAdjVertexData)
{
	int i,j;
	int iRet=-1;
	T_LinkListElement tElement={0};
	i=LocateVertex(i_ptAdjacencyListGraph,i_ptVertexData);// i�Ƕ���v(��β)�����
	j=LocateVertex(i_ptAdjacencyListGraph,i_ptAdjVertexData);// j�Ƕ���w(��ͷ)�����
	if(i<0||j<0)// û�ҵ���ɾ���Ļ�
	{
		iRet=-1;
	}
	else
	{
		tElement.iAdjvex=j;
		iRet=DeleteElementFromLinkList(i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode,&tElement,EqualVertex);
		if(0!=iRet)
		{
		}
		else// ɾ���ɹ�
		{
			i_ptAdjacencyListGraph->iArcNum--;// ���������1
			if(i_ptAdjacencyListGraph->iKind%2)//// ��
			{
				free(tElement.pcInfo);
			}
			else{
			}
			if(i_ptAdjacencyListGraph->iKind>=2) // ����ɾ���Գƻ�<w,v>
			{
				tElement.iAdjvex=i;
				iRet=DeleteElementFromLinkList(i_ptAdjacencyListGraph->atVertexList[j].ptFirstArcNode,&tElement,EqualVertex);
			}
			else
			{
			}
		}
	}
	return iRet;
}


/*****************************************************************************
-Fuction		: DisplayGraph
-Description	: 
// ���ͼ���ڽӾ���G
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void DisplayGraph(T_AdjacencyListGraph *i_ptAdjacencyListGraph)
{
	int i;
	T_ArcNode *ptAcrNode=NULL;
	switch(i_ptAdjacencyListGraph->iKind)
	{
		case DG: 
			printf("����ͼ\n");
		break;
		case DN: 
			printf("������\n");
		break;
		case UDG: 
			printf("����ͼ\n");
		break;
		case UDN: 
			printf("������\n");
	}
	printf("%d�����㣺\n",i_ptAdjacencyListGraph->iVexNum);
	for(i=0;i<i_ptAdjacencyListGraph->iVexNum;++i)
	printf("%s ",i_ptAdjacencyListGraph->atVertexList[i].tData.acData);
	printf("\n%d����(��):\n",i_ptAdjacencyListGraph->iArcNum);
	for(i=0;i<i_ptAdjacencyListGraph->iVexNum;i++)
	{
		ptAcrNode=i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode;
		while(NULL!=ptAcrNode)
		{
			if(i_ptAdjacencyListGraph->iKind<=1||i<ptAcrNode->tData.iAdjvex) // ��������������е�һ��
			{
				printf("%s-->%s ",i_ptAdjacencyListGraph->atVertexList[i].tData.acData,i_ptAdjacencyListGraph->atVertexList[ptAcrNode->tData.iAdjvex].tData.acData);
				if(i_ptAdjacencyListGraph->iKind%2) // ��
				printf(":%d ",ptAcrNode->tData.pcInfo->iWeight);
			}
			ptAcrNode=ptAcrNode->ptNext;
		}
		printf("\n");
	}
}
















