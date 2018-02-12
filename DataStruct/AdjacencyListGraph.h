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
	int iWeight;//Ȩֵ
}T_InfoType,*PT_InfoType;//��򵥵Ļ��������Ϣ����(ֻ��Ȩֵ)

typedef struct VertexData
{
	char acData[MAX_NAME];
}T_VertexData,*PT_VertexData;
enum GraphKind{DG,DN,UDG,UDN}; // {����ͼ,������,����ͼ,������}

typedef struct LinkListElement
{
	int iAdjvex;// �û���ָ��Ķ����λ��,�ڽӱ������е�λ��
	T_InfoType *pcInfo;// ����Ȩֵָ��
}T_LinkListElement,*PT_LinkListElement;

typedef struct ArcNode 
{
	T_LinkListElement tData;// ��ָ������Ĳ��ֶ�����T_ListElement
	struct ArcNode *ptNext;// ָ����һ������ָ��
}T_ArcNode,*PT_ArcNode;// ��������

typedef struct VertexNode
{
	T_VertexData tData;// ������Ϣ
	T_ArcNode *ptFirstArcNode;// ��һ������ĵ�ַ��ָ���һ�������ö���Ļ���ָ��
}T_VertexNode,*PT_VertexNode;// ������

typedef struct AdjacencyListGraph
{
	T_VertexNode atVertexList[MAX_VERTEX_NUM];//�ڽӱ�������ж���ͻ�����Ϣ
	int iVexNum;// ͼ�ĵ�ǰ�������ͻ���
	int iArcNum;
	int iKind;// ͼ�������־
}T_AdjacencyListGraph,*PT_AdjacencyListGraph;




#endif
