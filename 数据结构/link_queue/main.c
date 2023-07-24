#include <stdio.h>
#include "linkqueue.h"
int main(int argc, char const *argv[])
{
   linkqueue_t *p=CreateEmptyLinkQueue();
    for (size_t i = 0; i < 6; i++)
    {
        InLinkQueue(p,i);
    }
    printf("当前长度为%d\n",LengthLinkQueue(p));
    while (!IsEmptyLinkQueue(p))
    {
        printf("%d\n",OutLinkQueue(p));
    }
    printf("当前长度为%d\n",LengthLinkQueue(p));
    //先释放出开辟出的头结点（此时头尾节点是一个地址）
    //然后释放指针结构体开辟出的空间
    free(p->front);
    p->front=p->rear=NULL;
    free(p);
    p=NULL;
    // printf("%d %d %d\n",(int)(p->front),(int)(p->rear),(int)p);
    return 0;
}
