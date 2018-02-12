/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	LetterProcess.c
* Description		: 	门面模式
						本文件是写信过程的具体实现
						
* Created			: 	2017.07.27.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"LetterProcess.h"


/*****************************************************************************
-Fuction		: WriteContent
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/27	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void WriteContent(char *i_strContent)
{	
	printf("填写信的内容......%s\r\n",i_strContent);
}

/*****************************************************************************
-Fuction		: FillEnvelope
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/27	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void FillEnvelope(char *i_strAddress)
{	
	printf("填写收件人地址及姓名......%s\r\n",i_strAddress);
}

/*****************************************************************************
-Fuction		: LetterIntoEnvelope
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/27	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void LetterIntoEnvelope()
{	
	printf("把信放到信封中......\r\n");
}

/*****************************************************************************
-Fuction		: SendLetter
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/27	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void SendLetter()
{	
	printf("邮递信件......\r\n");
}



