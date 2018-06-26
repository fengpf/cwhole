#include <pthread.h>

func_d()
{
	int i;
	for(i=0;i<50000;i++);
	sleep(1);
}

func_a()
{
	int i;
	for(i=0;i<100000;i++);
	func_d();
}

func_b()
{
	int i;
	for(i=0;i<200000;i++);
}

func_c()
{
	int i;
	for(i=0;i<300000;i++);
}

void* thread_fun(void* param)
{
	while(1) {
		int i;
		for(i=0;i<100000;i++);

		func_a();
		func_b();
		func_c();
	}
}

int main(void)
{
	pthread_t tid1,tid2;
	int ret;

	ret=pthread_create(&tid1,NULL,thread_fun,NULL);
	if(ret==-1){
		perror("cannot create new thread");
		return 1;
	}

	ret=pthread_create(&tid2,NULL,thread_fun,NULL);
	if(ret==-1){
		perror("cannot create new thread");
		return 1;
	}

	if(pthread_join(tid1,NULL)!=0){
		perror("call pthread_join function fail");
		return 1;
	}

	if(pthread_join(tid2,NULL)!=0){
		perror("call pthread_join function fail");
		return 1;
	}

	return 0;
}	
