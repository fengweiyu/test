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
	CreateAdjacencyListGraphFromFile(&tGraph); // 利用数据文件创建无向图
	DisplayGraph(&tGraph);// 输出无向图
	printf("深度优先搜索的结果:\n");
	DFSTraverse(&tGraph);
	printf("广度优先搜索的结果:\n");
	BFSTraverse(&tGraph);
	DestroyGraph(&tGraph); // 销毁图g

	return 0;
}

/*****************************************************************************
-Fuction		: DFS
-Description	: // 从第v(i_iPos)个顶点出发递归地深度优先遍历图
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
	g_acVisitedFlag[i_iVertexPos]=TRUE;// 设置访问标志为TRUE(已访问)
	printf("%s ",i_ptAdjacencyListGraph->atVertexList[i_iVertexPos].tData.acData);// 访问第v个顶点
	for(iAdjacencyVertexPos=GetFirstAdjacencyVertex(i_ptAdjacencyListGraph,&i_ptAdjacencyListGraph->atVertexList[i_iVertexPos].tData);
	      iAdjacencyVertexPos>=0;
	      iAdjacencyVertexPos=GetNextAdjacencyVertex(i_ptAdjacencyListGraph,&i_ptAdjacencyListGraph->atVertexList[i_iVertexPos].tData,&i_ptAdjacencyListGraph->atVertexList[iAdjacencyVertexPos].tData))
	{
		if(TRUE==g_acVisitedFlag[iAdjacencyVertexPos])
		{
		}
		else
		{
			DFS(i_ptAdjacencyListGraph,iAdjacencyVertexPos);// 对v的尚未访问的邻接点w(iAdjacencyVertexPos)递归调用DFS
		}
	}
}

/*****************************************************************************
-Fuction		: DFSTraverse
-Description	: // 对图G作深度优先遍历。
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
		g_acVisitedFlag[i]=FALSE;// 访问标志数组初始化
	}
	for(i=0;i<i_ptAdjacencyListGraph->iVexNum;i++)
	{
		if(TRUE==g_acVisitedFlag[i])
		{
		}
		else
		{
			DFS(i_ptAdjacencyListGraph,i);// 对尚未访问的顶点调用DFS
		}
	}
	printf("\r\n");
}

/*****************************************************************************
-Fuction		: BFSTraverse
-Description	: //按广度优先非递归遍历图G。使用辅助队列Q和访问标志数组visited
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
		g_acVisitedFlag[v]=FALSE;// 访问标志数组初始化
	}
	InitLinkQueue(&tLinkQueue);
	for(v=0;v<i_ptAdjacencyListGraph->iVexNum;v++)// 如果是连通图，只v=0就遍历全图
	{
		if(TRUE==g_acVisitedFlag[v])
		{
		}
		else// v尚未访问
		{
			g_acVisitedFlag[v]=TRUE;
			printf("%s ",i_ptAdjacencyListGraph->atVertexList[v].tData.acData);
			tEnterElement.iData=v;
			EnterLinkQueue(&tLinkQueue,tEnterElement);// v入队列
			while(0!=IsLinkQueueEmpty(&tLinkQueue))// 队列不空
			{
				ExitLinkQueue(&tLinkQueue,&tExitElement);// 出队用于访问其各个邻接点	
				u=tExitElement.iData;
				for(w=GetFirstAdjacencyVertex(i_ptAdjacencyListGraph,&i_ptAdjacencyListGraph->atVertexList[u].tData);
				      w>=0;
				      w=GetNextAdjacencyVertex(i_ptAdjacencyListGraph,&i_ptAdjacencyListGraph->atVertexList[u].tData,&i_ptAdjacencyListGraph->atVertexList[w].tData))
				{
					  if(TRUE==g_acVisitedFlag[w])
					  {
					  }
					  else// w为u的尚未访问的邻接顶点
					  {
						  g_acVisitedFlag[w]=TRUE;
						  printf("%s ",i_ptAdjacencyListGraph->atVertexList[w].tData.acData);
						  tEnterElement.iData=w;
						  EnterLinkQueue(&tLinkQueue,tEnterElement);// w入队,当本层邻接点访问完后，由此可按顺序访问下一层邻接点
					  }		  
				}
			}
		}
	}
	printf("\r\n");
}

