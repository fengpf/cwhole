//
// Created by fpf on 2020-04-30.
//
#include <string.h>
#include <unistd.h>

#include <sys/shm.h>


int main(int argc, char **argv){
    key_t key = ftok("/dev/shm/myshm2", 0);
    int shm_id = shmget(key, 0x400000, IPC_CREAT|0666);

    char *p=(char *)shmat(shm_id, NULL, 0);
    memset(p, 'A', 0x400000);
    shmdt(p);

    return 0;
}
