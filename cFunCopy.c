#include"stdio.h"

int cFunWork(char a)
{
	a=3;
	printf("a=%d\r\n",a);
	return 0;
}

int main(int argc,char **argv)
{
	char b=1;
	cFunWork(b);
	printf("b=%d\r\n",b);
	return 0;
}
