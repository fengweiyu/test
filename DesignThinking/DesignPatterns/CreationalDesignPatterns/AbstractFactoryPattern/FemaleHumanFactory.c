/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	FemaleHumanFactory.c
* Description		: 	抽象工厂模式
						本文件是女性人类工厂(创造女性)的具体实现
						
* Created			: 	2017.08.02.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AbstractFactoryPattern.h"

void BlackHumanGetColor();
void BlackHumanTalk();

void WhiteHumanGetColor();
void WhiteHumanTalk();

void YellowHumanGetColor();
void YellowHumanTalk();

void FemaleBlackHumanGetSex();
#define newFemaleBlackHuman {BlackHumanGetColor,BlackHumanTalk,FemaleBlackHumanGetSex}

void FemaleWhiteHumanGetSex();
#define newFemaleWhiteHuman {WhiteHumanGetColor,WhiteHumanTalk,FemaleWhiteHumanGetSex}

void FemaleYellowHumanGetSex();
#define newFemaleYellowHuman {YellowHumanGetColor,YellowHumanTalk,FemaleYellowHumanGetSex}

/*****************************************************************************
-Fuction		: FemaleHumanFactoryCreateYellowHuman
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/02    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
T_Human FemaleHumanFactoryCreateYellowHuman()
{
	T_Human tHuman=newFemaleYellowHuman;
	return tHuman;
}

/*****************************************************************************
-Fuction		: FemaleHumanFactoryCreateWhiteHuman
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/02    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
T_Human FemaleHumanFactoryCreateWhiteHuman()
{
	T_Human tHuman=newFemaleWhiteHuman;
	return tHuman;
}

/*****************************************************************************
-Fuction		: FemaleHumanFactoryCreateBlackHuman
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/02    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
T_Human FemaleHumanFactoryCreateBlackHuman()
{
	T_Human tHuman=newFemaleBlackHuman;
	return tHuman;
}







