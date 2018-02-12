/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	Jt808Parse.java
* Description		: 	Jt808Parse operation center
* Created			: 	2017.06.16.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/



 

import java.io.InputStream;
import java.io.OutputStream;
import java.io.File;  
import java.io.FileInputStream;  
import java.io.FileNotFoundException;  
import java.io.FileOutputStream;  
import java.io.IOException;  
import java.io.InputStreamReader; 
import java.io.Reader; 
import java.io.InputStreamReader;  
import java.io.RandomAccessFile; 
import java.io.FileReader;
import java.io.BufferedReader; 
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.Set;


/*****************************************************************************
-Class			: BubbleSort
-Description	: main
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/19	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
public class Jt808Parse
{

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
	public static void main(String args[])
	{
		String strDataBuf=null;
		BufferedReader mBufRead=null;
		try
		{
			mBufRead = new BufferedReader(new InputStreamReader(new FileInputStream(args[0])));
			if(null==mBufRead)
			{
				System.out.println("Jt808Parse err!");
			}
			else
			{
				strDataBuf=mBufRead.readLine();
				if(null==strDataBuf)
				{
					System.out.println("Jt808Parse readLine err!");
				}
				else
				{
				//printf("fgets data len:%d\r\n",strlen(strDataBuf));
					byte [] DataBuf = strDataBuf.getBytes();
					int iLength = 0;
					byte FileDateBuffer[]=new byte[strDataBuf.getBytes().length];
					for(int i=0;i<strDataBuf.getBytes().length;i++)
					{
						if(DataBuf[i] == ' ')
						{
							
						}
						else 
						{
							FileDateBuffer[iLength] = DataBuf[i];
							iLength++;
						}
						
					}
					Jt808Parse2Print mParse=new Jt808Parse2Print();
					mParse.JT808Parse(FileDateBuffer,iLength);
				}	
			}
		}
		catch (IOException e) 
		{  
            e.printStackTrace();  
        } 
        finally 
        {  
            if (mBufRead != null) 
            {  
                try 
                {  
                    mBufRead.close();  
                } 
                catch (IOException e1) 
               	{
                	e1.printStackTrace();  
                }  
            }  
        }  
	}

}
/*****************************************************************************
-Class			: Jt808Parse2Print
-Description	: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/19	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
class Jt808Parse2Print
 {
	public static final int MAX_DATA_BUF_LEN=4*1024;
	public static final int JT808_BASE_LEN=15;
 	/*****************************************************************************
	-Fuction		: JT808Parse
	-Description	: JT808Parse
	-Input			: 
	-Output 		: 
	-Return 		: 
	* Modify Date	  Version		 Author 		  Modification
	* -----------------------------------------------
	* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
	******************************************************************************/
	public int JT808Parse(byte []i_cDataBuf,int i_iDataLen)
	{
		int iRet=-1;
		int iTempLen=0;
		byte bTemp[]=new byte[MAX_DATA_BUF_LEN];
		String strTemp=null;
		char wMsgId=0; 
		char wMsgLen=0; 
		if(i_iDataLen<JT808_BASE_LEN*2)
		{
			System.out.println("JT808Parse err:"+i_iDataLen);
		}
		else
		{
			System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,2);
			Jt808Print("标识位",bTemp,2);	
			iTempLen+=2;
			System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,4);
			Jt808Print("消息ID",bTemp,4);	
			iTempLen+=4;
			strTemp=new String(bTemp,0,4);
			wMsgId=(char)Integer.parseInt(strTemp,16);
			System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,4);
			Jt808Print("消息体属性(长度)",bTemp,4);	
			iTempLen+=4;
			strTemp=new String(bTemp,0,4);
			wMsgLen=(char)Integer.parseInt(strTemp,16);
			System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,12);
			Jt808Print("终端手机号",bTemp,12);	
			iTempLen+=12;
			System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,4);
			Jt808Print("消息流水号",bTemp,4);	
			iTempLen+=4;
			if(0x0200==wMsgId)
			{
				System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,8);
				Jt808Print("报警标志",bTemp,8);	
				iTempLen+=8;
				System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,8);
				Jt808Print("状态",bTemp,8);	
				iTempLen+=8;
				System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,8);
				Jt808Print("纬度",bTemp,8);	
				iTempLen+=8;
				System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,8);
				Jt808Print("经度",bTemp,8);	
				iTempLen+=8;
				System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,4);
				Jt808Print("高程",bTemp,4);	
				iTempLen+=4;
				System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,4);
				Jt808Print("速度",bTemp,4);	
				iTempLen+=4;
				System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,4);
				Jt808Print("方向",bTemp,4);	
				iTempLen+=4;
				System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,12);
				Jt808Print("时间",bTemp,12);	
				iTempLen+=12;
				System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,(wMsgLen-28)*2);
				Jt808Print("附加信息",bTemp,(wMsgLen-28)*2);	
				iTempLen+=(wMsgLen-28)*2;
			}
			else
			{
				System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,wMsgLen*2);
				Jt808Print("消息内容",bTemp,wMsgLen*2);	
				iTempLen+=wMsgLen*2;
			}
			System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,2);
			Jt808Print("校验",bTemp,2);	
			iTempLen+=2;
			System.arraycopy(i_cDataBuf,iTempLen,bTemp,0,2);
			Jt808Print("标识位",bTemp,2);	
		}
		return iRet;
	}
	/*****************************************************************************
	-Fuction		: Jt808Print
	-Description	: Jt808Print
	-Input			: 
	-Output 		: 
	-Return 		: 
	* Modify Date	  Version		 Author 		  Modification
	* -----------------------------------------------
	* 2017/03/29	  V1.0.0		 Yu Weifeng 	  Created
	******************************************************************************/
	private void Jt808Print(String i_strCmd,byte []i_cDataBuf,int i_iDataLen)
	{
		int i=0;
		String strPrint=new String(i_cDataBuf,0,i_iDataLen);
		
		System.out.println(i_strCmd+":"+strPrint);
	}
}
	

 
	
