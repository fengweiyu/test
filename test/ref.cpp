#include "stdlib.h"
#include "stdio.h"
#include "string.h"



int & ChangeFun()
{
	int i=11;
	return i;
	
	
}
int id=13;

int & ChangeFun1()
{
	
	return id;//报警告但有效
}
int * ChangeFun2()
{
	
	int i=13;
	return &i;//报警告但有效
}
int ChangeFun3()
{
	
	int i=14;
	return i;
}

void ChangeFun(int &i)
{
	int j=12;
	memcpy(&i,&j,4);
	
}


int main(int argc,char **argv)
{
	int i=0;
	//int &j;//引用必须初始化
	i=ChangeFun();
	printf("i=%d\r\n",i);
	ChangeFun(i);
	printf("i=%d\r\n",i);
	
	printf("id=%d\r\n",id);
	ChangeFun1()=123;
	printf("id=%d\r\n",id);
	
	i=*ChangeFun2();
	printf("i=%d\r\n",i);
	
	
	//ChangeFun3()=133;//这样错误
	
	
	
	return 0;
}
