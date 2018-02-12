/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	DualLinkList.c
* Description		: 	DualLinkList operation center
* Created			: 	2017.04.22.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"string.h"

typedef struct MazePosType
{
	int x;
	int y;
}T_MazePosType,*PT_MazePosType;
typedef struct StackElement
{
	int iOrder;
	T_MazePosType tPos;
	int iDirection;
}T_StackElement,*PT_StackElement;
typedef struct SeqStack
{
	T_StackElement *ptBase; 
	T_StackElement *ptTop; 
	int iLen;
}T_SeqStack,*PT_SeqStack;

#define MAX_MAZE_LENGTH				25
#define MAX_STACK_LENGTH				(MAX_MAZE_LENGTH*MAX_MAZE_LENGTH)
#define INCREMENT_STACK_LENGTH		(2)

static int InitStack(T_SeqStack *i_ptSeqStack);
static int Push(T_SeqStack *i_ptSeqStack,T_StackElement *i_ptStackElement);
static int Pop(T_SeqStack *i_ptSeqStack,T_StackElement *o_ptStackElement);
static int StackEmpty(T_SeqStack *i_ptSeqStack);

static void PrintMaze(int i_daiMaze[][MAX_MAZE_LENGTH],int i_iX,int i_iY);
static void InitMaze(int i_dwPassValue,int i_daiMaze[][MAX_MAZE_LENGTH],int *o_piX,int *o_piY,T_MazePosType *ptBeginPos,T_MazePosType *ptEndPos);
static int PassJudge(int i_daiMaze[][MAX_MAZE_LENGTH],T_MazePosType *i_ptMazePos);
static void FootMark(int i_daiMaze[][MAX_MAZE_LENGTH],T_MazePosType *i_ptMazePos,int i_iCurStep);
static void NextPos(T_MazePosType *i_ptMazePos,int i_iDirection);
static void NoWayMark(int i_daiMaze[][MAX_MAZE_LENGTH],T_MazePosType *i_ptMazePos);


/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
	int aMaze[MAX_MAZE_LENGTH][MAX_MAZE_LENGTH]={0};
	int iRowNum,iRankNum;
	T_MazePosType tBeginPos={0};
	T_MazePosType tEndPos={0};
	InitMaze(1,aMaze,&iRowNum,&iRankNum,&tBeginPos,&tEndPos);
	if(0==MazePath(aMaze,&tBeginPos,&tEndPos))
	{
		printf("����ڵ�����һ��ͨ·����:\r\n");
		PrintMaze(aMaze,iRowNum,iRankNum);
	}
	else
	{
		printf("���Թ�û��ͨ·\r\n");
	}
	
	return 0;
}

