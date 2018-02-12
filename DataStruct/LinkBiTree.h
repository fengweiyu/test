/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	LinkBiTree.h
* Description		: 	LinkBiTree operation center
* Created			: 	2017.05.17.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef _LINK_BI_TREE_H
#define _LINK_BI_TREE_H

typedef struct LinkBiTreeNode
{
	char cData;
	struct LinkBiTreeNode *ptLeftChild,*ptRightChild;
}T_LinkBiTreeNode,*PT_LinkBiTreeNode;




#endif
