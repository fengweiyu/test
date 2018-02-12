/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	Stock.c
* Description		: 	中介者模式
						本文件是库存管理的具体实现
						
* Created			: 	2017.07.28.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MediatorPattern.h"


static int g_iComputerNum=100;
/*****************************************************************************
-Fuction		: Increase
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/28	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void Increase(T_Stock *i_ptThis,int i_iNum)
{	
	g_iComputerNum +=i_iNum;
	printf("库存数量为:%d\r\n",g_iComputerNum);
}

/*****************************************************************************
-Fuction		: Decrease
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/28	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void Decrease(T_Stock *i_ptThis,int i_iNum)
{	
	g_iComputerNum -=i_iNum;
	printf("库存数量为:%d\r\n",g_iComputerNum);
}

/*****************************************************************************
-Fuction		: Decrease
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/28	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int GetStockNumber(T_Stock *i_ptThis)
{	
	return g_iComputerNum;
}

/*****************************************************************************
-Fuction		: Decrease
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/28	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void ClearStock(T_Stock *i_ptThis)
{	
	printf("清理存货数量为:%d\r\n",g_iComputerNum);
	i_ptThis->ptMediator->Execute(i_ptThis->ptMediator,"stock.clear",0);
}




