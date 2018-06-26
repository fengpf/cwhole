#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("error command format\n");
		exit(-1);
	}

	/*
	 * 当你敲./a.out cmd，"cmd"是argv[1]
	 */
	printf("%s\n", argv[1]);

	/*
	 * strcmp可以进行字符串比对
	 */
	if (!strcmp(argv[1], "hello"))
		printf("you input hello\n");
	
	return 0;
}
