/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	DecoratorPatternUsage.c
* Description		: 	装饰模式的使用

book@book-desktop:/work/projects/test/DesignPatterns/DecoratorPattern$ gcc -o DecoratorPatternUsage HighScoreDecorator.c SortDecorator.c DecoratorPattern.c DecoratorPatternUsage.c
book@book-desktop:/work/projects/test/DesignPatterns/DecoratorPattern$ ./DecoratorPatternUsage 
这次语文考试最高是75,数学是78,自然是80
尊敬的XXX家长:
.......................................
语文62，数学65，体育98，自然63
.......................................
                                 家长签名                       
家长签名为:老三
尊敬的XXX家长:
.......................................
语文62，数学65，体育98，自然63
.......................................
                                 家长签名                       
排名第33
家长签名为:老三

* Created			: 	2017.07.25.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"DecoratorPattern.h"




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
	T_SchoolReport tSchoolReport=newFourthGradeSchoolReport;

	T_Decorator tDecorator=newHighScoreDecorator(tSchoolReport);
	tDecorator.tDecoratorReport.Report(&tDecorator);
	tDecorator.tDecoratorReport.Sign(&tDecorator,"老三");
	//由于向上转型比较难实现,暂不支持多重修饰
	tDecorator=(T_Decorator)newSortDecorator(tSchoolReport);
	tDecorator.tDecoratorReport.Report(&tDecorator);
	tDecorator.tDecoratorReport.Sign(&tDecorator,"老三");
	return 0;
}


