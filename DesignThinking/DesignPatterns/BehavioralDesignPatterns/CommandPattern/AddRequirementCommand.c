/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	AddRequirementCommand.c
* Description		: 	增加需求命令
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
-Fuction		: RequirementGroupFind
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/18	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void AddRequirementCommandExecute(T_Command *i_ptThis)
{
	i_ptThis->tRequirementGroup.Find();
	i_ptThis->tRequirementGroup.Add();
	i_ptThis->tRequirementGroup.Plan();
}




