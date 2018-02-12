/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SocketIPCClient.cpp
* Description		: 	SocketIPCClient operation center
* Created			: 	2017.09.11.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#include <stdio.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <sys/un.h> 
#include "SocketIPC.h"
/*****************************************************************************
-Class			: BubbleSort
-Description	: main
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/06/19	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/




/*****************************************************************************
-Fuction		: main
-Description	: main
-Input			: 
-Output 		: 
-Return 		: 
* Modify Date	  Version		 Author 		  Modification
* -----------------------------------------------
* 2017/09/11	  V1.0.0		 Yu Weifeng 	  Created
******************************************************************************/
int main(int argc,char **argv)
{
    int iConnectFd;  
    int iRet;  
    char acSendBuf[1024];  
    int i;  
    static struct sockaddr_un tServerAddr; 
 
    //creat unix socket  
    iConnectFd=socket(PF_UNIX,SOCK_DGRAM,0);  
    if(iConnectFd<0)  
    {  
        perror("cannot create communication socket");  
        return -1;  
    }     

    tServerAddr.sun_family=AF_UNIX;  
    strncpy(tServerAddr.sun_path,UNIX_DOMAIN,sizeof(tServerAddr.sun_path)-1);  

    while(1)
    {
	memset(acSendBuf,0,1024);  
	strcpy(acSendBuf,"message from client");  
	//send info server	
        sendto(iConnectFd,acSendBuf,strlen(acSendBuf),0,(struct sockaddr*)&tServerAddr,sizeof(tServerAddr));  
        sleep(2);//���ʱ��Ҫ���ڷ����������ݵļ������ֹ����˶���ʱ��,���ﻹ��д,
                    //�Ӷ����·���˶��������ݡ�һֱ�����ڶ������С�
        //��ö�д�����ж�ʹ��select�������ͺñ�֤��д�ɹ�
    }
/*һ���ǿ�д�ģ�����˵����ͬʱselect�Ļ�,�Ͳ����������,Ҳ�ͻ���ɷǳ�Ƶ���Ķ�д����˵���ݴ����Ƶ��
    FD_ZERO(&tWriteFds); //�������������   
    FD_SET(iConnectFd, &tWriteFds); //��������������
    while(1)
    {
        iRet = select(iConnectFd + 1, NULL, &tWriteFds, NULL, NULL);//����select������غ���//NULL һֱ�ȵ��б仯
        if(iRet<0)  
        {
                perror("select server err\n");  
                close(iConnectFd);  
                unlink(UNIX_DOMAIN);  
                return -1;  
        }
        else
        {
        }
        if (FD_ISSET(iConnectFd, &tWriteFds))   //����fd1�Ƿ��д 
        {
            memset(acSendBuf,0,1024);  
            strcpy(acSendBuf,"message from client");  
            //send info server  
            write(iConnectFd,acSendBuf,strlen(acSendBuf));  
        }
        else
        {
            //printf("FD_ISSET err\n");
        }
    }*/

    close(iConnectFd);  
    return 0;  

}

