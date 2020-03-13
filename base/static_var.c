//
// Created by fpf on 2020-03-13.
//

#include <stdio.h>
int f();

//全局变量，具有全局的作用域和全局的生存期
//全局变量和静态变量位于相同的内存区域
int gAll=1;
//const 规定变量在全局中是只读的变量，并且它的值无法被修改
//static const 规定变量在当前的模块中是只读的变量，无法在全局中被其他的模块读取
//static 一般有两个作用域，规定作用域和存储方式，
// 对于局部变量，static规定其为静态存储方式，每次调用的初始值为上一次调用的值，调用结束后的存储空间不释放
// 对于全局变量，如果以文件划分作用域的话，此变量只在当前文件中可见，对于static函数也是在当前模块内函数可见

//static const 应该就是上面两者的合集
int main(int argc, char *argv[]){
    int j;
    j=f();
    printf("func=%s, j=%d, addr=%p"
          "\n", __func__, j, &j);
//   f();
//   f();
   return 0;
}

int f(){
    int i=0;//本地变量具有本地的作用域和生存期
    static int all=1;//静态本地变量是特殊的全局变量，具有本地变量的作用域，全局变量的生存期？
    printf("func=%s, i=%d,    addr=%p\n", __func__, i, &i);
    printf("func=%s, gAll=%d, addr=%p\n", __func__, gAll, &gAll);
    printf("func=%s, all=%d,  addr=%p\n", __func__, all, &all);

    all+=2;
    printf("again func=%s, all=%d, addr=%p\n", __func__, all, &all);
    return all;
}

