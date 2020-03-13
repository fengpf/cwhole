//
// Created by fengpengfei on 2020/3/12.
//

#include <stdio.h>

#define REDIS_GIT_SHA1 "bd28dbee"
char *redisGitSHA1(void);

int main(int argc, char const *argv[]){

    char *a;
    a=redisGitSHA1();
    printf("%s\r\n",a);

    int m,n;
    m=1;
    n=2;
    int* const q=&m;
    *q=11;
//    q++; //note: variable 'q' declared const here
    printf("%d\n", m);

    const int *p=&n;
//    *p=22; //error: invalid operands to binary expression ('int *' and 'const int *')
    printf("before p++ %p\n", p);
    p++;
    printf("after p++ %p\n", p);
}

char *redisGitSHA1(void) {
    return REDIS_GIT_SHA1;
}

void test() {
    int i,j;
    for (i=1;i<=9;i++) {
        for (j=1;j<=i;j++){
           printf("%d*%d=%d\t",j,i,i*j);
        }
        printf("\n");
    }
}