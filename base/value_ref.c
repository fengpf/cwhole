#include<stdio.h>
#include<stdlib.h>


//使用值传递交换两个变量的值
void swap(int a, int b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

//使用地址传递交换两个变量的值
void swap2(int* a, int* b){
    printf("1111 value: a=%d,b=%d, address:  a=%p,b=%p\n", *a, *b,  &a, &b);
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    printf("2222 value: a=%d,b=%d, address:  a=%p,b=%p\n", *a, *b,  &a, &b);
}


//使用引用传递交换两个变量的值
void swap3(int* a, int* b){
   printf("1111 value: a=%d,b=%d, address:  a=%p,b=%p\n", *a, *b,  &a, &b);
   int* temp;
   temp = a;
   a = b;
   b = temp;
   printf("2222 value: a=%d,b=%d, address:  a=%p,b=%p\n", *a, *b,  &a, &b);
}

int main(){
    int i,j;
    i=3;
    j=4;

    printf("before swap i=%d,j=%d\t address: i=%p,j=%p\n", i, j, &i, &j);
    // swap(i,j);
    // swap2(&i, &j);
    swap3(&i, &j);
    printf("after swap i=%d,j=%d\t address: i=%p,j=%p\n", i, j, &i, &j);
}

