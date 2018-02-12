

#include <stdio.h>
#include "Virtual.h"

int main(int argc,char **argv)
{
	Virtual Virtual;
	Virtual.PrintInfo();
}

virtual void Virtual::PrintInfo()
{
	printf("PrintInfo\r\n");
}

