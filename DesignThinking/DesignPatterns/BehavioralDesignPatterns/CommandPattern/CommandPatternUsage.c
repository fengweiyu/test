/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	CommandPatternUsage.c
* Description		: 	命令模式的使用

book@book-desktop:/work/projects/test/DesignPatterns/CommandPattern$ gcc -o CommandPatternUsage CodeGroup.c PageGroup.c RequirementGroup.c CommandPattern.c AddRequirementCommand.c DeletePageCommand.c CommandPatternUsage.c
book@book-desktop:/work/projects/test/DesignPatterns/CommandPattern$ ./CommandPatternUsage 
客户要求增加一项需求:
找到需求组。。。
客户要求增加一项需求。。。
客户要求给出需求变更计划。。。
客户要求删除一个页面:
找到美工组。。。
客户要求删除一项页面。。。
客户要求给出页面变更计划。。。

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
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/18    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	printf("客户要求增加一项需求:\r\n");
	T_Command tCommand=newAddRequirementCommand;
	g_tInvoker.SetCommand(&tCommand);
	g_tInvoker.Action();
	
	printf("客户要求删除一个页面:\r\n");
	tCommand=(T_Command)newDeletePageCommand;
	g_tInvoker.SetCommand(&tCommand);
	g_tInvoker.Action();

	return 0;
}


