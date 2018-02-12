/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	ResponsibilityChainPattern.h
* Description		: 	������ģʽ
									
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


typedef struct Woman//Ů����
{
	int (*GetType)();
	char *  (*GetRequest)(); 
	void (*SetType)(int i_iType);//	void (*SetRequest)(char *i_strRequset);
}T_Woman;

struct Handle;

typedef struct HandleManage//ͳһ����ŵ�����
{
	void (*HandleMessage)(T_Woman *i_ptWoman,struct Handle *i_ptThis);//struct Handle *i_ptThis���ڵ�������ķ���
	//���������������,���������ʵ�ַ�����ֱ�ӵ���
	//���ඨ���������Ҫʵ�ֵĳ��󷽷�����

}T_HandleManage;

typedef struct Handle
{//���Ƴ�����
	T_HandleManage tFatherHandle;//������ʵ��(�궨�屣֤)
	void (*Handle)(T_Woman *i_ptWoman);//������ʵ��,���Ƴ��󷽷�//��������
	int (*GetLevel)();
	void (*SetNextHandle)(struct Handle *i_ptHandle);//����C���еĳ�Ա�����Ǿ�̬��,���Էŵ�������
	struct Handle *(*GetNextHandle)();
}T_Handle;


void HandleMessage(T_Woman *i_ptWoman,T_Handle *i_ptThis);

void FatherReponse(T_Woman *i_ptWoman);
int GetFatherHandleLevel();
void SetFatherNextHandle(T_Handle*i_ptHandle);
T_Handle *GetFatherNextHandle();
//ͨ���궨��ȷ���̳й�ϵ�Լ�����Ĳ�����д
#define newFatherHandle {HandleMessage,FatherReponse,GetFatherHandleLevel,SetFatherNextHandle,GetFatherNextHandle}

void HusbandReponse(T_Woman *i_ptWoman);
int GetHusbandHandleLevel();
void SetHusbandNextHandle(T_Handle*i_ptHandle);
T_Handle *GetHusbandNextHandle();
//ͨ���궨��ȷ���̳й�ϵ�Լ�����Ĳ�����д
#define newHusbandHandle {HandleMessage,HusbandReponse,GetHusbandHandleLevel,SetHusbandNextHandle,GetHusbandNextHandle}

void SonReponse(T_Woman *i_ptWoman);
int GetSonHandleLevel();
void SetSonNextHandle(T_Handle*i_ptHandle);
T_Handle *GetSonNextHandle();
//ͨ���궨��ȷ���̳й�ϵ�Լ�����Ĳ�����д
#define newSonHandle {HandleMessage,SonReponse,GetSonHandleLevel,SetSonNextHandle,GetSonNextHandle}









int GetType();
char *GetRequest();
void SetType(int i_iType);
#define newWoman {GetType,GetRequest,SetType}

#endif

