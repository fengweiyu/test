/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ResponsibilityChainPatternUsage.c
* Description		: 	责任链模式的使用

book@book-desktop:/work/projects/test/DesignPatterns/ResponsibilityChainPattern$ gcc -o ResponsibilityChainPatternUsage Woman.c Father.c Husband.c Son.c ResponsibilityChainPattern.c ResponsibilityChainPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/ResponsibilityChainPattern$ ./ResponsibilityChainPatternUsage
女儿向父亲请示:
女儿的请求是:我要出去逛街
父亲的答复是:同意
母亲向儿子请示:
女儿的请求是:我要出去逛街
儿子的答复是:同意

* Created			: 	2017.07.14.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"ResponsibilityChainPattern.h"




/*****************************************************************************
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_Handle tFatherHandle=newFatherHandle;
	T_Handle tHusbandHandle=newHusbandHandle;
	T_Handle tSonHandle=newSonHandle;

	T_Woman tWoman=newWoman;
	tFatherHandle.SetNextHandle(&tHusbandHandle);
	tHusbandHandle.SetNextHandle(&tSonHandle);

	tFatherHandle.tFatherHandle.HandleMessage(&tWoman,&tFatherHandle);

	tWoman.SetType(SON_HANDLE_LEVEL);
	tFatherHandle.tFatherHandle.HandleMessage(&tWoman,&tFatherHandle);
	
	return 0;
}


