//
// Created by fpf on 2020-04-24.
//

#include <stdio.h>
#include "lib/sds.h"

void bprint(int p);
void bitset();

int main (int argc, char *argv[]){
    sds str;
//    char a[]={'a'};
    char a = 'a'; // char	1 字节	-128 到 127 或 0 到 255

//  sds 返回给上层的，不是结构体首地址，而是指向内容的buf指针
    str = sdsnewlen(&a, 1);//01100001 低3位存类型 001，高5位存长度 01100
    printf("str:%s, %lu\n", str, sdslen(str));

    printf("sdshdr5:%lu\n", sizeof(struct sdshdr5)); // 1
    printf("sdshdr8:%lu\n", sizeof(struct sdshdr8)); // 3
    printf("sdshdr16:%lu\n", sizeof(struct sdshdr16)); //5
    printf("sdshdr32:%lu\n", sizeof(struct sdshdr32)); //9
    printf("sdshdr64:%lu\n", sizeof(struct sdshdr64)); //17

//    bitset();

    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    char buf[]={'0'};
    printf("flags:%lu, buf:%lu\n", sizeof(flags), sizeof(buf));
    return 0;
}

void bitset() {
    sds ptr;
    size_t bitoffset;
    bitoffset = 7;
    ssize_t  bit;
    int byteval, bitval;
    long on = 0;

//    void *ptr;
//    sdsgrowzero(ptr,byte+1);

    size_t byte = bitoffset >> 3;
    ptr = sdsnewlen(NULL,byte + 1);

    /* Get current values */
    //    byte = bitoffset >> 3;
    printf("byte:%zu\n", byte + 1);
    printf("ptr:%p\n", ptr);

    byteval = ((uint8_t*) ptr)[byte];

    printf("byteval:%d\n", byteval);

    bit = 7 - (bitoffset & 0x7);

    printf("bit:%zd\n", bit);

    bitval = byteval & (1 << bit);

    printf("bitval:%d\n", bitval);

    /* Update byte with new bit value and return original value */
    byteval &= ~(1 << bit);
    byteval |= ((on & 0x1) << bit);
    ((uint8_t*) ptr)[byte] = byteval;

    printf("byteval:%d\n", byteval);
    bprint(byteval);
}
void bprint(int p) {
    int i=0;
    int bit1 = 1;
    for (i=sizeof (p) * 8-1;i>=0; i--){
        unsigned int x = (((bit1<<i) &p) !=0);
        printf("%d", x);
    }

    printf("\n ");
}

