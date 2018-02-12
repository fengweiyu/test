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
    while(1)//创建连接成功后,不断接受数据
    {
        //read and printf sent client info  
        memset(acRecvBuf,0,1024);  
        int num=read(iClientFd,acRecvBuf,sizeof(acRecvBuf));  
        printf("Message from client (%d)) :%s\n",num,acRecvBuf);  
        sleep(1);
    }
  
    close(iClientFd);  
    close(iListenFd);  
    unlink(UNIX_DOMAIN);  

    return 0;  	
}
