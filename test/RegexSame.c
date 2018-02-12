/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	Regex.c
* Description		: 	

[yweifeng@localhost test]$ gcc -o Regex Regex.c
[yweifeng@localhost test]$ ./Regex
Match
a=fmtp:96 packetization-mode=1;profile-level-id=640020;sprop-parameter-sets=Z2QAIKzZQEgG2wEQAAADABAAAAMB6PGDGWA=,aOvjyyLA
1
640020
Z2QAIKzZQEgG2wEQAAADABAAAAMB6PGDGWA=
aOvjyyLA
[yweifeng@localhost test]$ 


* Created			: 	2017.11.01.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include <stdio.h>  
#include <stdlib.h>

#include <regex.h>



/*****************************************************************************
-Fuction		: main
-Description	: main
.点			匹配除“\r\n”之外的任何单个字符
*				匹配前面的子表达式任意次。例如，zo*能匹配“z”，也能匹配“zo”以及“zoo”。*等价于o{0,}
(pattern)		匹配模式串pattern并获取这一匹配。所获取的匹配可以从产生的Matches集合得到
[xyz]			字符集合。匹配所包含的任意一个字符。例如，“[abc]”可以匹配“plain”中的“a”。
+				匹配前面的子表达式一次或多次(大于等于1次）。例如，“zo+”能匹配“zo”以及“zoo”，但不能匹配“z”。+等价于{1,}。
				//如下例子中不用+，默认是一次，即只能匹配到一个数字6
				
[A-Za-z0-9] 	26个大写字母、26个小写字母和0至9数字

[A-Za-z0-9+/=]	26个大写字母、26个小写字母0至9数字以及+/= 三个字符


-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/11/01	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	int i,j=0;
	char acErrBuf[256];
	int iRet=-1;
	regex_t tReg;    //定义一个正则实例
	const char *strPattern = "a=.*packetization-mode=([0-9]+);profile-level-id=([0-9]+)";//定义模式串
	//profile-level-id=640020;profile-level-id=640021; 相同的,只能匹配前一个
	char *pStrBuf = "a=fmtp:96 packetization-mode=1;profile-level-id=640020;profile-level-id=640021";   //定义待匹配串
	const size_t dwMatch = 5;    //定义匹配结果最大允许数		//表示允许几个匹配
	regmatch_t atMatch[5];   //定义匹配结果在待匹配串中的下标范围	//存储匹配串位置的数组
	//数组0单元存放主正则表达式位置，后边的单元依次存放子正则表达式位置



	//REG_ICASE 匹配字母时忽略大小写。
	iRet =regcomp(&tReg, strPattern, REG_EXTENDED);    //编译正则模式串
	if(iRet != 0) 
	{
		regerror(iRet, &tReg, acErrBuf, sizeof(acErrBuf));
		printf("Regex Error: %s\n", acErrBuf);
	}
	else
	{
		iRet = regexec(&tReg, pStrBuf, dwMatch, atMatch, 0); //匹配他
		if (iRet == REG_NOMATCH)
		{ //如果没匹配上
			printf("No Match\n");
		}
		else if (iRet == REG_NOERROR)
		{  //如果匹配上了
			printf("Match\n");
			for(j=0;j<dwMatch;j++)
			{
				for (i= atMatch[j].rm_so; i < atMatch[j].rm_eo; i++)
				{ //遍历输出匹配范围的字符串
					printf("%c", pStrBuf[i]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("Unknow err:%d",iRet);
		}
		
		regfree(&tReg);  //释放正则表达式
	}
	
	return 0;
}

