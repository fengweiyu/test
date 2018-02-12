#include<stdio.h>
#include<string.h>
int main(int argc,char **argv)
{
	char a[3];
	memset(a,'0',sizeof(a));
	snprintf(a,4,"abcd");
	printf("str:%s\r\n",a);
	return 0;
}
