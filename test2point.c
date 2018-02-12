#include<stdio.h>
char a=9;
int fuc(char **p)
{
	*p=&a;//使用二级指针才能修改地址
}
int main(int argc,char **argv)
{
	char *i;
	char j;
	i=&j;
	*i=1;
	fuc(&i);
	printf("i=%d\r\n",*i);
}
