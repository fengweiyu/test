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
    iConnectFd=socket(PF_UNIX,SOCK_STREAM,0);  
    if(iConnectFd<0)  
    {  
        perror("cannot create communication socket");  
        return -1;  
    }     

    tServerAddr.sun_family=AF_UNIX;  
    strncpy(tServerAddr.sun_path,UNIX_DOMAIN,sizeof(tServerAddr.sun_path)-1);  
    //connect server  
    iRet=connect(iConnectFd,(struct sockaddr*)&tServerAddr,sizeof(tServerAddr));  
    if(iRet==-1)  
    {  
        perror("cannot connect to the server");  
        close(iConnectFd);  
        return -1;  
    }  

    while(1)
    {
	memset(acSendBuf,0,1024);  
	strcpy(acSendBuf,"message from client");  
	//send info server	
        write(iConnectFd,acSendBuf,strlen(acSendBuf));  
        sleep(2);//这个时间要大于服务器读数据的间隔，防止服务端读的时候,这里还在写,
                    //从而导致服务端读不到数据、一直阻塞在读操作中。
        //最好读写操作中都使用select，这样就好保证读写成功
    }

    close(iConnectFd);  
    return 0;  

}

