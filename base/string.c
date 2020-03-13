//
// Created by fpf on 2020-03-13.
//

#include <stdio.h>

int main(int argc, char* argv[]){
    int a =10;
    printf("a=%d, addr=%p\n",a, &a);
   char* s="hello";
//  s[0]='b';
  printf("s=%p\n",s);

  while(*s!='\0'){
      printf("s=%c\n",*s++);
  }
}