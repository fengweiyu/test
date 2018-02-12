/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	Purchase.c
* Description		: 	�н���ģʽ
						���ļ��ǲɹ�����ľ���ʵ��
						
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
-Fuction		: BuyIBMComputer
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/28	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void BuyIBMComputer(T_Purchase *i_ptThis,int i_iNum)
{	
	i_ptThis->ptMediator->Execute(i_ptThis->ptMediator,"purchase.buy",i_iNum);
}

/*****************************************************************************
-Fuction		: BuyIBMComputer
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/28	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void RefuseBuyIBM()
{	
	printf("���ٲɹ�IBM����\r\n");
}



