/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	AdultSuperManBuilder.c
* Description		: 	建造者模式
						本文件是成年超人建造者的具体实现
						
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
-Fuction		: AdultBuilderGetSuperMan
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/01    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
T_SuperMan AdultBuilderGetSuperMan(T_Builder *ptThis)
{
	ptThis->SetBody(ptThis,"强壮的躯体");
	ptThis->SetSpecialTalent(ptThis,"刀枪不入");
	ptThis->SetSpecialSymbol(ptThis,"胸前带小S标记");
	return ptThis->tSuperMan;
}




