/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ResponsibilityChainPattern.h
* Description		: 	责任链模式
									
* Created			: 	2017.07.13.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef RESPONSIBILITY_CHAIN_PATTERN_H
#define RESPONSIBILITY_CHAIN_PATTERN_H


#define FATHER_HANDLE_LEVEL		1
#define HUSBAND_HANDLE_LEVEL	2
#define SON_HANDLE_LEVEL			3

#define HANDLE_NUMBER	3


typedef struct Woman//女性类
{
	int (*GetType)();
	char *  (*GetRequest)(); 
	void (*SetType)(int i_iType);//	void (*SetRequest)(char *i_strRequset);
}T_Woman;

struct Handle;

typedef struct HandleManage//统一处理放到父类
{
	void (*HandleMessage)(T_Woman *i_ptWoman,struct Handle *i_ptThis);//struct Handle *i_ptThis用于调用子类的方法
	//其他面向对象语言,调用子类的实现方法可直接调用
	//父类定义的子类需要实现的抽象方法即可

}T_HandleManage;

typedef struct Handle
{//类似抽象类
	T_HandleManage tFatherHandle;//父类来实现(宏定义保证)
	void (*Handle)(T_Woman *i_ptWoman);//由子类实现,类似抽象方法//对请求处理
	int (*GetLevel)();
	void (*SetNextHandle)(struct Handle *i_ptHandle);//由于C类中的成员变量是静态的,所以放到子类中
	struct Handle *(*GetNextHandle)();
}T_Handle;


void HandleMessage(T_Woman *i_ptWoman,T_Handle *i_ptThis);

void FatherReponse(T_Woman *i_ptWoman);
int GetFatherHandleLevel();
void SetFatherNextHandle(T_Handle*i_ptHandle);
T_Handle *GetFatherNextHandle();
//通过宏定义确保继承关系以及父类的不被覆写
#define newFatherHandle {HandleMessage,FatherReponse,GetFatherHandleLevel,SetFatherNextHandle,GetFatherNextHandle}

void HusbandReponse(T_Woman *i_ptWoman);
int GetHusbandHandleLevel();
void SetHusbandNextHandle(T_Handle*i_ptHandle);
T_Handle *GetHusbandNextHandle();
//通过宏定义确保继承关系以及父类的不被覆写
#define newHusbandHandle {HandleMessage,HusbandReponse,GetHusbandHandleLevel,SetHusbandNextHandle,GetHusbandNextHandle}

void SonReponse(T_Woman *i_ptWoman);
int GetSonHandleLevel();
void SetSonNextHandle(T_Handle*i_ptHandle);
T_Handle *GetSonNextHandle();
//通过宏定义确保继承关系以及父类的不被覆写
#define newSonHandle {HandleMessage,SonReponse,GetSonHandleLevel,SetSonNextHandle,GetSonNextHandle}









int GetType();
char *GetRequest();
void SetType(int i_iType);
#define newWoman {GetType,GetRequest,SetType}

#endif

