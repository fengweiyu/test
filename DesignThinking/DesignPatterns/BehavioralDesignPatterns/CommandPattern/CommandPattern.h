/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	CommandPattern.h
* Description		: 	命令模式
									
* Created			: 	2017.07.18.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef COMMAND_PATTERN_H
#define COMMAND_PATTERN_H



typedef struct Group
{
	void (*Find)();
	void (*Add)();
	void (*Delete)();
	void (*Change)();
	void (*Plan)();
}T_Group;

typedef struct Command
{
	T_Group tRequirementGroup;
	T_Group tCodeGroup;
	T_Group tPageGroup;
	void (*Execute)(struct Command *i_ptThis);
}T_Command;

typedef struct Invoker
{
	void (*SetCommand)(T_Command *i_ptCommand);
	void (*Action)();
}T_Invoker;


void RequirementGroupFind();
void RequirementGroupAdd();
void RequirementGroupDelete();
void RequirementGroupChange();
void RequirementGroupPlan();
#define newRequirementGroup {RequirementGroupFind,RequirementGroupAdd,RequirementGroupDelete,\
						     RequirementGroupChange,RequirementGroupPlan}

void CodeGroupFind();
void CodeGroupAdd();
void CodeGroupDelete();
void CodeGroupChange();
void CodeGroupPlan();
#define newCodeGroup {CodeGroupFind,CodeGroupAdd,CodeGroupDelete,CodeGroupChange,CodeGroupPlan}

void PageGroupFind();
void PageGroupAdd();
void PageGroupDelete();
void PageGroupChange();
void PageGroupPlan();
#define newPageGroup {PageGroupFind,PageGroupAdd,PageGroupDelete,PageGroupChange,PageGroupPlan}



void AddRequirementCommandExecute(T_Command *i_ptThis);
#define newAddRequirementCommand {newRequirementGroup,newCodeGroup,newPageGroup,AddRequirementCommandExecute}

void DeletePageCommandExecute(T_Command *i_ptThis);
#define newDeletePageCommand {newRequirementGroup,newCodeGroup,newPageGroup,DeletePageCommandExecute}


extern const T_Invoker g_tInvoker;//单例，一个项目一个接头人



#endif

