#include<string.h>
#include<stdio.h>

int main(int argc,char **argv)
{
	char cCount=0;
	cCount=(char)((float)240/11+0.5);
	printf("cCount:%d\r\n",cCount);
	if(22>(char)(240/11+0.5))
	{
		printf("no ok\r\n");
	}
	else
	{
		printf("ok\r\n");
	}
	return 0;
}
