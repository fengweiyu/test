/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	CommandPatternUsage.c
* Description		: 	����ģʽ��ʹ��

book@book-desktop:/work/projects/test/DesignPatterns/CommandPattern$ gcc -o CommandPatternUsage CodeGroup.c PageGroup.c RequirementGroup.c CommandPattern.c AddRequirementCommand.c DeletePageCommand.c CommandPatternUsage.c
book@book-desktop:/work/projects/test/DesignPatterns/CommandPattern$ ./CommandPatternUsage 
�ͻ�Ҫ������һ������:
�ҵ������顣����
�ͻ�Ҫ������һ�����󡣡���
�ͻ�Ҫ������������ƻ�������
�ͻ�Ҫ��ɾ��һ��ҳ��:
�ҵ������顣����
�ͻ�Ҫ��ɾ��һ��ҳ�档����
�ͻ�Ҫ�����ҳ�����ƻ�������

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
	printf("�ͻ�Ҫ������һ������:\r\n");
	T_Command tCommand=newAddRequirementCommand;
	g_tInvoker.SetCommand(&tCommand);
	g_tInvoker.Action();
	
	printf("�ͻ�Ҫ��ɾ��һ��ҳ��:\r\n");
	tCommand=(T_Command)newDeletePageCommand;
	g_tInvoker.SetCommand(&tCommand);
	g_tInvoker.Action();

	return 0;
}


