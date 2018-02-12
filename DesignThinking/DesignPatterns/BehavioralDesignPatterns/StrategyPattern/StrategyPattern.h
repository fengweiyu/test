/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	StrategyPattern.h
* Description		: 	����ģʽ
									
* Created			: 	2017.07.19.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef STRATEGY_PATTERN_H
#define STRATEGY_PATTERN_H

typedef struct Algorithm
{
	int (*Compress)(char *i_strSource,char *i_strDestination);
	int (*Uncompress)(char *i_strSource,char *i_strDestination);
}T_Algorithm;

typedef struct Context
{
	void (*SetAlgorithm)(T_Algorithm *i_ptAlgorithm);
	int (*Compress)(char *i_strSource,char *i_strDestination);
	int (*Uncompress)(char *i_strSource,char *i_strDestination);
}T_Context;

//������ɫһ��һ���͹���,
//�����ִ��Ч����Ҫ����Ҫ����ʱ����ɲ�ʹ�õ���
extern const T_Context g_tContext;


int GzipCompress(char *i_strSource,char *i_strDestination);
int GzipUncompress(char *i_strSource,char *i_strDestination);
#define newGzipAlgorithm {GzipCompress,GzipUncompress}

int ZipCompress(char *i_strSource,char *i_strDestination);
int ZipUncompress(char *i_strSource,char *i_strDestination);
#define newZipAlgorithm {ZipCompress,ZipUncompress}


#endif

