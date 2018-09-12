#include<stdio.h>
#include<stdlib.h>

// https://www.cs.dartmouth.edu/~doug/tinysort.html

#define getArrayLen(array,len) {len = sizeof(array)/sizeof(array[0]);}


// a!=NULL&&n>=0

void 
sort(int *a,int n){
    int *b,*c,t;

    for(b=a+n;--b>a;) {
       for(c=b;--c>=a;){
          if(*c>*b) {
             t=*b,*b=*c,*c=t;
          } 
        }
    }
}

// sort(first,last+1)
void sort2(int*a,int*b){for(int*c,t;--b>a;)
for(c=b;c-->a;)if(*c>*b)t=*b,*b=*c,*c=t;}

int 
main(){
    int i,len;
    int arr[3];

    arr[2]=0;
    arr[1]=1;
    arr[0]=2;


    getArrayLen(arr, len)
    printf("len=%d \n",len);

    printf("-------------\n");

    // for (i=len-1; i>=0; i--){
    //     printf("i=%d \n",i);
    //     arr[i]=i;
    // }
    
    for (i=0; i<len; i++){
       printf("before sort arr[%d]=%d \n",i, arr[i]);
    }
 

    // sort(arr, len);
    sort2(arr, &arr[len]);


    printf("-------------\n");


    for (i=0; i<len; i++){
       printf("after sort  arr[%d]=%d \n",i, arr[i]);
    }
}