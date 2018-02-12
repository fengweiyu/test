/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	AdultSuperManBuilder.c
* Description		: 	������ģʽ
						���ļ��ǳ��곬�˽����ߵľ���ʵ��
						
* Created			: 	2017.08.01.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BuilderPattern.h"



/*****************************************************************************
-Fuction		: AdultBuilderGetSuperMan
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/01    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
T_SuperMan AdultBuilderGetSuperMan(T_Builder *ptThis)
{
	ptThis->SetBody(ptThis,"ǿ׳������");
	ptThis->SetSpecialTalent(ptThis,"��ǹ����");
	ptThis->SetSpecialSymbol(ptThis,"��ǰ��СS���");
	return ptThis->tSuperMan;
}




