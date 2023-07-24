#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_
#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct linkstack
{
   datatype data; //数据域
   struct linkstack * next;//指针域
}linkstack_t;
//1.入栈
int PushLinkStack(linkstack_t **ptop,datatype data);
//2.判断栈是否为空
int IsEpLinkStack(linkstack_t *top);
//3.出栈
datatype PopLinkStack(linkstack_t **ptop);
//4.清空栈
void ClearLinkStack(linkstack_t **ptop);
//5.求栈的长度
int LengthLinkStack(linkstack_t *top);
//6.获取栈顶数据
datatype GetTopLinkStack(linkstack_t *top);
#endif