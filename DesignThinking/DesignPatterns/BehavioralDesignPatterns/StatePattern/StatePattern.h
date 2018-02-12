/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	StatePattern.h
* Description		: 	״̬ģʽ
						�Ը���״̬���й���Ҳ���Ը���ΪStateManage.h
						Ϊͳһ����,���ļ�Ҳ��״̬ģʽ�ĺ��Ĺʻ���
						����ΪStatePattern.h
* Created			: 	2017.07.12.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef STATE_PATTERN_H
#define STATE_PATTERN_H

struct StateContext;//������һ��

typedef struct FatherState//���������ͳһ����������״̬����
{
	void (*SetContext)(struct StateContext i_tStateContext);//�����������
	struct StateContext (*GetContext)();
}T_FatherState;

typedef struct State//�Ե�����������״̬����
{
	T_FatherState tFatherState;
	void (*Open)(struct State *ptThis);//���������
	void (*Close)(struct State *ptThis);
	void (*Run)(struct State *ptThis);
	void (*Stop)(struct State *ptThis);
}T_State;//�Ը���״̬����Ϊ���г����ĳ���ӿ�


typedef struct StateContext//��Ϊ״̬��Ҫ�л�������Ҫ��������
{
	T_State (*GetClosingState)();
	T_State (*GetStoppingState)();
	T_State (*GetRunningState)();
	T_State (*GetOpenningState)();
	void (*SetState)(T_State i_tState,struct StateContext i_tThis);//��״̬������һ״̬ʹ��
	T_State (*GetState)();
	void (*Open)();//�ڲ�������״̬�ľ�̬����,��Ϊ���ӵĻ��ṹ������ӷ��
	void (*Close)();//���Ҳ�����ʹ�ø���ͬʱC�Ķ����Ǻ���ָ�벻���ڴ�
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