/*****************************************************************************
-Fuction		: MazePath
-Description	: ��ǰλ�ò���ǽֱ����ջֱ���յ㣬�����յ�
�����¸�λ�á���ǰλ����ǽ�����ջ��Ϊ�գ���ջ�ҵ�
ǽ��ǰһ��λ�ã�������λ���ĸ������߹��˲�ͨ����
ջ���գ�������ջ�ҵ�ǰһ��λ�û��з���û�߹��ģ�
�ҵ��󻻷��򣬻���һλ�ü����ж�
ͬʱ���ڸ�λ�ò���ǽ(ǰ���жϹ���)���Լ�����ջ
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int MazePath(int i_daiMaze[][MAX_MAZE_LENGTH],T_MazePosType *i_ptBeginPos,T_MazePosType *i_ptEndPos)
{
	T_MazePosType tCurrentPos={0};
	int iCurrentStep=1;//Ϊ1��һ��λ�ã���ֹ��0��ǽ����
	T_SeqStack tSeqStack;
	T_StackElement tStackElement={0};
	memcpy(&tCurrentPos,i_ptBeginPos,sizeof(T_MazePosType));
	InitStack(&tSeqStack);
	do
	{
		if(0==PassJudge(i_daiMaze,&tCurrentPos))//��ǰλ�ò���ǽ
		{
			FootMark(i_daiMaze,&tCurrentPos,iCurrentStep);
			tStackElement.iOrder=iCurrentStep;
			tStackElement.tPos=tCurrentPos;
			tStackElement.iDirection=0;
			Push(&tSeqStack,&tStackElement);				
			iCurrentStep++;
			if((tCurrentPos.x==i_ptEndPos->x)&&(tCurrentPos.y==i_ptEndPos->y))
			return 0;
			NextPos(&tCurrentPos,tStackElement.iDirection);
			//printf("Line:%d,Step:%d,x:%d,y:%d\r\n", __LINE__,iCurrentStep,tStackElement.tPos.x,tStackElement.tPos.y);
		}
		else// ��ǰλ�ò���ͨ��,��ǽ(��ǰλ��û��ջ,ǽû���߲���ջ)
		{
			if(0!=StackEmpty(&tSeqStack))
			{
				Pop(&tSeqStack,&tStackElement); 	// ��ջ�ҵ�ǰһλ��(ǽǰһ��λ��)
				iCurrentStep--;// �㼣��1
				while((tStackElement.iDirection==3)&&(0!=StackEmpty(&tSeqStack)))// ǰһλ�ô������һ������(��)
				{
					NoWayMark(i_daiMaze,&tStackElement.tPos);//�߲�ͨ��û�����ˣ�����ջ����ջ��
					Pop(&tSeqStack,&tStackElement); 	
					iCurrentStep--;// �㼣��1
				}
				if(tStackElement.iDirection<3)
				{
					tStackElement.iDirection++;
					iCurrentStep++;
					tCurrentPos=tStackElement.tPos;
					NextPos(&tCurrentPos,tStackElement.iDirection);
					Push(&tSeqStack,&tStackElement);//(����ǽ,���˷���)�����ߣ���ջ
				}
				else{
				}
			}
			else
			{
			}
		}
	}while(0!=StackEmpty(&tSeqStack));
	return -1;
}
/*****************************************************************************
-Fuction		: PrintMaze
-Description	: PrintMaze
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void PrintMaze(int i_daiMaze[][MAX_MAZE_LENGTH],int i_iX,int i_iY)
{
	int i,j;
	for(i=0;i<i_iX;i++)
	{
		for(j=0;j<i_iY;j++)
		{
			printf("%3d",i_daiMaze[i][j]);
		}
		printf("\n");
	}
}
/*****************************************************************************
-Fuction		: InitMaze
-Description	: InitMaze
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void InitMaze(int i_dwPassValue,int i_daiMaze[][MAX_MAZE_LENGTH],int *o_piX,int *o_piY,T_MazePosType *ptBeginPos,T_MazePosType *ptEndPos)
{
	int i,j,x,y;
	int iWallNum=0;
	int iWallX=0,iWallY=0;
	printf("�������Թ�������,����(������ǽ):");
	scanf("%d,%d",&x,&y);
	*o_piX=x;
	*o_piY=y;
	for(i=0;i<y;i++)//��ǽȫΪ0
	{
		i_daiMaze[0][i]=0;
		i_daiMaze[x-1][i]=0;
	}
	for(i=1;i<x-1;i++)
	{
		i_daiMaze[i][0]=0;
		i_daiMaze[i][y-1]=0;
	}
	for(i=1;i<x-1;i++)// �������ǽ�����඼��ͨ������ֵΪk
	{
		for(j=1;j<y-1;j++)
		{
			i_daiMaze[i][j]=i_dwPassValue;
		}
	}
	printf("�������Թ���ǽ��Ԫ��:");
	scanf("%d",&iWallNum);
	printf("�����������Թ���ǽÿ����Ԫ������,����:\r\n");
	for(i=0;i<iWallNum;i++)
	{
		scanf("%d,%d",&iWallX,&iWallY);
		i_daiMaze[iWallX][iWallY]=0;// �޸�ǽ��ֵΪ0
	}
	printf("�Թ��ṹ����:\r\n");
	PrintMaze(i_daiMaze,x,y);
	printf("��������ڵ�����,����:");
	scanf("%d,%d",&ptBeginPos->x,&ptBeginPos->y);
	printf("��������ڵ�����,����:");
	scanf("%d,%d",&ptEndPos->x,&ptEndPos->y);
}
/*****************************************************************************
-Fuction		: PassJudge
-Description	: PassJudge
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int PassJudge(int i_daiMaze[][MAX_MAZE_LENGTH],T_MazePosType *i_ptMazePos)
{
	int iRet=-1;
	if(i_daiMaze[i_ptMazePos->x][i_ptMazePos->y]!=1)
	{
		iRet=-1;
	}
	else
	{
		iRet=0;
	}
	return iRet;
}
/*****************************************************************************
-Fuction		: FootMark
-Description	: FootMark
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void FootMark(int i_daiMaze[][MAX_MAZE_LENGTH],T_MazePosType *i_ptMazePos,int i_iCurStep)
{
	i_daiMaze[i_ptMazePos->x][i_ptMazePos->y]=i_iCurStep;
}
/*****************************************************************************
-Fuction		: NextPos
-Description	: NextPos
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void NextPos(T_MazePosType *i_ptMazePos,int i_iDirection)
{
	static T_MazePosType s_atMazePos[4]={{0,1},{1,0},{0,-1},{-1,0}};// {������,������},�ƶ�����,����Ϊ��������
	i_ptMazePos->x+=s_atMazePos[i_iDirection].x;
	i_ptMazePos->y+=s_atMazePos[i_iDirection].y;
}
/*****************************************************************************
-Fuction		: NoWayMark
-Description	: NoWayMark
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static void NoWayMark(int i_daiMaze[][MAX_MAZE_LENGTH],T_MazePosType *i_ptMazePos)
{
	i_daiMaze[i_ptMazePos->x][i_ptMazePos->y]=-1;

}
/*****************************************************************************
-Fuction		: InitStack
-Description	: InitStack
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int InitStack(T_SeqStack *i_ptSeqStack)
{
	int iRet=-1;
	i_ptSeqStack->ptBase=(T_StackElement *)malloc(MAX_STACK_LENGTH*sizeof(T_StackElement));
	if(NULL==i_ptSeqStack->ptBase)
	{
		iRet=-1;
		printf("mallocFail,InitStack err");
		exit(-1);
	}
	else
	{
		i_ptSeqStack->ptTop=i_ptSeqStack->ptBase;
		i_ptSeqStack->iLen=MAX_MAZE_LENGTH;
		iRet=0;
	}
	return iRet;
}

/*****************************************************************************
-Fuction		: Push
-Description	: Push
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int Push(T_SeqStack *i_ptSeqStack,T_StackElement *i_ptStackElement)
{
	int iRet=-1;
	if((i_ptSeqStack->ptTop-i_ptSeqStack->ptBase)==i_ptSeqStack->iLen)
	{//׷���ڴ棬���ص�ַ�������µģ�����ԭ�������ݱ��ֲ���(�´��)
		i_ptSeqStack->ptBase=(T_StackElement *)realloc(i_ptSeqStack->ptBase,(i_ptSeqStack->iLen+INCREMENT_STACK_LENGTH)*
							sizeof(T_StackElement));
		if(NULL==i_ptSeqStack->ptBase)
		{
			iRet=-1;
			printf("StackFull,ReallocFail,Push err");
			exit(-1);
		}
		else
		{//�����ڴ��ַ���ܻ�䣬����ԭ�ȵ���
			i_ptSeqStack->ptTop=i_ptSeqStack->ptBase+i_ptSeqStack->iLen;
			i_ptSeqStack->iLen=i_ptSeqStack->iLen+INCREMENT_STACK_LENGTH;
		}
	}
	else
	{
	}
	memcpy(i_ptSeqStack->ptTop,i_ptStackElement,sizeof(T_StackElement));
	i_ptSeqStack->ptTop++;
	iRet=0;
	return iRet;
}

/*****************************************************************************
-Fuction		: Pop
-Description	: Pop
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int Pop(T_SeqStack *i_ptSeqStack,T_StackElement *o_ptStackElement)
{
	int iRet=-1;
	if(i_ptSeqStack->ptTop==i_ptSeqStack->ptBase)
	{
		iRet=-1;
		printf("StackEmpty,Pop err");
	}
	else
	{
		i_ptSeqStack->ptTop--;
		memcpy(o_ptStackElement,i_ptSeqStack->ptTop,sizeof(T_StackElement));
		iRet=0;
	}
	return iRet;
}


/*****************************************************************************
-Fuction		: Pop
-Description	: Pop
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/04/21	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
static int StackEmpty(T_SeqStack *i_ptSeqStack)
{
	int iRet=-1;
	if(i_ptSeqStack->ptTop==i_ptSeqStack->ptBase)
	{
		iRet=0;
		printf("StackEmpty\r\n");
	}
	else
	{
		iRet=-1;
	}
	return iRet;
}

