#include<stdio.h>
#include<string.h>

int mycmp(const char* s1,  const char* s2);
int mycmp2(const char* s1,  const char* s2);
int mycmp3(const char* s1,  const char* s2);

int main(int argc, char const *argv[])
{
	char s1[] = "abc";
	char s2[] = "Abc";//bbc Abc

//	printf("%d\n", s1==s2); //array can not compare always.
	//printf("%d\n", strcmp(s1,s2));
	printf("mycpm:%d\n", mycmp(s1,s2));
	printf("mycmp2:%d\n", mycmp2(s1,s2));
	printf("mycmp3:%d\n", mycmp3(s1,s2));

	if( strcmp(s1,s2)==0 ){

	}

	return 0;
}

int mycmp(const char* s1,  const char* s2){
   int idx=0;

   while(1){
    if (s1[idx]!=s2[idx]){
        break;
     }else if (s1[idx]=='\0'){
         break;
     }
      idx++;
   }

   return s1[idx]-s2[idx];
}

int mycmp2(const char* s1,  const char* s2){
   int idx=0;

   while(s1[idx]==s2[idx] && s1[idx]!='\0'){
      idx++;
   }

   return s1[idx]-s2[idx];
}

int mycmp3(const char* s1,  const char* s2){
   int idx=0;

   while(*s1==*s2 && *s1!='\0'){
      s1++;
      s2++;
   }

   return *s1-*s2;
}
