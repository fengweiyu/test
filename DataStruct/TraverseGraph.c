/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	TraverseGraph.c
* Description		: 	TraverseGraph operation center
* Created			: 	2017.06.12.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include "LinkQueue.c"
#include "AdjacencyListGraph.c"

static void DFSTraverse(T_AdjacencyListGraph *i_ptAdjacencyListGraph);
static void BFSTraverse(T_AdjacencyListGraph *i_ptAdjacencyListGraph);

#define FALSE	0
#define TRUE 		1

static char g_acVisitedFlag[MAX_VERTEX_NUM]={0};

/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_AdjacencyListGraph tGraph;
	CreateAdjacencyListGraphFromFile(&tGraph); // ���������ļ���������ͼ
	DisplayGraph(&tGraph);// �������ͼ
	printf("������������Ľ��:\n");
	DFSTraverse(&tGraph);
	printf("������������Ľ��:\n");
	BFSTraverse(&tGraph);
	DestroyGraph(&tGraph); // ����ͼg

	return 0;
}

/*****************************************************************************
-Fuction		: DFS
-Description	: // �ӵ�v(i_iPos)����������ݹ��������ȱ���ͼ
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void DFS(T_AdjacencyListGraph *i_ptAdjacencyListGraph,int i_iVertexPos)
{
	int iAdjacencyVertexPos=0;
	g_acVisitedFlag[i_iVertexPos]=TRUE;// ���÷��ʱ�־ΪTRUE(�ѷ���)
	printf("%s ",i_ptAdjacencyListGraph->atVertexList[i_iVertexPos].tData.acData);// ���ʵ�v������
	for(iAdjacencyVertexPos=GetFirstAdjacencyVertex(i_ptAdjacencyListGraph,&i_ptAdjacencyListGraph->atVertexList[i_iVertexPos].tData);
	      iAdjacencyVertexPos>=0;
	      iAdjacencyVertexPos=GetNextAdjacencyVertex(i_ptAdjacencyListGraph,&i_ptAdjacencyListGraph->atVertexList[i_iVertexPos].tData,&i_ptAdjacencyListGraph->atVertexList[iAdjacencyVertexPos].tData))
	{
		if(TRUE==g_acVisitedFlag[iAdjacencyVertexPos])
		{
		}
		else
		{
			DFS(i_ptAdjacencyListGraph,iAdjacencyVertexPos);// ��v����δ���ʵ��ڽӵ�w(iAdjacencyVertexPos)�ݹ����DFS
		}
	}
}

/*****************************************************************************
-Fuction		: DFSTraverse
-Description	: // ��ͼG��������ȱ�����
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void DFSTraverse(T_AdjacencyListGraph *i_ptAdjacencyListGraph)
{
	int i;
	for(i=0;i<i_ptAdjacencyListGraph->iVexNum;i++)
	{
		g_acVisitedFlag[i]=FALSE;// ���ʱ�־�����ʼ��
	}
	for(i=0;i<i_ptAdjacencyListGraph->iVexNum;i++)
	{
		if(TRUE==g_acVisitedFlag[i])
		{
		}
		else
		{
			DFS(i_ptAdjacencyListGraph,i);// ����δ���ʵĶ������DFS
		}
	}
	printf("\r\n");
}

/*****************************************************************************
-Fuction		: BFSTraverse
-Description	: //��������ȷǵݹ����ͼG��ʹ�ø�������Q�ͷ��ʱ�־����visited
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void BFSTraverse(T_AdjacencyListGraph *i_ptAdjacencyListGraph)
{
	int v,u,w;
	T_LinkQueue tLinkQueue={0};
	T_QueueDataElement tEnterElement={0};	
	T_QueueDataElement tExitElement={0};
	for(v=0;v<i_ptAdjacencyListGraph->iVexNum;v++)
	{
		g_acVisitedFlag[v]=FALSE;// ���ʱ�־�����ʼ��
	}
	InitLinkQueue(&tLinkQueue);
	for(v=0;v<i_ptAdjacencyListGraph->iVexNum;v++)// �������ͨͼ��ֻv=0�ͱ���ȫͼ
	{
		if(TRUE==g_acVisitedFlag[v])
		{
		}
		else// v��δ����
		{
			g_acVisitedFlag[v]=TRUE;
			printf("%s ",i_ptAdjacencyListGraph->atVertexList[v].tData.acData);
			tEnterElement.iData=v;
			EnterLinkQueue(&tLinkQueue,tEnterElement);// v�����
			while(0!=IsLinkQueueEmpty(&tLinkQueue))// ���в���
			{
				ExitLinkQueue(&tLinkQueue,&tExitElement);// �������ڷ���������ڽӵ�	
				u=tExitElement.iData;
				for(w=GetFirstAdjacencyVertex(i_ptAdjacencyListGraph,&i_ptAdjacencyListGraph->atVertexList[u].tData);
				      w>=0;
				      w=GetNextAdjacencyVertex(i_ptAdjacencyListGraph,&i_ptAdjacencyListGraph->atVertexList[u].tData,&i_ptAdjacencyListGraph->atVertexList[w].tData))
				{
					  if(TRUE==g_acVisitedFlag[w])
					  {
					  }
					  else// wΪu����δ���ʵ��ڽӶ���
					  {
						  g_acVisitedFlag[w]=TRUE;
						  printf("%s ",i_ptAdjacencyListGraph->atVertexList[w].tData.acData);
						  tEnterElement.iData=w;
						  EnterLinkQueue(&tLinkQueue,tEnterElement);// w���,�������ڽӵ��������ɴ˿ɰ�˳�������һ���ڽӵ�
					  }		  
				}
			}
		}
	}
	printf("\r\n");
}

