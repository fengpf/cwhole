//
// Created by fpf on 2020-03-10.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

int make_socket(uint16_t port) {
    int sock;
    struct sockaddr_in name;

    //创建字节流类型的ipv4 socket
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock<0){
        perror("socket");
        exit(EXIT_FAILURE);
    }

    //绑定port和ip
    name.sin_family = AF_INET;//ipv4
    name.sin_port=htons(port);//指定端口
    name.sin_addr.s_addr=htonl(INADDR_ANY);//通配地址
    //把ipv4地址转成通用地址格式，同时传递长度
    if (bind (sock, (struct sockaddr *)&name, sizeof(name))<0){
        perror("bind");
        exit(EXIT_FAILURE);
    }
    return sock;
}

void main(){
    int sock;
    sock=make_socket(9000);
    printf("%d\n",sock);
}


