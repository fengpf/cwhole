#include<stdio.h>
#include<stddef.h>

#if (defined(__GNUC__) || defined(__SUNPRO_CC))
#define CJSON_PUBLIC(type) __attribute__((visibility("default"))) type
#else
#define CJSON_PUBLIC(type) type
#endif
typedef struct cJSON
{
	struct cJSON *next;
	struct cJSON *prev;
	struct cJSON *child;

	int  type;

	char *string;
}cJSON


CJSON_PUBLIC(cJSON*) cJSON_CreateString(const char* const *strings, int count)
{
   size_t i=0;
   if ((count<0)||(strings==NULL))
   {
	   return NULL;
   }
   
   cJSON *item=(cJSON*)malloc(sizeof(cJSON));
   if (item==NULL){
	   return NULL;
   } 
   memset(item, '\0', sizeof(cJSON));
   item->type=1<<5;
   
    for(i=0; item && (i<(size_t)count); i++){
	   printf("%s\n", strings[i]);
   }

   return item;
}

int main(int argc, char* argv[])
{
	const char *strings[2]={
		"Sunday",
		"Monday"
	};
          
	cJSON *root=NULL;
	root=cJSON_CreateString(strings,7);
	printf("%p\n", root);
	return 0;
}

