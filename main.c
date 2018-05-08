/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: fpf
 *
 * Created on 2018年5月7日, 下午4:56
 */

#include <stdio.h>
#include <stdlib.h>
#include "inet_1.h"
/*
 * 
 * 功能：inet_addr()函数用于将点分十进制IP地址转换成网络字节序IP地址;
   原型：in_addr_t inet_addr(const char *cp);
   返回值：如果正确执行将返回一个无符号长整数型数。如果传入的字符串不是一个合法的IP地址，将返回INADDR_NONE;
 * 
 * 
 * 
 * inet_aton()函数
   功能：inet_aton()函数用于将点分十进制IP地址转换成网络字节序IP地址;
   原型：int inet_aton(const char *string, struct in_addr *addr);
   返回值：如果这个函数成功，函数的返回值非零，如果输入地址不正确则会返回零;
 * 
 * 
 * 
 * inet_ntoa()函数
   功能inet_ntoa()函数用于网络字节序IP转化点分十进制IP;
   原型：char *inet_ntoa (struct in_addr);
   返回值：若无错误发生，inet_ntoa()返回一个字符指针。否则的话，返回NULL。其中的数据应在下一个WINDOWS套接口调用前复制出来;
 * 
 */
int main(int argc, char** argv) {

        
//    printf("%d\n",argc);  
//    printf("%s\n",argv[0]);  
    printf("%s\n",argv[1]);  
//    printf("%s\n",argv[2]); 
    
  
    struct in_addr addr;
    addr.s_addr=inet_addr(argv[1]);
    char *strAddr =inet_ntoa(addr);
    printf("StrIP: %s\n",strAddr);
    
    if (inet_aton(argv[2], &addr)>0){
        printf("NetIP:0x%x\n",addr);
    }
    
    return (EXIT_SUCCESS);
}

//void test(){
//    struct in_addr addr;
//    
//    char lo[]="127.0.0.1";
//    addr.s_addr=inet_addr(lo);
//    printf("NetIP: 0x%x\n",addr.s_addr);
//    
//    char *strAddr =inet_ntoa(addr);
//    printf("StrIP: %s\n",strAddr);
//    
//    if (inet_aton(strAddr, &addr)>0){
//        printf("NetIP:0x%x\n", addr);
//    }
//}



