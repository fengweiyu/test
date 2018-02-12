#include<stdio.h>
#include<string.h>
int main(int argc,char **argv)
{
	char temp[2]={1,1};
	short tmp =0;
	memcpy(&tmp,&temp,2);
	printf("tmp =%d\r\n",tmp);

}
