#include <stdio.h>

__attribute__((weak)) void sayhi(void )
{
	printf("hello\n");
}

void main(void)
{
	sayhi();
}

