#include<stdio.h>
#include<string.h>
int main(int argc,char **argv)
{
	char tem='a';
	char te[6];
	char i;
	snprintf(te,sizeof(te),"cc%c\r\n",tem);
	for(i=0;i<6;i++)	
	{
		printf("%c",te[i]);
	}
	return 0;
}
