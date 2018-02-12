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

    FD_ZERO(&tReadFds); //清空描述符集合   
    FD_SET(iListenFd, &tReadFds); //设置描述符集合
    //tTimeValue.tv_sec  =1;//超时时间，超时返回错误
   // tTimeValue.tv_usec = 0;
    while(1)
    {
        iRet = select(iListenFd + 1, &tReadFds, NULL, NULL, NULL);//调用select（）监控函数//NULL 一直等到有变化
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
        if (FD_ISSET(iListenFd, &tReadFds))   //测试fd1是否可读  
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
