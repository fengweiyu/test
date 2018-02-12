/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	BubbleSort.java
* Description		: 	BubbleSort operation center

一、基本思想
一般的起泡排序核心思想是两两比较。
首先将第一个和第二个比较，若为逆序，则交换之。
然后比较第二和第三个。依次类推,直到序列结束。
第一趟排序，其结果使得最大的被放到最后一个位置上。
有序序列在整个序列后面，随着排序趟数的增加，其长度
不断增加，同时无序序列从末尾不断减少

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
	
