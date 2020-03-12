#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<errno.h>

#define PROCESS_NUM 10
int main()
{
    int fd = socket(PF_INET, SOCK_STREAM, 0);
    int connfd;
    int pid;
 
    char sendbuff[1024];
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(1234);
    bind(fd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    listen(fd, 1024);
    int i;
    for(i = 0; i < PROCESS_NUM; ++i){
        pid = fork();
        if(pid == 0){
            while(1){
                connfd = accept(fd, (struct sockaddr *)NULL, NULL);
                        
                //test 1  nc 127.0.0.1 1234 只有一个进程accept成功
                // snprintf(sendbuff, sizeof(sendbuff), "接收到accept事件的进程PID = %d\n", getpid());
                // send(connfd, sendbuff, strlen(sendbuff)+1, 0);
                // printf("process %d accept success\n", getpid());
                // close(connfd);

                //test 2
                if(connfd == 0){
                    snprintf(sendbuff, sizeof(sendbuff), "接收到accept事件的进程PID = %d\n", getpid());
                    send(connfd, sendbuff, strlen(sendbuff)+1, 0);
                    printf("process %d accept success\n", getpid());
                    close(connfd);
                }else{
                    printf("process %d accept a connection failed: %s\n", getpid(), strerror(errno));
                    close(connfd);
                }

            }
        }
    }
    //int status;
    wait(0);
    return 0;
}
