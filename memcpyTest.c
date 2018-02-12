#include"stdio.h"
#include"string.h"

int main(int argc,char **argv)
{
	char TestMemcpy[5]={0};
	memcpy(TestMemcpy,"1234",strlen("1234"));
	memcpy(TestMemcpy+1,TestMemcpy,3);
	printf("Mem:%s\r\n",TestMemcpy);
	TestMemcpy[5]='6';
//	TestMemcpy[4]='7';
	printf("Last:%d\r\n",TestMemcpy[sizeof(TestMemcpy)-1]);
	return 0;
}
