#include"stdio.h"
#include"string.h"
char v=2;
char *ReturnPointFun()
{
	return &v;
}
int main(int argc,char **argv)
{
	char a=1;
	char *c;
	a=*ReturnPointFun();
	c=ReturnPointFun();
	printf("a=%d,c=%d\r\n",a,*c);
	return 0;
}
