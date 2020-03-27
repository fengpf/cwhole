#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
   int n;
   printf("enter size of array \n");

   scanf("%d", &n);

   int *A = (int *) malloc(n*sizeof(int));//malloc 动态分配数组内存空间
   //int *A = (int *) calloc(n, sizeof(int));//calloc 动态分配数组内存空间
   
   // calloc 默认初始化内存值
   //10
   //0 0 0 0 0 0 0 0 0 0
   
   //for(int i=0; i<n; i++)
   //{
    //   A[i] = i+1;
   //}

   for(int i=0; i<n; i++)
   {
      A[i] = i+1;
   }

    //free(A);
   // *A = (int *) realloc(NULL, 0);
   printf("A address =%p\n", A);//equivalent to free(A)
   //A[2] = 6; //value at address A+2
    //  10

    //0 0 3 4 5 6 7 8 9 10
   for (int i=0; i<n; i++)
   {
       printf("%d ", A[i]);
   }

   printf("\n");
   
   //int *B = (int *) realloc(A, 2*n*sizeof(int));
   //int *B = (int *) realloc(A, (n/2)*sizeof(int));
   int *B = (int *) realloc(NULL, n*sizeof(int));//equivalent to malloc
   printf("prev block address =%p, new address = %p\n", A, B);//equivalent to free(A)
   for (int i=0; i<n; i++) //2*n
   {
       printf("%d ", B[i]);
   }
   printf("\n");
   return 0;
}
