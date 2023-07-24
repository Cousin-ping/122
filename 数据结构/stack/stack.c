#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//1.创建一个空的栈
seqstack_t *CreateEpSeqStack(int len)//len代表的是创建栈的时候的最大长度
{
    seqstack_t *p=(seqstack_t *)malloc(sizeof(seqstack_t));
    if (NULL==p)
    {
        perror("p malloc err");
        return NULL;
    }
    p->maxlen=len;
    p->data=(data_type *)malloc(sizeof(data_type)*len);
    if (NULL==p->data)
    {
        perror("p->data malloc err");
        free(p);
        p=NULL;
        return NULL;
    }
    p->top=-1;
    return p;
    
}
//2.判断是否为满,满返回1 未满返回0
int	 IsFullSeqStack(seqstack_t *p)
{
    return p->maxlen==p->top+1;
}
//3.入栈 
int  PushStack(seqstack_t *p, int data)//data代表入栈的数据
{
    if (IsFullSeqStack(p))
    {
        perror("max err");
        return -1;
    }
    p->top=p->top+1;
    p->data[p->top]=data;
    
}
//4.判断栈是否为空
int IsEpSeqStack(seqstack_t *p)
{
    return p->top==-1;
}
//5.出栈 
int PopSeqStack(seqstack_t *p)
{
    if(IsEpSeqStack(p))
    {
        perror("stack is NULL");
        return -1;
    }
    p->top--;
    return p->data[p->top+1];

}
//6. 清空栈 
void ClearSeqStack(seqstack_t *p)
{

    p->top=-1;    
}
//7. 获取栈顶数据(注意不是出栈操作，如果出栈，相当于删除了栈顶数据，只是将栈顶的数据获取到，不需要移动栈针)
int GetTopSeqStack(seqstack_t *p)
{
    if (!IsEpSeqStack(p))
    {
        return p->data[p->top];
    }else
    {
        perror("Get top err");
        return -1;
    }
   
}
//8. 求栈的长度
int LengthSeqStack(seqstack_t *p)
{
    return p->top+1;
}