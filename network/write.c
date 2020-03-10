#include <sys/select.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
	//select_demo(8);
	
	fd_set rfds;
	struct timeval tv;
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
	
	while(1){
		char *str = "this is for test";
		write(fd, str, strlen(str)); // 往管道里写内容
		printf("after write to fifo\n");
		sleep(5);
	}
	
	return 0;
}
