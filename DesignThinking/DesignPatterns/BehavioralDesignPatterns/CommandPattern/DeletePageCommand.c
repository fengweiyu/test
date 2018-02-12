/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	DeletePageCommand.c
* Description		: 	删除页面命令
						本文件是命令的具体实现类
* Created			: 	2017.07.18.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"CommandPattern.h"

/*****************************************************************************
-Fuction		: DeletePageCommandExecute
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/18	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void DeletePageCommandExecute(T_Command *i_ptThis)
{
	i_ptThis->tPageGroup.Find();
	i_ptThis->tPageGroup.Delete();
	i_ptThis->tPageGroup.Plan();
}





