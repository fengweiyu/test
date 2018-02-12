/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	AdapterPattern.c
* Description		: 	������ģʽ
						���ļ��ǳ�СѼ�ľ���ʵ��(��������ɫ(��ת��ɫ))
						�԰���������Ѽ�Ӿ���	
						
* Created			: 	2017.07.26.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"AdapterPattern.h"

/*****************************************************************************
-Fuction		: UglyDucklingCry
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/26	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void UglyDucklingCry(void *i_ptThis)
{	
	T_UglyDuckling *ptUglyDuckling=(T_UglyDuckling *)i_ptThis;
	ptUglyDuckling->tFatherSwan.Cry();
}

/*****************************************************************************
-Fuction		: UglyDucklingAppearance
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/26	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void UglyDucklingAppearance(void *i_ptThis)
{	
	T_UglyDuckling *ptUglyDuckling=(T_UglyDuckling *)i_ptThis;
	ptUglyDuckling->tFatherSwan.Appearance();
}

/*****************************************************************************
-Fuction		: UglyDucklingBehavior
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/26	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void UglyDucklingBehavior(void *i_ptThis)
{	
	T_UglyDuckling *ptUglyDuckling=(T_UglyDuckling *)i_ptThis;
	printf("����Ӿ\r\n");//��СѼ��������Ӿ
	ptUglyDuckling->tFatherSwan.Fly();//�������
}


