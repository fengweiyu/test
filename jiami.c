#include"stdio.h"
#include"string.h"
int main(int argc,char **argv)
{
	char *pOpassword="13dgs1";
	char acArgv[6]={10,15,12,2,0,6};
	char acPassword[6];
	int i=0;
	//memcpy(acArgv,argv[1],6);
//	for(i=0;i<6;i++)
	{
		//printf("%x",acArgv[i]);
	}
	//printf("\r\n");
	for(i=0;i<6;i++)
	{
		acPassword[i]=(pOpassword[i]^acArgv[i])%(i+23);
		printf("%x",acPassword[i]);
		printf("\r\n");
	}
	printf("\r\n");
	return 0;
}
