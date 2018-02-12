/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	MediatorPatternUsage.c
* Description		: 	中介者模式的使用

book@book-desktop:/work/projects/test/DesignPatterns/MediatorPattern$ gcc -o MediatorPatternUsage Purchase.c Sale.c Stock.c MediatorPattern.c MediatorPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/MediatorPattern$ ./MediatorPatternUsage 
---------------采购人员采购电脑--------------
IBM电脑的销售情况为:95
采购IBM电脑100台
库存数量为:200
---------------销售人员销售电脑--------------
IBM电脑的销售情况为:95
库存数量为:199
销售IBM电脑:1台
---------------库房人员清库处理--------------
清理存货数量为:199
折价销售IBM电脑199台
不再采购IBM电脑

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
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/28    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_Mediator tMediator=newMediator(&tMediator);
	printf("---------------采购人员采购电脑--------------\r\n");
	T_Purchase tPurchase=newPurchase(&tMediator);
	tPurchase.BuyIBMComputer(&tPurchase,100);
	printf("---------------销售人员销售电脑--------------\r\n");
	T_Sale tSale=newSale(&tMediator);
	tSale.SellIBMComputer(&tSale,1);
	printf("---------------库房人员清库处理--------------\r\n");
	T_Stock tStock=newStock(&tMediator);
	tStock.ClearStock(&tStock);


	
	return 0;
}


