#include<stdio.h>
#include<string.h>
#include <sys/time.h>
typedef struct T_ISizeof{
	char *name;
	int c[20];
}T_ISizeof;
typedef struct T_Sizeof{
	char *name;
	int a[5];
	int b;
	struct T_Sizeof *ptnext;
	T_ISizeof TSIZEOF;
	int  (*Pinit) (char p[],unsigned int c);
	int (*s)(char *s);
		
}T_Sizeof,*PT_Sizeof;
int pinit(char p[],unsigned int c)
{
	if(c==1)
	{
		char *str;
		printf("p:%c\n",p[0]);//��ӡ��h
	}
	
}
int shows(char *s)
{
	char str[6];//Ҫ����С��������Ȼ����
	strcpy(str,s);
	printf("s=%c\n",str[1]);//��ӡ��e
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
	/*0-255֮�䲻�ϴ�ӡ*/
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
	//gettimeofday()�����ǵõ���ǰʱ���ʱ�����ֱ�д��tv��tz�У����tzΪNULL����tzд�롣
	/*������ʹ��*str1���������ڱ����Լ��洢����ԭ�򣬷��ʺ��޸ľͲ�ͬ��*/
	printf("struct tsizeof:%d\n",sizeof(T_Sizeof));//��ӡ����������Ĵ�СҪ������ȥ
	//printf("struct tsizeof:%d\n",T_IGetSizeof.a);//T_IGetSizeof.a��ӡ�����ĵ�ַ
	printf("struct tsizeof:%d\n",T_IGetSizeof.a[0]);//��ӡ��������1
	printf("struct tsizeof:%d\n",sizeof(T_IGetSizeof));//��ʼ���Ĵ�С��ͬ�ڶ������͵�ֵ
	printf("struct tsizeof:%s\n",  T_IGetSizeof.TSIZEOF.name);//size
	printf("struct tsizeof:%d\n",T_IGetSizeof.TSIZEOF.c[0]);//0
	printf("tvsec:%d,tvusec:%d\n",tTV.tv_sec,tTV.tv_usec);
	ptmp = &T_IGetSizeof;
	ptmp->Pinit(str1,1);
	ptmp->s(str1);
	//funp();
	return 0;
	
}
