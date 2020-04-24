#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *next;
} Node;

int main(int argc, char **argv)
{
    int number = 0;
    
    Node *head = NULL;
    
   // Node *head = (Node *) malloc(sizeof(Node));
    
    do {
        printf("请输入数字：\n");
        scanf("%d", &number);

        if (number!=-1)
        {
            printf("构造节点的值：%d\n", number);

            //构造一个节点
            Node *p = (Node*) malloc(sizeof(Node));
            p->val = number;

            
            //寻找链表尾部节点，尾插法
            Node *last = head;//开始尾部节点指向头部节点
//            if (last){
//                while(last->next)
//                {
//                    last = last->next;
//                }
//                last->next = p;//尾部插入节点
//            } else {
//                head = p;//插入第一个节点
//            }
              if (last)
              {
                  last->next = p;
                  last = p;
                  printf("head: %p, last: %p p: %p\n", head, last, p);
              }else {
                  head = p;
              }
        }
    } while(number!=-1);
    
    Node *t = NULL;
    for (Node *t=head; t; t=t->next)
    {
        printf("输出节点%d\n", t->val);
    }
    
    printf("程序退出\n");
}
