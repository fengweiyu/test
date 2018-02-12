/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BridgePatternUsage.c
* Description		: 	桥梁模式的使用

book@book-desktop:/work/projects/test/DesignPatterns/BridgePattern$ gcc -o BridgePatternUsage IPodProduct.c HouseProduct.c ClothesProduct.c ShaizhaiCorp.c HouseCorp.c BridgePattern.c BridgePatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/BridgePattern$ ./BridgePatternUsage 
-----------------房地产公司是这样运行的----------------
生产出房子了...
生产出的房子卖出去了...
房地产公司赚大钱了...
------------------山寨公司是这样运行的-----------------
生产出IPod了...
生产出的IPod卖出去了...
我赚钱啊...
生产出衣服了...
生产出的衣服卖出去了...
我赚钱啊...

* Created			: 	2017.07.20.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"BridgePattern.h"




/*****************************************************************************
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/20    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	T_Product tProduct=newHouseProduct;
	printf("-----------------房地产公司是这样运行的----------------\r\n");
	T_HouseCorp tHouseCorp=newHouseCorp(tProduct);
	tHouseCorp.MakeMoney(&tHouseCorp);
	printf("------------------山寨公司是这样运行的-----------------\r\n");
	tProduct=(T_Product)newIPodProduct;
	T_ShanzhaiCorp tShanzhaiCorp=newShanzhaiCorp(tProduct);
	tShanzhaiCorp.MakeMoney(&tShanzhaiCorp);
	
	tProduct=(T_Product)newClothesProduct;
	tShanzhaiCorp=(T_ShanzhaiCorp)newShanzhaiCorp(tProduct);
	tShanzhaiCorp.MakeMoney(&tShanzhaiCorp);


	
	return 0;
}


