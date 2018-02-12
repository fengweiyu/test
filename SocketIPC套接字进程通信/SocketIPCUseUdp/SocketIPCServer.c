/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	SocketIPCServer.cpp
* Description		: 	SocketIPCServer operation center
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
    int iListenFd;  
    int iRet;  
    int i;  
    static char acRecvBuf[1024];   
    int iLen;  
    struct sockaddr_un tClientAddr;  
    struct sockaddr_un tServerAddr;  
    struct timeval  tTimeValue;
    fd_set tReadFds;

    iListenFd=socket(PF_UNIX,SOCK_DGRAM,0);  
    if(iListenFd<0)  
    {  
        perror("cannot create communication socket");  
        return -1;  
    }    
      
    //set server addr_param  
    tServerAddr.sun_family=AF_UNIX;  
    strncpy(tServerAddr.sun_path,UNIX_DOMAIN,sizeof(tServerAddr.sun_path)-1);  
    unlink(UNIX_DOMAIN);  
    //bind sockfd & addr  
    iRet=bind(iListenFd,(struct sockaddr*)&tServerAddr,sizeof(tServerAddr));  
    if(iRet==-1)  
    {  
        perror("cannot bind server socket");  
        close(iListenFd);  
        unlink(UNIX_DOMAIN);  
        return -1;  
    }  

    FD_ZERO(&tReadFds); //�������������   
    FD_SET(iListenFd, &tReadFds); //��������������
    //tTimeValue.tv_sec  =1;//��ʱʱ�䣬��ʱ���ش���
   // tTimeValue.tv_usec = 0;
    while(1)
    {
        iRet = select(iListenFd + 1, &tReadFds, NULL, NULL, NULL);//����select������غ���//NULL һֱ�ȵ��б仯
        if(iRet<0)  
        {
                perror("select client err\n");  
                close(iListenFd);  
                unlink(UNIX_DOMAIN);  
                return -1;  
        }
        else
        {
        }
        if (FD_ISSET(iListenFd, &tReadFds))   //����fd1�Ƿ�ɶ�  
        {
            //read and printf sent client info  
            memset(acRecvBuf,0,1024);  
            ssize_t num=recvfrom(iListenFd,acRecvBuf,sizeof(acRecvBuf),0,(struct sockaddr*)&tClientAddr,&iLen);  
            printf("Message from client (%d)) :%s\n",num,acRecvBuf);  
        }
        else
        {
            //printf("FD_ISSET err\n");
        }
    }

    close(iListenFd);  
    unlink(UNIX_DOMAIN);  

    return 0;  	
}
