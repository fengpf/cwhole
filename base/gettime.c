#include<stdio.h>
#include<sys/time.h>

static void aeGetTime(long *seconds, long *milliseconds);

int main(int argc, char *argv[])
{
	long now_sec, now_ms;
	aeGetTime(&now_sec, &now_ms);
	printf("now_sec(%ld), now_ms(%ld)\n", now_sec, now_ms);
}

static void aeGetTime(long *seconds, long *milliseconds)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    *seconds = tv.tv_sec;
    *milliseconds = tv.tv_usec/1000;
}
