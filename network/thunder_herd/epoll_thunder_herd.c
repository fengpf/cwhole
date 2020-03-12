#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/epoll.h>
#include<netdb.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<errno.h>
#define PROCESS_NUM 10
#define MAXEVENTS 64
//socket创建和绑定
int sock_creat_bind(char * port){
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(port));
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
 
    bind(sock_fd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    return sock_fd;
}
//利用fcntl设置文件或者函数调用的状态标志
int make_nonblocking(int fd){
    int val = fcntl(fd, F_GETFL);
    val |= O_NONBLOCK;
    if(fcntl(fd, F_SETFL, val) < 0){
        perror("fcntl set");
        return -1;
    }
    return 0;
}
 
int main(int argc, char *argv[])
{
    int sock_fd, epoll_fd;
    struct epoll_event event;
    struct epoll_event *events;
        
    if(argc < 2){
        printf("usage: [port] %s", argv[1]);
        exit(1);
    }
     if((sock_fd = sock_creat_bind(argv[1])) < 0){
        perror("socket and bind");
        exit(1);
    }
    if(make_nonblocking(sock_fd) < 0){
        perror("make non blocking");
        exit(1);
    }
    if(listen(sock_fd, SOMAXCONN) < 0){
        perror("listen");
        exit(1);
    }
    if((epoll_fd = epoll_create(MAXEVENTS))< 0){
        perror("epoll_create");
        exit(1);
    }
    event.data.fd = sock_fd;
    event.events = EPOLLIN;
    if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sock_fd, &event) < 0){
        perror("epoll_ctl");
        exit(1);
    }
    /*buffer where events are returned*/
    events = calloc(MAXEVENTS, sizeof(event));
    int i;
    for(i = 0; i < PROCESS_NUM; ++i){
        int pid = fork();
        if(pid == 0){
            while(1){
                int num, j;
                num = epoll_wait(epoll_fd, events, MAXEVENTS, -1);
                printf("process %d returnt from epoll_wait\n", getpid());
                
                // 看我们的代码，看似部分进程被唤醒了，而事实上其余进程没有被唤醒的原因是因为某个进程已经处理完这个事件，
                // 无需唤醒其他进程，你可以在epoll获知这个事件的时候sleep（2）；
                // 这样所有的进程都会被唤起。看下面改正后的代码结果更加清晰：

                sleep(2);
                for(i = 0; i < num; ++i){
                    if((events[i].events & EPOLLERR) || (events[i].events & EPOLLHUP) || (!(events[i].events & EPOLLIN))){
                        fprintf(stderr, "epoll error\n");
                        close(events[i].data.fd);
                        continue;
                    }else if(sock_fd == events[i].data.fd){
                        //收到关于监听套接字的通知，意味着一盒或者多个传入连接
                        struct sockaddr in_addr;
                        socklen_t in_len = sizeof(in_addr);
                        if(accept(sock_fd, &in_addr, &in_len) < 0){
                            printf("process %d accept failed!\n", getpid());
                        }else{
                            printf("process %d accept successful!\n", getpid());
                        }
                    }
                }
            }
        }
    }
    wait(0);
    free(events);
    close(sock_fd);
    return 0;
}
 

// process 11055 returnt from epoll_wait
// process 11054 returnt from epoll_wait
// process 11047 returnt from epoll_wait
// process 11047 accept failed!
// process 11054 accept successful!
// process 11055 accept failed!
// process 11053 returnt from epoll_wait
// process 11053 accept failed!

  //after  sleep(2);

// process 11083 returnt from epoll_wait
// process 11084 returnt from epoll_wait
// process 11085 returnt from epoll_wait
// process 11086 returnt from epoll_wait
// process 11087 returnt from epoll_wait
// process 11088 returnt from epoll_wait
// process 11092 returnt from epoll_wait
// process 11091 returnt from epoll_wait
// process 11090 returnt from epoll_wait
// process 11089 returnt from epoll_wait
// process 11087 accept successful!
// process 11092 accept failed!
// process 11086 accept failed!
// process 11090 accept failed!
// process 11089 accept failed!
// process 11091 accept failed!
// process 11085 accept failed!
// process 11084 accept failed!
// process 11083 accept failed!
// process 11088 accept failed!