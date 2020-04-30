//
// Created by fpf on 2020-04-30.
//
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){
    int fd = shm_open("posixsm", O_CREAT|O_RDWR, 0666);
    ftruncate(fd, 0x400000);

    char *p=(char *)mmap(NULL, 0x400000,
                         PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    printf("%c %c %c %c\n", p[0], p[1], p[2], p[3]);
    munmap(p, 0x400000);

    return 0;
}

//gcc -o mr -g /data/app/c/cwhole/training/process/mmap_r.c  -lrt