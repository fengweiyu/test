/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	Builder.c
* Description		: 	建造者模式
						本文件是建造者的具体实现
						
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



/*****************************************************************************
-Fuction		: BuilderSetBody
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/01    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void BuilderSetBody(T_Builder *ptThis,char *i_strBody)
{
	ptThis->tSuperMan.SetBody(&ptThis->tSuperMan,i_strBody);
}

/*****************************************************************************
-Fuction		: BuilderSetSpecialTalent
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/01    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void BuilderSetSpecialTalent(T_Builder *ptThis,char *i_strSpecialTalent)
{
	ptThis->tSuperMan.SetSpecialTalent(&ptThis->tSuperMan,i_strSpecialTalent);
}

/*****************************************************************************
-Fuction		: BuilderSetSpecialSymbol
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/01    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void BuilderSetSpecialSymbol(T_Builder *ptThis,char *i_strSpecialSymbol)
{
	ptThis->tSuperMan.SetSpecialSymbol(&ptThis->tSuperMan,i_strSpecialSymbol);
}




