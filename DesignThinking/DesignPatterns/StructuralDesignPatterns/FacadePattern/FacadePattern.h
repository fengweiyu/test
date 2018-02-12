/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	FacadePattern.h
* Description		: 	����ģʽ
									
* Created			: 	2017.07.27.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef FACADE_PATTERN_H
#define FACADE_PATTERN_H


typedef struct ModernPostOffice//�����ɫ
{
	void (*SendLetter)(char *i_strContext,char *i_strAddress);

}T_ModernPostOffice;//ʵ�ַ�װ(��װд�Ź���,�ڲ����̶Ը߲�͸��,���ھ�)

const T_ModernPostOffice g_tModernPostOffice;

#endif

