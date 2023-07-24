#include <stdio.h>
#include <stdlib.h>

typedef struct seqstack
{
    int *data;  //指针，指向栈存储位置
    int maxlen; //栈的最大长度
    int top;    //栈针，当作顺序表的last使用即可
} seqstack_t;

//1.创建一个空的栈
seqstack_t *CreateEpSeqStack(int len)
{
    seqstack_t *p = (seqstack_t *)malloc(sizeof(seqstack_t));
    if (NULL == p)
    {
        perror("p malloc err");
        return NULL;
    }
    p->maxlen = len;
    p->top = -1;
    p->data = (int *)malloc(sizeof(int) * len);
    if (p->data == NULL)
    {
        perror("p->data malloc err");
        free(p);
        p = NULL;
        return NULL;
    }
    return p;
}
//2.判断是否为满,满返回1 未满返回0
int IsFullSeqStack(seqstack_t *p)
{
    return p->maxlen == p->top + 1;
}

//3.入栈
int PushStack(seqstack_t *p, int data) //data代表入栈的数据
{
    //1.容错判断
    if (IsFullSeqStack(p))
    {
        printf("IsFullSeqStack\n");
        return -1;
    }
    //2.移动栈针
    p->top++;
    //3.将数据入栈
    p->data[p->top] = data;
    return 0;
}
//4.判断栈是否为空
int IsEpSeqStack(seqstack_t *p)
{
    return p->top == -1;
}
//5.出栈 
int PopSeqStack(seqstack_t *p)
{
    //1.容错判断
    if(IsEpSeqStack(p))
    {
        printf("IsEpSeqStack\n");
        return -1;
    }
    //2.移动栈针
    p->top--;
    //3.将数据取出
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
    if(!IsEpSeqStack(p))//只要栈不为空，就返回栈顶数据
    {
        return p->data[p->top];
    }
    return -1;
}
//8. 求栈的长度
int LengthSeqStack(seqstack_t *p)
{
    return p->top+1;
}
int main(int argc, char const *argv[])
{
    int i;
    seqstack_t *p=CreateEpSeqStack(5);
    for(i=1;i<=6;i++)//1 2 3 4 5,6入栈失败
    {
        PushStack(p,i);
    }
    printf("栈顶数据是%d\n",GetTopSeqStack(p));

    //只要栈不为空就出栈
    while(!IsEpSeqStack(p))
    {
        printf("%d ",PopSeqStack(p));
    }
    printf("\n");
    free(p->data);
    p->data=NULL;
    free(p);
    p=NULL;
    return 0;
}
