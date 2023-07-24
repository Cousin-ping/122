#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

//1.创建一个空的队列
linkqueue_t *CreateEmptyLinkQueue()
{
    linkqueue_t *p=(linkqueue_t *)malloc(sizeof(linkqueue_t));
    if (NULL==p)
    {
        printf("p malloc err");
        return NULL;
    }
    p->front=p->rear=(linkqueue_list_t)malloc(sizeof(linkqueue_node_t));
    if (NULL==p->rear)
    {
        perror("p->rear malloc err");
        return NULL;
    }
    p->rear->next=NULL;
    return p;
}
//2.入列 data代表入列的数据
int InLinkQueue(linkqueue_t *p,datatype data)
{
    linkqueue_list_t pnew=(linkqueue_list_t)malloc(sizeof(linkqueue_node_t));
    if (NULL==pnew)
    {
        perror("pnew malloc err");
        return -1;
    }
    pnew->data=data;
    pnew->next=NULL;
    p->rear->next=pnew;
    p->rear=pnew;
    return 0;
    
}
//3.出列 
datatype OutLinkQueue(linkqueue_t *p)
{
    //两种思路这是其中一种
    if (IsEmptyLinkQueue(p))
    {
        perror("is Empty err");
        return -1;
    }
    linkqueue_list_t pdel=NULL;
    pdel=p->front;
    p->front=p->front->next;
    free(pdel);
    pdel=NULL;
    return p->front->data;
    
}
//4.判断队列是否为空
int IsEmptyLinkQueue(linkqueue_t *p)
{
    return p->front->next==NULL;
}
//5.求队列长度的函数
int LengthLinkQueue(linkqueue_t *p)
{
    int len=0;
    linkqueue_list_t h=p->front->next;
    while (h!=NULL)
    {
        len++;
        h=h->next;
    }
    return len;
}
//6.清空队列
void ClearLinkQueue(linkqueue_t *p)
{
    while (!IsEmptyLinkQueue(p))
    {
        OutLinkQueue(p);
    }
    
}