#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"
//1.入栈
int PushLinkStack(linkstack_t **ptop,datatype data)
{
    //创建新的节点
    linkstack_t *pnew=(linkstack_t *)malloc(sizeof(linkstack_t));
    if(NULL == pnew)
    {
        perror("pnew malloc err.");
        return -1;
    }
    pnew->data=data;//初始化
    pnew->next=*ptop;//将新节点压入栈
    *ptop=pnew;//栈顶指针指向表头
    return 0;
}
//2.判断栈是否为空
int IsEpLinkStack(linkstack_t *top)
{
    return NULL==top;
}
//3.出栈
datatype PopLinkStack(linkstack_t **ptop)
{
    
    if(IsEpLinkStack(*ptop))
    {
        printf("stack is empty\n");
        return -1;
    }
    linkstack_t *del=*ptop;
    *ptop=del->next;
    datatype s=del->data;
    free(del);
    del=NULL;
    return s;
}
//4.清空栈
void ClearLinkStack(linkstack_t **ptop)
{
    if(IsEpLinkStack(*ptop))
    {
        printf("栈为空,无需清空\n");
    }
    while(*ptop!=NULL)
        PopLinkStack(ptop);
}
//5.求栈的长度
int LengthLinkStack(linkstack_t *top)
{
    int len=0;
   while(top!=NULL)
   {
       len++;
       top=top->next;
   }
   return len;

}
//6.获取栈顶数据
datatype GetTopLinkStack(linkstack_t *top)
{
    if(IsEpLinkStack(top))
    {
        return top->data;
    }
    return -1;
}