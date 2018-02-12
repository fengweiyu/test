/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	LittleAndBigEndian.cpp
* Description		: 	

[yweifeng@localhost test]$ ./LittleAndBigEndian
temp 1,4ADDR:0xc25f5440,0xc25f5443
temp 1,4:0x1,0

* Created			: 	2017.09.11.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include <stdio.h>  
#include <stdlib.h>
/*****************************************************************************
-Class			: BubbleSort
-Description	: main
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/19	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/



/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/11	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	unsigned char temp[4]={0};
	unsigned int iHeader=0x00000001;
	memcpy(temp,&iHeader,sizeof(iHeader));
	printf("temp 1,4ADDR:%#x,%#x\r\n",&temp[0],&temp[3]);
	printf("temp 1,4:%#x,%#x\r\n",temp[0],temp[3]);
	return 0;
}
