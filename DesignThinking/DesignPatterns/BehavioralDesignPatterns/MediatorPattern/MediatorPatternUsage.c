/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	MediatorPatternUsage.c
* Description		: 	�н���ģʽ��ʹ��

book@book-desktop:/work/projects/test/DesignPatterns/MediatorPattern$ gcc -o MediatorPatternUsage Purchase.c Sale.c Stock.c MediatorPattern.c MediatorPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/MediatorPattern$ ./MediatorPatternUsage 
---------------�ɹ���Ա�ɹ�����--------------
IBM���Ե��������Ϊ:95
�ɹ�IBM����100̨
�������Ϊ:200
---------------������Ա���۵���--------------
IBM���Ե��������Ϊ:95
�������Ϊ:199
����IBM����:1̨
---------------�ⷿ��Ա��⴦��--------------
����������Ϊ:199
�ۼ�����IBM����199̨
���ٲɹ�IBM����

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
	printf("---------------�ɹ���Ա�ɹ�����--------------\r\n");
	T_Purchase tPurchase=newPurchase(&tMediator);
	tPurchase.BuyIBMComputer(&tPurchase,100);
	printf("---------------������Ա���۵���--------------\r\n");
	T_Sale tSale=newSale(&tMediator);
	tSale.SellIBMComputer(&tSale,1);
	printf("---------------�ⷿ��Ա��⴦��--------------\r\n");
	T_Stock tStock=newStock(&tMediator);
	tStock.ClearStock(&tStock);


	
	return 0;
}


