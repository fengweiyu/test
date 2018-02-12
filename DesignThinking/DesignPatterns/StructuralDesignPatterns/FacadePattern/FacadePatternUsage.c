/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	FacadePatternUsage.c
* Description		: 	����ģʽ��ʹ��

book@book-desktop:/work/projects/test/DesignPatterns/FacadePattern$ gcc -o FacadePatternUsage LetterProcess.c Police.c FacadePattern.c FacadePatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/FacadePattern$ ./FacadePatternUsage 
��д�ŵ�����......Happy Road NO.666,God Province,Heaven
��д�ռ��˵�ַ������......Hello,It's me,do you know who I am?I'm your old lover,I'd like to ......
�ż��Ѿ�������......
���ŷŵ��ŷ���......
�ʵ��ż�......

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




/*****************************************************************************
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/27    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	char *strContent="Happy Road NO.666,God Province,Heaven";
	char *strAddress="Hello,It's me,do you know who I am?I'm your old lover,I'd like to ......";
	g_tModernPostOffice.SendLetter(strContent,strAddress);
	return 0;
}


