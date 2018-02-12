/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ChildSuperManBuilder.c
* Description		: 	建造者模式
						本文件是未成年超人建造者的具体实现
						
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
-Fuction		: ChildBuilderGetSuperMan
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/01    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
T_SuperMan ChildBuilderGetSuperMan(T_Builder *ptThis)
{
	ptThis->SetBody(ptThis,"强壮的躯体");
	ptThis->SetSpecialTalent(ptThis,"会飞行");
	ptThis->SetSpecialSymbol(ptThis,"胸前带S标记");
	return ptThis->tSuperMan;
}





