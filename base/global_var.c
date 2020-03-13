//
// Created by fpf on 2020-03-13.
//

#include <stdio.h>

int f(void);

int gAll=12;

int main(int argc, char const *argv[]){
    printf("in %s gAll=%d\n", __func__, gAll);

    f();

    printf("again in %s aAll=%d\n", __func__, gAll);
    return 0;
}

int f(void){
//    int gAll=1; //本地变量在作用域范围内覆盖全局变量
    printf("in %s gAll=%d\n", __func__, gAll);
    gAll+=2;
    printf("again in %s gAll=%d\n", __func__, gAll);
    return gAll;
}