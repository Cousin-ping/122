#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_
#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node
{
	datatype data;//数据域
	struct node *next;//指针域
}linkqueue_node_t,*linkqueue_list_t;

//linkqueue_list_t p === linkqueue_node_t *
typedef struct//将队列头指针和尾指针封装到一个结构体里
{
	linkqueue_list_t front;//相当于队列的头指针
	linkqueue_list_t rear;//相当于队列的尾指针
	//有了链表的头指针和尾指针，那么我们就可以操作这个链表
}linkqueue_t;
//1.创建一个空的队列
linkqueue_t *CreateEmptyLinkQueue();
//2.入列 data代表入列的数据
int InLinkQueue(linkqueue_t *p,datatype data);
//3.出列 
datatype OutLinkQueue(linkqueue_t *p);
//4.判断队列是否为空
int IsEmptyLinkQueue(linkqueue_t *p);
//5.求队列长度的函数
int LengthLinkQueue(linkqueue_t *p);
//6.清空队列
void ClearLinkQueue(linkqueue_t *p);

#endif