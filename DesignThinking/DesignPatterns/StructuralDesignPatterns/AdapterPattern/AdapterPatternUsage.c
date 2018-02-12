/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	AdapterPatternUsage.c
* Description		: 	������ģʽ��ʹ��

book@book-desktop:/work/projects/test/DesignPatterns/AdapterPattern$ gcc -o AdapterPatternUsage Duckling.c WhiteSwan.c AdapterPattern.c AdapterPatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns/AdapterPattern$ ./AdapterPatternUsage 
Ѽ������������ӣ������ĸ���������:
�����Ǹ�---��---��
�����ǻư����,�쳤
����Ӿ
����һֻ���ص�СѼ�ӣ�ģ����������::
�����ǿ�³---��³---��³
�����Ǵ���ɫ��,����ϲ��
����Ӿ
�ܹ�����

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
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/25    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	printf("Ѽ������������ӣ������ĸ���������:\r\n");
	T_Duck tDuckling =newDuckling;
	tDuckling.Cry((void *)&tDuckling);
	tDuckling.Appearance((void *)&tDuckling);
	tDuckling.Behavior((void *)&tDuckling);
	printf("����һֻ���ص�СѼ�ӣ�ģ����������::\r\n");
	T_UglyDuckling tUglyDuckling =newUglyDuckling;
	tUglyDuckling.tDuck.Cry((void *)&tUglyDuckling);
	tUglyDuckling.tDuck.Appearance((void *)&tUglyDuckling);
	tUglyDuckling.tDuck.Behavior((void *)&tUglyDuckling);
	
	return 0;
}


