/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	TemplateMethodPattern.c
* Description		: 	ģ�淽��ģʽ
						��Ҫ��ģ�淽����ͬʱģ�淽�����ø�����������
						������Ҳ���Ը���ΪTemplateMethod.c
						Ϊͳһ����,���ļ�Ҳ��ģ�淽��ģʽ�ĺ��Ĺʻ���
						����ΪTemplateMethodPattern.c
									
* Created			: 	2017.07.12.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"TemplateMethodPattern.h"


/*****************************************************************************
-Fuction		: HummerRun
-Description	: ���к���
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void HummerRun(T_HummerModel *i_ptHummerModel)
{
	i_ptHummerModel->Start();
	i_ptHummerModel->EngineBoom();
	i_ptHummerModel->Alarm();
	i_ptHummerModel->Stop();
}


