/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BubbleSort.java
* Description		: 	BubbleSort operation center

һ������˼��
һ��������������˼���������Ƚϡ�
���Ƚ���һ���͵ڶ����Ƚϣ���Ϊ�����򽻻�֮��
Ȼ��Ƚϵڶ��͵���������������,ֱ�����н�����
��һ����������ʹ�����ı��ŵ����һ��λ���ϡ�
�����������������к��棬�����������������ӣ��䳤��
�������ӣ�ͬʱ�������д�ĩβ���ϼ���

* Created			: 	2017.06.16.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/




import java.util.Arrays; 


/*****************************************************************************
-Class			: BubbleSort
-Description	: main
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/19	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
public class BubbleSort
{
	public static final int ARRAY_LEN=9;
	BubbleSortClass pBuddleSort;
	/*****************************************************************************
	-Fuction		: main
	-Description	: main
	-Input			: 
	-Output 		: 
	-Return 		: 
	* Modify Date	  Version		 Author 		  Modification
	* -----------------------------------------------
	* 2017/06/19	  V1.0.0		 Yu Weifeng 	  Created
	******************************************************************************/
	public static void main(String args[]){
		int aiSortBuf[] = {3,4,1,2,6,7,8,9,5};//constant Init must be in define
		BubbleSortClass mBuddleSort = new BubbleSortClass(aiSortBuf,ARRAY_LEN);
		System.out.println("oneCmpOneSort");
		mBuddleSort.oneCmpOneSort();
		mBuddleSort.printInfo();
		System.out.println("oneCmpAllSort");
		mBuddleSort.oneCmpAllSort();
		mBuddleSort.printInfo();
		System.out.println("apiSort");
		mBuddleSort.apiSort();
		mBuddleSort.printInfo();
	}
}

/*****************************************************************************
-Class			: BubbleSortClass
-Description	: oneCmpOneSort
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/19	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
 class BubbleSortClass
 {
 	private int[] piSortBuf;
	private int iLen;
	/*****************************************************************************
	-Fuction		: BubbleSortClass
	-Description	: BubbleSortClass
	-Input			: 
	-Output 		: 
	* Modify Date	  Version		 Author 		  Modification
	* -----------------------------------------------
	* 2017/06/19	  V1.0.0		 Yu Weifeng 	  Created
	******************************************************************************/
	public BubbleSortClass(int[] i_piBuf,int i_iLen)
	{
		int i;
		//aiSortBuf=Arrays.copyOf(i_piBuf,i_iLen);// Or use this to copy
		piSortBuf=new int[i_iLen];
		for(i=0;i<i_iLen;i++){
			piSortBuf[i]=i_piBuf[i];
		}
		iLen=i_iLen;
	}
	/*****************************************************************************
	-Fuction		: oneCmpOneSort
	-Description	: oneCmpOneSort
	-Input			: 
	-Output 		: 
	-Return 		: 
	* Modify Date	  Version		 Author 		  Modification
	* -----------------------------------------------
	* 2017/06/19	  V1.0.0		 Yu Weifeng 	  Created
	******************************************************************************/
	public void oneCmpOneSort()
	{
		int i,j;
		int iBufSwap;
		for(i=0;i<iLen-1;i++){//all trips
			for(j=0;j<iLen-i-1;j++){//cmp times a trip
				if(piSortBuf[j]>piSortBuf[j+1]){
					iBufSwap=piSortBuf[j+1];
					piSortBuf[j+1]=piSortBuf[j];
					piSortBuf[j]=iBufSwap;
				}
				else{
				}
			}
		}
	}
	/*****************************************************************************
	-Fuction		: oneCmpAllSort
	-Description	: oneCmpAllSort
	-Input			: 
	-Output 		: 
	* Modify Date	  Version		 Author 		  Modification
	* -----------------------------------------------
	* 2017/06/19	  V1.0.0		 Yu Weifeng 	  Created
	******************************************************************************/
	public void oneCmpAllSort()
	{
		int i,j;
		int iBufSwap;
		for(i=0;i<iLen-1;i++){//all trips
			for(j=0;j<iLen-i-1;j++){//cmp times a trip
				if(piSortBuf[i]>piSortBuf[j+i+1]){
					iBufSwap=piSortBuf[j+i+1];
					piSortBuf[j+i+1]=piSortBuf[i];
					piSortBuf[i]=iBufSwap;
				}
				else{
				}
			}
		}
	}
	/*****************************************************************************
	-Fuction		: oneCmpAllSort
	-Description	: oneCmpAllSort
	-Input			: 
	-Output 		: 
	* Modify Date	  Version		 Author 		  Modification
	* -----------------------------------------------
	* 2017/06/19	  V1.0.0		 Yu Weifeng 	  Created
	******************************************************************************/
	public void apiSort()
	{
		Arrays.sort(piSortBuf);
	}
	/*****************************************************************************
	-Fuction		: oneCmpAllSort
	-Description	: oneCmpAllSort
	-Input			: 
	-Output 		: 
	* Modify Date	  Version		 Author 		  Modification
	* -----------------------------------------------
	* 2017/06/19	  V1.0.0		 Yu Weifeng 	  Created
	******************************************************************************/
	public void printInfo()
	{
		int i;
		for(i=0;i<iLen;i++){
			System.out.println(piSortBuf[i]);
		}
		//System.out.println(Arrays.toString(aiSortBuf));//Or use this to print
	}
}
	
