/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	FacadePattern.c
* Description		: 	门面模式
						本文件是现代邮局的具体实现(门面角色)
						以写信过程举例	
						
* Created			: 	2017.07.27.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FacadePattern.h"
#include "LetterProcess.h"
#include "Police.h"

static T_Police g_tPolice=newPolice;
static T_LetterProcess g_tLetterProcess=newLetterProcess;

void ModernPostOfficeSendLetter(char *i_strContent,char *i_strAddress);
const T_ModernPostOffice g_tModernPostOffice={
	.SendLetter=ModernPostOfficeSendLetter

};

/*****************************************************************************
-Fuction		: ModernPostOfficeSendLetter
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/27	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void ModernPostOfficeSendLetter(char *i_strContent,char *i_strAddress)
{	
	g_tLetterProcess.WriteContent(i_strContent);
	g_tLetterProcess.FillEnvelope(i_strAddress);
	g_tPolice.CheckLetter();
	g_tLetterProcess.LetterIntoEnvelope();
	g_tLetterProcess.SendLetter();
}


