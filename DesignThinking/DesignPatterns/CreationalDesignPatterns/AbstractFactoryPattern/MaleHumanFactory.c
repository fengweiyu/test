/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	MaleHumanFactory.c
* Description		: 	抽象工厂模式
						本文件是男性人类工厂(创造男性)的具体实现
						
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

void MaleBlackHumanGetSex();
#define newMaleBlackHuman {BlackHumanGetColor,BlackHumanTalk,MaleBlackHumanGetSex}

void MaleWhiteHumanGetSex();
#define newMaleWhiteHuman {WhiteHumanGetColor,WhiteHumanTalk,MaleWhiteHumanGetSex}

void MaleYellowHumanGetSex();
#define newMaleYellowHuman {YellowHumanGetColor,YellowHumanTalk,MaleYellowHumanGetSex}

/*****************************************************************************
-Fuction		: MaleHumanFactoryCreateYellowHuman
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/02    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
T_Human MaleHumanFactoryCreateYellowHuman()
{
	T_Human tHuman=newMaleYellowHuman;
	return tHuman;
}

/*****************************************************************************
-Fuction		: MaleHumanFactoryCreateWhiteHuman
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/02    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
T_Human MaleHumanFactoryCreateWhiteHuman()
{
	T_Human tHuman=newMaleWhiteHuman;
	return tHuman;
}

/*****************************************************************************
-Fuction		: MaleHumanFactoryCreateBlackHuman
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/02    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
T_Human MaleHumanFactoryCreateBlackHuman()
{
	T_Human tHuman=newMaleBlackHuman;
	return tHuman;
}








