/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	WhiteSwan.c
* Description		: 	适配器模式
						本文件是天鹅的具体实现(源角色)

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
-Fuction		: WhiteSwanCry
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/26	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void WhiteSwanCry()
{	
	printf("叫声是克鲁---克鲁---克鲁\r\n");
	
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
void WhiteSwanAppearance()
{	
	printf("外形是纯白色的,惹人喜爱\r\n");
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
void WhiteSwanFly()
{	
	printf("能够飞行\r\n");
}




