#include<stdio.h>
#include<stdlib.h>

int main()
{
	int **table;

	int i;
	int *entry;
	void *key;
	for (i=0; i<2; i++)
	{
		key = malloc(sizeof(*entry));
		table[i] = key;
	}
    

	for (i=0; i<2; i++)
	{
		printf("%p\n", table[i]);
	}
      
    int a = 1;
    int b = 2;

    table[0] = &a;
    table[1] = &b;       
        
    for (i=0; i<2; i++)
	{
		if (i==0) {
		   printf("%d\n", *table[i]);
		}
                
		if (i==1) {
		   printf("%d\n", *table[i]);
		}

        
        //free(table[i]);

	}
    
}

