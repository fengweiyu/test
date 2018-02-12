#include<stdio.h>
#include<string.h>
#include <sys/time.h>
typedef struct T_ISizeof{
	char *name;//28+4=32
	int c[20];//32+1=33,36 每个成员的偏移量都得是对应类型的整数倍，并不是变量的大小的倍数
}T_ISizeof;
typedef struct T_Sizeof{
	char *name;//0
	int a[5];//0+1=1 ,4
	int b;//4+20=24(偏移量=上个偏移量+上个变量大小)
	struct T_Sizeof *ptnext;//24+4=28
	T_ISizeof TSIZEOF;//把结构体里面的等同在这里算就行，注意结构体大小要是里面最大类型的整数倍(即116是4的整数倍			          //所以ok)
	int  (*Pinit) (char p[],unsigned int c);//36+80=116
	int (*s)(char *s);//116+4 120
		
}T_Sizeof,*PT_Sizeof;//120+4=124 结构体大小也就是结束这里的偏移量(上个偏移量120+大小4=124，是里面最大类型4的整数倍)
int pinit(char p[],unsigned int c)
{
	if(c==1)
	{
		char *str;
		printf("p:%c\n",p[0]);//打印出h
	}
	
}
int shows(char *s)
{
	char str[6];//要给大小出来，不然报错
	strcpy(str,s);
	printf("s=%c\n",str[1]);//打印出e
}
static T_Sizeof T_IGetSizeof = {
	.name = "sizeof",
	/*.a = {
		[0] = 1,
		[1] = 2,
		[2] = 3,
		[3] = 4
		[4] = 5,
		},*/
	.a = {1,2,3,4,5,},
	/*.a[0] = 1,
	.a[1] = 2,
	.a[2] = 3,
	.a[3] = 4,
	.a[4] = 5,*/	
	.b = 4,
	.ptnext = NULL,
	.TSIZEOF.name="size",
	.TSIZEOF.c[0]=0,
	.Pinit = pinit,
	.s = shows,
};
int funp()
{
	unsigned char index;
	for(index=20;index>=0;index--)
		printf("index value:%d\n",index);
	/*0-255之间不断打印*/
	return 0;
}
int main(int argc, char **argv)
{
	struct timeval tTV;
       tTV.tv_sec = 0;
       tTV.tv_usec = 0;
	PT_Sizeof ptmp;
	char str1[]= "hello";
	//gettimeofday(&tTV,NULL);
	//gettimeofday()功能是得到当前时间和时区，分别写到tv和tz中，如果tz为NULL则不向tz写入。
	/*还可以使用*str1，但是由于变量以及存储区的原因，访问和修改就不同了*/
	printf("struct tsizeof:%d\n",sizeof(T_Sizeof));//打印出来的数组的大小要包含进去  124
	//printf("struct tsizeof:%d\n",T_IGetSizeof.a);//T_IGetSizeof.a打印出来的地址
	printf("struct tsizeof:%d\n",T_IGetSizeof.a[0]);//打印出来的是1
	printf("struct tsizeof:%d\n",sizeof(T_IGetSizeof));//初始化的大小等同于定义类型的值 124
	printf("struct tsizeof:%s\n",  T_IGetSizeof.TSIZEOF.name);//size
	printf("struct tsizeof:%d\n",T_IGetSizeof.TSIZEOF.c[0]);//0
	printf("tvsec:%d,tvusec:%d\n",tTV.tv_sec,tTV.tv_usec);
	ptmp = &T_IGetSizeof;
	ptmp->Pinit(str1,1);
	ptmp->s(str1);
	//funp();
	return 0;
	
}
