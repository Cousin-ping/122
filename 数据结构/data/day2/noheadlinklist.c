#include<stdio.h>
typedef struct node_t
{
    char data;//数据域
    struct node_t * next; //指针域  
}link_node_t,*link_list_t;

//typedef struct node_t link_node_t;
//struct node_t a;==link_node_t a;

//typedef struct node_t * link_list_t;
//struct node_t * p;==link_list_t p;==link_node_t * p;
int main(int argc, char const *argv[])
{
    //1. 定义四个节点
    link_node_t A={'A',NULL};
    link_node_t B={'B',NULL};
    link_node_t C={'C',NULL};
    link_node_t D={'D',NULL};
    //2.将四个节点链接到一起
    A.next=&B;
    B.next=&C;
    C.next=&D;
    //3.定义一个头指针指向第一个节点
    link_list_t h = &A;
    //4.遍历无头单项链表
    while(h !=NULL)
    {
        printf("%c  ",h->data);
        h=h->next;
    }
    printf("\n");
    return 0;
}
