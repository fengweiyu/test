/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	Duckling.c
* Description		: 	适配器模式
						本文件是鸭子的具体实现

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
-Fuction		: DucklingCry
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/26	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void DucklingCry(void *i_ptThis)
{	
	printf("叫声是嘎---嘎---嘎\r\n");
	
}

/*****************************************************************************
-Fuction		: DucklingAppearance
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/26	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void DucklingAppearance(void *i_ptThis)
{	
	printf("外形是黄白相间,嘴长\r\n");
}

/*****************************************************************************
-Fuction		: DucklingBehavior
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/26	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void DucklingBehavior(void *i_ptThis)
{	
	printf("会游泳\r\n");
}



