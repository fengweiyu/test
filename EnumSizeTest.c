#include"stdio.h"
#include"string.h"

typedef enum EnumSize
{
	one,
	two
}T_EnumSize;

int main(int argc,char **argv)
{
	printf("EnumSize:%d\r\n",sizeof(T_EnumSize));
	return 0;

}
