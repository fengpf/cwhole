#include <sys/select.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
 
// 1）每次调用 select()，都需要把 fd 集合从用户态拷贝到内核态，这个开销在 fd 很多时会很大，同时每次调用 select() 都需要在内核遍历传递进来的所有 fd，这个开销在 fd 很多时也很大。
// 2）单个进程能够监视的文件描述符的数量存在最大限制，在 Linux 上一般为 1024，可以通过修改宏定义甚至重新编译内核的方式提升这一限制，但是这样也会造成效率的降低

int main(int argc, char *argv[])
{
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
	
	ret = 0;
	
	while(1){
		// 这部分内容，要放在while(1)里面
		FD_ZERO(&rfds);		// 清空
		FD_SET(0, &rfds);   // 标准输入描述符 0 加入集合
		FD_SET(fd, &rfds);  // 有名管道描述符 fd 加入集合
		
		// 超时设置
		tv.tv_sec = 1;
		tv.tv_usec = 0;
		
		// 监视并等待多个文件（标准输入，有名管道）描述符的属性变化（是否可读）
		// 没有属性变化，这个函数会阻塞，直到有变化才往下执行，这里没有设置超时
		// FD_SETSIZE 为 <sys/select.h> 的宏定义，值为 1024
		ret = select(FD_SETSIZE, &rfds, NULL, NULL, NULL);
		//ret = select(FD_SETSIZE, &rfds, NULL, NULL, &tv);
 
		if(ret == -1){ // 出错
			perror("select()");
		}else if(ret > 0){ // 准备就绪的文件描述符
		
			char buf[100] = {0};
			if( FD_ISSET(0, &rfds) ){ // 标准输入
				read(0, buf, sizeof(buf));
				printf("stdin buf = %s\n", buf);
				
			}else if( FD_ISSET(fd, &rfds) ){ // 有名管道
				read(fd, buf, sizeof(buf));
				printf("fifo buf = %s\n", buf);
			}
			
		}else if(0 == ret){ // 超时
			printf("time out\n");
		}
	
	}
	
	return 0;
}
