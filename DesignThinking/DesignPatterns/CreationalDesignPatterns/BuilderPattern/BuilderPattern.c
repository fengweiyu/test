/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BuilderPattern.c
* Description		: 	建造者模式
						本文件是导演类的具体实现
						以创造各种超人举例	
						
* Created			: 	2017.08.01.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BuilderPattern.h"

void SuperManSetBody(T_SuperMan *ptThis,char *i_strBody);
char * SuperManGetBody(T_SuperMan *ptThis);
void SuperManSetSpecialTalent(T_SuperMan *ptThis,char *i_strSpecialTalent);
char * SuperManGetSpecialTalent(T_SuperMan *ptThis);
void SuperManSetSpecialSymbol(T_SuperMan *ptThis,char *i_strSpecialSymbol);
char * SuperManGetSpecialSymbol(T_SuperMan *ptThis);
#define newSuperMan {NULL,NULL,NULL,SuperManSetBody,SuperManGetBody,SuperManSetSpecialTalent,\
					SuperManGetSpecialTalent,SuperManSetSpecialSymbol,SuperManGetSpecialSymbol}

void BuilderSetBody(T_Builder *ptThis,char *i_strBody);
void BuilderSetSpecialTalent(T_Builder *ptThis,char *i_strSpecialTalent);
void BuilderSetSpecialSymbol(T_Builder *ptThis,char *i_strSpecialSymbol);

T_SuperMan AdultBuilderGetSuperMan(T_Builder *ptThis);
#define newAdultBuilder {newSuperMan,BuilderSetBody,BuilderSetSpecialTalent,BuilderSetSpecialSymbol,AdultBuilderGetSuperMan}

T_SuperMan ChildBuilderGetSuperMan(T_Builder *ptThis);
#define newChildBuilder {newSuperMan,BuilderSetBody,BuilderSetSpecialTalent,BuilderSetSpecialSymbol,ChildBuilderGetSuperMan}


static T_Builder g_tAdultBuilder=newAdultBuilder;
static T_Builder g_tChildBuilder=newChildBuilder;
static T_SuperMan GetAdultSuperMan();
static T_SuperMan GetChildSuperMan();
const T_Director g_tDirector={
	.GetAdultSuperMan=GetAdultSuperMan,
	.GetChildSuperMan=GetChildSuperMan,
};



/*****************************************************************************
-Fuction		: GetAdultSuperMan
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/01    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static T_SuperMan GetAdultSuperMan()
{
	return g_tAdultBuilder.GetSuperMan(&g_tAdultBuilder);
}

/*****************************************************************************
-Fuction		: GetChildSuperMan
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/01    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static T_SuperMan GetChildSuperMan()
{
	return g_tChildBuilder.GetSuperMan(&g_tChildBuilder);
}


