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
    int iClientFd;  
    int iRet;  
    int i;  
    static char acRecvBuf[1024];   
    int iLen;  
    struct sockaddr_un tClientAddr;  
    struct sockaddr_un tServerAddr;  
    struct timeval  tTimeValue;
    fd_set tReadFds;

    iListenFd=socket(PF_UNIX,SOCK_STREAM,0);  
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

    //listen sockfd   
    iRet=listen(iListenFd,1); //等待连接个数,也就是允许连接的客户端个数 
    if(iRet==-1)  
    {  
        perror("cannot listen the client connect request");  
        close(iListenFd);  
        unlink(UNIX_DOMAIN);  
        return -1;  
    }  
    //have connect request use accept  
    iLen=sizeof(tClientAddr);  
    iClientFd=accept(iListenFd,(struct sockaddr*)&tClientAddr,&iLen);  //这里会等待客户端连接
    if(iClientFd<0)  
    {  
        perror("cannot accept client connect request");  
        close(iListenFd);  
        unlink(UNIX_DOMAIN);  
        return -1;	
    }  

    FD_ZERO(&tReadFds); //清空描述符集合   
    FD_SET(iClientFd, &tReadFds); //设置描述符集合
    //tTimeValue.tv_sec  =1;//超时时间，超时返回错误
   // tTimeValue.tv_usec = 0;
    while(1)
    {
        iRet = select(iClientFd + 1, &tReadFds, NULL, NULL, NULL);//调用select（）监控函数//NULL 一直等到有变化
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
        if (FD_ISSET(iClientFd, &tReadFds))   //测试fd1是否可读  
        {
            //read and printf sent client info  
            memset(acRecvBuf,0,1024);  
            int num=read(iClientFd,acRecvBuf,sizeof(acRecvBuf));  
            printf("Message from client (%d)) :%s\n",num,acRecvBuf);  
        }
        else
        {
            //printf("FD_ISSET err\n");
        }
    }

    close(iClientFd);  
    close(iListenFd);  
    unlink(UNIX_DOMAIN);  

    return 0;  	
}
