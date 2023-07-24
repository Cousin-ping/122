#include<stdio.h>
#include<stdlib.h>
#include"seqlist.h"

int main(int argc, char const *argv[])
{
    seqlist_t * p = CreateEpSeqlist();

    InsertIntoSeqlist(p,0,1);
    InsertIntoSeqlist(p,1,2);
    InsertIntoSeqlist(p,2,3);
    InsertIntoSeqlist(p,3,4);
    InsertIntoSeqlist(p,4,5);

    ShowSeqlist(p);// 1 2 3 4 5
    DeletePostSeqlist(p,2);
    ShowSeqlist(p);//1 2 4 5
    ChangePostSeqList(p,2,400);
    ShowSeqlist(p);//1 2 400 5
    printf("%d 的位置在%d \n",400,SearchDataSeqList(p,400));
    ClearSeqList(p);
    if(IsEpSeqlist(p))
    {
        printf("空\n");
    }
    free(p);
    p=NULL;
    return 0;
}
