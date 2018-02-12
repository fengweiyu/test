/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	LetterProcess.h
* Description		: 	����ģʽ
						д�Ź���
						
* Created			: 	2017.07.27.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef LETTER_PROCESS_H
#define LETTER_PROCESS_H


typedef struct LetterProcess
{
	void (*WriteContent)(char *i_strContent);
	void (*FillEnvelope)(char *i_strAddress);
	void (*LetterIntoEnvelope)();
	void (*SendLetter)();
}T_LetterProcess;


void WriteContent(char *i_strContent);
void FillEnvelope(char *i_strAddress);
void LetterIntoEnvelope();
void SendLetter();
#define newLetterProcess {WriteContent,FillEnvelope,LetterIntoEnvelope,SendLetter}








#endif

