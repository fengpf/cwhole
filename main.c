#include<stdlib.h>
#include<stdio.h>


int main(int argc, char *argv[])
{
    int a[]={1,2,3};

    for (int i = 0; i < 3; ++i) {
        printf("数组元素%d地址:%p\n", a[i], &a[i]);
    }

//    for (int i = 0; i < 3; ++i) {
//        printf("i地址:%p\n", &i);
//    }
    return 0;
}