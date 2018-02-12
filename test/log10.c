#include <stdio.h>
#include <math.h>


int main(int argc,char **argv)
{
	int x=(int)ceil(log10(200));
	int a=(int)log10(200);
	double b=log10(200);
	printf("log10 200:%lf,int:%d,ceil int:%d\r\n",b,a,x);

	return 0;
}
