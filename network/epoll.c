/*
 * =====================================================================================
 *
 *       Filename:  EpollServer.c
 *
 *    Description:  this is a epoll server example
 *
 *        Version:  1.0
 *        Created:  2012年03月15日 20时24分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LGP (), lgp8819@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>

/*struct addrinfo 
{
	int              ai_flags;
	int              ai_family;
	int              ai_socktype;
	int              ai_protocol;
	size_t           ai_addrlen;
	struct sockaddr *ai_addr;
	char            *ai_canonname;
	struct addrinfo *ai_next;
}; */

static int create_and_bind(char* port)
{
	struct addrinfo hints;
	struct addrinfo*result,*rp;
	int s,sfd;

	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_family= AF_UNSPEC;/* Return IPv4 and IPv6 */
	hints.ai_socktype= SOCK_STREAM;/* TCP socket */
	hints.ai_flags= AI_PASSIVE;/* All interfaces */

	s = getaddrinfo(NULL, port,&hints,&result); //more info about getaddrinfo() please see:man getaddrinfo!
	if(s != 0)
	{
		fprintf(stderr,"getaddrinfo: %s\n",gai_strerror(s));
		return -1;
	}
	for(rp= result;rp!= NULL;rp=rp->ai_next)
	{
		sfd = socket(rp->ai_family,rp->ai_socktype,rp->ai_protocol);
		if(sfd==-1)
			continue;
		s =bind(sfd,rp->ai_addr,rp->ai_addrlen);
		if(s ==0)
		{
			/* We managed to bind successfully! */
			break;
		}
		close(sfd);
	}

	if(rp== NULL)
	{
		fprintf(stderr,"Could not bind\n");
		return-1;
	}
	freeaddrinfo(result);
	return sfd;
}

static int make_socket_non_blocking(int sfd)
{
	int flags, s;
	flags = fcntl(sfd, F_GETFL,0);
	if(flags == -1)
	{
		perror("fcntl");
		return-1;
	}

	flags|= O_NONBLOCK;
	s =fcntl(sfd, F_SETFL, flags);
	if(s ==-1)
	{
		perror("fcntl");
		return-1;
	}
	return 0;
}


