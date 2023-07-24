#include <stdio.h>
#include "linklist.h"
int main(int argc, char const *argv[])
{
    link_list_t p = CreateEpLinkList();
    InsertIntoPostLinkList(p, 0, 1);
    InsertIntoPostLinkList(p, 1, 2);
    InsertIntoPostLinkList(p, 2, 3);
    ShowLinkList(p); //1 2 3
    DeletePostLinkList(p, 2);
    ShowLinkList(p); //1 2
    ChangePostLinkList(p, 0, 100);
    ShowLinkList(p);                                            //100 2
    printf("%d post is %d\n", 100, SearchDataLinkList(p, 100)); //100  0
    InsertIntoPostLinkList(p, 2, 100);
    ShowLinkList(p); //100 2 100
    DeleteDataLinkList(p, 100);
    ShowLinkList(p); // 2
    InsertIntoPostLinkList(p, 1, 1);
    ShowLinkList(p); //2 1
    ReverseLinkList(p);
    printf("转置后：\n");
    ShowLinkList(p); // 1 2
    ClearLinkList(p);
    if(IsEpLinkList(p))
    {
        printf("linklist is empty\n");
    }

    return 0;
}
