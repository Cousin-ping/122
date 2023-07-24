#include <stdio.h>
#include "linkstack.h"
int main(int argc, char const *argv[])
{
    linkstack_t *p=NULL;
    //1.入栈
    for(int i=10;i<16;i++)
    {
        PushLinkStack(&p,i);
    }
    for(int j=0;j<3;j++)
      printf("%d\n",PopLinkStack(&p));
   
    return 0;
}
