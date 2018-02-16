




#include "ManyVirtual.h"

virtual1::virtual1()
{


}
virtual1::~virtual1()
{


}

void virtual1::print()
{
	printf("this is virtual1\r\n");

}

virtual2::virtual2()
{


}
virtual2::~virtual2()
{


}

void virtual2::print()
{
	printf("this is virtual2\r\n");

}

virtual3::virtual3()
{


}
virtual3::~virtual3()
{


}

void virtual3::print()
{
	printf("this is virtual3\r\n");

}

/*
book@book-desktop:/work/project/test$ 
book@book-desktop:/work/project/test$ g++ -o ManyVirtual ManyVirtual.cpp 
book@book-desktop:/work/project/test$ ./ManyVirtual 
this is virtual3
*/
int main(int argc,char **argv)
{
	virtual3 virtualObj;
	virtualObj.print();

	return 0;
}