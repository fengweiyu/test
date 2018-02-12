#include"stdio.h"
#include"string.h"

char FunGetPara()
{
	return 'a';
}
void FunUsePara(char i_cPara)
{
	char a=i_cPara;
	printf("Para:%c\r\n",i_cPara);
	printf("Para=%d\r\n",a);
}
int main(int argc,char **argv)
{
	FunUsePara(FunGetPara());
	return 0;
}
