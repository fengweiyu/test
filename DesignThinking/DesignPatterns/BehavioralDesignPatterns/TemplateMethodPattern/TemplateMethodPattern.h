/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	TemplateMethodPattern.h
* Description		: 	ģ�淽��ģʽ
						��Ҫ��ģ�淽����ͬʱģ�淽�����ø�����������
						������Ҳ���Ը���ΪTemplateMethod.h
						Ϊͳһ����,���ļ�Ҳ��ģ�淽��ģʽ�ĺ��Ĺʻ���
						����ΪTemplateMethodPattern.h
									
* Created			: 	2017.07.12.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef TEMPLATE_METHOD_PATTERN_H
#define TEMPLATE_METHOD_PATTERN_H

struct HummerModel;

typedef struct HummerDemonstration//����ģ����ʾ
{
	void (*Run)(struct HummerModel *i_ptThis);//������д
}T_HummerDemonstration;//�������������


typedef struct HummerModel//�����캷��Ϊ��
{
	void (*Start)();
	void (*EngineBoom)();
	void (*Alarm)();
	void (*Stop)();	
	T_HummerDemonstration tFatherDemonstration;//����ֱ�Ӱ�Run�����������
	//Ϊ�˱������ʹ�ü̳г�����������֣�����ôд
}T_HummerModel;//������ģ��





void HummerRun(T_HummerModel *i_ptHummerModel);
void HummerH1ModelStart();
void HummerH1ModelEngineBoom();
void HummerH1ModelAlarm();
void HummerH1ModelStop();
#define newHummerH1Model {HummerH1ModelStart,HummerH1ModelEngineBoom,\
						    HummerH1ModelAlarm,HummerH1ModelStop,HummerRun}//���һ������������д

void HummerH2ModelStart();
void HummerH2ModelEngineBoom();
void HummerH2ModelAlarm();
void HummerH2ModelStop();
#define newHummerH2Model {HummerH2ModelStart,HummerH2ModelEngineBoom,\
						    HummerH2ModelAlarm,HummerH2ModelStop,HummerRun}//���һ������������д

#endif

