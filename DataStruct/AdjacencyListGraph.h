/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	AdjacencyListGraph.h
* Description		: 	AdjacencyListGraph operation center
* Created			: 	2017.05.23.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef _ADJACENCY_LIST_GRAPH_H
#define _ADJACENCY_LIST_GRAPH_H

#define MAX_NAME				5
#define MAX_VERTEX_NUM		20
typedef struct InfoType
{
	int iWeight;//权值
}T_InfoType,*PT_InfoType;//最简单的弧的相关信息类型(只有权值)

typedef struct VertexData
{
	char acData[MAX_NAME];
}T_VertexData,*PT_VertexData;
enum GraphKind{DG,DN,UDG,UDN}; // {有向图,有向网,无向图,无向网}

typedef struct LinkListElement
{
	int iAdjvex;// 该弧所指向的顶点的位置,邻接表数组中的位置
	T_InfoType *pcInfo;// 网的权值指针
}T_LinkListElement,*PT_LinkListElement;

typedef struct ArcNode 
{
	T_LinkListElement tData;// 除指针以外的部分都属于T_ListElement
	struct ArcNode *ptNext;// 指向下一条弧的指针
}T_ArcNode,*PT_ArcNode;// 弧链表结点

typedef struct VertexNode
{
	T_VertexData tData;// 顶点信息
	T_ArcNode *ptFirstArcNode;// 第一个表结点的地址，指向第一条依附该顶点的弧的指针
}T_VertexNode,*PT_VertexNode;// 顶点结点

typedef struct AdjacencyListGraph
{
	T_VertexNode atVertexList[MAX_VERTEX_NUM];//邻接表包含所有顶点和弧的信息
	int iVexNum;// 图的当前顶点数和弧数
	int iArcNum;
	int iKind;// 图的种类标志
}T_AdjacencyListGraph,*PT_AdjacencyListGraph;




#endif
