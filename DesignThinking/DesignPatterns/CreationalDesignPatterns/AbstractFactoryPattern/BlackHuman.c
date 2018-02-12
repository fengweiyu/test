/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BlackHuman.c
* Description		: 	抽象工厂模式
						本文件是黑人的具体实现
						
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
-Fuction		: YellowHumanGetColor
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/02    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void BlackHumanGetColor()
{
	printf("黑色人种的皮肤是黑色的\r\n");
}

/*****************************************************************************
-Fuction		: YellowHumanTalk
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/02    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void BlackHumanTalk()
{
	printf("黑色人种会说话，一般人听不懂\r\n");
}






