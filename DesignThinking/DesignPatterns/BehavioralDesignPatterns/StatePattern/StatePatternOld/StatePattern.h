/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	StatePattern.h
* Description		: 	状态模式
						对各个状态进行管理，也可以改名为StateManage.h
						为统一名称,本文件也是状态模式的核心故还是
						命名为StatePattern.h
* Created			: 	2017.07.12.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef STATE_PATTERN_H
#define STATE_PATTERN_H



typedef struct State//以电梯运行四种状态举例
{
//	T_FatherState tFatherState;//继承父类，由于c中没有super关键字
	void (*Open)();//子类内部函数要初始化后才能使用父类的,除非初始化后再设置状态
	void (*Close)();//为了封装，内部函数就直接调用上下文类设置状态,不使用继承
	void (*Run)();//也是由于C中只有一个上下文Context,才可以这么做
	void (*Stop)();
}T_State;//对各种状态的行为进行抽象后的抽象接口

typedef struct FatherState//抽象出子类统一会设置上下状态函数
{
//void (*SetContext)(T_StateContext *i_ptStateContext);//由于面向对象语言中
//每个子类new的时候都会有一个Context引用产生,切换状态时，
//就需要要设置context(下一个子类才能使用context来设置下一态)，
//而C中只有一个,所以不需要
	void (*SetState)(T_State *i_ptState);//供状态设置下一状态使用
	void (*GetState)(T_State *o_ptState);
}T_FatherState;

typedef struct StateContext//因为状态需要切换所以需要上下文类
{
	void (*SetState)(T_State *i_ptState);//供状态设置下一状态使用
	void (*GetState)(T_State *o_ptState);
	void (*Open)();//内部不加入状态的静态对象,因为增加的话结构体会过于臃肿
	void (*Close)();//而且不加入使用更灵活，同时C的对象都是函数指针不费内存
	void (*Run)();
	void (*Stop)();
}T_StateContext;






void SetState(T_State *i_ptState);
void GetState(T_State *o_ptState);
void Open();
void Close();
void Run();
void Stop();
#define newStateContext {SetState,GetState,Open,Close,Run,Stop};





void RunningStateOpen();
void RunningStateClose();
void RunningStateRun();
void RunningStateStop();
#define newRunningState {RunningStateOpen,RunningStateClose,RunningStateRun,RunningStateStop}

void StoppingStateOpen();
void StoppingStateClose();
void StoppingStateRun();
void StoppingStateStop();
#define newStoppingState {StoppingStateOpen,StoppingStateClose,StoppingStateRun,StoppingStateStop}

void ClosingStateOpen();
void ClosingStateClose();
void ClosingStateRun();
void ClosingStateStop();
#define newClosingState {ClosingStateOpen,ClosingStateClose,ClosingStateRun,ClosingStateStop}

void OpenningStateOpen();
void OpenningStateClose();
void OpenningStateRun();
void OpenningStateStop();
#define newOpenningState {OpenningStateOpen,OpenningStateClose,OpenningStateRun,OpenningStateStop}



#endif

