/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ChildSiblingTree.h
* Description		: 	ChildSiblingTree operation center
* Created			: 	2017.05.23.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef _CHILD_SIBLING_TREE_H
#define _CHILD_SIBLING_TREE_H


typedef struct ChildSiblingTreeNode
{
	char cData;
	struct ChildSiblingTreeNode *ptFirstChild;
	struct ChildSiblingTreeNode *ptFirstSibling;
}T_ChildSiblingTreeNode,*PT_ChildSiblingTreeNode;







#endif
