#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct linkstack
{
	int data;//数据域
	struct linkstack * next;//指针域
}linkstack_t;

//1.创建一个空的栈
void createEmptyLinkStack(linkstack_t **ptop)
{
    *ptop = NULL;
}

//2.入栈   data是入栈的数据
int pushLinkStack(linkstack_t **ptop, datatype data)
{
    //1.创建新节点存放数据
    linkstack_t * pnew =(linkstack_t *)malloc(sizeof(linkstack_t));
    if(NULL == pnew)
    {
        perror("P MALLOC ERR");
        return -1;
    }
    //2.初始化新节点
    pnew->data = data;

    //3.将新节点作为无头单向链表的头
    pnew->next = *ptop;
    //4.移动栈针，栈针top始终指向无头单向链表的头
    *ptop=pnew;
    return 0;
}
int main(int argc, char const *argv[])
{
    linkstack_t * top ;
    createEmptyLinkStack(&top);
    pushLinkStack(&top,1);

    printf("%d\n",top->data);
    // printf("%d\n",sizeof(int));

    int *p=(int*)((int *)top);
    printf("%d\n",*p);
    return 0;
}



// #include<stdio.h>
// #include"stack.h"

// int main(int argc, char const *argv[])
// {
//     //先释放
//     seqstack_t *stack=CreateEpSeqStack(6);
//     PushStack(stack,11);
//     PushStack(stack,22);
//     PushStack(stack,33);
//     PushStack(stack,44);
//     PushStack(stack,55);

//     int *p=(int *)((data_type *)stack+5);
//     printf("%d\n",*p);
//     p=(int *)((data_type *)stack+6);
//     printf("%d\n",*p);
//     p=(int *)((data_type *)stack+7);
//     printf("%d\n",*p);
//     p=(int *)((data_type *)stack+8);
//     printf("%d\n",*p);
//     p=(int *)((int *)((data_type *)stack+8)+4);
//     printf("%p\n",p);

//     printf("%p\n",&(stack->maxlen));

//     printf("%d\n",sizeof(int *));
//     return 0;
// }
