#include<stdio.h>
#include<string.h>
int main(char **argv,int argc)
{
	char TwoArray[2][3]=
	{
		{1,2,3},
		{4,5,6}
	};
	char Array[3]={7,8,9};
	memset(TwoArray,0,sizeof(TwoArray));
	printf("size:%d\r\n",sizeof(TwoArray));
	memcpy(&Array,&TwoArray[1][0],sizeof(TwoArray[1]));
	printf("Len:%d\r\n",sizeof(TwoArray[1]));
	printf("a:%d\r\n",Array[0]);

}
