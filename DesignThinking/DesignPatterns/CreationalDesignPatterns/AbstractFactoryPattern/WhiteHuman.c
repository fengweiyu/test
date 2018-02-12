/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	WhiteHuman.c
* Description		: 	抽象工厂模式
						本文件是白人的具体实现
						
* Created			: 	2017.08.02.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AbstractFactoryPattern.h"



/*****************************************************************************
-Fuction		: WhiteHumanGetColor
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/02    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void WhiteHumanGetColor()
{
	printf("白色人种的皮肤是白色的\r\n");
}

/*****************************************************************************
-Fuction		: WhiteHumanGetColor
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/02    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void WhiteHumanTalk()
{
	printf("白色人种会说话，一般说的是单字节\r\n");
}




