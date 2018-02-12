/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	AdapterPatternUsage.c
* Description		: 	适配器模式的使用

book@book-desktop:/work/projects/test/DesignPatterns/AdapterPattern$ gcc -o AdapterPatternUsage Duckling.c WhiteSwan.c AdapterPattern.c AdapterPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/AdapterPattern$ ./AdapterPatternUsage 
鸭妈妈有五个孩子，其中四个是这样的:
叫声是嘎---嘎---嘎
外形是黄白相间,嘴长
会游泳
还有一只独特的小鸭子，模样是这样的::
叫声是克鲁---克鲁---克鲁
外形是纯白色的,惹人喜爱
会游泳
能够飞行

* Created			: 	2017.07.26.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"AdapterPattern.h"




/*****************************************************************************
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/25    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	printf("鸭妈妈有五个孩子，其中四个是这样的:\r\n");
	T_Duck tDuckling =newDuckling;
	tDuckling.Cry((void *)&tDuckling);
	tDuckling.Appearance((void *)&tDuckling);
	tDuckling.Behavior((void *)&tDuckling);
	printf("还有一只独特的小鸭子，模样是这样的::\r\n");
	T_UglyDuckling tUglyDuckling =newUglyDuckling;
	tUglyDuckling.tDuck.Cry((void *)&tUglyDuckling);
	tUglyDuckling.tDuck.Appearance((void *)&tUglyDuckling);
	tUglyDuckling.tDuck.Behavior((void *)&tUglyDuckling);
	
	return 0;
}


