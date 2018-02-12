#include<stdio.h>
#include<string.h>
int main(int argc,char **argv)
{
	char temp[2]={0,0};
	char i;
	short tem=0x0101;
	memcpy(temp,&tem,2);
	for(i=0;i<2;i++)
	{
		printf("temp =%d\r\n",temp[i]);
	}
	return 0;

}
