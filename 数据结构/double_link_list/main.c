#include<stdio.h>
#include"double_link_list.h"

int main(int argc, char const *argv[])
{
    double_list_t p=createEmptyDoubleLinkList();
    insertIntoDoubleLinkList(p,0,11);
    insertIntoDoubleLinkList(p,1,33);
    insertIntoDoubleLinkList(p,2,33);
    insertIntoDoubleLinkList(p,3,44);
    insertIntoDoubleLinkList(p,4,55);
    printf("此时的长度为%d\n",lengthDoubleLinkList(p));
    showDoubleLinkList(p);
    printf("33为第%d个元素\n",searchPostDoubleLinkList(p,33));

    changeDataDoubleLinkList(p,3,77);
    printf("修改之后的链表为%d\n");
    showDoubleLinkList(p);
    printf("删除查找的全部数据\n");
    deleteDataDoubleLinkList(p,33);
    showDoubleLinkList(p);
    printf("删除指定位置数据\n");
    deletePostDoubleLinkList(p,1);
    showDoubleLinkList(p);
    return 0;
}
