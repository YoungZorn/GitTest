//
// Created by YoungZorn on 2024/6/4.
//
#include <iostream>
#include <sys/types.h>	//基本系统数据类型
#include <winsock2.h>	//网络信息转换
#include <unistd.h>		//POSIX系统API访问
#include <string.h>


int main(){

    //创建一个监听socket
    int listenfd = socket(AF_INET,SOCK_STREAM,0);
    if (listenfd == -1)
    {
        std::cout << " create listen socket error " << std::endl;
        return -1;
    }

    //初始化服务器地址
    struct sockaddr_in bindaddr;
    bindaddr.sin_family = AF_INET;
    bindaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bindaddr.sin_port = htons(8081);

    //绑定服务器地址信息
    if (bind(listenfd,(struct sockaddr*)&bindaddr, sizeof(bindaddr)) == -1)
    {
        std::cout << "bind listen socket error" << std::endl;
        return -1;
    }

    //开始监听
    if (listen(listenfd,SOMAXCONN) == -1)
    {
        std::cout << "listen error" << std::endl;
        return -1;
    }

    std::cout << "--------------开始监听--------------" << std::endl;

    while (true)
    {
        struct sockaddr_in client_addr;
        int client_addr_len = sizeof(client_addr);

        //接收客户端连接
        int clientfd = accept(listenfd,(struct sockaddr*)&client_addr,&client_addr_len);
        if (clientfd != -1)
        {
            char recvBuf[32] = {0};
            //从客户端接收数据
            int ret = recv(clientfd,recvBuf, sizeof(recvBuf),0);
            if (ret > 0)
            {
                std::cout << "receive data from client , data:" << recvBuf << std::endl;
                //将接收到的数据返回给客户端
                ret = send(clientfd,recvBuf, sizeof(recvBuf),0);
                if (ret != strlen(recvBuf))
                {
                    std::cout << "send data error" << std::endl;
                }else {
                    std::cout << "send data to client successfully, data " << recvBuf <<std::endl;
                }
            }else {
                std::cout << "recv data error" <<std::endl;
            }
            close(clientfd);
        }
    }

    //关闭监听
    close(listenfd);
    return 0;
}