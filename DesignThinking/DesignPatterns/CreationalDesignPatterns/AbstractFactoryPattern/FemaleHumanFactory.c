/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	FemaleHumanFactory.c
* Description		: 	���󹤳�ģʽ
						���ļ���Ů�����๤��(����Ů��)�ľ���ʵ��
						
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
-Description	: ���к���
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
-Description	: ���к���
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
-Description	: ���к���
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







