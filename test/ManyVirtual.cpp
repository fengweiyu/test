/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu All rights reserved.
------------------------------------------------------------------------------
* File Module	: ManyVirtual.cpp
* Description	: ManyVirtual operation center

book@book-desktop:/work/project/test$ 
book@book-desktop:/work/project/test$ g++ -o ManyVirtual ManyVirtual.cpp 
book@book-desktop:/work/project/test$ ./ManyVirtual 
this is virtual 3
this is virtualprint 3
this is virtual 3
this is virtualprint 2
this is virtualprint 3

//基类函数名加上virtual表示虚函数，基类对应的实现函数可以加也可以不加，
同时派生类对应的函数可以加也可以不加，已经是虚函数的属性了，此时在向上转型中派生类实现的与基类一样的函数就可以被调用(派生类的对象当然可以调用自己的成员函数不管是否有virtual)，
否则在向上转型中调用的都是基类的(即没有加virtual的情况)。

* Created	: 2017.09.11.
* Author	: Yu Weifeng
* Function List : 
* Last Modified : 
* History	: 
******************************************************************************/

 

 

#include "ManyVirtual.h"

virtual1::virtual1()
{


}
virtual1::~virtual1()
{


}
void virtual1::print()
{
printf("this is virtual 1\r\n");

}

virtual2::virtual2()
{


}
virtual2::~virtual2()
{


}
void virtual2::print()
{
printf("this is virtual 2\r\n");

}
void virtual2::virtualprint()
{
printf("this is virtualprint 2\r\n");

}

virtual3::virtual3()
{


}
virtual3::~virtual3()
{


}
void virtual3::print()
{
printf("this is virtual 3\r\n");

}
void virtual3::virtualprint()
{
printf("this is virtualprint 3\r\n");

}

int main(int argc,char **argv)
{
virtual3 virtualObj3;
virtualObj3.print();//已经是虚函数的属性
virtualObj3.virtualprint();//调用的是virtualObj3自己的virtualprint

//virtual2 *virtualObj2=&virtualObj3;//这样编译错误，不能访问
virtual2 *virtualObj2=(virtual2 *)&virtualObj3;//向上转型(要加强制转换否则编译错误)
//virtual2 *virtualObj2 = (virtual2 *)new virtual3;//向上转型(要加强制转换否则编译错误)
virtualObj2->print();//派生类(virtualObj3)的print被调用

virtualObj2->virtualprint();//调用的是基类的
virtualObj3.virtualprint();//调用的是virtualObj3自己的virtualprint

return 0;
}