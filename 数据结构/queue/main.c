#include <stdio.h>
#include "queue.h"
int main(int argc, char const *argv[])
{
   
   sequeue_t * queue=CreateEmptySequeue();
   InSequeue(queue,11);
   InSequeue(queue,22);
   InSequeue(queue,33);
   InSequeue(queue,44);
//    InSequeue(queue,55);//此时队列有效长度已经满了，这个无法入队
   printf("此时队列长度为%d\n",LengthSequeue(queue));
   while (queue->rear!=queue->front)
   {
        printf("%d\n",OutSequeue(queue));
   }
   printf("此时队列长度为%d\n",LengthSequeue(queue));
return 0;
}
