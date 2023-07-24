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

//3.判断栈是否为空
int isEmptyLinkStack(linkstack_t *top)
{
    return top ==  NULL;
}

//4.出栈
datatype popLinkStack(linkstack_t **ptop)
{
    linkstack_t * pdel = NULL;
    //1.容错处理
    if(isEmptyLinkStack(*ptop))
    {
        printf("isEmptyLinkStack\n");
        return -1;
    }
    //2.定义一个指针指向出栈的节点
    pdel = *ptop;
    //3.定义一个变量，存储出栈的数据
    datatype temp = pdel->data;
    //4.删除节点
    *ptop = pdel->next;
    //5.释放节点
    free(pdel);
    pdel = NULL;

    return temp;
}

//5.清空栈
void clearLinkStack(linkstack_t **ptop)
{
    while(!isEmptyLinkStack(*ptop))//只要不为空就出栈
    {
        popLinkStack(ptop);
    }
}

//6.求栈的长度
int lengthLinkStack(linkstack_t *top)
{
    int len=0;//计算长度
    while(top != NULL)//遍历无头单向链表
    {
        len++;
        top = top->next;
    }
    return len;
}

//7.获取栈顶数据,不是出栈,不需要移动main函数中的top，所以用一级指针
datatype getTopLinkStack(linkstack_t *top)
{
    if(!isEmptyLinkStack(top))
    {
        return top->data;//返回栈顶数据
    }
    return -1;// 空
}

int main(int argc, char const *argv[])
{
    int i;
    linkstack_t * top ;
    createEmptyLinkStack(&top);
    for(i=1;i<=5;i++)
        pushLinkStack(&top,i);
    printf("len is %d\n",lengthLinkStack(top));
    printf("top is %d\n",getTopLinkStack(top));
    clearLinkStack(&top);
    printf("清空栈后：\n");
    printf("len is %d\n",lengthLinkStack(top));
    while(!isEmptyLinkStack(top))
    {
        printf("%d  ",popLinkStack(&top));
    }
    printf("\n");
    
    return 0;
}
