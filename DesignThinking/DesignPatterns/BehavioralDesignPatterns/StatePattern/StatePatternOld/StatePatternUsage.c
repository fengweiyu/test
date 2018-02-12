/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	StatePatternUsage.c
* Description		: 	状态模式的使用

book@book-desktop:/work/projects/test/DesignPatterns$ gcc -o StatePatternUsage RunningState.c StoppingState.c  OpenningState.c ClosingState.c StatePattern.c StatePatternUsage.c 
book@book-desktop:/work/projects/test/DesignPatterns$ ./StatePatternUsage 
Lift door open!
Lift door close!
Lift door run!
Lift door stop!

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
#include"StatePattern.h"




/*****************************************************************************
-Fuction		: main
-Description	: 
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/12    V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
 	T_StateContext tStateContext=newStateContext;
	T_State tState=newClosingState;
	tStateContext.SetState(&tState);

	tStateContext.Open();
	tStateContext.Close();
	tStateContext.Run();
	tStateContext.Stop();

	
	return 0;
}


