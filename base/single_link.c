#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *next;
};

typedef struct node Node;

//typedef struct node{
//	int val;
//	struct node *next;
//}Node;

int main(int argc, char *argv[])
{
     struct node *head = (struct node*) malloc (sizeof(struct node));
     //Node *head = (Node*) malloc (sizeof(Node));
     //Node *head = &Node;//错误
     
     int i;

     struct node *p;
     //Node *p;
     
     p = head;
     for(i=1; i<5; i++)
     {    
         struct node *q = (struct node*) malloc (sizeof(struct node));
	     //Node *q = (Node*) malloc(sizeof(Node));
	     //Node *q = &Node;//错误
	     q->val = i;
	     printf("q: addr(%p)\n", q);
	     p->next = q;
	     p = q;
     }
     
     printf("head: addr(%p), value(%d)\n", head, head->val);
     printf("p: addr(%p), value(%d)\n", p, p->val);
     
     struct node *t;
     //Node *t;
     for (t=head; t; t = t->next)
     {
	     printf("t: addr(%p), value(%d)\n", t, t->val);
     }
}
