/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SuperMan.c
* Description		: 	������ģʽ
						���ļ��ǳ��˵ľ���ʵ��
						
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
-Fuction		: SuperManSetBody
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/01    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void SuperManSetBody(T_SuperMan *ptThis,char *i_strBody)
{
	ptThis->strBody=i_strBody;
}

/*****************************************************************************
-Fuction		: SuperManGetBody
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/01    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
char * SuperManGetBody(T_SuperMan *ptThis)
{
	return ptThis->strBody;
}
/*****************************************************************************
-Fuction		: SuperManSetBody
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/01    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void SuperManSetSpecialTalent(T_SuperMan *ptThis,char *i_strSpecialTalent)
{
	ptThis->strSpecialTalent=i_strSpecialTalent;
}

/*****************************************************************************
-Fuction		: SuperManGetBody
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/01    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
char * SuperManGetSpecialTalent(T_SuperMan *ptThis)
{
	return ptThis->strSpecialTalent;
}
/*****************************************************************************
-Fuction		: SuperManSetBody
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/01    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void SuperManSetSpecialSymbol(T_SuperMan *ptThis,char *i_strSpecialSymbol)
{
	ptThis->strSpecialSymbol=i_strSpecialSymbol;
}

/*****************************************************************************
-Fuction		: SuperManGetBody
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/08/01    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
char * SuperManGetSpecialSymbol(T_SuperMan *ptThis)
{
	return ptThis->strSpecialSymbol;
}



