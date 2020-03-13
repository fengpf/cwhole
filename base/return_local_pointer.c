//
// Created by fpf on 2020-03-13.
//

#include <stdio.h>

int* f(void);
void g(void);

int main(int argc, char const *argv[]){
    int *p=f();
    printf("*p=%d, addr=%p\n", *p, &p);

    g();

    printf("*p=%d, addr=%p\n", *p, &p);
    return 0;
}
int* f(void){
    int i=12;

    //没有警告！
//    int* q;
//    q=&i;

    printf("i=%d, addr=%p\n", i, &i);
    return &i;//warning: address of stack memory associated with local variable 'i' returned
}

void g(void){
    int k=24;
    printf("k=%d, addr=%p\n", k, &k);
}