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
	printf("请顺序选择有向图,有向网,无向图,无向网\n");
	for(i=0;i<4;i++) // 验证4种情况
	{
		InitAdjacencyListGraph(&tGraph);
		DisplayGraph(&tGraph);
		printf("插入新顶点，请输入顶点的值: ");
		scanf("%s",v1.acData);
		InsertVertex(&tGraph,&v1);
		printf("插入与新顶点有关的弧或边，请输入弧或边数: ");
		scanf("%d",&n);
		for(k=0;k<n;k++)
		{
			printf("请输入另一顶点的值: ");
			scanf("%s",v2.acData);
			if(tGraph.iKind<=1) // 有向
			{
				printf("对于有向图或网，请输入另一顶点的方向(0:弧头1:弧尾): ");
				scanf("%d",&j);
				if(j)
				InsertArc(&tGraph,&v2,&v1);
				else
				InsertArc(&tGraph,&v1,&v2);
			}
			else // 无向
			{
				InsertArc(&tGraph,&v1,&v2);
			}
		}
		DisplayGraph(&tGraph);
		if(i==3)
		{
			printf("删除一条边或弧，请输入待删除边或弧的弧尾弧头：");
			scanf("%s%s",v1.acData,v2.acData);
			DeleteArc(&tGraph,&v1,&v2);
			printf("修改顶点的值，请输入原值新值: ");
			scanf("%s%s",v1.acData,v2.acData);
			PutVertexNewData(&tGraph,&v1,&v2);
		}
		printf("删除顶点及相关的弧或边，请输入顶点的值: ");
		scanf("%s",v1.acData);
		DeleteVertex(&tGraph,&v1);
		DisplayGraph(&tGraph);
		DestroyGraph(&tGraph);
	}
}*/

