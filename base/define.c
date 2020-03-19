#include<stdio.h>

#define PI 3.1415926
#define FORMAT "%f\n"
#define PI2 2*PI //2*pi
#define PRT printf("%f\n", PI);\
            printf("%f\n", PI2)
#define _DEBUG
#define cube(x) ((x)*(x)*(x))

#define RADTODEG1(x) ((x)*2)
#define RADTODEG2(x) ((x))*3

#define MIN(a,b) ((a)>(b)?(b):(a))

int main(int argc, char const *argv[]){
   printf(FORMAT, PI2*3.0);
   PRT;
   printf("%s:%d\n", __FILE__, __LINE__);
   printf("%s:%s\n", __DATE__, __TIME__);

   int i;
   scanf("%d", &i);
   printf("%d\n", cube(i));

   printf("%d\n", RADTODEG1(5+2));
   printf("%d\n", 180/RADTODEG2(1));

   printf("min:%d\n", MIN(30,20));
   return 0;
}
