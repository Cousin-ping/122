#include<stdio.h>
#include"list.h"

int main(int argc, char const *argv[])
{
    link_node_list p=CreateEpLinkList();
    InsertIntoPostLinkList(p,1,'a');
    InsertIntoPostLinkList(p,2,'b');
    InsertIntoPostLinkList(p,3,'e');
    InsertIntoPostLinkList(p,4,'z');
    InsertIntoPostLinkList(p,5,'c');
    InsertIntoPostLinkList(p,6,'c');
    InsertIntoPostLinkList(p,7,'c');

    // head_insert(p,'b');
    // head_insert(p,'c');
    // head_insert(p,'d');
    // head_insert(p,'e');
    ShowLinkList(p);
    printf("开始转置\n");
    ReverseLinkList(p);
    ShowLinkList(p);
    // while (p->next!=NULL)
    // {
    //     printf("%c\n",p->data);
    //     p=p->next;
    // }
    
    

    // DeleteDataLinkList(p,'c');
    // ShowLinkList(p);
    // printf("链表有效长度为%d\n",LengthLinkList(p));

    // printf("e的位置是%d\n",SearchDataLinkList(p,'e'));
    // ChangePostLinkList(p,2,'x');
    // ShowLinkList(p);
    return 0;
}
