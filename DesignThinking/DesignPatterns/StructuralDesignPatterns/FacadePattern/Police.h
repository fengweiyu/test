/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	Police.h
* Description		: 	����ģʽ
						����(����ż�)			
* Created			: 	2017.07.27.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef POLICE_H
#define POLICE_H


typedef struct Police
{
	void (*CheckLetter)();

}T_Police;

void CheckLetter();
#define newPolice {CheckLetter}


#endif


