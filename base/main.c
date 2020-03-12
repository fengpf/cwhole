#include<string.h>

int main(int argc, char const *argv[])
{
    /* code */
   struct {
       int a;
       char s[5];
       float f;
   } tt;
   bzero(&tt,sizeof(tt));
   printf("init succss\n");
   getchar();

    char temp[32];
    memset(temp,0,sizeof(temp));
    strcpy(temp,"Golden Global View");
    char *s = temp;
    char *p,c='v';
    p=strchr(s,c);
    if(p)
        printf("%s",p);
    else
        printf("Not Found!"); return 0;
}



