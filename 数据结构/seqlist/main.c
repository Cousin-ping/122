#include<stdio.h>
#include"seqlist.h"

int main(int argc, char const *argv[])
{
    seqlist_t * p = CreateEpSeqlist();

    InsertIntoSeqlist(p,0,100);
    InsertIntoSeqlist(p,1,200);
    InsertIntoSeqlist(p,2,300);
    InsertIntoSeqlist(p,3,400);
    InsertIntoSeqlist(p,4,500);
    ShowSeqlist(p);
    DeletePostSeqlist(p,3);
    printf("Delete\n");
    ShowSeqlist(p);
    printf("Change\n");
    ChangePostSeqList(p,3,1234);
    ShowSeqlist(p);
    return 0;
}
