/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ResponsibilityChainPattern.c
* Description		: 	责任链模式
						以古代女子三从四德举例,女子先请求父亲,
						父亲不处理则丈夫处理,丈夫不处理则儿子
						处理,处理完可直接返回

* Created			: 	2017.07.14.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"
#include"ResponsibilityChainPattern.h"


//static T_Handle g_tNextHandle[HANDLE_NUMBER]={NULL};//由于C类中的成员变量是静态的,所以放到子类中
//static int g_iHandleNum=0;//如果放在父类,则需要定义为数组并定义长度与使用长度
/*****************************************************************************
-Fuction		: HandleMessage
-Description	: 公有函数
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/07/14	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
void HandleMessage(T_Woman *i_ptWoman,T_Handle *i_ptThis)
{
	if(i_ptThis->GetLevel()==i_ptWoman->GetType())
	{
		i_ptThis->Handle(i_ptWoman);//调用子类的处理
	}
	else
	{
		if(i_ptThis->GetNextHandle()!=NULL)
		{
			i_ptThis->GetNextHandle()->tFatherHandle.HandleMessage(i_ptWoman,i_ptThis->GetNextHandle());
		}
		else
		{
			printf("没地方请示 了，按不同意处理\r\n");
		}
	}
}


