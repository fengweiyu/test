/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BridgePatternUsage.c
* Description		: 	����ģʽ��ʹ��

book@book-desktop:/work/projects/test/DesignPatterns/BridgePattern$ gcc -o BridgePatternUsage IPodProduct.c HouseProduct.c ClothesProduct.c ShaizhaiCorp.c HouseCorp.c BridgePattern.c BridgePatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/BridgePattern$ ./BridgePatternUsage 
-----------------���ز���˾���������е�----------------
������������...
�������ķ�������ȥ��...
���ز���˾׬��Ǯ��...
------------------ɽկ��˾���������е�-----------------
������IPod��...
��������IPod����ȥ��...
��׬Ǯ��...
�������·���...
���������·�����ȥ��...
��׬Ǯ��...

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
	printf("-----------------���ز���˾���������е�----------------\r\n");
	T_HouseCorp tHouseCorp=newHouseCorp(tProduct);
	tHouseCorp.MakeMoney(&tHouseCorp);
	printf("------------------ɽկ��˾���������е�-----------------\r\n");
	tProduct=(T_Product)newIPodProduct;
	T_ShanzhaiCorp tShanzhaiCorp=newShanzhaiCorp(tProduct);
	tShanzhaiCorp.MakeMoney(&tShanzhaiCorp);
	
	tProduct=(T_Product)newClothesProduct;
	tShanzhaiCorp=(T_ShanzhaiCorp)newShanzhaiCorp(tProduct);
	tShanzhaiCorp.MakeMoney(&tShanzhaiCorp);


	
	return 0;
}


