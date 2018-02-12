#include<stdio.h>
int main(int argc,char **argv)
{
     char temp[2]={'a','b'};
     short tem =0;
     memcpy(&tem,temp,2);
    printf("tem:%d\r\n",tem);
     return 0;
}