/*****************************************************************************
-Fuction		: LocateVertex
-Description	: 
// 操作结果：若G中存在顶点i_ptVertexData，则返回该顶点在图中位置
；否则返回-1
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
// 采用邻接表存储结构，构造没有相关信息图或网G(用一个函数构造4种图)

-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void InitAdjacencyListGraph(T_AdjacencyListGraph *i_ptAdjacencyListGraph)
{
	int i,j,k,w; // w是权值
	T_VertexNode tVa,tVb; // 连接边或弧的2顶点
	T_LinkListElement tElement;
	printf("请输入图的类型(有向图:0,有向网:1,无向图:2,无向网:3): ");
	scanf("%d",&i_ptAdjacencyListGraph->iKind);
	printf("请输入图的顶点数,边数: ");
	scanf("%d,%d",&i_ptAdjacencyListGraph->iVexNum,&i_ptAdjacencyListGraph->iArcNum);
	printf("请输入%d个顶点的值(<%d个字符):\n",i_ptAdjacencyListGraph->iVexNum,MAX_NAME);
	for(i=0;i<i_ptAdjacencyListGraph->iVexNum;++i) // 构造顶点向量
	{
		scanf("%s",i_ptAdjacencyListGraph->atVertexList[i].tData.acData);
		i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode=NULL; // 初始化与该顶点有关的出弧链表
	}
	if(i_ptAdjacencyListGraph->iKind%2) // 网
	printf("请输入每条弧(边)的权值、弧尾和弧头(以空格作为间隔):\n");
	else // 图
	printf("请输入每条弧(边)的弧尾和弧头(以空格作为间隔):\n");
	for(k=0;k<i_ptAdjacencyListGraph->iArcNum;++k) // 构造相关弧链表
	{
		if(i_ptAdjacencyListGraph->iKind%2) // 网
		scanf("%d%s%s",&w,tVa.tData.acData,tVb.tData.acData);
		else // 图
		scanf("%s%s",tVa.tData.acData,tVb.tData.acData);
		i=LocateVertex(i_ptAdjacencyListGraph,&tVa.tData); // 弧尾
		j=LocateVertex(i_ptAdjacencyListGraph,&tVb.tData); // 弧头
		tElement.pcInfo=NULL; // 给待插表结点e赋值，图无权
		tElement.iAdjvex=j; // 弧头
		if(i_ptAdjacencyListGraph->iKind%2) // 网
		{
			tElement.pcInfo=(T_InfoType *)malloc(sizeof(T_InfoType)); // 动态生成存放权值的空间
			tElement.pcInfo->iWeight=w;
		}
		else{
		}
		InsertNodeToLinkList(&i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode,1,&tElement); // 插在第i个元素(出弧)的表头
		if(i_ptAdjacencyListGraph->iKind>=2) // 无向图或网，产生第2个表结点，并插在第j个元素(入弧)的表头
		{//无向
			tElement.iAdjvex=i; // e.info不变，不必再赋值
			InsertNodeToLinkList(&i_ptAdjacencyListGraph->atVertexList[j].ptFirstArcNode,1,&tElement); // 插在第j个元素的表头
		}
		else
		{
		}
	}
}

/*****************************************************************************
-Fuction		: CreateAdjacencyListGraphFromFile
-Description	:
// 采用邻接表存储结构，由文件构造没有相关信息图或网G(用一个函数构造4种图)
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void CreateAdjacencyListGraphFromFile(T_AdjacencyListGraph *i_ptAdjacencyListGraph)
{
	int i,j,k,w; // w是权值
	T_VertexNode tVa,tVb; // 连接边或弧的2顶点
	T_LinkListElement tElement;
	char strFileName[30]={0};
	FILE *fileGraphList;
	printf("请输入数据文件名(f7-1.txt或f7-2.txt)：");
	scanf("%s",strFileName);
	printf("请输入图的类型(有向图:0,有向网:1,无向图:2,无向网:3): ");
	scanf("%d",&i_ptAdjacencyListGraph->iKind);
	fileGraphList=fopen(strFileName,"r"); // 以读的方式打开数据文件，并以fileGraphList表示
	fscanf(fileGraphList,"%d",&i_ptAdjacencyListGraph->iVexNum);
	fscanf(fileGraphList,"%d",&i_ptAdjacencyListGraph->iArcNum);
	
	for(i=0;i<i_ptAdjacencyListGraph->iVexNum;++i) // 构造顶点向量
	{
		fscanf(fileGraphList,"%s",i_ptAdjacencyListGraph->atVertexList[i].tData.acData);
		i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode=NULL; // 初始化与该顶点有关的出弧链表
	}
	for(k=0;k<i_ptAdjacencyListGraph->iArcNum;++k) // 构造相关弧链表
	{
		if(i_ptAdjacencyListGraph->iKind%2) // 网
		fscanf(fileGraphList,"%d%s%s",&w,tVa.tData.acData,tVb.tData.acData);
		else // 图
		fscanf(fileGraphList,"%s%s",tVa.tData.acData,tVb.tData.acData);
		i=LocateVertex(i_ptAdjacencyListGraph,&tVa.tData); // 弧尾
		j=LocateVertex(i_ptAdjacencyListGraph,&tVb.tData); // 弧头
		tElement.pcInfo=NULL; // 给待插表结点e赋值，图无权
		tElement.iAdjvex=j; // 弧头
		if(i_ptAdjacencyListGraph->iKind%2) // 网
		{
			tElement.pcInfo=(T_InfoType *)malloc(sizeof(T_InfoType)); // 动态生成存放权值的空间
			tElement.pcInfo->iWeight=w;
		}
		else{
		}
		InsertNodeToLinkList(&i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode,1,&tElement); // 插在第i个元素(出弧)的表头
		if(i_ptAdjacencyListGraph->iKind>=2) // 无向图或网，产生第2个表结点，并插在第j个元素(入弧)的表头
		{//无向
			tElement.iAdjvex=i; // e.info不变，不必再赋值
			InsertNodeToLinkList(&i_ptAdjacencyListGraph->atVertexList[j].ptFirstArcNode,1,&tElement); // 插在第j个元素的表头
		}
		else
		{
		}
	}
	fclose(fileGraphList); // 关闭数据文件
}


/*****************************************************************************
-Fuction		: DestroyGraph
-Description	: 
// 初始条件：图G存在。操作结果：销毁图G
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
		if(i_ptAdjacencyListGraph->iKind%2) // 网
		{
			while(i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode!=NULL)
			{
				DeleteNodeFromLinkList(&i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode,1,&tElement); // 删除链表的第1个结点，并将值赋给e
				if(tElement.iAdjvex>i) // 每个顶点序号>i(保证访问一次即保证动态生成的权值空间只释放1次)
				free(tElement.pcInfo);
			}

		}
		else
		{
			DestroyLinkList(i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode); // 销毁弧或边链表，在bo2-8.cpp中
		}
	}
	i_ptAdjacencyListGraph->iVexNum=0; // 顶点数为0
	i_ptAdjacencyListGraph->iArcNum=0; // 边或弧数为0
}


/*****************************************************************************
-Fuction		: GetVertexData
-Description	: 
// 初始条件：图G存在，v是G中某个顶点的序号。
操作结果：返回v的值
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
// 初始条件：图G存在，v是G中某个顶点。
操作结果：对v赋新值value
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
	if(iPos>-1) // v是G的顶点
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
// 初始条件：图G存在，v是G中某个顶点
// 操作结果：返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点，则返回-1
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
// 初始条件：图G存在，v(i_ptVertexData)是G中某个顶点，w(i_ptAdjVertexData)是v的邻接顶点
// 操作结果：返回v的(相对于w的)下一个邻接顶点的序号。若w是v的最后一个邻接点，则返回-1
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
	iNum=LocateVertex(i_ptAdjacencyListGraph,i_ptVertexData);// iNum为顶点v在图G中的序号
	tElement.iAdjvex=LocateVertex(i_ptAdjacencyListGraph,i_ptAdjVertexData);// tElement.adjvex为顶点w在图G中的序号
	ptLinkListNode=GetLinkListNodePoint(i_ptAdjacencyListGraph->atVertexList[iNum].ptFirstArcNode,&tElement,EqualVertex,&ptLinkListPreNode);
	if(NULL==ptLinkListNode||NULL==ptLinkListNode->ptNext)// ptLinkListNode指向顶点v的链表中邻接顶点为w的结点
	{// 没找到w或w是最后一个邻接点
		iAdjNextVertexNum=-1;
	}
	else
	{// 返回v的(相对于w的)下一个邻接顶点的序号
		iAdjNextVertexNum=ptLinkListNode->ptNext->tData.iAdjvex;
	}
	return iAdjNextVertexNum;

}



/*****************************************************************************
-Fuction		: InsertVertex
-Description	: 
// 初始条件：图G存在，v和图中顶点有相同特征
// 操作结果：在图G中增添新顶点v(不增添与顶点相关的弧，留待InsertArc()去做)
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/02	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void InsertVertex(T_AdjacencyListGraph *i_ptAdjacencyListGraph,T_VertexData *i_ptVertexData)
{
	memcpy(&i_ptAdjacencyListGraph->atVertexList[i_ptAdjacencyListGraph->iVexNum].tData, i_ptVertexData,sizeof(T_VertexData));// 构造新顶点向量
	i_ptAdjacencyListGraph->atVertexList[i_ptAdjacencyListGraph->iVexNum].ptFirstArcNode=NULL;
	i_ptAdjacencyListGraph->iVexNum++;// 图G的顶点数加1

}

/*****************************************************************************
-Fuction		: DeleteVertex
-Description	: 
// 初始条件：图G存在，v是G中某个顶点。操作结果：删除G中顶点v及其相关的弧
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
		i=GetLinkListLength(i_ptAdjacencyListGraph->atVertexList[j].ptFirstArcNode);// 以v为出度的弧或边数
		i_ptAdjacencyListGraph->iArcNum-=i;// 边或弧数-i
		if(i_ptAdjacencyListGraph->iKind%2)//// 网
		{
			while(i_ptAdjacencyListGraph->atVertexList[j].ptFirstArcNode)// 对应的弧或边链表不空
			{
				DeleteNodeFromLinkList(&i_ptAdjacencyListGraph->atVertexList[j].ptFirstArcNode,1,&tElement);// 删除链表的第1个结点，并将值赋给e
				free(tElement.pcInfo);// 释放动态生成的权值空间
			}
		}
		else// 图
		{
			DestroyLinkList(i_ptAdjacencyListGraph->atVertexList[j].ptFirstArcNode);// 销毁弧或边链表
		}
		i_ptAdjacencyListGraph->iVexNum--;// 顶点数减1(j从0开始，所以前面减一)
		for(i=j;i<i_ptAdjacencyListGraph->iVexNum;i++)// 顶点v后面的顶点前移
		{
			i_ptAdjacencyListGraph->atVertexList[i]=i_ptAdjacencyListGraph->atVertexList[i+1];
		}
		for(i=0;i<i_ptAdjacencyListGraph->iVexNum;i++)
		{// 删除以v为入度的弧或边且必要时修改表结点的顶点位置值
			tElement.iAdjvex=j;
			ptLinkListNode=GetLinkListNodePoint(i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode,&tElement,EqualVertex,&ptLinkListPreNode);
			if(NULL==ptLinkListNode)// 顶点i的邻接表上有v为入度的结点
			{
			}
			else// 顶点i的邻接表上有v为入度的结点
			{
				if(NULL==ptLinkListPreNode)// p指向首元结点
				{
					i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode=ptLinkListNode->ptNext;// 头指针指向下一结点
				}
				else// p1指向p所指结点的前驱
				{
					ptLinkListPreNode->ptNext=ptLinkListNode->ptNext;// 从链表中删除p所指结点
				}
				if(i_ptAdjacencyListGraph->iKind<2)// 有向
				{
					i_ptAdjacencyListGraph->iArcNum--;// 边或弧数-1
					if(i_ptAdjacencyListGraph->iKind==1)// 有向网
					{
						free(ptLinkListNode->tData.pcInfo);// 释放动态生成的权值空间
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
			{// 对于adjvex域>j的结点，其序号-1(弧指针中指向顶点序号(数组下标)删除后要减一)
				tElement.iAdjvex=k;
				ptLinkListNode=GetLinkListNodePoint(i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode,&tElement,EqualVertex,&ptLinkListPreNode);
				if(NULL==ptLinkListNode)
				{
				}
				else
				{
					ptLinkListNode->tData.iAdjvex--;// 序号-1(因为前移)
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
// 初始条件：图G存在，v(i_ptVertexData)和w(i_ptAdjVertexData)是G中两个顶点
// 操作结果：在G中增添弧<v,w>，若G是无向的，则还增添对称弧<w,v>
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
	i=LocateVertex(i_ptAdjacencyListGraph,i_ptVertexData);// 弧尾或边的序号
	j=LocateVertex(i_ptAdjacencyListGraph,i_ptAdjVertexData);// 弧头或边的序号
	if(i<0||j<0)
	{
		iRet=-1;
	}
	else
	{
		i_ptAdjacencyListGraph->iArcNum++;
		tElement.iAdjvex=j;
		tElement.pcInfo=NULL;
		if(i_ptAdjacencyListGraph->iKind%2)//// 网
		{
			tElement.pcInfo=(T_InfoType *)malloc(sizeof(T_InfoType));
			printf("请输入弧(边)%s→%s的权值: ",i_ptVertexData->acData,i_ptAdjVertexData->acData);
			scanf("%d",&tElement.pcInfo->iWeight);
		}
		else
		{
		}
		InsertNodeToLinkList(&i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode,1,&tElement);// 将tElement插在弧尾的表头
		if(i_ptAdjacencyListGraph->iKind>=2) // 无向，生成另一个表结点
		{
			tElement.iAdjvex=i; // e.info不变
			InsertNodeToLinkList(&i_ptAdjacencyListGraph->atVertexList[j].ptFirstArcNode,1,&tElement);// 将e插在弧头的表头
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
// 初始条件：图G存在，v和w是G中两个顶点
// 操作结果：在G中删除弧<v,w>，若G是无向的，则还删除对称弧<w,v>
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
	i=LocateVertex(i_ptAdjacencyListGraph,i_ptVertexData);// i是顶点v(弧尾)的序号
	j=LocateVertex(i_ptAdjacencyListGraph,i_ptAdjVertexData);// j是顶点w(弧头)的序号
	if(i<0||j<0)// 没找到待删除的弧
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
		else// 删除成功
		{
			i_ptAdjacencyListGraph->iArcNum--;// 弧或边数减1
			if(i_ptAdjacencyListGraph->iKind%2)//// 网
			{
				free(tElement.pcInfo);
			}
			else{
			}
			if(i_ptAdjacencyListGraph->iKind>=2) // 无向，删除对称弧<w,v>
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
// 输出图的邻接矩阵G
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
			printf("有向图\n");
		break;
		case DN: 
			printf("有向网\n");
		break;
		case UDG: 
			printf("无向图\n");
		break;
		case UDN: 
			printf("无向网\n");
	}
	printf("%d个顶点：\n",i_ptAdjacencyListGraph->iVexNum);
	for(i=0;i<i_ptAdjacencyListGraph->iVexNum;++i)
	printf("%s ",i_ptAdjacencyListGraph->atVertexList[i].tData.acData);
	printf("\n%d条弧(边):\n",i_ptAdjacencyListGraph->iArcNum);
	for(i=0;i<i_ptAdjacencyListGraph->iVexNum;i++)
	{
		ptAcrNode=i_ptAdjacencyListGraph->atVertexList[i].ptFirstArcNode;
		while(NULL!=ptAcrNode)
		{
			if(i_ptAdjacencyListGraph->iKind<=1||i<ptAcrNode->tData.iAdjvex) // 有向或无向两次中的一次
			{
				printf("%s-->%s ",i_ptAdjacencyListGraph->atVertexList[i].tData.acData,i_ptAdjacencyListGraph->atVertexList[ptAcrNode->tData.iAdjvex].tData.acData);
				if(i_ptAdjacencyListGraph->iKind%2) // 网
				printf(":%d ",ptAcrNode->tData.pcInfo->iWeight);
			}
			ptAcrNode=ptAcrNode->ptNext;
		}
		printf("\n");
	}
}
















