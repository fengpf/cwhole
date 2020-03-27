#include<stdio.h>

int main(int argc, char *argv[])
{
    char *a = "hello";
    char *b = "there";
    char *c = "sam";

    char *d[4] = {NULL};
    d[0] = a;
    d[1] = b;
    d[2] = c;

    char **ptr = d;
    while(*ptr){
      printf("item:%s\n", *ptr++);
    }

    return 0;
}

