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
.��			ƥ�����\r\n��֮����κε����ַ�
*				ƥ��ǰ����ӱ��ʽ����Ρ����磬zo*��ƥ�䡰z����Ҳ��ƥ�䡰zo���Լ���zoo����*�ȼ���o{0,}
(pattern)		ƥ��ģʽ��pattern����ȡ��һƥ�䡣����ȡ��ƥ����ԴӲ�����Matches���ϵõ�
[xyz]			�ַ����ϡ�ƥ��������������һ���ַ������磬��[abc]������ƥ�䡰plain���еġ�a����
+				ƥ��ǰ����ӱ��ʽһ�λ���(���ڵ���1�Σ������磬��zo+����ƥ�䡰zo���Լ���zoo����������ƥ�䡰z����+�ȼ���{1,}��
				//���������в���+��Ĭ����һ�Σ���ֻ��ƥ�䵽һ������6
				
[A-Za-z0-9] 	26����д��ĸ��26��Сд��ĸ��0��9����

[A-Za-z0-9+/=]	26����д��ĸ��26��Сд��ĸ0��9�����Լ�+/= �����ַ�


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
	regex_t tReg;    //����һ������ʵ��
	const char *strPattern = "a=.*packetization-mode=([0-9]+);profile-level-id=([0-9]+)";//����ģʽ��
	//profile-level-id=640020;profile-level-id=640021; ��ͬ��,ֻ��ƥ��ǰһ��
	char *pStrBuf = "a=fmtp:96 packetization-mode=1;profile-level-id=640020;profile-level-id=640021";   //�����ƥ�䴮
	const size_t dwMatch = 5;    //����ƥ�������������		//��ʾ������ƥ��
	regmatch_t atMatch[5];   //����ƥ�����ڴ�ƥ�䴮�е��±귶Χ	//�洢ƥ�䴮λ�õ�����
	//����0��Ԫ�����������ʽλ�ã���ߵĵ�Ԫ���δ����������ʽλ��



	//REG_ICASE ƥ����ĸʱ���Դ�Сд��
	iRet =regcomp(&tReg, strPattern, REG_EXTENDED);    //��������ģʽ��
	if(iRet != 0) 
	{
		regerror(iRet, &tReg, acErrBuf, sizeof(acErrBuf));
		printf("Regex Error: %s\n", acErrBuf);
	}
	else
	{
		iRet = regexec(&tReg, pStrBuf, dwMatch, atMatch, 0); //ƥ����
		if (iRet == REG_NOMATCH)
		{ //���ûƥ����
			printf("No Match\n");
		}
		else if (iRet == REG_NOERROR)
		{  //���ƥ������
			printf("Match\n");
			for(j=0;j<dwMatch;j++)
			{
				for (i= atMatch[j].rm_so; i < atMatch[j].rm_eo; i++)
				{ //�������ƥ�䷶Χ���ַ���
					printf("%c", pStrBuf[i]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("Unknow err:%d",iRet);
		}
		
		regfree(&tReg);  //�ͷ�������ʽ
	}
	
	return 0;
}

