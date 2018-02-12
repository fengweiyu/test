/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	Sale.c
* Description		: 	�н���ģʽ
						���ļ������۹���ľ���ʵ��
						
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
-Description	: ���к���
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
	printf("����IBM����:%d̨\r\n",i_iNum);
}

/*****************************************************************************
-Fuction		: Decrease
-Description	: ���к���
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
	printf("IBM���Ե��������Ϊ:%d\r\n",iStatus);
	return iStatus;
}

/*****************************************************************************
-Fuction		: Decrease
-Description	: ���к���
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





