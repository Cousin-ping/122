#include<stdio.h>
#include<stdlib.h>

typedef int datatype;

typedef struct node
{
    datatype data;//数据域
    struct node * next;//指针域
}linkqueue_node_t,*linkqueue_list_t;

typedef struct 
{
    linkqueue_list_t front;
    linkqueue_list_t rear;
}linkqueue_t;

//1.创建一个空的队列
linkqueue_t *createEmptyLinkQueue()
{
    //申请存放头尾指针的空间
    linkqueue_t * p = (linkqueue_t *)malloc(sizeof(linkqueue_t));
    if(NULL == p)
    {
        perror("p malloc err");
        return NULL;
    }
    //头尾指针初始化，将头节点的地址复制给头尾指针
    p->front=p->rear=(linkqueue_list_t)malloc(sizeof(linkqueue_node_t));
    if(NULL == p->rear)
    {
        perror("p->rear malloc err");
        return NULL;
    }
    //头节点初始化
    p->rear->next=NULL;//头节点初始化，或者p->front->next = NULL;
    return p;
}

//2.入列 data代表入列的数据
int inLinkQueue(linkqueue_t *p,datatype data)
{
    //1.创建新节点
    linkqueue_list_t pnew = (linkqueue_list_t)malloc(sizeof(linkqueue_node_t));
    if(NULL == pnew)
    {
        printf("pnew malloc err\n");
        return -1;
    }
    //2.初始化
    pnew->data = data;
    pnew->next = NULL;
    //3.插入链表作为尾巴节点（队尾），移动队尾
    p->rear->next = pnew;//新节点链接到链表的尾巴
    p->rear = pnew;//移动尾指针，永远指向链表的尾巴
    return 0;
}

//4.判断队列是否为空
int isEmptyLinkQueue(linkqueue_t *p)
{
    return p->rear == p->front;
}
//3.出列 
datatype outLinkQueue(linkqueue_t *p)
{
    linkqueue_list_t pdel = NULL;
    //1.容错判断
    if(isEmptyLinkQueue(p))
    {
        perror("isEmptyLinkQueue");
        return -1;
    }
    //2.数据出列
        //pdel指向被删除的头节点
        pdel = p->front;
        //头节点向后移动一个位置
        p->front = p->front->next;
        //释放被删除的节点
        free(pdel);
        pdel = NULL;
        //返回数据
        return p->front->data;
}

//5.求队列长度的函数
int lengthLinkQueue(linkqueue_t *p)
{
    int len=0;
    linkqueue_list_t h = p->front->next;//定义一个指针代替front移动
    while( h != NULL)//遍历无头链表
    {
        len++;
        h=h->next;
    }
    return len;
}

//6.清空队列
void clearLinkQueue(linkqueue_t *p)
{
    while(! isEmptyLinkQueue(p))//只要不为空就出列
        outLinkQueue(p);
}
int main(int argc, char const *argv[])
{
    int i;
    linkqueue_t * p = createEmptyLinkQueue();
    for(i=1;i<6;i++)
        inLinkQueue(p,i);
    printf("len is %d\n",lengthLinkQueue(p));
    while(!isEmptyLinkQueue(p))
    {
        printf("%d ",outLinkQueue(p));
    }
    printf("\n");
    free(p->front);
    p->front=NULL;
    p->rear=NULL;
    free(p);
    p=NULL;

    return 0;
}
