/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	AbstractFactoryPattern.h
* Description		: 	抽象工厂模式
									
* Created			: 	2017.08.02.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef ABSTRACT_FACTORY_PATTERN_H
#define ABSTRACT_FACTORY_PATTERN_H


typedef struct Human
{
	void (*GetColor)();
	void (*Talk)();
	void (*GetSex)();
}T_Human;

typedef struct HumanFactory
{
	T_Human (*CreateYellowHuman)();
	T_Human (*CreateWhiteHuman)();
	T_Human (*CreateBlackHuman)();
}T_HumanFactory;

T_Human MaleHumanFactoryCreateYellowHuman();
T_Human MaleHumanFactoryCreateWhiteHuman();
T_Human MaleHumanFactoryCreateBlackHuman();
#define newMaleHumanFactory {MaleHumanFactoryCreateYellowHuman,MaleHumanFactoryCreateWhiteHuman,MaleHumanFactoryCreateBlackHuman}

T_Human FemaleHumanFactoryCreateYellowHuman();
T_Human FemaleHumanFactoryCreateWhiteHuman();
T_Human FemaleHumanFactoryCreateBlackHuman();
#define newFemaleHumanFactory {FemaleHumanFactoryCreateYellowHuman,FemaleHumanFactoryCreateWhiteHuman,FemaleHumanFactoryCreateBlackHuman}



#endif

