#include "stdio.h"
#include "string.h"
int main(int argc,char **argv)
{
	char auc[6];
	char ac[]={1,2,3,4,5};
	printf("acSize:%d\r\n",sizeof(ac));
	memcpy(auc,ac,sizeof(ac));
	return 0;
}
