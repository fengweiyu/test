/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	TemplateMethodPattern.h
* Description		: 	模版方法模式
						主要放模版方法，同时模版方法调用各个基本方法
						，所以也可以改名为TemplateMethod.h
						为统一名称,本文件也是模版方法模式的核心故还是
						命名为TemplateMethodPattern.h
									
* Created			: 	2017.07.12.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef TEMPLATE_METHOD_PATTERN_H
#define TEMPLATE_METHOD_PATTERN_H

struct HummerModel;

typedef struct HummerDemonstration//悍马模型演示
{
	void (*Run)(struct HummerModel *i_ptThis);//不允许覆写
}T_HummerDemonstration;//抽象出公共部分


typedef struct HummerModel//以制造悍马为例
{
	void (*Start)();
	void (*EngineBoom)();
	void (*Alarm)();
	void (*Stop)();	
	T_HummerDemonstration tFatherDemonstration;//可以直接把Run方法放这里，但
	//为了表意清楚使用继承抽象出公共部分，就这么写
}T_HummerModel;//抽象悍马模型





void HummerRun(T_HummerModel *i_ptHummerModel);
void HummerH1ModelStart();
void HummerH1ModelEngineBoom();
void HummerH1ModelAlarm();
void HummerH1ModelStop();
#define newHummerH1Model {HummerH1ModelStart,HummerH1ModelEngineBoom,\
						    HummerH1ModelAlarm,HummerH1ModelStop,HummerRun}//最后一个参数不允许覆写

void HummerH2ModelStart();
void HummerH2ModelEngineBoom();
void HummerH2ModelAlarm();
void HummerH2ModelStop();
#define newHummerH2Model {HummerH2ModelStart,HummerH2ModelEngineBoom,\
						    HummerH2ModelAlarm,HummerH2ModelStop,HummerRun}//最后一个参数不允许覆写

#endif

