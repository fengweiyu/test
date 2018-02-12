 #include<string.h>
 #include<stdio.h>
 int main(char **argv,int argc)
 {
     char a=9;
     char b=8;
     memcpy(&a,&b,sizeof(a));
     printf("mem=%d\r\n",a);
     return 0; 
 }

