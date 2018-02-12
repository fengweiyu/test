#include<stdio.h>
#include<string.h>
int main(char **argv,int argc)
{
	struct test1{
		char c;
		int i;
		short s;
	};
	struct StructPointTest{
		char c;
		int i;
		short s;
	};
	struct test2{
		char c;
		short s;
		int i;
	}b;
	struct test3{
		short s;
		char c;
		int i;
	}c;
	struct test1 a;
	struct test1 *ptTest1=&a;
	struct StructPointTest *ptStructTest;
	a.c=88;
	printf("a=%d\r\n",sizeof(a));
	printf("b=%d\r\n",sizeof(b));
	printf("c=%d\r\n",sizeof(c));	
	printf("ptA=%d\r\n",sizeof(ptStructTest));
	memcpy(&ptStructTest,&ptTest1,sizeof(ptStructTest));
	printf("p.c=%d\r\n",ptStructTest->c);
	return 0;


}
