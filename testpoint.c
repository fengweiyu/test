#include<stdio.h>
#include<string.h>
int main(int argc,char **argv)
{
	int i=8998;
	int j=8;
	int *p=&j;
	//int *p=NULL;
	memcpy(p,&i,4);
	//memcpy use byte for unit and can nou use a point what is not init	
	printf("p=%d\r\n",*p);
	return 0;
}
