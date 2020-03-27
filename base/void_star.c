#include<stdio.h>
#include<stdlib.h>

void test();

int main(int argc, char *argv[])
{
    //pointer types, pointer arithmetic, void pointers
    int a = 1025;
    int *p;
    p = &a;
    printf("size of integer is %ld bytes\n", sizeof(int));
    printf("p: address = %p, value=%d\n", p, *p);
    printf("p+1: address = %p, value=%d\n", p+1, *(p+1));
    
    char *p0;
    p0 = (char *)p; //typecasting
    printf("size of char is %ld bytes\n", sizeof(char));
    printf("p0: address = %p, value=%d\n", p0, *p0);
    printf("p0+1: address = %p, value=%d\n", p0+1, *(p0+1));
    // 1025 = 00000000 00000000 00000100 00000001

    void *p1;
    p1 = p;
    printf("p1: address = %p\n", p1);// p1= p 0x7ffd42bbdb0c = 0x7ffd42bbdb0c
}

void test()
{
   void *a;
    printf("a: %ld,%p\n", sizeof(a), a);
    char *b;
    void *t;
    t = malloc(sizeof(char));
    printf("t: %ld,%p\n", sizeof(t), t);
    b = (char *) t;
    printf("b: %ld,%p\n", sizeof(b), b);
    b = "hello world";
    printf("output: %s\n", b);
 }
