/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	Jt808Parse.c
* Description		: 	Jt808Parse operation center
* Created			: 	2017.03.02.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"


static void Jt808Print(char *i_strCmd,unsigned char *i_ucDataBuf,int i_iDataLen);
static int Jt808Parse(unsigned char *i_ucDataBuf,int i_iDataLen);
static int GetJt808Data(char *i_strFile,unsigned char *o_ucDataBuf,int i_iDataLen);

#define MAX_FILE_NAME 127
#define MAX_DATA_BUF_LEN	(4*1024)
#define JT808_BASE_LEN 15

/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	char acTextFile[MAX_FILE_NAME+1];
	unsigned char strDataBuf[MAX_DATA_BUF_LEN]={0};
	if(argc<2)
	{
		printf("Usage: %s <JT808_file>\n", argv[0]);
	}
	else
	{
		strncpy(acTextFile, argv[1], MAX_FILE_NAME+1);
		acTextFile[MAX_FILE_NAME] = '\0';//strncpy不会追加\0
		memset(strDataBuf,0,sizeof(strDataBuf));
		if(-1==GetJt808Data(acTextFile,strDataBuf,sizeof(strDataBuf)))
		{
		}
		else
		{
			//printf("fgets data len:%d\r\n",strlen(strDataBuf));
			Jt808Parse(strDataBuf,strlen(strDataBuf)-2);
		}
	}
	return 0;
}
/*****************************************************************************
-Fuction		: GetJt808Data
-Description	: GetJt808Data
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int GetJt808Data(char *i_strFile,unsigned char *o_ucDataBuf,int i_iDataLen)
{
	int iRet=-1;
	FILE *fdJt808=NULL;
	fdJt808=fopen(i_strFile,"r");
	if(NULL==fdJt808)
	{
		printf("Open file fail!\r\n");
	}
	else
	{
		if(NULL==fgets(o_ucDataBuf,i_iDataLen,fdJt808))
		{
			printf("fgets data err\r\n");
		}
		else
		{
			iRet=0;
		}
		fclose(fdJt808);
	}

	return iRet;
}
/*****************************************************************************
-Fuction		: Jt808Parse
-Description	: Jt808Parse
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int Jt808Parse(unsigned char *i_ucDataBuf,int i_iDataLen)
{
	int iRet=-1;
	unsigned char *pucTemp=i_ucDataBuf;
	char strTemp[5];
	unsigned short wMsgId=0; 
	unsigned short wMsgLen=0; 
	if(i_iDataLen<JT808_BASE_LEN*2)
	{
		printf("%s err:%d\r\n",__func__,i_iDataLen);
	}
	else
	{
		printf("标识位:%c%c\r\n",pucTemp[0],pucTemp[1]);
		pucTemp+=2;
		printf("消息ID:%c%c%c%c\r\n",pucTemp[0],pucTemp[1],pucTemp[2],pucTemp[3]);
		memcpy(strTemp,pucTemp,4);
		strTemp[4]='\0';
		wMsgId=strtol(strTemp,NULL,16);
		pucTemp+=4;
		printf("消息体属性(长度):%c%c%c%c\r\n",pucTemp[0],pucTemp[1],pucTemp[2],pucTemp[3]);
		memcpy(strTemp,pucTemp,4);
		strTemp[4]='\0';
		wMsgLen=strtol(strTemp,NULL,16);
		pucTemp+=4;
		Jt808Print("终端手机号",pucTemp,12);	
		pucTemp+=12;
		printf("消息流水号:%c%c%c%c\r\n",pucTemp[0],pucTemp[1],pucTemp[2],pucTemp[3]);
		pucTemp+=4;
		if(0x0200==wMsgId)
		{
			Jt808Print("报警标志",pucTemp,8);	
			pucTemp+=8;
			Jt808Print("状态",pucTemp,8);	
			pucTemp+=8;
			Jt808Print("纬度",pucTemp,8);	
			pucTemp+=8;
			Jt808Print("经度",pucTemp,8);	
			pucTemp+=8;
			Jt808Print("高程",pucTemp,4);	
			pucTemp+=4;
			Jt808Print("速度",pucTemp,4);	
			pucTemp+=4;
			Jt808Print("方向",pucTemp,4);	
			pucTemp+=4;
			Jt808Print("时间",pucTemp,12);	
			pucTemp+=12;
			Jt808Print("附加信息",pucTemp,(wMsgLen-28)*2);	
			pucTemp+=(wMsgLen-28)*2;
		}
		else
		{
			Jt808Print("消息内容",pucTemp,wMsgLen*2);	
			pucTemp+=wMsgLen*2;
		}
		printf("校验:%c%c\r\n",pucTemp[0],pucTemp[1]);
		pucTemp+=2;
		printf("标识位:%c%c\r\n",pucTemp[0],pucTemp[1]);
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: Jt808Parse
-Description	: Jt808Parse
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void Jt808Print(char *i_strCmd,unsigned char *i_ucDataBuf,int i_iDataLen)
{
	int i=0;
	printf("%s:",i_strCmd);
	for(i=0;i<i_iDataLen;i++)
	{
		printf("%c",i_ucDataBuf[i]);
		
	}
	printf("\r\n");
}




