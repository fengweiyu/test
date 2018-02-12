/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	AdapterPattern.c
* Description		: 	适配器模式
						本文件是丑小鸭的具体实现(适配器角色(中转角色))
						以白天鹅适配成鸭子举例	
						
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
-Fuction		: UglyDucklingCry
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/26	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void UglyDucklingCry(void *i_ptThis)
{	
	T_UglyDuckling *ptUglyDuckling=(T_UglyDuckling *)i_ptThis;
	ptUglyDuckling->tFatherSwan.Cry();
}

/*****************************************************************************
-Fuction		: UglyDucklingAppearance
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/26	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void UglyDucklingAppearance(void *i_ptThis)
{	
	T_UglyDuckling *ptUglyDuckling=(T_UglyDuckling *)i_ptThis;
	ptUglyDuckling->tFatherSwan.Appearance();
}

/*****************************************************************************
-Fuction		: UglyDucklingBehavior
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/26	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void UglyDucklingBehavior(void *i_ptThis)
{	
	T_UglyDuckling *ptUglyDuckling=(T_UglyDuckling *)i_ptThis;
	printf("会游泳\r\n");//丑小鸭不仅会游泳
	ptUglyDuckling->tFatherSwan.Fly();//还会飞行
}


