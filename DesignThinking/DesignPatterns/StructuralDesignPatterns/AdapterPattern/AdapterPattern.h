/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	AdapterPattern.h
* Description		: 	������ģʽ
									
* Created			: 	2017.07.26.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef ADAPTER_PATTERN_H
#define ADAPTER_PATTERN_H

typedef struct Duck
{//ptThis�е�ʵ����Ҫ��,�еĲ���,Ϊͳһʹ��void *
	void (*Cry)(void *ptThis);//����void *�ⲿ�������޷�ȷ������ʲô����(Ҫ���ݾ���ʵ����ʹ������ж�,
	void (*Appearance)(void *ptThis);//һ�㶼��ֱ�Ӵ��뱾����,�����Ǳ�������������)
	void (*Behavior)(void *ptThis);//���������ͳһ��,�ɲ�ʹ��void *���þ������ʹ���,��T_UglyDuckling *
}T_Duck;//Ŀ���ɫ

typedef struct Swan
{
	void (*Cry)();//����
	void (*Appearance)();//���
	void (*Fly)();
}T_Swan;//Դ��ɫ

typedef struct UglyDuckling//��������ɫ,
{
	T_Swan tFatherSwan;;//Դ��ɫ(ͨ���̳л�ȡԴ��ɫ��Ϣ)
	T_Duck tDuck;//Ŀ���ɫ(���ü̳е���Ϣʵ��Ѽ�ӽӿ�,Ҳ�������Ѽ��)
}T_UglyDuckling;//��������ɫ,�Ѱ���������Ѽ��,


void DucklingCry(void *i_ptThis);
void DucklingAppearance(void *i_ptThis);
void DucklingBehavior(void *i_ptThis);
#define newDuckling {DucklingCry,DucklingAppearance,DucklingBehavior}

void WhiteSwanCry();
void WhiteSwanAppearance();
void WhiteSwanFly();
#define newWhiteSwanFly {WhiteSwanCry,WhiteSwanAppearance,WhiteSwanFly}

void UglyDucklingCry(void *i_ptThis);
void UglyDucklingAppearance(void *i_ptThis);
void UglyDucklingBehavior(void *i_ptThis);
#define newUglyDuckling {newWhiteSwanFly,UglyDucklingCry,UglyDucklingAppearance,UglyDucklingBehavior}

#endif

