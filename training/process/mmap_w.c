//
// Created by fpf on 2020-04-30.
//

#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv){

    int fd = shm_open("posixsm", O_CREAT|O_RDWR, 0666);
    ftruncate(fd, 0x400000);

    char *p=(char *)mmap(NULL, 0x400000,
            PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    memset(p, 'A', 0x400000);
    munmap(p, 0x400000);

    return 0;
}

//gcc -o mw -g /data/app/c/cwhole/training/process/mmap_w.c  -lrt