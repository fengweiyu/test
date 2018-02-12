/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	FacadePattern.h
* Description		: 	门面模式
									
* Created			: 	2017.07.27.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef FACADE_PATTERN_H
#define FACADE_PATTERN_H


typedef struct ModernPostOffice//门面角色
{
	void (*SendLetter)(char *i_strContext,char *i_strAddress);

}T_ModernPostOffice;//实现封装(封装写信过程,内部过程对高层透明,高内聚)

const T_ModernPostOffice g_tModernPostOffice;

#endif