#define MAXEVENTS 64
int main(int argc, char*argv[])
{
	int sfd, s;
	int efd;
	struct epoll_event event;
	struct epoll_event* events;

	if(argc!=2)
	{
		fprintf(stderr,"Usage: %s [port]\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	sfd = create_and_bind(argv[1]);
	if( sfd == -1 )
		abort();

	s = make_socket_non_blocking(sfd);
	if(s ==-1)
		abort();

	s = listen(sfd, SOMAXCONN);
	if(s ==-1)
	{
		perror("listen");
		abort();
	}

	efd = epoll_create1(0);
	if(efd==-1)
	{
		perror("epoll_create");
		abort();
	}

	event.data.fd=sfd;
	event.events= EPOLLIN | EPOLLET;
	s =epoll_ctl(efd, EPOLL_CTL_ADD, sfd, &event);
	if(s ==-1)
	{
		perror("epoll_ctl");
		abort();
	}

	/* Buffer where events are returned */
	events=calloc(MAXEVENTS,sizeof event);

	/* The event loop */
	while(1)
	{
		int n,i;
		n =epoll_wait(efd, events, MAXEVENTS,-1);
		for(i=0;i< n;i++)
		{
			if((events[i].events & EPOLLERR)||
					(events[i].events & EPOLLHUP)||
					(!(events[i].events & EPOLLIN)))
			{
				/* An error has occured on this fd, or the socket is not
				   ready for reading (why were we notified then?) */
				fprintf(stderr,"epoll error\n");
				close(events[i].data.fd);
				continue;
			}

			else if(sfd == events[i].data.fd)
			{
				/* We have a notification on the listening socket, which
				   means one or more incoming connections. */
				while(1)
				{
					struct sockaddr in_addr;
					socklen_t in_len;
					int infd;
					char hbuf[NI_MAXHOST],sbuf[NI_MAXSERV];

					in_len = sizeof in_addr;
					infd = accept(sfd, &in_addr, &in_len);
					if(infd==-1)
					{
						if((errno== EAGAIN)||
								(errno== EWOULDBLOCK))
						{
							/* We have processed all incoming
							   connections. */
							break;
						}
						else
						{
							perror("accept");
							break;
						}
					}

					s =getnameinfo(&in_addr,in_len,
							hbuf,sizeof hbuf,
							sbuf,sizeof sbuf,
							NI_NUMERICHOST | NI_NUMERICSERV);
					if(s ==0)
					{
						printf("Accepted connection on descriptor %d "
								"(host=%s, port=%s)\n",infd,hbuf,sbuf);
					}

					/* Make the incoming socket non-blocking and add it to the
					   list of fds to monitor. */
					s = make_socket_non_blocking(infd);
					if(s ==-1)
						abort();

					event.data.fd=infd;
					event.events= EPOLLIN | EPOLLET;
					s = epoll_ctl(efd, EPOLL_CTL_ADD, infd, &event);
					if(s ==-1)
					{
						perror("epoll_ctl");
						abort();
					}
				}
				continue;
			}
			else
			{
				/* We have data on the fd waiting to be read. Read and
				   display it. We must read whatever data is available
				   completely, as we are running in edge-triggered mode
				   and won't get a notification again for the same
				   data. */
				int done =0;
				while(1)
                {
					ssize_t count;
					char buf[512];
					count = read(events[i].data.fd, buf, sizeof buf);
					if(count == -1)
					{
						/* If errno == EAGAIN, that means we have read all
						   data. So go back to the main loop. */
						if(errno!= EAGAIN)
						{
							perror("read");
							done=1;
						}
						break;
					}
					else if(count ==0)
					{
						/* End of file. The remote has closed the
						   connection. */
						done=1;
						break;
					}
					/* Write the buffer to standard output */
					s = write(1, buf, count);
					if(s ==-1)
					{
						perror("write");
						abort();
					}
				}
				if(done)
				{
					printf("Closed connection on descriptor %d\n",events[i].data.fd);
					/* Closing the descriptor will make epoll remove it
					   from the set of descriptors which are monitored. */
					close(events[i].data.fd);
				}
			}
		}
	}
	free(events);
	close(sfd);
	return EXIT_SUCCESS;
}
=======
#include <sys/epoll.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
 
	int ret;
	int fd;
	
	ret = mkfifo("test_fifo", 0666); // 创建有名管道
	if(ret != 0){
		perror("mkfifo：");
	}
	
	fd = open("test_fifo", O_RDWR); // 读写方式打开管道
	if(fd < 0){
		perror("open fifo");
		return -1;
	}
	
	ret = 0;
	struct epoll_event event;	// 告诉内核要监听什么事件
	struct epoll_event wait_event;
	
	
	int epfd = epoll_create(10); // 创建一个 epoll 的句柄，参数要大于 0， 没有太大意义
	if( -1 == epfd ){
		perror ("epoll_create");
		return -1;
    }
	
	event.data.fd = 0; 	   // 标准输入
	event.events = EPOLLIN; // 表示对应的文件描述符可以读
	
	// 事件注册函数，将标准输入描述符 0 加入监听事件
	ret = epoll_ctl(epfd, EPOLL_CTL_ADD, 0, &event);
	if(-1 == ret){
		perror("epoll_ctl");
		return -1;
    }
	
	event.data.fd = fd; 	// 有名管道
	event.events = EPOLLIN; // 表示对应的文件描述符可以读
	
	// 事件注册函数，将有名管道描述符 fd 加入监听事件
	ret = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event);
	if(-1 == ret){
		perror("epoll_ctl");
		return -1;
    }
	
	ret = 0;
	
	while(1){
		
	
		// 监视并等待多个文件（标准输入，有名管道）描述符的属性变化（是否可读）
		// 没有属性变化，这个函数会阻塞，直到有变化才往下执行，这里没有设置超时
		ret = epoll_wait(epfd, &wait_event, 2, -1);
		//ret = epoll_wait(epfd, &wait_event, 2, 1000);
		
		if(ret == -1){ // 出错
			close(epfd);
			perror("epoll");
		}else if(ret > 0){ // 准备就绪的文件描述符
		
			char buf[100] = {0};
			
			if( ( 0 == wait_event.data.fd ) 
			&& ( EPOLLIN == wait_event.events & EPOLLIN ) ){ // 标准输入
			
				read(0, buf, sizeof(buf));
				printf("stdin buf = %s\n", buf);
				
			}else if( ( fd == wait_event.data.fd ) 
			&& ( EPOLLIN == wait_event.events & EPOLLIN ) ){ // 有名管道
			
				read(fd, buf, sizeof(buf));
				printf("fifo buf = %s\n", buf);
				
			}
			
		}else if(0 == ret){ // 超时
			printf("time out\n");
		}
	
	}
	
	close(epfd);
	
	return 0;
}
>>>>>>> 7bcbca8da3d016d335789d7d4929f4e2185b58a7
