/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	MediatorPattern.c
* Description		: 	�н���ģʽ
						���ļ����н��ߵľ���ʵ��
						�Խ�����������	
						
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

static void MediatorBuyComputer(T_Mediator *i_ptThis,int i_iNum);
static void MediatorSellComputer(T_Mediator *i_ptThis,int i_iNum);
static void MediatorOffSell(T_Mediator *i_ptThis);
static void MediatorClearStock(T_Mediator *i_ptThis);


/*****************************************************************************
-Fuction		: MediatorExecute
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/28	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void MediatorExecute(T_Mediator *i_ptThis,char *i_strCmd,int i_iNum)
{	
	if(0==strcmp(i_strCmd,"purchase.buy"))
	{
		MediatorBuyComputer(i_ptThis,i_iNum);
	}
	else if(0==strcmp(i_strCmd,"sale.sell"))
	{
		MediatorSellComputer(i_ptThis,i_iNum);
	}
	else if(0==strcmp(i_strCmd,"sale.offsell"))
	{
		MediatorOffSell(i_ptThis);
	}
	else if(0==strcmp(i_strCmd,"stock.clear"))
	{
		MediatorClearStock(i_ptThis);
	}
	else
	{
	}
}

/*****************************************************************************
-Fuction		: BuyComputer
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/28	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void MediatorBuyComputer(T_Mediator *i_ptThis,int i_iNum)
{	
	int iSaleStatus=i_ptThis->tSale.GetSaleStatus(&i_ptThis->tSale);
	int iBuyNum;
	if(iSaleStatus>80)
	{//�����������
		printf("�ɹ�IBM����%d̨\r\n",i_iNum);
		i_ptThis->tStock.Increase(&i_ptThis->tStock,i_iNum);
	}
	else
	{
		iBuyNum=i_iNum/2;//�۰�ɹ�
		printf("�ɹ�IBM����%d̨\r\n",iBuyNum);
		i_ptThis->tStock.Increase(&i_ptThis->tStock,iBuyNum);
	}
}

/*****************************************************************************
-Fuction		: SellComputer
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/28	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void MediatorSellComputer(T_Mediator *i_ptThis,int i_iNum)
{	
	int iSaleStatus=i_ptThis->tSale.GetSaleStatus(&i_ptThis->tSale);
	int iBuyNum;
	if(i_ptThis->tStock.GetStockNum(&i_ptThis->tStock)<i_iNum)
	{//�����������
		i_ptThis->tPurchase.BuyIBMComputer(&i_ptThis->tPurchase,i_iNum);
	}
	else
	{	
	}
	i_ptThis->tStock.Decrease(&i_ptThis->tStock,i_iNum);
}

/*****************************************************************************
-Fuction		: SellComputer
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/28	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void MediatorOffSell(T_Mediator *i_ptThis)
{	
	printf("�ۼ�����IBM����%d̨\r\n",i_ptThis->tStock.GetStockNum(&i_ptThis->tStock));
}

/*****************************************************************************
-Fuction		: SellComputer
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/28	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void MediatorClearStock(T_Mediator *i_ptThis)
{	
	i_ptThis->tSale.OffSale(&i_ptThis->tSale);
	i_ptThis->tPurchase.RefuseBuyIBM();
}


