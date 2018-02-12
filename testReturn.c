#include<stdio.h>
#include<string.h>


typedef struct Num
{
	int Num1;
	int Num2;

}T_Num;

static int g_iNum=123;
static T_Num g_tNum={11,22};
static T_Num g_tNum1={13,23};

int GetNum()
{
	return g_iNum;
}

T_Num GetNums()
{
	return g_tNum;

}


int main(char **argv,int argc)
{
	//GetNum()=1;
	//GetNums().Num1=2;
	//memcpy(&GetNums(),&g_tNum1,sizeof(T_Num));//都不允许赋值
	printf("Num1:%d\r\n",GetNums().Num1);//都只能读取无法赋值


	return 0;
}

