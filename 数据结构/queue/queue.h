#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdio.h>
#include <stdlib.h>

#define N 5
typedef int datatype;
typedef struct sequeue
{
	datatype data[N];//循环队列的数组
	int rear;//存数据端 rear 后面
	int front;//取数据端 front 前面
}sequeue_t;
//1.创建一个空的队列
sequeue_t *CreateEmptySequeue();
//2.入列 data代表入列的数据
int InSequeue(sequeue_t *p,datatype data);
//3.判断队列是否为满
int IsFullSequeue(sequeue_t *p);
//4.判断队列是否为空
int IsEmptySequeue(sequeue_t *p);
//5.出列 
datatype OutSequeue(sequeue_t *p);
//6.求队列的长度
int LengthSequeue(sequeue_t *p);
//7.清空队列函数
void ClearSequeue(sequeue_t *p);

#endif