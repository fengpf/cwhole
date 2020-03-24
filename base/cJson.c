#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>
#include<limits.h>

#if (defined(__GNUC__) || defined(__SUNPRO_CC))
#define CJSON_PUBLIC(type)   __attribute__((visibility("default"))) type
#else
#define CJSON_PUBLIC(type) type
#endif

//cjson type
#define cJSON_Invalid (0)
#define cJSON_False (1<<0)
#define cJSON_True (1<<1)
#define cJSON_NULL (1<<2)
#define cJSON_Number (1<<3)
#define cJSON_String (1<<4)
#define cJSON_Array (1<<5)
#define cJSON_Object (1<<6)
#define cJSON_Raw (1<<7)

#define cJSON_IsReference 256
#define cJSON_StringIsConst 512

typedef struct cJSON
{
	struct cJSON *next;
	struct cJSON *prev;
	struct cJSON *child;

	int  type;
	
	char *valuestring;
	int valueint;
	double valuedouble;

	char *string;
}cJSON;


CJSON_PUBLIC(cJSON *) cJSON_CreateStringArray(const char *const *strings, int count);
CJSON_PUBLIC(cJSON *) cJSON_CreateArray();
CJSON_PUBLIC(cJSON *) cJSON_CreateString(const char *string);
CJSON_PUBLIC(cJSON *) cJSON_CreateNumber(double num);
CJSON_PUBLIC(void) cJSON_Delete(cJSON *item);

// constructor
static cJSON *cJSON_New_Item()
{
	cJSON *item = (cJSON*) malloc(sizeof(cJSON));

	if (item)
	{ 
		memset(item, '\0', sizeof(cJSON));
	}

	return item;
}

static void suffix_object(cJSON *prev, cJSON *item)
{
     prev->next = item;
     item->prev = prev;
}

static unsigned char* cJSON_strdup(const unsigned char *string)
{
	size_t length=0;
	unsigned char *copy = NULL;
	
	if (string == NULL)
	{ 
             return NULL;
	}

	length = strlen((const char*)string) + sizeof("");
	copy = (unsigned char*) malloc(length);
        if (copy == NULL)
	{
            return NULL;
	}
	memcpy(copy, string, length);

	return copy;
}

int main(int argc, char *argv[])
{
	const char *strings[2]={
		"Sunday",
		"Monday"
	};
          
	cJSON *root=NULL;
	root = cJSON_CreateStringArray(strings, 2);
	printf("%p\n", root);
	return 0;
}

CJSON_PUBLIC(cJSON*) cJSON_CreateStringArray(const char *const *strings, int count)
{
   size_t i=0;
   cJSON *n = NULL;
   cJSON *p= NULL;
   cJSON *a = NULL;
   
   if ((count<0) || (strings==NULL))
   {
	   return NULL;
   }
   
    a = cJSON_CreateArray();

    for(i=0; a && (i<(size_t)count); i++){
	   printf("%s\n", strings[i]);
	   n = cJSON_CreateString(strings[i]);
	   if (!n)
	   {
		   cJSON_Delete(a);
		   return NULL;
	   }
	   if(!i)
	   {
		   a->child=n;
	   }
	   else
	   {
	         suffix_object(p, n);
	   }

	   p=n;
   }

   return a;
}

CJSON_PUBLIC(cJSON*) cJSON_CreateArray()
{
    cJSON *item = cJSON_New_Item();
    if (item)
    {
	    item->type= cJSON_Array;
    }

    return item;
}

CJSON_PUBLIC(cJSON*) cJSON_CreateString(const char *string)
{
         cJSON *item = cJSON_New_Item();
	 if (item)
	 {
		 item->type = cJSON_String;
		 item->valuestring = (char*) cJSON_strdup((const unsigned char*)string);
	         if (!item->valuestring){
			 cJSON_Delete(item);
			 return NULL;
		 }
	 }

	 return item;
}


CJSON_PUBLIC(void) cJSON_Delete(cJSON *item)
{
    cJSON *next = NULL;
    while(item != NULL)
    {
       next = item->next;
       if (!(item->type & cJSON_IsReference) && (item->child != NULL))
       {
	       cJSON_Delete(item->child);
       }
       
       if (!(item->type & cJSON_IsReference) && (item->valuestring !=NULL))
       {
	       free(item->valuestring);
       }

       if (!(item->type & cJSON_StringIsConst) && (item->string !=NULL))
       {
	       free(item->string);
       }

       free(item);
       item = next;
    }
}


CJSON_PUBLIC(cJSON*) cJSON_CreateNumber(double num)
{
   cJSON *item = cJSON_New_Item();
   if (item)
   {
	   item->type = cJSON_Number;
	   item->valuedouble = num;

	   if (num>=INT_MAX)
	   {
		   item->valueint = INT_MAX;
	   }
	   else if (num <=(double)INT_MIN)
	   {
		   item->valueint = INT_MIN;
	   }
	   else
	   {
		   item->valueint = (int)num;
	   }
   }

   return item;
}


