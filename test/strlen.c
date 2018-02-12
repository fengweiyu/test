#include "stdlib.h"
#include "stdio.h"
#include "string.h"




int main(int argc,char **argv)
{
	char file[126]={0};
	memset(file,0,sizeof(file));
	printf("Len:%d\r\n",strlen(file));
	

	return 0;


}
