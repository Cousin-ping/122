#include<stdio.h>
#include<stdlib.h>

#define N 5
typedef int datatype;

typedef struct 
{
  datatype data[N]; 
  int front;
  int rear; 
}sequeue_t;

//1.创建一个空的队列
sequeue_t *createEmptySequeue()
{
    sequeue_t * p = (sequeue_t *)malloc(sizeof(sequeue_t));
    if(NULL == p)
    {
        perror("p malloc err");
        return NULL;
    }
    //初始化
    p->front=0;
    p->rear=0;
    return p;
}

//3.判断队列是否为满,满返回1
int isFullSequeue(sequeue_t *p)
{
    return (p->rear+1)%N == p->front;
}

//2.入列 data代表入列的数据
int inSequeue(sequeue_t *p,datatype data)
{
    //1.容错判断
    if(isFullSequeue(p))
    {
        printf("isFullSequeue\n");
        return -1;
    }
    //2.将数据入队,队尾移动
    p->data[p->rear]=data;
    p->rear = (p->rear+1)%N;
    return 0;
}

//4.判断队列是否为空
int isEmptySequeue(sequeue_t *p)
{
    return p->rear == p->front;
}

//5.出列 
datatype outSequeue(sequeue_t *p)
{
    datatype temp;
    //1.容错判断
    if(isEmptySequeue(p))
    {
        printf("isEmptySequeue\n");
        return -1;
    }
    //2.出队
        //1）取出数据
        temp = p->data[p->front];
        //2）移动队头
        p->front=(p->front+1)%N;
    return temp;
}

//6.求队列的长度
int lengthSequeue(sequeue_t *p)
{
    //方法1：
    // if(p->rear >= p->front)
    //     return p->rear-p->front;
    // else 
    //     return p->rear-p->front+N;
    //方法2：
        return (p->rear-p->front+N)%N;
}

//7.清空队列函数
void clearSequeue(sequeue_t *p)
{
    p->rear=p->front;
}
int main(int argc, char const *argv[])
{
    int i;
    sequeue_t *p = createEmptySequeue();
    for(i=0;i<N;i++)
    {
        inSequeue(p,i);//0 1 2 3 正常，4入队失败
    }
    printf("len is %d\n",lengthSequeue(p));//4
    printf("front is %d rear is %d\n",p->front,p->rear);//0  4
    outSequeue(p);//front 1 rear 4
    outSequeue(p);//front 2 rear 4
    inSequeue(p,100);//front 2 rear 0
    printf("front is %d rear is %d\n",p->front,p->rear);//2  0
    printf("len is %d\n",lengthSequeue(p));// 3
    while (!isEmptySequeue(p))
    {
        printf("%d ",outSequeue(p));
    }
    printf("\n");

    free(p);
    p=NULL;
    
    return 0;
}
