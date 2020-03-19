#include<stdio.h>
#include<string.h>

size_t mylen(char* s)
{ 
	//s[6]=97;//test not use const
	
	int idx=0;
	while(s[idx]!='\0'){
		idx++;
		printf("%c:%p\n", s[idx], &s[idx]);
	}
	return idx;
}

int main(int argc, char const *argv[])
{
     char line[]="hello";
     printf("strlen=%lu\n", mylen(line));
     printf("sizeof=%lu\n", sizeof(line));
}
