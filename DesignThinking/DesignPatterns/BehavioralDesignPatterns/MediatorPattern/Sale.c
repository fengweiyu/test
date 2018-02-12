/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	Sale.c
* Description		: 	中介者模式
						本文件是销售管理的具体实现
						
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
void SellIBMComputer(T_Sale *i_ptThis,int i_iNum)
{	
	i_ptThis->ptMediator->Execute(i_ptThis->ptMediator,"sale.sell",i_iNum);
	printf("销售IBM电脑:%d台\r\n",i_iNum);
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
int GetSaleStatus(T_Sale *i_ptThis)
{	
	int iStatus=95;
	printf("IBM电脑的销售情况为:%d\r\n",iStatus);
	return iStatus;
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
void OffSale(T_Sale *i_ptThis)
{	
	i_ptThis->ptMediator->Execute(i_ptThis->ptMediator,"sale.offsell",0);
}





