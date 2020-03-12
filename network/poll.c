#include <poll.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
 
int main(int argc, char *argv[])
{
 
	int ret;
	int fd;
	struct pollfd fds[2]; // 监视文件描述符结构体，2 个元素
	
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
	
	fds[0].fd = 0;	 // 标准输入
	fds[1].fd = fd;	 // 有名管道
		
	fds[0].events = POLLIN;	// 普通或优先级带数据可读
	fds[1].events = POLLIN; // 普通或优先级带数据可读
	
	while(1){
	
		// 监视并等待多个文件（标准输入，有名管道）描述符的属性变化（是否可读）
		// 没有属性变化，这个函数会阻塞，直到有变化才往下执行，这里没有设置超时
		ret = poll(fds, 2, -1);
		//ret = poll(&fd, 2, 1000);
 
		if(ret == -1){ // 出错
			perror("poll()");
		}else if(ret > 0){ // 准备就绪的文件描述符
		
			char buf[100] = {0};
			if( ( fds[0].revents & POLLIN ) ==  POLLIN ){ // 标准输入
				read(0, buf, sizeof(buf));
				printf("stdin buf = %s\n", buf);
				
			}else if( ( fds[1].revents & POLLIN ) ==  POLLIN ){ // 有名管道
				read(fd, buf, sizeof(buf));
				printf("fifo buf = %s\n", buf);
			}
			
		}else if(0 == ret){ // 超时
			printf("time out\n");
		}
	
	}
	
	return 0;
}
