/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newsimpletest.c
 * Author: fpf
 *
 * Created on 2018年5月8日, 下午2:52
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Simple C Test Suite
 */

void test1() {
    printf("simple test 1\n");
}

void test2() {
    printf("newsimpletest test 2\n");
    printf("%%TEST_FAILED%% time=0 testname=test2 (newsimpletest) message=error message sample\n");
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% newsimpletest\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test1 (newsimpletest)\n");
    test1();
    printf("%%TEST_FINISHED%% time=0 test1 (newsimpletest) \n");

    printf("%%TEST_STARTED%% test2 (newsimpletest)\n");
    test2();
    printf("%%TEST_FINISHED%% time=0 test2 (newsimpletest) \n");

    printf("%%SUITE_FINISHED%% time=0\n");


    test:

    printf("test goto\n");
    exit(0);
    
    for(int i = 10; i >= 0; i--)
    {
       printf("%d\n",i);
       if (i==5){
           goto test;
       }
    }
    

    return (EXIT_SUCCESS);
}
