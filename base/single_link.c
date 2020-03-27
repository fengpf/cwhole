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

struct node *head;

void construct();
void print(struct node *t);
void delete(struct node *entry);

int main(int argc, char *argv[])
{
 
    construct();
    print(head);

   
    printf("删除头节点\n");
    delete(head);
    print(head);
    
    printf("删除头节点之后的某个节点\n");
    delete(head->next);
    print(head);
}

void print(struct node *t)
{
     //Node *t;
     for (t=head; t; t = t->next)
     {
	     printf("t: addr(%p), value(%d)\n", t, t->val);
     }
}

void construct()
{
     head = (struct node*) malloc (sizeof(struct node));
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
	   //  printf("q: addr(%p)\n", q);
	     p->next = q;
	     p = q;
     }
     
     //printf("head: addr(%p), value(%d)\n", head, head->val);
     //printf("p: addr(%p), value(%d)\n", p, p->val);
     
  }


void delete(struct node *entry)
{
     struct node *prev = NULL;
     struct node *walk = NULL;
     walk = head;

     while(walk != entry){
         prev = walk;
         walk = walk->next;
     }

     if (!prev){//如果是头节点，直接删除
         head = entry->next;
     } else {
         prev->next = entry->next;
     }

}
