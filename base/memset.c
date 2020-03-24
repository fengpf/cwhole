#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	char str[50];

	strcpy(str, "this is string.h lib func");
	puts(str);

	memset(str, '$', 7);
	puts(str);
	return 0;
}
