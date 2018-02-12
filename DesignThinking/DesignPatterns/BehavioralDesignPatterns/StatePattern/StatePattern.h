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

struct StateContext;//先声明一下

typedef struct FatherState//抽象出子类统一会设置上下状态函数
{
	void (*SetContext)(struct StateContext i_tStateContext);//放外面弱耦合
	struct StateContext (*GetContext)();
}T_FatherState;

typedef struct State//以电梯运行四种状态举例
{
	T_FatherState tFatherState;
	void (*Open)(struct State *ptThis);//参数弱耦合
	void (*Close)(struct State *ptThis);
	void (*Run)(struct State *ptThis);
	void (*Stop)(struct State *ptThis);
}T_State;//对各种状态的行为进行抽象后的抽象接口


typedef struct StateContext//因为状态需要切换所以需要上下文类
{
	T_State (*GetClosingState)();
	T_State (*GetStoppingState)();
	T_State (*GetRunningState)();
	T_State (*GetOpenningState)();
	void (*SetState)(T_State i_tState,struct StateContext i_tThis);//供状态设置下一状态使用
	T_State (*GetState)();
	void (*Open)();//内部不加入状态的静态对象,因为增加的话结构体会过于臃肿
	void (*Close)();//而且不加入使用更灵活，同时C的对象都是函数指针不费内存
	void (*Run)();
	void (*Stop)();
}T_StateContext;

T_State GetClosingState();
T_State GetStoppingState();
T_State GetRunningState();
T_State GetOpenningState();
void SetState(T_State i_tState,T_StateContext i_tThis);
T_State GetState();
void Open();
void Close();
void Run();
void Stop();
#define newStateContext {GetClosingState,GetStoppingState,GetRunningState,GetOpenningState,SetState,GetState,Open,Close,Run,Stop};



void SetContext(T_StateContext i_tStateContext);
T_StateContext GetContext();

void RunningStateOpen(T_State *ptThis);
void RunningStateClose(T_State *ptThis);
void RunningStateRun(T_State *ptThis);
void RunningStateStop(T_State *ptThis);
#define newRunningState {SetContext,GetContext,RunningStateOpen,RunningStateClose,RunningStateRun,RunningStateStop}

void StoppingStateOpen(T_State *ptThis);
void StoppingStateClose(T_State *ptThis);
void StoppingStateRun(T_State *ptThis);
void StoppingStateStop(T_State *ptThis);
#define newStoppingState {SetContext,GetContext,StoppingStateOpen,StoppingStateClose,StoppingStateRun,StoppingStateStop}

void ClosingStateOpen(T_State *ptThis);
void ClosingStateClose(T_State *ptThis);
void ClosingStateRun(T_State *ptThis);
void ClosingStateStop(T_State *ptThis);
#define newClosingState {SetContext,GetContext,ClosingStateOpen,ClosingStateClose,ClosingStateRun,ClosingStateStop}

void OpenningStateOpen(T_State *ptThis);
void OpenningStateClose(T_State *ptThis);
void OpenningStateRun(T_State *ptThis);
void OpenningStateStop(T_State *ptThis);
#define newOpenningState {SetContext,GetContext,OpenningStateOpen,OpenningStateClose,OpenningStateRun,OpenningStateStop}



#endif

