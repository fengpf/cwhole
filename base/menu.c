#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  while(1)
  {
	  char cmd[128];
         scanf("%s", cmd);
	 if (!strcmp(cmd, "help"))
	 {
	    printf("this is help cmd \n");
	 }
	 else if(!strcmp(cmd, "quit"))
	 {
		 //exit();
	 }
	 else
	 {
		 printf("wrong cmd!\n");
	 }
   }
}
