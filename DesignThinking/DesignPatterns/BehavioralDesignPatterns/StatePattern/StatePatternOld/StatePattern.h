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



typedef struct State//�Ե�����������״̬����
{
//	T_FatherState tFatherState;//�̳и��࣬����c��û��super�ؼ���
	void (*Open)();//�����ڲ�����Ҫ��ʼ�������ʹ�ø����,���ǳ�ʼ����������״̬
	void (*Close)();//Ϊ�˷�װ���ڲ�������ֱ�ӵ���������������״̬,��ʹ�ü̳�
	void (*Run)();//Ҳ������C��ֻ��һ��������Context,�ſ�����ô��
	void (*Stop)();
}T_State;//�Ը���״̬����Ϊ���г����ĳ���ӿ�

typedef struct FatherState//���������ͳһ����������״̬����
{
//void (*SetContext)(T_StateContext *i_ptStateContext);//�����������������
//ÿ������new��ʱ�򶼻���һ��Context���ò���,�л�״̬ʱ��
//����ҪҪ����context(��һ���������ʹ��context��������һ̬)��
//��C��ֻ��һ��,���Բ���Ҫ
	void (*SetState)(T_State *i_ptState);//��״̬������һ״̬ʹ��
	void (*GetState)(T_State *o_ptState);
}T_FatherState;

typedef struct StateContext//��Ϊ״̬��Ҫ�л�������Ҫ��������
{
	void (*SetState)(T_State *i_ptState);//��״̬������һ״̬ʹ��
	void (*GetState)(T_State *o_ptState);
	void (*Open)();//�ڲ�������״̬�ľ�̬����,��Ϊ���ӵĻ��ṹ������ӷ��
	void (*Close)();//���Ҳ�����ʹ�ø���ͬʱC�Ķ����Ǻ���ָ�벻���ڴ�
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

