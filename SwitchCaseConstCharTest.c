#include<stdio.h>
int main(char **argv,int argc)
{
	const char *name="abc";
	switch(name)
	{
		case "abc":
		{
			printf("case ok\r\n");
			break;
		}
		default:
		break;
	}
	return 0;

}
